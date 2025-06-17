using System;
using System.Collections.Generic;
using System.Linq;
using System.Linq.Expressions;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ2
{
    public class Restoran
    {
        string naziv;
        List<Stavka> meni;

        public Restoran() { meni = new List<Stavka>(); }

        public Restoran(string naziv)
        {
            this.naziv = naziv;
            meni = new List<Stavka>();
        }

        public void Dodaj(Stavka s)
        {
            if(meni.Contains(s) == false)
                meni.Add(s);
        }

        public void SortirajPoCeni()
        {
            meni.Sort();
        }

        public void izbaciIstekle()
        {
            for(int i = 0; i < meni.Count; i++)
            {
                if (meni[i].Istekao)
                    meni.Remove(meni[i]);
            }
        }

        public bool ImaVeganskih()
        {
            bool nadjen = false;
            for(int i = 0; i < meni.Count && !nadjen; i++)
            {
                if (meni[i].Veganska)
                    nadjen = true;
            }

            if (!nadjen)
                throw new VeganUnfriendly("Nismo vegan friendly");
            return true;
        }

        public void Ispisi(string putanja)
        {
            FileStream fs = new FileStream(putanja, FileMode.Append);
            using(BinaryWriter bw = new BinaryWriter(fs))
            {
                bw.Write(naziv);
                bw.Write(meni.Count);
                foreach(Stavka s in meni)
                    s.Ispisi(bw);
            }
        }

        public void Citaj(string putanja)
        {
            FileStream fs = new FileStream(putanja, FileMode.Open);
            using(BinaryReader br = new BinaryReader(fs))
            {
                naziv = br.ReadString();
                int broj = br.ReadInt32();
                for (int i = 0; i < broj; i++)
                {
                    Stavka s;
                    string tip = br.ReadString();
                    if (tip == "Jelo")
                    { 
                        s = new Jelo();
                        s.Citaj(br);
                        Dodaj(s);
                    }
                    else
                    {
                        s = new Pice();
                        s.Citaj(br);
                        Dodaj(s);
                    }

                }
               
            }
        }

        public Stavka this[int i]
        {
            get
            {
                return meni[i];
            }
            set
            {
                meni[i] = value;
            }
        }

    }
}
