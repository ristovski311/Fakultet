using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace Podaci
{
    [Serializable]
    public class Polje : Button
    {
        string picture;
        bool otvoreno;
        static int Velicina = 100;

        public Polje()
        {
            this.picture = null;
            this.Height = Velicina;
            this.Width = Velicina;
            this.AutoSize = true;
        }

        public Polje(string image)
        {
            this.picture = image;
            this.otvoreno = false;
            this.Height = Velicina;
            this.Width = Velicina;

        }

        public Polje(string image, bool otvoreno)
        {
            this.picture = image;
            this.otvoreno = otvoreno;
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

        [XmlElementAttribute("Otvoreno")]
        public bool Otvoreno
        {
            get { return this.otvoreno; }
            set { this.otvoreno = value; }
        }

        [XmlElementAttribute("Picture")]
        public string Picture
        {
            get { return this.picture; }
            set { this.picture = value; }
        }

        public void OtvoriPolje()
        {
            Otvoreno = true;
            OsveziPolje();
        }

    }
}
