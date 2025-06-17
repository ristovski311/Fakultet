using Funkcije;
using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using Podaci;
using System.Xml;

namespace VozaciLab
{
    public partial class Form1 : Form
    {

        public ListaVozaca Lv { get; set; }
        public Form1()
        {
            InitializeComponent();
            
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            lblVreme.Text = string.Empty;
            tmrVreme.Start();
            UpdateList();
            cmbSort.SelectedIndex = 0;
        }

        private void tmrVreme_Tick(object sender, EventArgs e)
        {
            DateTime now = DateTime.Now;
            lblVreme.Text = now.ShowCurrentTime();
        }

        private void UpdateList()
        {
            if(ListaVozaca.Instanca.ListaVozacaValue != null)
            {
                dgvListaVozaca.DataSource = ListaVozaca.Instanca.ListaVozacaValue.ToList();
            }
            if (dgvListaVozaca.RowCount > 0)
            {
                btnObrisi.Enabled = true;
                btnIzmeni.Enabled = true;
            }
            else
            {
                btnObrisi.Enabled = false;
                btnIzmeni.Enabled = false;
            }
        }

        private void btnDodaj_Click(object sender, EventArgs e)
        {
            var dodajVozaca = new VozaciLab.Vozac();
            DialogResult res = dodajVozaca.ShowDialog();
            if (res == DialogResult.OK)
            {
                UpdateList();
                MessageBox.Show("Dodat novi vozac.", "Obavestenje o dodavanju", MessageBoxButtons.OK, MessageBoxIcon.Information);
            }
        }

        private void btnIzmeni_Click(object sender, EventArgs e)
        {
            if (dgvListaVozaca.SelectedRows.Count == 0)
                return;

            Podaci.Vozac temp = dgvListaVozaca.SelectedRows[0].DataBoundItem as Podaci.Vozac;


            var dodajVozaca = new VozaciLab.Vozac(temp);
            DialogResult res = dodajVozaca.ShowDialog();
            if (res == DialogResult.OK)
            {
                UpdateList();
                string msg = "Izmenjen vozac {0} {1}!";
                MessageBox.Show(String.Format(msg,temp.Ime, temp.Prezime), "Obavestenje o izmeni", MessageBoxButtons.OK, MessageBoxIcon.Information);
        
            }

        }

        private void btnObrisi_Click(object sender, EventArgs e)
        {
            Podaci.Vozac temp = dgvListaVozaca.SelectedRows[0].DataBoundItem as Podaci.Vozac;
            ListaVozaca.Instanca.ObrisiVozaca(temp);
            UpdateList();
            string msg = "Obrisan vozac {0} {1}!";
            MessageBox.Show(String.Format(msg,temp.Ime, temp.Prezime), "Obavestenje o brisanju", MessageBoxButtons.OK, MessageBoxIcon.Information);
        }

        public void SortirajPoImenu()
        {
            Podaci.Vozac temp = new Podaci.Vozac();
            for(int i = 0; i < ListaVozaca.Instanca.ListaVozacaValue.Count - 1; i++) 
            {
                for(int j = i+1; j < ListaVozaca.Instanca.ListaVozacaValue.Count; j++)
                {
                    if (String.Compare(ListaVozaca.Instanca.ListaVozacaValue[i].Ime, ListaVozaca.Instanca.ListaVozacaValue[j].Ime) > 0)
                    {
                        temp = ListaVozaca.Instanca.ListaVozacaValue[i];
                        ListaVozaca.Instanca.ListaVozacaValue[i] = ListaVozaca.Instanca.ListaVozacaValue[j];
                        ListaVozaca.Instanca.ListaVozacaValue[j] = temp;
                    }
                }
            }
        }

        public void SortirajPoPrezimenu()
        {
            Podaci.Vozac temp = new Podaci.Vozac();
            for (int i = 0; i < ListaVozaca.Instanca.ListaVozacaValue.Count - 1; i++)
            {
                for (int j = i + 1; j < ListaVozaca.Instanca.ListaVozacaValue.Count; j++)
                {
                    if (String.Compare(ListaVozaca.Instanca.ListaVozacaValue[i].Prezime, ListaVozaca.Instanca.ListaVozacaValue[j].Prezime) > 0)
                    {
                        temp = ListaVozaca.Instanca.ListaVozacaValue[i];
                        ListaVozaca.Instanca.ListaVozacaValue[i] = ListaVozaca.Instanca.ListaVozacaValue[j];
                        ListaVozaca.Instanca.ListaVozacaValue[j] = temp;
                    }
                }
            }
        }

        public void SortirajPoDozvoli()
        {
            Podaci.Vozac temp = new Podaci.Vozac();
            for (int i = 0; i < ListaVozaca.Instanca.ListaVozacaValue.Count - 1; i++)
            {
                for (int j = i + 1; j < ListaVozaca.Instanca.ListaVozacaValue.Count; j++)
                {
                    if (String.Compare(ListaVozaca.Instanca.ListaVozacaValue[i].BrojDozvole, ListaVozaca.Instanca.ListaVozacaValue[j].BrojDozvole) > 0)
                    {
                        temp = ListaVozaca.Instanca.ListaVozacaValue[i];
                        ListaVozaca.Instanca.ListaVozacaValue[i] = ListaVozaca.Instanca.ListaVozacaValue[j];
                        ListaVozaca.Instanca.ListaVozacaValue[j] = temp;
                    }
                }
            }
        }

        private void cmbSort_SelectedValueChanged(object sender, EventArgs e)
        {
            ListaVozaca.Instanca.ClearSort();
            if (cmbSort.SelectedItem == "Ime")
            {
                ListaVozaca.Instanca.SortingDel = new ListaVozaca.SortDel(this.SortirajPoImenu);
            }
            else if (cmbSort.SelectedItem == "Prezime")
            {
                ListaVozaca.Instanca.SortingDel = new ListaVozaca.SortDel(this.SortirajPoPrezimenu);
            }
            else if (cmbSort.SelectedItem == "Broj vozacke dozvole")
            {
                ListaVozaca.Instanca.SortingDel = new ListaVozaca.SortDel(this.SortirajPoDozvoli);

            }
            else
                MessageBox.Show("lose");
        }

        private void btnSort_Click(object sender, EventArgs e)
        {
            if (ListaVozaca.Instanca.ListaVozacaValue.Count > 0)
            {
                ListaVozaca.Instanca.Sort();
                UpdateList();
                MessageBox.Show("Sortirana lista vozaca!");
            }
            else 
                return;
        }

        private void Form1_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult dr = MessageBox.Show("Da li ste sigurni?", "Zatvaranje", MessageBoxButtons.OKCancel, MessageBoxIcon.Question);
            if (dr == DialogResult.Cancel)
            {
                e.Cancel = true;
            }
        }
    }
}
