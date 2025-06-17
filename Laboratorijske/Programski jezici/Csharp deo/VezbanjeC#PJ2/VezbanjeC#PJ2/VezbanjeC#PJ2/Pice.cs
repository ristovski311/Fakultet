using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ2
{
    internal class Pice : Stavka
    {
        double kolicinaLitara;
        double cenaPoL;
        bool domace;

        public Pice() : base() { }

        public Pice(string naziv, DateTime istekRoka, bool veganska,double kolicinaLitara, double cenaPoL, bool domace) : base(naziv, istekRoka, veganska)
        {
            this.kolicinaLitara = kolicinaLitara;
            this.cenaPoL = cenaPoL;
            this.domace = domace;
        }

        public override double Cena
        {
            get
            {
                double res = cenaPoL * kolicinaLitara;
                if (!domace)
                    res *= 1.3;
                return res;
            }
        }

        public override void Ispisi(BinaryWriter bw)
        {
            bw.Write("Pice");
            base.Ispisi(bw);
            bw.Write(kolicinaLitara);
            bw.Write(cenaPoL);
            bw.Write(domace);
        }

        public override void Citaj(BinaryReader br)
        {
            base.Citaj(br);
            kolicinaLitara = br.ReadDouble();
            cenaPoL = br.ReadDouble();
            domace = br.ReadBoolean();
        }


    }
}
