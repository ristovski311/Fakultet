using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ2
{
    abstract class Biljka : IComparable<Biljka>
    {
        protected String naziv;
        protected bool jedogodisnja;
        protected double potrebnaVodaDnevno;

        public bool Visegodisnja { get { return !jedogodisnja; } }

        public Biljka()
        {
            naziv = null;
            jedogodisnja = false;
            potrebnaVodaDnevno = 0.0;
        }

        public Biljka(string naziv, bool jedogodisnja, double potrebnaVodaDnevno)
        {
            this.naziv = naziv;
            this.jedogodisnja = jedogodisnja;
            this.potrebnaVodaDnevno = potrebnaVodaDnevno;
        }

        public abstract double cenaOdrzavanja();

        public virtual void Ispisi(BinaryWriter bw)
        {
            bw.Write(naziv);
            bw.Write(jedogodisnja);
            bw.Write(potrebnaVodaDnevno);
        }

        public virtual void Citaj(BinaryReader br)
        {
            naziv = br.ReadString();
            jedogodisnja = br.ReadBoolean();
            potrebnaVodaDnevno = br.ReadDouble();
        }

        public int CompareTo(Biljka? other)
        {
            if (other == null)
                return 0;
            if (this.potrebnaVodaDnevno > other.potrebnaVodaDnevno)
                return 1;
            else if(this.potrebnaVodaDnevno < other.potrebnaVodaDnevno)
                return -1;
            else return 0;
        }
    }
}
