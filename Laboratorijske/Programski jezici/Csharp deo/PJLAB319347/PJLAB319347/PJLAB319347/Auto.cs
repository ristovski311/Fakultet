using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace PJLAB319347
{
    internal abstract class Auto : IComparable<Auto>
    {
        protected String naziv;
        protected int godinaProizvodnje;
       
        public Auto() : this("", 0) { }
        
        public Auto(string naziv, int godinaProizvodnje)
        {
            this.naziv = naziv;
            this.godinaProizvodnje = godinaProizvodnje;
        }

        //public String Naziv
        //{
        //    get { return naziv; }

        //    set { naziv = value; }
        //}

        //public int GodinaProizvodnje
        //{
        //    get { return godinaProizvodnje; }

        //    set { godinaProizvodnje = value; }
        //}

        public abstract double cenaKilometra();

        public virtual void Upisi(FileStream stream)
        {
            using(StreamWriter sw = new StreamWriter(stream))
            {
                sw.WriteLine(this.naziv);
                sw.WriteLine(this.godinaProizvodnje);
                sw.Close();
            }
        }

        public virtual void UpisiStream(StreamWriter stream)
        {
            stream.WriteLine(this.naziv);
            stream.WriteLine(this.godinaProizvodnje);
        }

        public virtual void Citaj(FileStream stream)
        {
            using (StreamReader sr = new StreamReader(stream))
            {
                naziv = sr.ReadLine();
                godinaProizvodnje = Int32.Parse(sr.ReadLine());
            }
        }

        public virtual void CitajStream(StreamReader sr)
        {
            naziv = sr.ReadLine();
            godinaProizvodnje = Int32.Parse(sr.ReadLine());
        }

        public int CompareTo(Auto other)
        {
            if (this.godinaProizvodnje == other.godinaProizvodnje) return 0;
            else if (this.godinaProizvodnje > other.godinaProizvodnje) return 1;
            else return -1;
        }
    }
}
