using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ
{
    internal class StudijskaEmisija : Emisija
    {
        double plataVoditelja;
        int brojGostiju;
        double honorarPoGostu;

        public StudijskaEmisija() : base()
        {
            plataVoditelja = 0;
            brojGostiju = 0;
            honorarPoGostu = 0;
        }

        public StudijskaEmisija(string naziv, double gledanost, Dani danPrikazivanja, double plataVoditelja, int brojGostiju, double honorarPoGostu) : base(naziv,gledanost,danPrikazivanja)
        {
            this.plataVoditelja = plataVoditelja;
            this.brojGostiju = brojGostiju;
            this.honorarPoGostu = honorarPoGostu;
        }

        public override double cenaEmisije()
        {
            double res = plataVoditelja + brojGostiju * honorarPoGostu;
            if(danPrikazivanja == Dani.Saturday || danPrikazivanja == Dani.Sunday)
            {
                res *= 1.2;
            }
            return res;
        }

        public override void Ispisi(StreamWriter sw)
        {
            base.Ispisi(sw);
            sw.WriteLine(plataVoditelja);
            sw.WriteLine(brojGostiju);
            sw.WriteLine(honorarPoGostu);
            sw.WriteLine(cenaEmisije().ToString());

        }
    }
}
