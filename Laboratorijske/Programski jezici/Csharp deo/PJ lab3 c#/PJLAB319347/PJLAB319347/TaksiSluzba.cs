using System;
using System.Collections.Generic;
using System.Linq;
using System.Runtime.InteropServices.Marshalling;
using System.Text;
using System.Threading.Tasks;

namespace PJLAB319347
{
    internal class TaksiSluzba
    {
        private String naziv;
        private int predjeniKM;
        private double ukupnoNaplaceno;
        private List<Auto> vozila;

        private double ProsekCene
        {
            get { return ukupnoNaplaceno / predjeniKM; }
        }

        public TaksiSluzba(string naziv, int predjeniKM, double ukupnoNaplaceno)
        {
            this.naziv = naziv;
            this.predjeniKM = predjeniKM;
            this.ukupnoNaplaceno = ukupnoNaplaceno;
            this.vozila = new List<Auto>();
        }

        public TaksiSluzba() : this("", 0, 0) { }
            
        public void Dodaj(ref Auto a)
        {
            vozila.Add(a);
        }

        public void IzbaciPreskupaVozila()
        { 

            for(int i = vozila.Count - 1; i >= 0; i--)
            {
                if (vozila[i].cenaKilometra() > this.ProsekCene)
                    vozila.Remove(vozila[i]);
            }
        }

        public void SortirajPoGodiniProizvodnje()
        {
            for(int i = 0; i < vozila.Count - 1; i++)
            {
                int min = i;
                for (int j = i + 1; j < vozila.Count; j++)
                {
                    if (vozila[min].CompareTo(vozila[j]) > 0)
                    {
                        min = j;
                    }
                }
                if(min != i)
                {
                    Auto pom = vozila[i];
                    vozila[i] = vozila[min];
                    vozila[min] = pom;
                }
            }
        }

        public void proveriBaterije()
        {
            foreach(Auto a in vozila)
            {
                if(a is EAuto)
                {
                    DateTime trenutno = DateTime.Now;
                    EAuto provera = (EAuto)a;
                    if (trenutno.CompareTo(provera.IstekBaterije) > 0)
                        throw new PotencijalnaEksplozija("Pokvarene baterije, istekao rok!");
                }
            }
        }

        public void Upisi(String file)
        {
            using (StreamWriter sw = new StreamWriter(file))
            {
                sw.WriteLine(naziv);
                sw.WriteLine(predjeniKM);
                sw.WriteLine(ukupnoNaplaceno);
                sw.WriteLine(vozila.Count);
                foreach (Auto a in vozila)
                {
                    a.UpisiStream(sw);
                }
            }
        }

        public void Citaj(String file)
        {
            using (StreamReader sr = new StreamReader(file))
            {
                naziv = sr.ReadLine();
                predjeniKM = Int32.Parse(sr.ReadLine());
                ukupnoNaplaceno = Double.Parse(sr.ReadLine());
                vozila = new List<Auto>();
                int brojVozila = Int32.Parse(sr.ReadLine());
                for (int i = 0; i < brojVozila; i++)
                {
                    String tip = sr.ReadLine();
                    if (tip == "AutoSUS")
                    {
                        Auto temp = new AutoSUS();
                        temp.CitajStream(sr);
                        vozila.Add(temp);
                    }
                    else
                    {
                        Auto temp = new EAuto();
                        temp.CitajStream(sr);
                        vozila.Add(temp);

                    }

                }


            }
        }


    }
}
