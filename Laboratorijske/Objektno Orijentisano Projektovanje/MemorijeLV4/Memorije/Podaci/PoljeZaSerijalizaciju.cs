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
        static int Velicina = 100;

        public PoljeZaSerijalizaciju()
        {
            picture = null;
            otvoreno = false;
        }
        public PoljeZaSerijalizaciju(Polje p)
        {
            picture = p.Picture;
            otvoreno = p.Otvoreno;
        }

        public void SpremiZaSerijalizaciju(Polje p)
        {
            picture = p.Picture;
            otvoreno = p.Otvoreno;
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
    }
}
