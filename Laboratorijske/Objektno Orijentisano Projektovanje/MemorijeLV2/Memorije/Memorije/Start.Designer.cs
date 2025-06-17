namespace Memorije
{
    partial class Start
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
            this.lblWin.Location = new System.Drawing.Point(216, 365);
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
            // Start
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(481, 401);
            this.Controls.Add(this.lblWin);
            this.Controls.Add(this.lblTimer);
            this.Name = "Start";
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
    }
}

