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
    public partial class Zabrana : Form
    {
        public Zabrana()
        {
            InitializeComponent();
            UcitajComboBox();
        }

        public void UcitajComboBox()
        {
            cmbKategorija.Items.Clear();
            foreach(Podaci.Kategorija k in Vozac.instancaVozaca.Kategorije)
            {
                cmbKategorija.Items.Add(k.ImeKategorije);
            }
        }

        private void Zabrana_Load(object sender, EventArgs e)
        {

        }

        private void cmbKategorija_Click(object sender, EventArgs e)
        {
            UcitajComboBox();
        }

        public bool Validacija()
        {
            if(cmbKategorija.SelectedIndex == -1) 
            {
                MessageBox.Show("Izaberite kategoriju!", "Greska", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false; 
            }
            if ((dtpDo.Value - dtpOd.Value).TotalDays < 0)
            {
                MessageBox.Show("Istek zabrane vozacke ne sme biti pre pocetka vazenja zabrane vozacke!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            return true;
        }


        private void btnProsledi_Click(object sender, EventArgs e)
        {
            if(Validacija())
            {
                DateTime dateDo = dtpDo.Value;
                DateTime dateOd = dtpOd.Value;
                string zabr = cmbKategorija.SelectedItem.ToString();
                Podaci.Zabrana temp = new Podaci.Zabrana(zabr, dateOd, dateDo);
                Vozac.instancaVozaca.DodajZabranu(temp);
                DialogResult = DialogResult.OK;
            }
            return;
        }

        private void btnZatvori_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Zabrana_FormClosing(object sender, FormClosingEventArgs e)
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
    }
}
