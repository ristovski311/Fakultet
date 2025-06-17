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
            this.tmrTimeElapsed = new System.Windows.Forms.Timer(this.components);
            this.tmrCheckWinCondition = new System.Windows.Forms.Timer(this.components);
            this.menuStrip1 = new System.Windows.Forms.MenuStrip();
            this.administrationToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.konfiguracijaTableToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.sacuvajToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.ucitajToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.restartujToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.otvoriSvaPoljaToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.timerToolStripMenuItem = new System.Windows.Forms.ToolStripMenuItem();
            this.menuStrip1.SuspendLayout();
            this.SuspendLayout();
            // 
            // tmrTimeElapsed
            // 
            this.tmrTimeElapsed.Interval = 1000;
            this.tmrTimeElapsed.Tick += new System.EventHandler(this.tmrTimeElapsed_Tick);
            // 
            // tmrCheckWinCondition
            // 
            this.tmrCheckWinCondition.Interval = 10;
            this.tmrCheckWinCondition.Tick += new System.EventHandler(this.tmrCheckWinCondition_Tick);
            // 
            // menuStrip1
            // 
            this.menuStrip1.ImageScalingSize = new System.Drawing.Size(20, 20);
            this.menuStrip1.Items.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.administrationToolStripMenuItem,
            this.timerToolStripMenuItem});
            this.menuStrip1.Location = new System.Drawing.Point(0, 0);
            this.menuStrip1.Name = "menuStrip1";
            this.menuStrip1.Size = new System.Drawing.Size(300, 30);
            this.menuStrip1.TabIndex = 6;
            this.menuStrip1.Text = "menuStrip1";
            // 
            // administrationToolStripMenuItem
            // 
            this.administrationToolStripMenuItem.DropDownItems.AddRange(new System.Windows.Forms.ToolStripItem[] {
            this.konfiguracijaTableToolStripMenuItem,
            this.sacuvajToolStripMenuItem,
            this.ucitajToolStripMenuItem,
            this.restartujToolStripMenuItem,
            this.otvoriSvaPoljaToolStripMenuItem});
            this.administrationToolStripMenuItem.Name = "administrationToolStripMenuItem";
            this.administrationToolStripMenuItem.Size = new System.Drawing.Size(121, 26);
            this.administrationToolStripMenuItem.Text = "Administration";
            // 
            // konfiguracijaTableToolStripMenuItem
            // 
            this.konfiguracijaTableToolStripMenuItem.Name = "konfiguracijaTableToolStripMenuItem";
            this.konfiguracijaTableToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.K)));
            this.konfiguracijaTableToolStripMenuItem.Size = new System.Drawing.Size(269, 26);
            this.konfiguracijaTableToolStripMenuItem.Text = "Konfiguracija table";
            this.konfiguracijaTableToolStripMenuItem.Click += new System.EventHandler(this.konfiguracijaTableToolStripMenuItem_Click);
            // 
            // sacuvajToolStripMenuItem
            // 
            this.sacuvajToolStripMenuItem.Name = "sacuvajToolStripMenuItem";
            this.sacuvajToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.S)));
            this.sacuvajToolStripMenuItem.Size = new System.Drawing.Size(269, 26);
            this.sacuvajToolStripMenuItem.Text = "Sacuvaj";
            this.sacuvajToolStripMenuItem.Click += new System.EventHandler(this.sacuvajToolStripMenuItem_Click);
            // 
            // ucitajToolStripMenuItem
            // 
            this.ucitajToolStripMenuItem.Name = "ucitajToolStripMenuItem";
            this.ucitajToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.L)));
            this.ucitajToolStripMenuItem.Size = new System.Drawing.Size(269, 26);
            this.ucitajToolStripMenuItem.Text = "Ucitaj";
            this.ucitajToolStripMenuItem.Click += new System.EventHandler(this.ucitajToolStripMenuItem_Click);
            // 
            // restartujToolStripMenuItem
            // 
            this.restartujToolStripMenuItem.Name = "restartujToolStripMenuItem";
            this.restartujToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.R)));
            this.restartujToolStripMenuItem.Size = new System.Drawing.Size(269, 26);
            this.restartujToolStripMenuItem.Text = "Restartuj";
            this.restartujToolStripMenuItem.Click += new System.EventHandler(this.restartujToolStripMenuItem_Click);
            // 
            // otvoriSvaPoljaToolStripMenuItem
            // 
            this.otvoriSvaPoljaToolStripMenuItem.Name = "otvoriSvaPoljaToolStripMenuItem";
            this.otvoriSvaPoljaToolStripMenuItem.ShortcutKeys = ((System.Windows.Forms.Keys)((System.Windows.Forms.Keys.Control | System.Windows.Forms.Keys.O)));
            this.otvoriSvaPoljaToolStripMenuItem.Size = new System.Drawing.Size(269, 26);
            this.otvoriSvaPoljaToolStripMenuItem.Text = "Otvori sva polja";
            this.otvoriSvaPoljaToolStripMenuItem.Click += new System.EventHandler(this.otvoriSvaPoljaToolStripMenuItem_Click);
            // 
            // timerToolStripMenuItem
            // 
            this.timerToolStripMenuItem.AccessibleRole = System.Windows.Forms.AccessibleRole.None;
            this.timerToolStripMenuItem.Enabled = false;
            this.timerToolStripMenuItem.ForeColor = System.Drawing.Color.Red;
            this.timerToolStripMenuItem.Name = "timerToolStripMenuItem";
            this.timerToolStripMenuItem.Size = new System.Drawing.Size(61, 26);
            this.timerToolStripMenuItem.Text = "Timer";
            // 
            // Game
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(8F, 16F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink;
            this.ClientSize = new System.Drawing.Size(300, 248);
            this.Controls.Add(this.menuStrip1);
            this.MainMenuStrip = this.menuStrip1;
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.Name = "Game";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Memorije";
            this.menuStrip1.ResumeLayout(false);
            this.menuStrip1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer tmrTimeElapsed;
        private System.Windows.Forms.Timer tmrCheckWinCondition;
        private System.Windows.Forms.MenuStrip menuStrip1;
        private System.Windows.Forms.ToolStripMenuItem administrationToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem konfiguracijaTableToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem sacuvajToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem ucitajToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem restartujToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem otvoriSvaPoljaToolStripMenuItem;
        private System.Windows.Forms.ToolStripMenuItem timerToolStripMenuItem;
    }
}

