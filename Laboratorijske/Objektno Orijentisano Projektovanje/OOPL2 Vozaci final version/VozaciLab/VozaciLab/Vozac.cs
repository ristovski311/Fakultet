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
using System.Windows.Forms.VisualStyles;
using static System.Windows.Forms.VisualStyles.VisualStyleElement;

namespace VozaciLab
{
    public partial class Vozac : Form
    {
        static Podaci.Vozac v;
        bool zamena = false;

        public static Podaci.Vozac instancaVozaca
        {
            get { return Vozac.v; }
            set { Vozac.v = value; }
        }

        public Vozac()
        {
            InitializeComponent();
            Vozac.instancaVozaca = new Podaci.Vozac();
            UpdateKategorijaList();
            UpdateZabranaList();
        }

        public Vozac(Podaci.Vozac v)
        {
            instancaVozaca = new Podaci.Vozac(v);
            InitializeComponent();
            UcitajKomponente();
            zamena = true;
            btnProsledi.Text = "Zameni";
            txbBrojDozvole.Enabled = false;
            UpdateKategorijaList();
            UpdateZabranaList();

        }

        public void UcitajKomponente()
        {
            txbIme.Text = v.Ime;
            txbPrezime.Text = v.Prezime;
            dtpRodjenje.Value = v.DatRodjenja;
            dtpVozackaOd.Value = v.DozvolaOd;
            dtpVozackaDo.Value = v.DozvolaDo;
            txbBrojDozvole.Text = v.BrojDozvole;
            txbMesto.Text = v.MestoIzdavanja;
            switch (v.Pol)
            {
                case 'M':
                    cmbPol.SelectedIndex = 0;
                    break;
                case 'Z':
                    cmbPol.SelectedIndex = 1;
                    break;
            }
            pictureBox1.Image = Image.FromFile(v.Slika);
        }

        private void txbPrezime_TextChanged(object sender, EventArgs e)
        {

        }

        private void txbIme_TextChanged(object sender, EventArgs e)
        {
            
        }

