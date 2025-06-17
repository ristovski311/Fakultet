using System;
using System.Collections.Generic;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PJLAB319347
{
    internal class EAuto : Auto
    {
        private double elEnergija;
        private double cenaElEn;
        private DateTime istekBaterije;

        //public double ElEnergija
        //{
        //    get { return elEnergija; }
        //    set { elEnergija = value; }
        //}

        //public double CenaElEn
        //{
        //    get { return cenaElEn; }
        //    set { cenaElEn = value; }
        //}

        public DateTime IstekBaterije
        {
            get { return istekBaterije; }
            set { istekBaterije = value; }
        }

        public EAuto(String naziv, int godpr, double elEnergija, double cenaElEn, DateTime istekbat) 
            : base(naziv,godpr)
        {
            this.elEnergija= elEnergija;
            this.cenaElEn = cenaElEn;
            this.istekBaterije = istekbat;
        }

        public EAuto() 
            : this("", 0, 0, 0, new DateTime(1,1,1,0,0,0)) { }

        public override double cenaKilometra()
        {
            double res = elEnergija * cenaElEn;

            int trenutnaGod = DateTime.Now.Year;

            for (int i = trenutnaGod; i > this.godinaProizvodnje; i--)
                res *= 1.05;

            return res;
        }

        public override void Upisi(FileStream stream)
        {
            using (StreamWriter sw = new StreamWriter(stream))
            {
                sw.WriteLine("EAuto");
                base.Upisi(stream);
                //sw.WriteLine(this.naziv);
                //sw.WriteLine(this.godinaProizvodnje);
                sw.WriteLine(this.elEnergija);
                sw.WriteLine(this.cenaElEn);
                sw.WriteLine(this.istekBaterije);
            }
        }

        public override void UpisiStream(StreamWriter stream)
        {
            stream.WriteLine("EAuto");
            base.UpisiStream(stream);
            //stream.WriteLine(naziv);
            //stream.WriteLine(godinaProizvodnje);
            stream.WriteLine(this.elEnergija);
            stream.WriteLine(this.cenaElEn);
            stream.WriteLine(this.istekBaterije);
        }

        public override void Citaj(FileStream stream)
        {
            using (StreamReader sr = new StreamReader(stream))
            {
                String tip = sr.ReadLine();
                base.Citaj(stream);
                //naziv = sr.ReadLine();
                //godinaProizvodnje = Int32.Parse(sr.ReadLine());
                elEnergija = Double.Parse(sr.ReadLine());
                cenaElEn = Double.Parse(sr.ReadLine());
                String tempDate = sr.ReadLine();
                istekBaterije = DateTime.Parse(tempDate);
            }
        }

        public override void CitajStream(StreamReader sr)
        {
            base.CitajStream(sr);
            //naziv = sr.ReadLine();
            //godinaProizvodnje = Int32.Parse(sr.ReadLine());
            elEnergija = Double.Parse(sr.ReadLine());
            cenaElEn = Double.Parse(sr.ReadLine());
            String tempDate = sr.ReadLine();
            istekBaterije = DateTime.Parse(tempDate);
        }

    }
}
