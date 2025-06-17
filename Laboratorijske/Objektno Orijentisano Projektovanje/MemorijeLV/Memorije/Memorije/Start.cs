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
        public TablaZaIgru tabla = new TablaZaIgru(6,5,10,14);
        public Start()
        {
            InitializeComponent();
            int strip = 47;
            int paddingx = (tabla.M - 1) * 4;
            int paddingy = (tabla.N - 1) * 4;
            this.Width = tabla.M * tabla.Polja[0][0].Width + paddingx;
            this.Height = tabla.N * tabla.Polja[0][0].Height + strip;
            this.MaximumSize = new System.Drawing.Size(this.Width, this.Height);
            this.MinimumSize = new System.Drawing.Size(this.Width, this.Height);
            for (int i = 0; i < tabla.N; i++)
            {
                for(int j = 0; j < tabla.M; j++)
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
    }
}
