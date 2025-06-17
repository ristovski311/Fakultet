using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ2
{
    internal class Jelo : Stavka
    {
        double nabavnaCena;
        Kvalitet kvalitet;

        public Jelo() : base() { }

        public Jelo(string naziv, DateTime istekRoka, bool veganska,double nabavnaCena, Kvalitet kvalitet) : base(naziv, istekRoka, veganska)
        {
            this.nabavnaCena = nabavnaCena;
            this.kvalitet = kvalitet;
        }

        public override double Cena
        {
            get 
            {
                double res = nabavnaCena * (int)kvalitet;
                if ((istekRoka - DateTime.Now).TotalDays <= 3)
                    res = res - 0.3 * res;
                return res;
            }
        }

        public override void Ispisi(BinaryWriter bw)
        {
            bw.Write("Jelo");
            base.Ispisi(bw);
            bw.Write(nabavnaCena);
            bw.Write((int)kvalitet);
        }

        public override void Citaj(BinaryReader br)
        {
            base.Citaj(br);
            nabavnaCena = br.ReadDouble();
            kvalitet = (Kvalitet)br.ReadInt32();

        }


        public static Jelo operator+(Jelo j1, Jelo j2)
        {
            return new Jelo("novo jelo", DateTime.Now, j2.Veganska && j1.Veganska, j1.nabavnaCena + j2.nabavnaCena, Kvalitet.Dobar); 
        }

    }
}
