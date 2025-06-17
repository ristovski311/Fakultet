using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Podaci
{
    public class Kategorija
    {
        string imeKategorije;
        DateTime vaziOd;
        DateTime vaziDo;

        public string ImeKategorije { get; set; }
        public DateTime VaziOd { get; set; }
        public DateTime VaziDo { get; set; }

        public Kategorija() { }

        public Kategorija(string imeKategorije, DateTime vaziOd, DateTime vaziDo)
        {
            ImeKategorije = imeKategorije;
            VaziOd = vaziOd;
            VaziDo = vaziDo;
        }
    }
}
