using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ2
{
    internal class SaksijskaBiljka : Biljka
    {
        double potrebnoDjubrivaUKG;
        double cenaDjubrivaPoKG;
        
        public SaksijskaBiljka() : base() { }

        public SaksijskaBiljka(string naziv, bool jedogodisnja, double potrebnaVodaDnevno,double potrebnoDjubrivaUKG, double cenaDjubrivaPoKG) : base(naziv, jedogodisnja, potrebnaVodaDnevno)
        {
            this.potrebnoDjubrivaUKG = potrebnoDjubrivaUKG;
            this.cenaDjubrivaPoKG = cenaDjubrivaPoKG;
        }

        public override double cenaOdrzavanja()
        {
            double res = potrebnaVodaDnevno * 10 + cenaDjubrivaPoKG * potrebnoDjubrivaUKG;
            if (!jedogodisnja)
                res *= 1.1;
            return res;
        }

        public override void Ispisi(BinaryWriter bw)
        {
            bw.Write("Saksijska");
            base.Ispisi(bw);
            bw.Write(potrebnoDjubrivaUKG);
            bw.Write(cenaDjubrivaPoKG);
            bw.Write(cenaOdrzavanja());
        }

        public override void Citaj(BinaryReader br)
        {
            base.Citaj(br);
            potrebnoDjubrivaUKG = br.ReadDouble();
            cenaDjubrivaPoKG = br.ReadDouble();
            double cena = br.ReadDouble();
        }
    }
}
