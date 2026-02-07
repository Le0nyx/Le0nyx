namespace cs04_memoryRedo
{
    partial class Form1
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            components = new System.ComponentModel.Container();
            tableLayoutPanel1 = new TableLayoutPanel();
            lblTime = new Label();
            lblMoves = new Label();
            btnNewGame = new Button();
            gameTimer = new System.Windows.Forms.Timer(components);
            flipTimer = new System.Windows.Forms.Timer(components);
            SuspendLayout();
            // 
            // tableLayoutPanel1
            // 
            tableLayoutPanel1.ColumnCount = 4;
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.ColumnStyles.Add(new ColumnStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.Dock = DockStyle.Fill;
            tableLayoutPanel1.Location = new Point(20, 80);
            tableLayoutPanel1.Margin = new Padding(0);
            tableLayoutPanel1.Name = "tableLayoutPanel1";
            tableLayoutPanel1.RowCount = 4;
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.RowStyles.Add(new RowStyle(SizeType.Percent, 25F));
            tableLayoutPanel1.Size = new Size(760, 760);
            tableLayoutPanel1.TabIndex = 0;
            // 
            // lblTime
            // 
            lblTime.AutoSize = true;
            lblTime.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lblTime.Location = new Point(20, 20);
            lblTime.Name = "lblTime";
            lblTime.Size = new Size(115, 28);
            lblTime.TabIndex = 1;
            lblTime.Text = "Time: 00:00";
            // 
            // lblMoves
            // 
            lblMoves.AutoSize = true;
            lblMoves.Font = new Font("Segoe UI", 12F, FontStyle.Bold, GraphicsUnit.Point, 0);
            lblMoves.Location = new Point(20, 48);
            lblMoves.Name = "lblMoves";
            lblMoves.Size = new Size(106, 28);
            lblMoves.TabIndex = 2;
            lblMoves.Text = "Moves: 0";
            // 
            // btnNewGame
            // 
            btnNewGame.Anchor = AnchorStyles.Top | AnchorStyles.Right;
            btnNewGame.Font = new Font("Segoe UI", 10F);
            btnNewGame.Location = new Point(650, 20);
            btnNewGame.Name = "btnNewGame";
            btnNewGame.Size = new Size(130, 40);
            btnNewGame.TabIndex = 3;
            btnNewGame.Text = "New Game";
            btnNewGame.UseVisualStyleBackColor = true;
            btnNewGame.Click += new System.EventHandler(btnNewGame_Click);  // Added event connection
            // 
            // gameTimer
            // 
            gameTimer.Interval = 1000;
            gameTimer.Tick += gameTimer_Tick;
            // 
            // flipTimer
            // 
            flipTimer.Interval = 1000;
            flipTimer.Tick += flipTimer_Tick;
            // 
            // Form1
            // 
            AutoScaleDimensions = new SizeF(8F, 20F);
            AutoScaleMode = AutoScaleMode.Font;
            ClientSize = new Size(800, 860);
            Controls.Add(btnNewGame);
            Controls.Add(lblMoves);
            Controls.Add(lblTime);
            Controls.Add(tableLayoutPanel1);
            MinimumSize = new Size(600, 600);
            Name = "Form1";
            Padding = new Padding(20);
            Text = "Memory Game";
            ResumeLayout(false);
            PerformLayout();
        }

        #endregion

        private TableLayoutPanel tableLayoutPanel1;
        private Label lblTime;
        private Label lblMoves;
        private Button btnNewGame;
        private System.Windows.Forms.Timer gameTimer;
        private System.Windows.Forms.Timer flipTimer;
    }
}