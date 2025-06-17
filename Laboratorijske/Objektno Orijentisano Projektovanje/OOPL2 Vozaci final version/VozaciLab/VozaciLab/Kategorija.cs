using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace VozaciLab
{
    public partial class Kategorija : Form
    {
        public Kategorija()
        {
            InitializeComponent();
        }

        private void Kategorija_Load(object sender, EventArgs e)
        {

        }

        public bool Validacija()
        {
            if(cmbKategorija.SelectedIndex < 0) 
            {
                MessageBox.Show("Izaberite kategoriju!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            if ((dtpDo.Value - dtpOd.Value).TotalDays < 0)
            {
                MessageBox.Show("Istek kategorije vozacke ne sme biti pre pocetka vazenja kategorije vozacke!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            return true;
        }

        private void btnProsledi_Click(object sender, EventArgs e)
        {
            if(Validacija())
            {
                string kateg = cmbKategorija.SelectedItem.ToString();
                DateTime odDat = dtpOd.Value;
                DateTime doDat = dtpDo.Value;
                Podaci.Kategorija kat = new Podaci.Kategorija(kateg, odDat, doDat);

                VozaciLab.Vozac.instancaVozaca.DodajKategoriju(kat);
                DialogResult = DialogResult.OK;
            }
            else
                return;
        }

        private void Kategorija_FormClosing(object sender, FormClosingEventArgs e)
        {
            if (!(this.DialogResult == DialogResult.OK))
            {
                DialogResult dr = MessageBox.Show("Da li ste sigurni?", "Zatvaranje", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
                if (dr == DialogResult.Cancel)
                {
                    e.Cancel = true;
                }
            }
        }

        private void btnZatvori_Click(object sender, EventArgs e)
        {
            this.Close();
        }
    }
}
