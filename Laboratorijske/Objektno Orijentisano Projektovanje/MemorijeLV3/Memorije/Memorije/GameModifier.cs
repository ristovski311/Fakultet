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
        public int[] podesavanjaIgre;
        public GameModifier()
        {
            InitializeComponent();
            InitializeArray();
            nudPairs.Maximum = (nudRows.Value * nudColumns.Value) /2;
        }
        public GameModifier(int[] array)
        {
            InitializeComponent();
            podesavanjaIgre = array;
            InitializeArray();
        }

        public void InitializeArray()
        {
            podesavanjaIgre = new int[4];
            podesavanjaIgre[0] = 5;
            podesavanjaIgre[1] = 6;
            podesavanjaIgre[2] = 7;
            podesavanjaIgre[3] = 5;
        }



        private void nudRows_ValueChanged(object sender, EventArgs e)
        {
            nudPairs.Maximum = (nudRows.Value * nudColumns.Value) / 2;
            podesavanjaIgre[0] = (int)nudRows.Value;
        }

        private void nudColumns_ValueChanged(object sender, EventArgs e)
        {
            nudPairs.Maximum = (nudRows.Value * nudColumns.Value) / 2;
            podesavanjaIgre[1] = (int)nudColumns.Value;

        }

        private void btnOK_Click(object sender, EventArgs e)
        {
            this.DialogResult = DialogResult.OK;
            Game.podesavanjaIgre = this.podesavanjaIgre;
            this.Close();
        }

        private void nudPairs_ValueChanged(object sender, EventArgs e)
        {
            podesavanjaIgre[2] = (int)nudPairs.Value;

        }

        private void numericUpDown4_ValueChanged(object sender, EventArgs e)
        {
            podesavanjaIgre[3] = (int)numericUpDown4.Value;

        }
    }
}
