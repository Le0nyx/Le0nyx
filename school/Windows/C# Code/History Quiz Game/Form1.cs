using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace CollabQuiz
{
    public partial class Form1 : Form
    {
        private class Question
        {
            public string Text { get; set; }
            public List<string> Answers { get; set; }
            public string CorrectAnswer { get; set; }
        }

        private List<Question> questions = new List<Question>();
        private int currentQuestionIndex = 0;
        private int score = 0;
        private int savedHighscore = 0;

        private readonly string fragenPath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "fragen.txt");
        private readonly string highscorePath = Path.Combine(AppDomain.CurrentDomain.BaseDirectory, "highscore.txt");
        private readonly Random rnd = new Random();

        private Timer quizTimer = new Timer();
        private int timeLeft = 120; // 2 minutes

        public Form1()
        {
            InitializeComponent();
            LoadHighscore();
            LoadQuestions();
            ShowQuestion();
            SetupTimer();

            // --- Style Form ---
            this.DoubleBuffered = true; // reduce flicker
            this.Paint += Form1_Paint;  // enable gradient background

            // --- Question Box Styling ---
            txtQuestion.BackColor = Color.AliceBlue;
            txtQuestion.BorderStyle = BorderStyle.FixedSingle;
            txtQuestion.Font = new Font("Segoe UI", 12, FontStyle.Bold);

            // --- Buttons Styling ---
            foreach (var btn in new[] { button1, button2, button3, button4, buttonRetry })
            {
                btn.FlatStyle = FlatStyle.Flat;
                btn.BackColor = Color.WhiteSmoke;
                btn.Font = new Font("Segoe UI", 10, FontStyle.Bold);

                btn.MouseEnter += (s, e) =>
                {
                    if (((Button)s).Enabled)
                        ((Button)s).BackColor = Color.LightSkyBlue;
                };
                btn.MouseLeave += (s, e) =>
                {
                    if (((Button)s).Enabled)
                        ((Button)s).BackColor = Color.WhiteSmoke;
                };
            }

            // --- Label Styling ---
            label2.BackColor = Color.Transparent;
            label2.Font = new Font("Segoe UI", 10, FontStyle.Bold);

            label3.BackColor = Color.Transparent;
            label3.Font = new Font("Segoe UI", 10, FontStyle.Bold);
            label3.ForeColor = Color.DarkBlue;

            label4.BackColor = Color.Transparent;
            label4.Font = new Font("Segoe UI", 10, FontStyle.Bold);
            label4.ForeColor = Color.MidnightBlue;
        }

        // Gradient background
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            using (var brush = new System.Drawing.Drawing2D.LinearGradientBrush(
                this.ClientRectangle,
                Color.LightSteelBlue,
                Color.White,
                90F))
            {
                e.Graphics.FillRectangle(brush, this.ClientRectangle);
            }
        }

        private void LoadQuestions()
        {
            if (!File.Exists(fragenPath))
            {
                MessageBox.Show($"file not found {fragenPath}");
                Application.Exit();
                return;
            }

            var lines = File.ReadAllLines(fragenPath)
                            .Where(l => !string.IsNullOrWhiteSpace(l) && !l.StartsWith("#"))
                            .ToList();

            var allQuestions = new List<Question>();

            foreach (var line in lines)
            {
                var parts = line.Split('|');
                if (parts.Length >= 5)
                {
                    allQuestions.Add(new Question
                    {
                        Text = parts[0].Trim(),
                        CorrectAnswer = parts[1].Trim(),
                        Answers = new List<string> { parts[1].Trim(), parts[2].Trim(), parts[3].Trim(), parts[4].Trim() }
                    });
                }
            }

            // Randomize all questions
            questions = allQuestions.OrderBy(x => rnd.Next()).ToList();
        }

        private void LoadHighscore()
        {
            if (File.Exists(highscorePath))
                int.TryParse(File.ReadAllText(highscorePath).Trim(), out savedHighscore);

            label3.Text = "Highscore:";
            label4.Text = savedHighscore.ToString();
        }

        private void SetupTimer()
        {
            quizTimer.Interval = 1000;
            quizTimer.Tick += QuizTimer_Tick;
            quizTimer.Start();
            UpdateTimeLabel();
        }

        private void QuizTimer_Tick(object sender, EventArgs e)
        {
            timeLeft--;
            UpdateTimeLabel();

            if (timeLeft <= 0)
            {
                quizTimer.Stop();
                EndGame();
            }
        }

        private void UpdateTimeLabel()
        {
            int minutes = timeLeft / 60;
            int seconds = timeLeft % 60;
            label2.Text = $"Punkte: {score} | Zeit: {minutes:D2}:{seconds:D2}";
        }

        private void ShowQuestion()
        {
            if (questions.Count == 0) return;

            if (currentQuestionIndex >= questions.Count)
            {
                currentQuestionIndex = 0;
                questions = questions.OrderBy(x => rnd.Next()).ToList();
            }

            var q = questions[currentQuestionIndex];
            txtQuestion.Text = q.Text;

            var display = q.Answers.OrderBy(a => rnd.Next()).ToList();
            button1.Text = display[0];
            button2.Text = display[1];
            button3.Text = display[2];
            button4.Text = display[3];

            UpdateHighscoreLabel();
        }

        private void UpdateHighscoreLabel()
        {
            int displayHighscore = Math.Max(savedHighscore, score);
            label4.Text = displayHighscore.ToString();
        }

        private async void AnswerClicked(string chosen)
        {
            var q = questions[currentQuestionIndex];
            bool correct = string.Equals(chosen.Trim(), q.CorrectAnswer.Trim(), StringComparison.OrdinalIgnoreCase);

            Button clickedButton = null;
            if (button1.Text == chosen) clickedButton = button1;
            else if (button2.Text == chosen) clickedButton = button2;
            else if (button3.Text == chosen) clickedButton = button3;
            else if (button4.Text == chosen) clickedButton = button4;

            if (clickedButton != null)
                clickedButton.BackColor = correct ? Color.LightGreen : Color.IndianRed;

            if (!correct)
            {
                foreach (var btn in new[] { button1, button2, button3, button4 })
                {
                    if (btn.Text.Equals(q.CorrectAnswer, StringComparison.OrdinalIgnoreCase))
                    {
                        btn.BackColor = Color.LightGreen;
                        break;
                    }
                }
            }

            if (correct) score += 10;
            else score -= 5;

            await Task.Delay(700);

            button1.BackColor = Color.WhiteSmoke;
            button2.BackColor = Color.WhiteSmoke;
            button3.BackColor = Color.WhiteSmoke;
            button4.BackColor = Color.WhiteSmoke;

            currentQuestionIndex++;
            ShowQuestion();
        }

        private void EndGame()
        {
            quizTimer.Stop();

            MessageBox.Show($"Game over!\nDeine Punkte: {score}", "Over");

            if (score > savedHighscore || savedHighscore < 0)
            {
                savedHighscore = score;
                try { File.WriteAllText(highscorePath, savedHighscore.ToString()); } catch { }
            }

            label4.Text = savedHighscore.ToString();

            button1.Enabled = button2.Enabled = button3.Enabled = button4.Enabled = false;
            buttonRetry.Enabled = true;
            buttonRetry.BackColor = Color.LightYellow; // highlight retry button
        }

        private void buttonRetry_Click(object sender, EventArgs e)
        {
            currentQuestionIndex = 0;
            score = 0;
            timeLeft = 120;
            button1.Enabled = button2.Enabled = button3.Enabled = button4.Enabled = true;
            buttonRetry.Enabled = false;
            buttonRetry.BackColor = Color.WhiteSmoke;

            questions = questions.OrderBy(x => rnd.Next()).ToList();

            ShowQuestion();
            quizTimer.Start();
        }

        private void button1_Click(object sender, EventArgs e) => AnswerClicked(button1.Text);
        private void button2_Click(object sender, EventArgs e) => AnswerClicked(button2.Text);
        private void button3_Click(object sender, EventArgs e) => AnswerClicked(button3.Text);
        private void button4_Click(object sender, EventArgs e) => AnswerClicked(button4.Text);
    }
}
