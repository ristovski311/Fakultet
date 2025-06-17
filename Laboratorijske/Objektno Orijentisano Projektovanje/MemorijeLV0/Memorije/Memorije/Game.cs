using Funkcije;
using Podaci;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Memorije
{
    public partial class Game : Form
    {
        public TablaZaIgru tabla;
        public Game()
        {
            InitializeComponent();
            ModifyGame();
        }

        //POSTAVKA FORME

        public void ModifyGame()
        {
            DimenzijeTable dt = new DimenzijeTable();
            dt = dt.Deserialize("C:\\Users\\risto\\source\\repos\\Memorije\\Memorije\\bin\\Debug\\LastConfiguration.xml");
            tabla = new TablaZaIgru(dt);
            SetSize();
            AddButtons();
            SetControls();
            SaveCurrentSettings();
        }

        public void SetControls()
        {
            SetTimerLabel();
            tmrTimeElapsed.Start();
            tmrCheckWinCondition.Start();
        }

        public void SaveCurrentSettings()
        {
            tabla.Dimenzija.Serialize("LastConfiguration.xml");
        }

        public void CheckWinCondition()
        {
            if (tabla.PronadjeniParovi == tabla.PotrebnoPronaciParova)
            {
                tabla.OtvoriSvaPolja();
                tmrTimeElapsed.Stop();
                tmrCheckWinCondition.Stop();
                MessageBox.Show("CONGRATS! YOU WON!\nTime needed: " + Functions.ConvertToTimerFormat(tabla.TimeElapsed), "YOU WON!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        public void SetSize()
        {
            int paddingx = 19;
            int paddingy = 40;
            this.MaximumSize = new Size(tabla.M * tabla.Polja[0][0].Width + paddingx, tabla.N * tabla.Polja[0][0].Height + paddingy + menuStrip1.Height);
            this.MinimumSize = new Size(tabla.M * tabla.Polja[0][0].Width + paddingx, tabla.N * tabla.Polja[0][0].Height + paddingy + menuStrip1.Height);
            this.Size = this.MaximumSize;
        }

        public void AddButtons()
        {
            for (int i = 0; i < tabla.N; i++)
            {
                for (int j = 0; j < tabla.M; j++)
                {
                    this.Controls.Add(tabla.Polja[i][j]);
                }
            }
        }

        public void RemoveButtons()
        {
            for (int i = 0; i < tabla.N; i++)
            {
                for (int j = 0; j < tabla.M; j++)
                {
                    this.Controls.Remove(tabla.Polja[i][j]);
                }
            }
        }


        //TIMER PODESAVANJA

        private void tmrTimeElapsed_Tick(object sender, EventArgs e)
        {
            tabla.TimeElapsed++;
            timerToolStripMenuItem.Text = Functions.ConvertToTimerFormat(tabla.TimeElapsed);
        }

        private void tmrCheckWinCondition_Tick(object sender, EventArgs e)
        {
            CheckWinCondition();
        }

        public void SetTimerLabel()
        {
            timerToolStripMenuItem.Text = Functions.ConvertToTimerFormat(tabla.TimeElapsed);
        }


        //PODESAVANJA U MENU STRIP-U

        private void konfiguracijaTableToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tmrTimeElapsed.Stop();
            GameModifier gm = new GameModifier();
            if (gm.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show("Promenjena konfiguracija table za igru.\nPri sledecem pokratanju konfiguracija ce biti primenjena.", "Promenjena konfiguracija.", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            tmrTimeElapsed.Start();
        }

        private void otvoriSvaPoljaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tabla.OtvoriSvaPolja();
            tmrCheckWinCondition.Stop();
            tmrTimeElapsed.Stop();
        }

        private void ucitajToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tmrTimeElapsed.Stop();

            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "xml files (*.xml)|*.xml";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                this.RemoveButtons();
                tabla = tabla.DeserializeFromXml(ofd.FileName);
                tabla.Deserijalizuj();
                tabla.PromeniVelicinuPolja();
                tabla.PostaviVelicinuPoljima();
                this.SetSize();
                SetControls();
                this.AddButtons();
                tabla.OsveziSvaPolja();
            }
            tmrTimeElapsed.Start();

        }

        private void sacuvajToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tmrTimeElapsed.Stop();
            tabla.SpremiZaSerijalizaciju();

            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = "xml files (*.xml)|*.xml";

            if (sfd.ShowDialog() == DialogResult.OK)
            {
                tabla.Serialize(sfd.FileName);
            }

            tmrTimeElapsed.Start();
        }

        private void restartujToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Restart();
        }

    }
}
