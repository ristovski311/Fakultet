using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ
{
    abstract class Emisija : IComparable<Emisija>
    {
        protected string naziv;
        protected double gledanost;
        protected Dani danPrikazivanja;

        public Dani DanPrikazivanja
        {
            get { return danPrikazivanja; }
        }
        public double Gledanost
        {
            get { return gledanost; } 
            set 
            {
                if (value >= 0 || value <= 10)
                    gledanost = value;
                else
                    gledanost = 0;
            }
        }
        public Emisija()
        {
            naziv = "";
            Gledanost = 0;
            danPrikazivanja = Dani.Monday;
        }

        public Emisija(string naziv, double gledanost, Dani danPrikazivanja)
        {
            this.naziv = naziv;
            Gledanost = gledanost;
            this.danPrikazivanja = danPrikazivanja;
        }

        public abstract double cenaEmisije();

        public virtual void Ispisi(StreamWriter sw)
        {
            sw.WriteLine(naziv);
            sw.WriteLine(gledanost);
            sw.WriteLine(danPrikazivanja);
        }

        public int CompareTo(Emisija? other)
        {
            if(other == null) return 0;
            if (this.danPrikazivanja > other.danPrikazivanja)
                return 1;
            else
                return -1;
        }
    }
}
