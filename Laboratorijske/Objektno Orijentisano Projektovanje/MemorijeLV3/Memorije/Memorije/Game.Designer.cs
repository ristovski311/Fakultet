namespace Memorije
{
    partial class Game
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
            this.components = new System.ComponentModel.Container();
            this.lblTimer = new System.Windows.Forms.Label();
            this.tmrTimeElapsed = new System.Windows.Forms.Timer(this.components);
            this.lblWin = new System.Windows.Forms.Label();
            this.tmrCheckWinCondition = new System.Windows.Forms.Timer(this.components);
            this.btnRestart = new System.Windows.Forms.Button();
            this.btnOpenAll = new System.Windows.Forms.Button();
            this.btnXML = new System.Windows.Forms.Button();
            this.btnLoadXML = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // lblTimer
            // 
            this.lblTimer.AutoSize = true;
            this.lblTimer.Font = new System.Drawing.Font("Microsoft YaHei", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(0)));
            this.lblTimer.Location = new System.Drawing.Point(12, 365);
            this.lblTimer.Name = "lblTimer";
            this.lblTimer.Size = new System.Drawing.Size(78, 27);
            this.lblTimer.TabIndex = 0;
            this.lblTimer.Text = "TIMER";
            // 
            // tmrTimeElapsed
            // 
            this.tmrTimeElapsed.Interval = 1000;
            this.tmrTimeElapsed.Tick += new System.EventHandler(this.tmrTimeElapsed_Tick);
            // 
            // lblWin
            // 
            this.lblWin.AutoSize = true;
            this.lblWin.Font = new System.Drawing.Font("Microsoft YaHei", 12F, System.Drawing.FontStyle.Bold);
            this.lblWin.ForeColor = System.Drawing.Color.Red;
            this.lblWin.Location = new System.Drawing.Point(117, 449);
            this.lblWin.Name = "lblWin";
            this.lblWin.Size = new System.Drawing.Size(253, 27);
            this.lblWin.TabIndex = 1;
            this.lblWin.Text = "CONGRATS! YOU WON!";
            // 
            // tmrCheckWinCondition
            // 
            this.tmrCheckWinCondition.Interval = 10;
            this.tmrCheckWinCondition.Tick += new System.EventHandler(this.tmrCheckWinCondition_Tick);
            // 
            // btnRestart
            // 
            this.btnRestart.Font = new System.Drawing.Font("Microsoft YaHei", 12F, System.Drawing.FontStyle.Bold);
            this.btnRestart.Location = new System.Drawing.Point(96, 358);
            this.btnRestart.Name = "btnRestart";
            this.btnRestart.Size = new System.Drawing.Size(145, 34);
            this.btnRestart.TabIndex = 2;
            this.btnRestart.Text = "RESTART GAME";
            this.btnRestart.UseVisualStyleBackColor = true;
            this.btnRestart.Click += new System.EventHandler(this.btnRestart_Click);
            // 
            // btnOpenAll
            // 
            this.btnOpenAll.Font = new System.Drawing.Font("Microsoft YaHei", 12F, System.Drawing.FontStyle.Bold);
            this.btnOpenAll.Location = new System.Drawing.Point(247, 358);
            this.btnOpenAll.Name = "btnOpenAll";
            this.btnOpenAll.Size = new System.Drawing.Size(145, 34);
            this.btnOpenAll.TabIndex = 3;
            this.btnOpenAll.Text = "REVEAL";
            this.btnOpenAll.UseVisualStyleBackColor = true;
            this.btnOpenAll.Click += new System.EventHandler(this.btnOpenAll_Click);
            // 
            // btnXML
            // 
            this.btnXML.Font = new System.Drawing.Font("Microsoft YaHei", 12F, System.Drawing.FontStyle.Bold);
            this.btnXML.Location = new System.Drawing.Point(96, 398);
            this.btnXML.Name = "btnXML";
            this.btnXML.Size = new System.Drawing.Size(145, 34);
            this.btnXML.TabIndex = 4;
            this.btnXML.Text = "SACUVAJ";
            this.btnXML.UseVisualStyleBackColor = true;
            this.btnXML.Click += new System.EventHandler(this.btnXML_Click);
            // 
            // btnLoadXML
            // 
            this.btnLoadXML.Font = new System.Drawing.Font("Microsoft YaHei", 12F, System.Drawing.FontStyle.Bold);
            this.btnLoadXML.Location = new System.Drawing.Point(247, 398);
            this.btnLoadXML.Name = "btnLoadXML";
            this.btnLoadXML.Size = new System.Drawing.Size(145, 34);
            this.btnLoadXML.TabIndex = 5;
            this.btnLoadXML.Text = "UCITAJ";
            this.btnLoadXML.UseVisualStyleBackColor = true;
            this.btnLoadXML.Click += new System.EventHandler(this.btnLoadXML_Click);
            // 
            // Game
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1078, 505);
            this.Controls.Add(this.btnLoadXML);
            this.Controls.Add(this.btnXML);
            this.Controls.Add(this.btnOpenAll);
            this.Controls.Add(this.btnRestart);
            this.Controls.Add(this.lblWin);
            this.Controls.Add(this.lblTimer);
            this.Name = "Game";
            this.Text = "Memorije";
            this.Load += new System.EventHandler(this.Start_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label lblTimer;
        private System.Windows.Forms.Timer tmrTimeElapsed;
        private System.Windows.Forms.Label lblWin;
        private System.Windows.Forms.Timer tmrCheckWinCondition;
        private System.Windows.Forms.Button btnRestart;
        private System.Windows.Forms.Button btnOpenAll;
        private System.Windows.Forms.Button btnXML;
        private System.Windows.Forms.Button btnLoadXML;
    }
}

