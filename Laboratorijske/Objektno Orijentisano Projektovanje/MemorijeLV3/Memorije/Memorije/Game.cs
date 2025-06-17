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
        public static int secondsElapsed = 0;
        public TablaZaIgru tabla;
        public static int[] podesavanjaIgre = new int[4];
        public Game()
        {
            InitializeComponent();
            ModifyGame();
        }



        public void ModifyGame()
        {
            GameModifier gm = new GameModifier();
            if (gm.ShowDialog() == DialogResult.OK)
            {
                tabla = new TablaZaIgru(podesavanjaIgre[0], podesavanjaIgre[1], podesavanjaIgre[2], podesavanjaIgre[3]);
                SetSize();
                AddButtons();
                SetWinLbl();
                SetTimerLabel();
                tmrTimeElapsed.Start();
                tmrCheckWinCondition.Start();
                SetRestartButton();
                SetRevealButton();
                SetSaveButton();
                SetLoadButton();
            }
        }

        public void SetRestartButton()
        {
            btnRestart.Location = new Point(lblTimer.Location.X + lblTimer.Width + 20, lblTimer.Location.Y);
        }

        public void SetRevealButton()
        {
            btnOpenAll.Location = new Point(btnRestart.Location.X + btnRestart.Width + 20 , btnRestart.Location.Y);
        }

        public void SetSaveButton()
        {
            btnXML.Location = new Point(lblTimer.Location.X + lblTimer.Width + 20, lblTimer.Location.Y + btnRestart.Height + 10);
        }

        public void SetLoadButton()
        {
            btnLoadXML.Location = new Point(btnRestart.Location.X + btnRestart.Width + 20, lblTimer.Location.Y + btnRestart.Height + 10);

        }

        public void CheckWinCondition()
        {
            if (tabla.PronadjeniParovi == tabla.Parovi)
            {
                tabla.OpenAllButtons();
                lblWin.Visible = true;
                tmrTimeElapsed.Stop();
                tmrCheckWinCondition.Stop();
                MessageBox.Show("CONGRATS! YOU WON!\nTime needed: " + Functions.ConvertToTimerFormat(secondsElapsed), "YOU WON!", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        public void SetWinLbl()
        {
            lblWin.Location = new Point(tabla.Polja[0][0].Width * 2, tabla.N * tabla.Polja[0][0].Height);
            lblWin.Visible = false;
        }

        public void SetSize()
        {
            int paddingx = 18;
            int paddingy = 45;
            this.Width = tabla.M * tabla.Polja[0][0].Width + paddingx;
            this.Height = tabla.N * tabla.Polja[0][0].Height + paddingy + btnRestart.Height * 3;
            this.MaximumSize = new System.Drawing.Size(this.Width, this.Height);
            this.MinimumSize = new System.Drawing.Size(this.Width, this.Height);
        }

        public void SetTimerLabel()
        {
            lblTimer.Text = Functions.ConvertToTimerFormat(secondsElapsed);
            lblTimer.Location = new Point(0, tabla.N * tabla.Polja[0][0].Height);
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
            secondsElapsed++;
            lblTimer.Text = Functions.ConvertToTimerFormat(secondsElapsed);
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
                tabla = tabla.Deserialize(ofd.FileName);
                this.AddButtons();
            }
        }
    }
}
