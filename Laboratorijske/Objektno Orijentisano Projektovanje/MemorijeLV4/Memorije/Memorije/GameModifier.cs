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
    public partial class GameModifier : Form
    {
        DimenzijeTable konfiguracija = new DimenzijeTable();
        
        public GameModifier()
        {
            InitializeComponent();
            Konfigurisi();
        }
        public void Konfigurisi()
        {
            konfiguracija = konfiguracija.Deserialize("C:\\Users\\risto\\source\\repos\\Memorije\\Memorije\\bin\\Debug\\LastConfiguration.xml");
            nudRows.Value = konfiguracija.Vrste;
            nudColumns.Value = konfiguracija.Kolone;
            nudPairs.Maximum = (nudRows.Value * nudColumns.Value) / 2;
            nudPairs.Value = konfiguracija.Parovi;
            numericUpDown4.Value = konfiguracija.RazliciteSlike;
            
        }
        private void nudRows_ValueChanged(object sender, EventArgs e)
        {
            nudPairs.Maximum = (nudRows.Value * nudColumns.Value) / 2;
            konfiguracija.Vrste = (int)nudRows.Value;
        }

        private void nudColumns_ValueChanged(object sender, EventArgs e)
        {
            nudPairs.Maximum = (nudRows.Value * nudColumns.Value) / 2;
            konfiguracija.Kolone = (int)nudColumns.Value;

        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            konfiguracija.Serialize("C:\\Users\\risto\\source\\repos\\Memorije\\Memorije\\bin\\Debug\\LastConfiguration.xml");
            this.Close();
        }

        private void nudPairs_ValueChanged(object sender, EventArgs e)
        {
            konfiguracija.Parovi = (int)nudPairs.Value;

        }

        private void numericUpDown4_ValueChanged(object sender, EventArgs e)
        {
            konfiguracija.RazliciteSlike = (int)numericUpDown4.Value;
        }

        private void GameModifier_Load(object sender, EventArgs e)
        {

        }
    }
}
