using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ
{
    internal class Serija : Emisija
    {
        int brojEpizoda;
        double cenaSvihEpizoda;
        bool inostrana;

        public Serija() : base()
        { 
            brojEpizoda = 0;
            cenaSvihEpizoda = 0;
            inostrana = false;
        }

        public Serija(string naziv, double gledanost, Dani danPrikazivanja,int brojEpizoda, double cenaSvihEpizoda, bool inostrana) : base(naziv, gledanost, danPrikazivanja)
        {
            this.brojEpizoda = brojEpizoda;
            this.cenaSvihEpizoda = cenaSvihEpizoda;
            this.inostrana = inostrana;
        }

        public override double cenaEmisije()
        {
            double res = cenaSvihEpizoda / brojEpizoda;
            if (inostrana)
                res *= 1.25;
            return res;
        }

        public override void Ispisi(StreamWriter sw)
        {
            base.Ispisi(sw);
            sw.WriteLine(brojEpizoda);
            sw.WriteLine(cenaSvihEpizoda);
            if(inostrana)
                sw.WriteLine("INOSTRANA");
            else
                sw.WriteLine("DOMACA");
            sw.WriteLine(cenaEmisije().ToString());
        }
    }
}
