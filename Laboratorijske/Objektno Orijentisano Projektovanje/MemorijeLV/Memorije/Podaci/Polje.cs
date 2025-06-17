using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Podaci
{
    public class Polje : Button
    {
        string picture;
        bool otvoreno;
        static int Velicina = 90; 

        public Polje()
        {
            this.picture = null;
            this.Click += new EventHandler(KlikNaPolje);
            this.Height = Velicina;
            this.Width = Velicina;
        }

        public Polje(string image)
        {
            this.picture = image;
            this.otvoreno = false;
            this.Click += new EventHandler(KlikNaPolje);
            this.Height = Velicina;
            this.Width = Velicina;

        }

        public Polje(string image, bool otvoreno)
        {
            this.picture = image;
            this.otvoreno = otvoreno;
            this.Click += new EventHandler(KlikNaPolje);
            this.Height = Velicina;
            this.Width = Velicina;

        }

        public void PostaviPoziciju(int x, int y)
        {
            this.Location = new Point(x, y);
        }

        public void OsveziPolje()
        {
            if (otvoreno)
            {
                if (picture != null)
                {
                    Image btnImg = Image.FromFile(picture);
                    this.Image = btnImg;
                }
                else
                {
                    this.Enabled = false;
                }
            }
            else
            {
                this.Image = null;
            }
        }

        public bool Otvoreno
        {
            get { return this.otvoreno; }
            set { this.otvoreno = value; }
        }

        public string Picture
        {
            get { return this.picture; }
            set { this.picture = value; }
        }

        public void KlikNaPolje(object sender, EventArgs e)
        {
            Otvoreno = true;
            OsveziPolje();
        }

    }
}
