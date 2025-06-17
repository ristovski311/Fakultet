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
        public static int[] podesavanjaIgre = new int[4];
        public Game()
        {
            InitializeComponent();
            ModifyGame();
        }

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
                tabla.OpenAllButtons();
                tmrTimeElapsed.Stop();
                tmrCheckWinCondition.Stop();
                MessageBox.Show("CONGRATS! YOU WON!\nTime needed: " + Functions.ConvertToTimerFormat(tabla.TimeElapsed), "YOU WON!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        public void SetSize()
        {
            int paddingx = 18;
            int paddingy = 45;
            this.Size = new Size(tabla.M * tabla.Polja[0][0].Width + paddingx, tabla.N * tabla.Polja[0][0].Height + paddingy + menuStrip1.Height);
        }

        public void SetTimerLabel()
        {
            timerToolStripMenuItem.Text = Functions.ConvertToTimerFormat(tabla.TimeElapsed);
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

        private void Start_Load(object sender, EventArgs e)
        {

        }

        private void btnZapocniIgru_Click(object sender, EventArgs e)
        {

        }

        private void tmrTimeElapsed_Tick(object sender, EventArgs e)
        {
            tabla.TimeElapsed++;
            timerToolStripMenuItem.Text = Functions.ConvertToTimerFormat(tabla.TimeElapsed);
        }

        private void tmrCheckWinCondition_Tick(object sender, EventArgs e)
        {
            CheckWinCondition();
        }

        private void btnRestart_Click(object sender, EventArgs e)
        {
            Application.Restart();
        }

        private void btnOpenAll_Click(object sender, EventArgs e)
        {
            tabla.OpenAllButtons();
            tmrCheckWinCondition.Stop();
            tmrTimeElapsed.Stop();
        }

        private void btnXML_Click(object sender, EventArgs e)
        {
            tabla.SpremiZaSerijalizaciju();

            SaveFileDialog sfd = new SaveFileDialog();
            sfd.Filter = "xml files (*.xml)|*.xml";

            if (sfd.ShowDialog() == DialogResult.OK)
            {
                tabla.Serialize(sfd.FileName);
            }
        }

        private void btnLoadXML_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "xml files (*.xml)|*.xml";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                this.RemoveButtons();
                tabla = tabla.DeserializeFromXml(ofd.FileName);
                tabla.Deserijalizuj();
                this.SetSize();
                SetControls();
                this.AddButtons();
                tabla.OsveziSvaPolja();
            }
        }

        private void konfiguracijaTableToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tmrTimeElapsed.Stop();
            GameModifier gm = new GameModifier();
            if(gm.ShowDialog() == DialogResult.OK)
            {
                MessageBox.Show("Promenjena konfiguracija table za igru.\nPri sledecem pokratanju konfiguracija ce biti primenjena.", "Promenjena konfiguracija.", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            tmrTimeElapsed.Start();
        }

        private void otvoriSvaPoljaToolStripMenuItem_Click(object sender, EventArgs e)
        {
            tabla.OpenAllButtons();
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
