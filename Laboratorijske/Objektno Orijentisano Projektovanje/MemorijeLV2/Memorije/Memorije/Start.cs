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
    public partial class Start : Form
    {
        public static int secondsElapsed = 0;
        public TablaZaIgru tabla = new TablaZaIgru(7,7,20,13);
        public Start()
        {
            InitializeComponent();
            SetSize();
            AddButtons();
            SetWinLbl();
            SetTimerLabel();
            tmrTimeElapsed.Start();
            tmrCheckWinCondition.Start();
        }

        public void CheckWinCondition()
        {
            if (tabla.PronadjeniParovi == tabla.Parovi)
            {
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
            this.Height = tabla.N * tabla.Polja[0][0].Height + paddingy + 30;
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
    }
}
