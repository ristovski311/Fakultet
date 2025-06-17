using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Podaci
{
    [Serializable]
    public class PoljeZaSerijalizaciju
    {
        string picture;
        bool otvoreno;
        int posX;
        int posY;
        bool pogodjeno;

        public PoljeZaSerijalizaciju()
        {
            picture = null;
            otvoreno = false;
            pogodjeno = false;
            posX = 0;
            posY = 0;
        }
        public PoljeZaSerijalizaciju(Polje p)
        {
            picture = p.Picture;
            otvoreno = p.Otvoreno;
            posX = p.PosX;
            posY = p.PosY;
            pogodjeno = p.Pogodjeno;
        }

        public void SpremiZaSerijalizaciju(Polje p)
        {
            picture = p.Picture;
            otvoreno = p.Otvoreno;
            posX = p.PosX;
            posY = p.PosY;
            pogodjeno = p.Pogodjeno;

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

        [XmlElementAttribute("PosX")]

        public int PosX
        {
            get { return this.posX; }
            set { this.posX = value; }
        }

        [XmlElementAttribute("PosY")]

        public int PosY
        {
            get { return this.posY; }
            set { this.posY = value; }
        }

        [XmlElementAttribute("Pogodjeno")]

        public bool Pogodjeno
        {
            get { return pogodjeno; }
            set { pogodjeno = value; }
        }


    }
}
