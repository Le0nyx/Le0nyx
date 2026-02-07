namespace WinFormsApp1
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;
        private TimeSpan countUpTime = TimeSpan.Zero;
        private TimeSpan countDownTime = TimeSpan.Zero;
        private TimeSpan initialCountDownTime = TimeSpan.Zero;
        private bool isTimer1Paused = false;
        private bool isTimer2Paused = false;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            tabControl1 = new TabControl();
            tabPage1 = new TabPage();
            label3 = new Label();
            listBox1 = new ListBox();
            button3 = new Button();
            label2 = new Label();
            button1 = new Button();
            tabPage2 = new TabPage();
            button4 = new Button();
            label5 = new Label();
            textBox1 = new TextBox();
            label1 = new Label();
            button2 = new Button();
            timer1 = new System.Windows.Forms.Timer(components);
            timer2 = new System.Windows.Forms.Timer(components);
            tabControl1.SuspendLayout();
            tabPage1.SuspendLayout();
            tabPage2.SuspendLayout();
            SuspendLayout();
            // 
            // tabControl1
            // 
            tabControl1.Controls.Add(tabPage1);
            tabControl1.Controls.Add(tabPage2);
            tabControl1.Location = new Point(12, 12);
            tabControl1.Name = "tabControl1";
            tabControl1.SelectedIndex = 0;
            tabControl1.Size = new Size(787, 441);
            tabControl1.TabIndex = 0;
            // 
            // tabPage1
            // 
            tabPage1.Controls.Add(label3);
            tabPage1.Controls.Add(listBox1);
            tabPage1.Controls.Add(button3);
            tabPage1.Controls.Add(label2);
            tabPage1.Controls.Add(button1);
            tabPage1.Location = new Point(4, 29);
            tabPage1.Name = "tabPage1";
            tabPage1.Padding = new Padding(3);
            tabPage1.Size = new Size(779, 408);
            tabPage1.TabIndex = 0;
            tabPage1.Text = "Countup";
            tabPage1.UseVisualStyleBackColor = true;
            // 
            // label3
            // 
            label3.AutoSize = true;
            label3.Location = new Point(469, 30);
            label3.Name = "label3";
            label3.Size = new Size(142, 20);
            label3.TabIndex = 5;
            label3.Text = "Past recorded times:";
            // 
            // listBox1
            // 
            listBox1.FormattingEnabled = true;
            listBox1.Location = new Point(469, 63);
            listBox1.Name = "listBox1";
            listBox1.Size = new Size(246, 284);
            listBox1.TabIndex = 4;
            // 
            // button3
            // 
            button3.Location = new Point(209, 318);
            button3.Name = "button3";
            button3.Size = new Size(127, 29);
            button3.TabIndex = 3;
            button3.Text = "Pause Clock 1";
            button3.UseVisualStyleBackColor = true;
            button3.Click += new EventHandler(button3_Click);
            // 
            // label2
            // 
            label2.AutoSize = true;
            label2.Location = new Point(172, 177);
            label2.Name = "label2";
            label2.Size = new Size(50, 20);
            label2.TabIndex = 1;
            label2.Text = "00:00:00:000";
            // 
            // button1
            // 
            button1.Location = new Point(54, 318);
            button1.Name = "button1";
            button1.Size = new Size(128, 29);
            button1.TabIndex = 0;
            button1.Text = "Start Clock 1";
            button1.UseVisualStyleBackColor = true;
            button1.Click += new EventHandler(button1_Click);
            // 
            // tabPage2
            // 
            tabPage2.Controls.Add(button4);
            tabPage2.Controls.Add(label5);
            tabPage2.Controls.Add(textBox1);
            tabPage2.Controls.Add(label1);
            tabPage2.Controls.Add(button2);
            tabPage2.Location = new Point(4, 29);
            tabPage2.Name = "tabPage2";
            tabPage2.Padding = new Padding(3);
            tabPage2.Size = new Size(779, 408);
            tabPage2.TabIndex = 1;
            tabPage2.Text = "Countdown";
            tabPage2.UseVisualStyleBackColor = true;
            // 
            // button4
            // 
            button4.Location = new Point(604, 313);
            button4.Name = "button4";
            button4.Size = new Size(128, 29);
            button4.TabIndex = 5;
            button4.Text = "Pause Clock 2";
            button4.UseVisualStyleBackColor = true;
            button4.Click += new EventHandler(button4_Click);
            // 
            // label5
            // 
            label5.AutoSize = true;
            label5.Location = new Point(17, 32);
            label5.Name = "label5";
            label5.Size = new Size(223, 20);
            label5.TabIndex = 4;
            label5.Text = "Enter Time to count down from (seconds): ";
            // 
            // textBox1
            // 
            textBox1.Location = new Point(17, 68);
            textBox1.Name = "textBox1";
            textBox1.Size = new Size(200, 27);
            textBox1.TabIndex = 3;
            // 
            // label1
            // 
            label1.AutoSize = true;
            label1.Location = new Point(564, 194);
            label1.Name = "label1";
            label1.Size = new Size(50, 20);
            label1.TabIndex = 1;
            label1.Text = "00:00:00:000";
            // 
            // button2
            // 
            button2.Location = new Point(448, 313);
            button2.Name = "button2";
            button2.Size = new Size(122, 29);
            button2.TabIndex = 0;
            button2.Text = "Start clock 2";
            button2.UseVisualStyleBackColor = true;
            button2.Click += new EventHandler(button2_Click);
            // 
            // timer1
            // 
            timer1.Interval = 100;
            timer1.Tick += new EventHandler(timer1_Tick);
            // 
            // timer2
            // 
            timer2.Interval = 100;
            timer2.Tick += new EventHandler(timer2_Tick);
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 450);
            Controls.Add(tabControl1);
            Name = "Form1";
            Text = "Form1";
            tabControl1.ResumeLayout(false);
            tabPage1.ResumeLayout(false);
            tabPage1.PerformLayout();
            tabPage2.ResumeLayout(false);
            tabPage2.PerformLayout();
            ResumeLayout(false);
        }

        #endregion

        private TabControl tabControl1;
        private TabPage tabPage1;
        private Button button1;
        private TabPage tabPage2;
        private Button button2;
        private Label label2;
        private Label label1;
        private Button button3;
        private Label label5;
        private TextBox textBox1;
        private Button button4;
        private Label label3;
        private ListBox listBox1;
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Timer timer2;

        private void button1_Click(object sender, EventArgs e)
        {
            countUpTime = TimeSpan.Zero;
            label2.Text = countUpTime.ToString(@"hh\:mm\:ss\:fff");
            timer1.Start();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            if (isTimer1Paused)
            {
                timer1.Start();
                isTimer1Paused = false;
            }
            else
            {
                timer1.Stop();
                listBox1.Items.Add(countUpTime.ToString(@"hh\:mm\:ss\:fff"));
                isTimer1Paused = true;
            }
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            countUpTime = countUpTime.Add(TimeSpan.FromMilliseconds(timer1.Interval));
            label2.Text = countUpTime.ToString(@"hh\:mm\:ss\:fff");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (int.TryParse(textBox1.Text, out int seconds))
            {
                initialCountDownTime = TimeSpan.FromSeconds(seconds);
                countDownTime = initialCountDownTime;
                label1.Text = countDownTime.ToString(@"hh\:mm\:ss\:fff");
                timer2.Start();
                isTimer2Paused = false;
            }
            else
            {
                label1.Text = "Please enter a valid number.";
            }
        }

        private void button4_Click(object sender, EventArgs e)
        {
            if (isTimer2Paused)
            {
                timer2.Start();
                isTimer2Paused = false;
            }
            else
            {
                timer2.Stop();
                isTimer2Paused = true;
            }
        }

        private void timer2_Tick(object sender, EventArgs e)
        {
            if (countDownTime > TimeSpan.Zero)
            {
                countDownTime = countDownTime.Subtract(TimeSpan.FromMilliseconds(timer2.Interval));
                label1.Text = countDownTime.ToString(@"hh\:mm\:ss\:fff");
            }
            else
            {
                timer2.Stop();
                label1.Text = "Countdown finished!";
            }
        }
    }
}
