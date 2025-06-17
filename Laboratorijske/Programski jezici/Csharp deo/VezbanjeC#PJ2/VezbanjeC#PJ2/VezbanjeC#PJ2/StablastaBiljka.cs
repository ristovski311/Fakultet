using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ2
{
    internal class StablastaBiljka : Biljka
    {
        DateTime datumSledecegPresadjivanja;

        public StablastaBiljka() : base() { }

        public StablastaBiljka(string naziv, bool jedogodisnja, double potrebnaVodaDnevno,DateTime datumSledecegPresadjivanja) : base(naziv, jedogodisnja, potrebnaVodaDnevno)
        {
            this.datumSledecegPresadjivanja = datumSledecegPresadjivanja;
        }

        public override double cenaOdrzavanja()
        {
            double res = potrebnaVodaDnevno * 100;
            if(datumSledecegPresadjivanja == DateTime.Now)
            {
                res += 2000;
            }
            return res;
        }

        public override void Ispisi(BinaryWriter bw)
        {
            bw.Write("Stablasta");
            base.Ispisi(bw);
            bw.Write(datumSledecegPresadjivanja.ToString());
            bw.Write(cenaOdrzavanja());
        }

        public override void Citaj(BinaryReader br)
        {
            base.Citaj(br);
            string datum = br.ReadString();
            datumSledecegPresadjivanja = DateTime.Parse(datum);
            double cena = br.ReadDouble();
        }
    }
}
