using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PJLab3NR
{
    internal abstract class Auto
    {
        String naziv;
        int godinaProizvodnje;

        public Auto() : this("", 0) { }

        public Auto(string naziv, int godinaProizvodnje)
        {
            this.naziv = naziv;
            this.godinaProizvodnje = godinaProizvodnje;
        } 

        public String Naziv
        {
            get {  return naziv; }

            set { naziv = value; }
        }

        public int GodinaProizvodnje
        {
            get { return godinaProizvodnje; }

            set { godinaProizvodnje = value; }
        }

        public abstract double cenaKilometra();

        public virtual void Upisi(FileStream stream)
        {
            using (StreamWriter sw = new StreamWriter(stream))
            {
                sw.WriteLine(this.naziv);
                sw.WriteLine(this.godinaProizvodnje);
            }
        }

        public virtual void Citaj(FileStream stream)
        {
            using(StreamReader sr = new StreamReader(stream))
            {
                String tempNaziv = sr.ReadLine();
                try
                {
                    int tempGodPr = Int32.Parse(sr.ReadLine());
                }
                catch(Exception ex)
                {
                    Console.WriteLine("Procitan pogresan format za godinu proizvodnje automobila iz fajla!");
                    Console.WriteLine(ex.Message);
                }
            }
        }
    }
    
}
