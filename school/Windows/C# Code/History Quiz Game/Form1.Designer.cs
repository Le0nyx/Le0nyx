namespace CollabQuiz
{
    partial class Form1
    {
        private System.ComponentModel.IContainer components = null;

        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null)) components.Dispose();
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        private void InitializeComponent()
        {
            this.button1 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button3 = new System.Windows.Forms.Button();
            this.button4 = new System.Windows.Forms.Button();
            this.buttonRetry = new System.Windows.Forms.Button();
            this.txtQuestion = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // txtQuestion
            this.txtQuestion.Multiline = true;
            this.txtQuestion.ReadOnly = true;
            this.txtQuestion.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtQuestion.Font = new System.Drawing.Font("Segoe UI", 12F);
            this.txtQuestion.Size = new System.Drawing.Size(600, 120);
            this.txtQuestion.Location = new System.Drawing.Point(100, 30);
            this.txtQuestion.BackColor = System.Drawing.SystemColors.Control;
            this.txtQuestion.BorderStyle = System.Windows.Forms.BorderStyle.None;
            // 
            // button1
            this.button1.Location = new System.Drawing.Point(100, 160);
            this.button1.Size = new System.Drawing.Size(250, 50);
            this.button1.Click += new System.EventHandler(this.button1_Click);
            // 
            // button2
            this.button2.Location = new System.Drawing.Point(450, 160);
            this.button2.Size = new System.Drawing.Size(250, 50);
            this.button2.Click += new System.EventHandler(this.button2_Click);
            // 
            // button3
            this.button3.Location = new System.Drawing.Point(100, 260);
            this.button3.Size = new System.Drawing.Size(250, 50);
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button4
            this.button4.Location = new System.Drawing.Point(450, 260);
            this.button4.Size = new System.Drawing.Size(250, 50);
            this.button4.Click += new System.EventHandler(this.button4_Click);
            // 
            // buttonRetry
            this.buttonRetry.Location = new System.Drawing.Point(300, 350);
            this.buttonRetry.Size = new System.Drawing.Size(200, 40);
            this.buttonRetry.Text = "play again?";
            this.buttonRetry.Enabled = false;
            this.buttonRetry.Click += new System.EventHandler(this.buttonRetry_Click);
            // 
            // label2 (score + timer)
            this.label2.AutoSize = true;
            this.label2.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.label2.Location = new System.Drawing.Point(12, 410);
            // 
            // label3 (Highscore label)
            this.label3.AutoSize = true;
            this.label3.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.label3.Location = new System.Drawing.Point(600, 12);
            this.label3.Text = "highscore:";
            // 
            // label4 (Highscore value)
            this.label4.AutoSize = true;
            this.label4.Font = new System.Drawing.Font("Segoe UI", 10F);
            this.label4.Location = new System.Drawing.Point(690, 12);
            this.label4.Text = "0";
            // 
            // Form1
            this.ClientSize = new System.Drawing.Size(800, 450);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.txtQuestion);
            this.Controls.Add(this.buttonRetry);
            this.Controls.Add(this.button4);
            this.Controls.Add(this.button3);
            this.Controls.Add(this.button2);
            this.Controls.Add(this.button1);
            this.Name = "Form1";
            this.Text = "GeschInfo Quiz";
            this.ResumeLayout(false);
            this.PerformLayout();
        }

        #endregion

        private System.Windows.Forms.TextBox txtQuestion;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button button4;
        private System.Windows.Forms.Button buttonRetry;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
    }
}
