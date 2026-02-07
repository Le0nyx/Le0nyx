using System;
using System.Collections.Generic;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Windows.Forms;

namespace cs04_memoryRedo
{
    public partial class Form1 : Form
    {
        // Game configuration
        private int gridSize = 4; // Default grid size
        private readonly string imagesPath = @"C:\Users\leonm\Desktop\pcC\all-Code\4bt\C#\cs04_memoryRedo\cs04_memoryRedo\MemoryPictures\";

        // Game state
        private List<string> imagePaths = new List<string>();
        private readonly List<PictureBox> cards = new List<PictureBox>();
        private PictureBox firstSelected;
        private PictureBox secondSelected;
        private int moveCount;
        private int matchedPairs;
        private DateTime gameStartTime;
        private readonly Image cardBackImage;

        public Form1()
        {
            InitializeComponent();
            cardBackImage = Image.FromFile(Path.Combine(imagesPath, "default.jpg"));
            InitializeGame();
        }

        private void InitializeGame()
        {
            // Reset game state
            cards.ForEach(c => c.Dispose());
            cards.Clear();
            tableLayoutPanel1.Controls.Clear();
            firstSelected = null;
            secondSelected = null;
            moveCount = 0;
            matchedPairs = 0;
            lblMoves.Text = "Moves: 0";
            lblTime.Text = "Time: 00:00";
            gameStartTime = DateTime.Now;

            // Load and shuffle images
            LoadImages();
            ShuffleImages();

            // Create game board
            CreateCardGrid();

            // Start game timer
            gameTimer.Start();
        }

        private void LoadImages()
        {
            imagePaths.Clear();
            var validExtensions = new[] { ".png", ".jpg", ".jpeg" };

            var files = Directory.GetFiles(imagesPath)
                .Where(f => validExtensions.Contains(Path.GetExtension(f).ToLower()))
                .Where(f => !Path.GetFileName(f).Equals("default.jpg", StringComparison.OrdinalIgnoreCase))
                .ToList();

            int requiredImages = (gridSize * gridSize) / 2;
            if (files.Count < requiredImages)
                throw new Exception($"Need at least {requiredImages} different images in the directory (excluding default.jpg)");

            // Use required number of images and create pairs
            var selectedImages = files.Take(requiredImages).ToList();
            imagePaths.AddRange(selectedImages);
            imagePaths.AddRange(selectedImages);
        }

        private void ShuffleImages()
        {
            var rng = new Random();
            imagePaths = imagePaths.OrderBy(_ => rng.Next()).ToList();
        }

        private void CreateCardGrid()
        {
            tableLayoutPanel1.RowCount = gridSize;
            tableLayoutPanel1.ColumnCount = gridSize;

            for (int i = 0; i < gridSize * gridSize; i++)
            {
                var card = new PictureBox
                {
                    Dock = DockStyle.Fill,
                    SizeMode = PictureBoxSizeMode.Zoom,
                    Image = cardBackImage,
                    Tag = i,
                    Margin = new Padding(8)
                };
                card.Click += Card_Click;
                cards.Add(card);
                tableLayoutPanel1.Controls.Add(card);
            }
        }

        private void Card_Click(object sender, EventArgs e)
        {
            if (firstSelected != null && secondSelected != null) return;

            var card = sender as PictureBox;
            if (card == null || card.Image != cardBackImage) return;

            // Reveal card
            card.Image = Image.FromFile(imagePaths[(int)card.Tag]);

            if (firstSelected == null)
            {
                firstSelected = card;
            }
            else
            {
                secondSelected = card;
                moveCount++;
                lblMoves.Text = $"Moves: {moveCount}";
                CheckForMatch();
            }
        }

        private void CheckForMatch()
        {
            if (imagePaths[(int)firstSelected.Tag] == imagePaths[(int)secondSelected.Tag])
            {
                // Match found
                firstSelected.Enabled = false;
                secondSelected.Enabled = false;
                matchedPairs++;

                if (matchedPairs == gridSize * gridSize / 2)
                {
                    gameTimer.Stop();
                    var duration = DateTime.Now - gameStartTime;
                    MessageBox.Show($"You won in {duration:mm\\:ss} and {moveCount} moves!");
                }

                ResetSelection();
            }
            else
            {
                // No match - flip back after delay
                flipTimer.Start();
            }
        }

        private void ResetSelection()
        {
            firstSelected = null;
            secondSelected = null;
        }

        private void flipTimer_Tick(object sender, EventArgs e)
        {
            flipTimer.Stop();
            firstSelected.Image = cardBackImage;
            secondSelected.Image = cardBackImage;
            ResetSelection();
        }

        private void gameTimer_Tick(object sender, EventArgs e)
        {
            var elapsed = DateTime.Now - gameStartTime;
            lblTime.Text = $"Time: {elapsed:mm\\:ss}";
        }

        private void btnNewGame_Click(object sender, EventArgs e)
        {
            gameTimer.Stop();
            flipTimer.Stop();
            InitializeGame();
        }
    }
}