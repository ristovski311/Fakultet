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
    public class Polje : Button
    {
        string picture;
        bool otvoreno;
        int posX;
        int posY;
        bool pogodjeno;
        public static int Velicina = 100;

        #region Constructors
        public Polje()
        {
            this.picture = null;
            this.Height = Velicina;
            this.Width = Velicina;
            this.Otvoreno = false;
            pogodjeno = false;
            posX = 0;
            posY = 0;
        }

        public Polje(string image)
        {
            this.picture = image;
            this.otvoreno = false;
            this.Height = Velicina;
            this.Width = Velicina;
            pogodjeno = false;
            posX = 0;
            posY = 0;
        }

        public Polje(string image, bool otvoreno)
        {
            this.picture = image;
            this.otvoreno = otvoreno;
            this.Height = Velicina;
            this.Width = Velicina;
            pogodjeno = false;
            posX = 0;
            posY = 0;
        }

        public Polje(PoljeZaSerijalizaciju pzs)
        {
            this.picture = pzs.Picture;
            this.Height = Velicina;
            this.Width = Velicina;
            this.Otvoreno = pzs.Otvoreno;
            this.pogodjeno = pzs.Pogodjeno;
            this.posX = pzs.PosX;
            this.posY = pzs.PosY;
        }

        #endregion Constructors

        #region Methods

        public void PostaviPoziciju()
        {
            this.Location = new Point(posX, posY);
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
                    this.pogodjeno = true;
                }
            }
            else
            {
                this.Image = null;
            }
        }

        public void OsveziPoljaPosleDeserijalizacije()
        {
            if (pogodjeno)
            {
                if (picture != null)
                {
                    Image btnImg = Image.FromFile(picture);
                    this.Image = btnImg;
                    this.Enabled = false;

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

        #endregion Methods

        #region Attributes

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

        public bool Pogodjeno
        {
            get { return pogodjeno; }
            set { pogodjeno = value; }
        }

        public int PosX
        {
            get { return posX; }
            set { posX = value; }
        }

        public int PosY
        {
            get { return posY; }
            set { posY = value; }
        }

        public void OtvoriPolje()
        {
            Otvoreno = true;
            OsveziPolje();
        }
        #endregion Attributes
    }
}
