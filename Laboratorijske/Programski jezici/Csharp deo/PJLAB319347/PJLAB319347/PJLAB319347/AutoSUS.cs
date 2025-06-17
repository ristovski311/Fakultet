using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PJLAB319347
{
    internal class AutoSUS : Auto
    {

        private double potrosnjaL;
        private double cenaPoL;

        //public double PotrosnjaL
        //{
        //    get { return potrosnjaL; }
        //    set {  potrosnjaL = value; }
        //}

        //public double CenaPoL
        //{
        //    get { return cenaPoL; }
        //    set { cenaPoL = value; }
        //}

        public AutoSUS(String naziv, int godpr, double potrosnja, double cena) 
            : base(naziv, godpr)
        {
            this.potrosnjaL = potrosnja;
            this.cenaPoL = cena;
        }

        public AutoSUS() 
            : this("", 0, 0, 0) { }

        public override double cenaKilometra()
        {
            double res = cenaPoL * potrosnjaL;

            int trenutnaGod = DateTime.Now.Year;

            for (int i = trenutnaGod; i > this.godinaProizvodnje; i--)
                res *= 1.1;

            return res;
        }

        public override void Upisi(FileStream stream)
        {
            using (StreamWriter sw = new StreamWriter(stream))
            {
                sw.WriteLine("AutoSUS");
                base.Upisi(stream);
                //sw.WriteLine(naziv);
                //sw.WriteLine(godinaProizvodnje);
                sw.WriteLine(potrosnjaL);
                sw.WriteLine(cenaPoL);
            }
        }

        public override void UpisiStream(StreamWriter stream)
        {
            stream.WriteLine("AutoSUS");
            base.UpisiStream(stream);
            //stream.WriteLine(naziv);
            //stream.WriteLine(godinaProizvodnje);
            stream.WriteLine(potrosnjaL);
            stream.WriteLine(cenaPoL);
        }

        public override void Citaj(FileStream stream)
        {
            using (StreamReader sr = new StreamReader(stream))
            {
                String tip = sr.ReadLine();
                base.Citaj(stream);
                //naziv = sr.ReadLine();
                //godinaProizvodnje = Int32.Parse(sr.ReadLine());
                potrosnjaL = Double.Parse(sr.ReadLine());
                cenaPoL = Double.Parse(sr.ReadLine());
            }
        }

        public override void CitajStream(StreamReader sr)
        {
            base.CitajStream(sr);
            //naziv = sr.ReadLine();
            //godinaProizvodnje = Int32.Parse(sr.ReadLine());
            potrosnjaL = Double.Parse(sr.ReadLine());
            cenaPoL = Double.Parse(sr.ReadLine());
        }
    }
}