        private void txbIme_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsLetter(e.KeyChar) && !Char.IsControl(e.KeyChar))
            { 
                e.Handled = true;
            }
        }

        private void txbPrezime_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (!Char.IsLetter(e.KeyChar) && !Char.IsControl(e.KeyChar))
            {
                e.Handled = true;
            }
        }

        private void btnDodajSliku_Click(object sender, EventArgs e)
        {
            OpenFileDialog ofd = new OpenFileDialog();
            ofd.Filter = "PNG|*.png|JPEG|*.jpeg";

            if (ofd.ShowDialog() == DialogResult.OK)
            {
                String fileName = ofd.FileName;
                v.Slika = fileName;
                Image img = Image.FromFile(fileName);
                pictureBox1.Image = img;   
            }
        }

        private void txbBrojDozvole_KeyPress(object sender, KeyPressEventArgs e)
        {
            if(!Char.IsDigit(e.KeyChar) && !Char.IsControl(e.KeyChar))
            {
                e.Handled = true;
            }
            if (Char.IsDigit(e.KeyChar) && txbBrojDozvole.Text.Length >= 10)
            {
                e.Handled = true;
            }
        }

        private void txbMesto_KeyPress(object sender, KeyPressEventArgs e)
        {
            if (Char.IsDigit(e.KeyChar))
            {
                e.Handled = true;
            }
        }

        public bool Validacija()
        {
            if (txbIme.Text.Length == 0)
            {
                MessageBox.Show("Ime ne sme biti prazno!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false; 
            }
            if(txbPrezime.Text.Length == 0)
            {
                MessageBox.Show("Prezime ne sme biti prazno!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            if (txbMesto.Text.Length == 0)
            {
                MessageBox.Show("Mesto ne sme biti prazno!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            if (txbBrojDozvole.Text.Length != 10)
            {
                MessageBox.Show("Broj dozvole ne sme biti prazan!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            if(cmbPol.SelectedIndex <0)
            {
                MessageBox.Show("Izaberite pol!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            if(pictureBox1.Image == null)
            {
                MessageBox.Show("Izaberite sliku!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            if((dtpVozackaDo.Value - dtpVozackaOd.Value).TotalDays < 0)
            {
                MessageBox.Show("Istek vazenja vozacke ne sme biti pre pocetka vazenja vozacke!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            if(v.Kategorije == null || v.Kategorije.Count <= 0)
            {
                MessageBox.Show("Odaberite kategoriju(e) koju vozac poseduje!", "Greska!", MessageBoxButtons.OK, MessageBoxIcon.Error);
                return false;
            }
            return true;

        }

        private void btnProsledi_Click(object sender, EventArgs e)
        {
            if (!Validacija())
            {
                return;
            }
            v.Ime = txbIme.Text;
            v.Prezime = txbPrezime.Text;
            v.DatRodjenja = dtpRodjenje.Value;
            v.DozvolaOd = dtpVozackaOd.Value;
            v.DozvolaDo = dtpVozackaDo.Value;
            v.Pol = cmbPol.SelectedItem.ToString().ToCharArray()[0];
            v.BrojDozvole = txbBrojDozvole.Text;
            v.MestoIzdavanja = txbMesto.Text;
            if(!zamena)
            {
                ListaVozaca.Instanca.DodajVozaca(v);
            }
            else
            {
                ListaVozaca.Instanca.ZameniVozaca(v);
            }
            this.DialogResult = DialogResult.OK;
            this.Close();
        }

        private void txbIme_Leave(object sender, EventArgs e)
        {
            txbIme.Text = txbIme.Text.Capitalize();
        }

        private void txbPrezime_Leave(object sender, EventArgs e)
        {
            txbPrezime.Text = txbPrezime.Text.Capitalize();
        }

        private void txbMesto_Leave(object sender, EventArgs e)
        {
            txbMesto.Text = txbMesto.Text.Capitalize();
        }

        private void btnDodajKategoriju_Click(object sender, EventArgs e)
        {
            VozaciLab.Kategorija katfr = new VozaciLab.Kategorija();
            DialogResult dlr = katfr.ShowDialog();
            if (dlr == DialogResult.OK)
            {
                UpdateKategorijaList();
                MessageBox.Show("Dodata nova kategorija.", "Obavestenje o dodavanju", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }

        }

        public void UpdateKategorijaList()
        {
            if (v.Kategorije != null)
            {
                dgvKategorije.DataSource = v.Kategorije.ToList();
            }
            if (dgvKategorije.RowCount > 0)
            {
                btnObrisiKategoriju.Enabled = true;
            }
            else
            {
                btnObrisiKategoriju.Enabled = false;
            }
        }

        public void UpdateZabranaList()
        {
            if (v.Zabrane != null)
            {
                dgvZabrane.DataSource = v.Zabrane.ToList();
            }
            if (dgvZabrane.RowCount > 0)
            {
                btnObrisiZabranu.Enabled = true;
            }
            else
            {
                btnObrisiZabranu.Enabled = false;
            }
        }

        private void btnDodajZabranu_Click(object sender, EventArgs e)
        {
            VozaciLab.Zabrana zabfr = new VozaciLab.Zabrana();
            DialogResult dlr = zabfr.ShowDialog();
            UpdateZabranaList();
            if (dlr == DialogResult.OK)
            {
                MessageBox.Show("Dodata nova zabrana.", "Obavestenje o dodavanju", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void btnObrisiKategoriju_Click(object sender, EventArgs e)
        {
            if(dgvKategorije.SelectedRows.Count > 0)
            {
                Podaci.Kategorija temp = dgvKategorije.SelectedRows[0].DataBoundItem as Podaci.Kategorija;
                Vozac.instancaVozaca.ObrisiKategoriju(temp);
                UpdateKategorijaList();
                UpdateZabranaList();
                MessageBox.Show($"Obrisana kategorija: {temp.ImeKategorije}", "Obavestenje", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
            
        }

        private void btnObrisiZabranu_Click(object sender, EventArgs e)
        {
            if(dgvZabrane.SelectedRows.Count > 0)
            {
                Podaci.Zabrana temp = dgvZabrane.SelectedRows[0].DataBoundItem as Podaci.Zabrana;
                Vozac.instancaVozaca.ObrisiZabranu(temp);
                UpdateZabranaList();
                MessageBox.Show($"Obrisana kategorija: {temp.Kategorija}", "Obavestenje", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void btnZatvori_Click(object sender, EventArgs e)
        {
            this.Close();
        }

        private void Vozac_FormClosing(object sender, FormClosingEventArgs e)
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

        private void Vozac_Load(object sender, EventArgs e)
        {

        }
    }
}
