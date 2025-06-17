using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ2
{
    public abstract class Stavka : IComparable<Stavka>
    {
        protected string naziv;
        protected DateTime istekRoka;
        protected bool veganska;

        public bool Veganska { get { return veganska; } }

        public Stavka() { }

        public Stavka(string naziv, DateTime istekRoka, bool veganska)
        {
            this.naziv = naziv;
            this.istekRoka = istekRoka;
            this.veganska = veganska;
        }

        public abstract double Cena { get;}

        public virtual void Ispisi(BinaryWriter bw)
        {
            bw.Write(naziv);
            bw.Write(istekRoka.ToString());
            bw.Write(veganska);
        }

        public virtual void Citaj(BinaryReader br)
        {
            naziv = br.ReadString();
            string date = br.ReadString();
            istekRoka = DateTime.Parse(date);
            veganska = br.ReadBoolean();
        }

        public int CompareTo(Stavka? other)
        {
            if (this.Cena > other.Cena)
                return 1;
            else if (this.Cena == other.Cena) return 0;
            else
                return -1;
        }

        public bool Istekao
        { 
            get
            {
                return ((istekRoka - DateTime.Now).TotalDays) < 0;
            }
        }
    }
}
