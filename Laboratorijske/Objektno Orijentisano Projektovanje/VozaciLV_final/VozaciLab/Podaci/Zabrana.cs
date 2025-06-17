using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Podaci
{
    public class Zabrana
    {
        string kategorija;
        DateTime zabranaOd;
        DateTime zabranaDo;

        public string Kategorija { get; set; }
        public DateTime ZabranaOd { get; set; }
        public DateTime ZabranaDo { get; set; }

        public Zabrana()
        {

        }

        public Zabrana(string kategorija, DateTime zabranaOd, DateTime zabranaDo)
        {
            Kategorija = kategorija;
            ZabranaOd = zabranaOd;
            ZabranaDo = zabranaDo;
        }


    }
}
