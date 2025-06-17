using System;
using System.Collections.Generic;
using System.ComponentModel;
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

        [DisplayName("Ime kategorije")]
        public string ImeKategorije { get; set; }
        [DisplayName("Vazi od")]
        public DateTime VaziOd { get; set; }
        [DisplayName("Vazi do")]
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
