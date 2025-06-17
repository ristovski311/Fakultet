using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ2
{
    internal class BotanickaBasta
    {
        string naziv;
        int brojPosetilacaZaDan;
        double cenaUlaznice;
        List<Biljka> biljke;

        public BotanickaBasta() { biljke = new List<Biljka>(); }

        public BotanickaBasta(string naziv, int brojPosetilacaZaDan, double cenaUlaznice, List<Biljka> biljke)
        {
            this.naziv = naziv;
            this.brojPosetilacaZaDan = brojPosetilacaZaDan;
            this.cenaUlaznice = cenaUlaznice;
            this.biljke = biljke;
        }

        public BotanickaBasta(string naziv, int brojPosetilacaZaDan, double cenaUlaznice)
        {
            this.naziv = naziv;
            this.brojPosetilacaZaDan = brojPosetilacaZaDan;
            this.cenaUlaznice = cenaUlaznice;
            this.biljke = new List<Biljka>();
        }

        public void Dodaj(Biljka b)
        {
            if(!biljke.Contains(b))
                biljke.Add(b);

        }

        public bool TrosakVeciOdZarade()
        {
            double trosak = 0;
            foreach (Biljka b in biljke)
                trosak += b.cenaOdrzavanja();

            return trosak > brojPosetilacaZaDan * cenaUlaznice;
        }

        public Biljka NajskupljaBiljka()
        {
            Biljka res = null;
            bool nadjen = false;
            for (int i = 0; i < biljke.Count && !nadjen; i++)
            {
                if (biljke[i].Visegodisnja)
                    res = biljke[i];
            }
            if (res == null)
                return res;
            foreach (Biljka b in biljke)
                if (b.Visegodisnja && b.cenaOdrzavanja() > res.cenaOdrzavanja())
                    res = b;
            return res;
        }

        public void IzbaciVisakBiljaka()
        {
            while(TrosakVeciOdZarade())
            {
                Biljka zaIzbacivanje = NajskupljaBiljka();
                if (zaIzbacivanje == null)
                    return;
                biljke.Remove(zaIzbacivanje);
            }
        }

        public void SortirajPoVodi()
        {
            biljke.Sort();
        }

        public bool proveriRaspored()
        {
            bool imaStablastih = false;
            bool imaSaksijskih = false;

            foreach (Biljka b in biljke)
            {
                if (b.GetType() == typeof(StablastaBiljka))
                    imaStablastih = true;
                else if (b.GetType() == typeof(SaksijskaBiljka))
                    imaSaksijskih = true;
            }

            if (!imaStablastih || !imaSaksijskih)
                throw new NedovoljnaRaznovrsnost("Greska raznovrsnosti");
            else
                return true;
        }

        public void Ispisi(string putanja)
        {
            FileStream fs = new FileStream(putanja, FileMode.Append);
            using(BinaryWriter bw = new BinaryWriter(fs))
            {
                bw.Write(biljke.Count);
                bw.Write(naziv);
                bw.Write(brojPosetilacaZaDan);
                bw.Write(cenaUlaznice);
                foreach(Biljka b in biljke)
                {
                    b.Ispisi(bw);
                }
            }
            fs.Close();
        }

        public void Citaj(string putanja)
        {
            FileStream fs = new FileStream(putanja, FileMode.Open);
            using (BinaryReader br = new BinaryReader(fs))
            {
                int brojBiljaka = br.ReadInt32();
                this.naziv = br.ReadString();
                this.brojPosetilacaZaDan = br.ReadInt32();
                this.cenaUlaznice = br.ReadDouble();

                for(int i = 0; i < brojBiljaka; i++)
                {
                    Biljka b;
                    string tip = br.ReadString();
                    if(tip == "Saksijska")
                    {
                        b = new SaksijskaBiljka();
                        b.Citaj(br);
                    }
                    else
                    {
                        b = new StablastaBiljka();
                        b.Citaj(br);
                    }

                    this.Dodaj(b);
                }
            }
            fs.Close();
        }

    }
}
