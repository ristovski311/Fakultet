using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Podaci
{
    public class Vozac
    {
        #region Atributi

        string ime;
        string prezime;
        DateTime datRodjenja;
        string brojDozvole;
        DateTime dozvolaOd;
        DateTime dozvolaDo;
        string mestoIzdavanja;
        char pol;
        string slika;
        List<Kategorija> kategorije;
        List<Zabrana> zabrane;

        #endregion Atributi

        #region Konstruktori

        public Vozac()
        {
            kategorije = new List<Kategorija>();
            zabrane = new List<Zabrana>();
        }

        public Vozac(string ime, string prezime, DateTime datRodjenja, string brojDozvole, DateTime dozvolaOd, DateTime dozvolaDo, string mestoIzdavanja, char pol, string slika, List<Kategorija> kategorije, List<Zabrana> zabrane)
        {
            this.ime = ime;
            this.prezime = prezime;
            this.datRodjenja = datRodjenja;
            this.brojDozvole = brojDozvole;
            this.dozvolaOd = dozvolaOd;
            this.dozvolaDo = dozvolaDo;
            this.mestoIzdavanja = mestoIzdavanja;
            this.pol = pol;
            this.slika = slika;
            this.kategorije = kategorije;
            this.zabrane = zabrane;
        }

        public Vozac(Vozac v)
        {
            this.ime = v.ime;
            this.prezime = v.prezime;
            this.datRodjenja = v.datRodjenja;
            this.brojDozvole = v.brojDozvole;
            this.dozvolaOd = v.dozvolaOd;
            this.dozvolaDo = v.dozvolaDo;
            this.mestoIzdavanja = v.mestoIzdavanja;
            this.pol = v.pol;
            this.slika = v.slika;
            this.kategorije = v.kategorije;
            this.zabrane = v.zabrane;
        }


        #endregion Konstruktori

        #region Svojstva
        public string Ime
        {
            get;
            set;
        }

        public string Prezime
        {
            get;
            set;
        }

        public string BrojDozvole
        {
            get;
            set;
        }

        [Browsable(false)]
        public DateTime DatRodjenja { get; set; }

        [Browsable(false)]
        public DateTime DozvolaOd { get; set; }

        [Browsable(false)]
        public DateTime DozvolaDo { get; set; }

        [Browsable(false)]

        public string MestoIzdavanja { get; set; }

        [Browsable(false)]

        public char Pol { get; set; }

        [Browsable(false)]

        public string Slika { get; set; }
        
        [Browsable(false)]

        public List<Kategorija> Kategorije
        {
            get { return this.kategorije; }
            set { this.kategorije = value; }
        }

        [Browsable(false)]
        public List<Zabrana> Zabrane
        {

            get { return this.zabrane; }
            set { this.zabrane = value;}
        }


        #endregion Svojstva

        #region Metodi

        public bool DodajKategoriju(Kategorija kat)
        {
            if (kat == null)
                return false;
            foreach (Kategorija k in kategorije)
            {
                if (k.ImeKategorije == kat.ImeKategorije)
                    return false;
            }
            kategorije.Add(kat);
            return true;
        }

        public bool ObrisiKategoriju(Kategorija kat)
        {
            if (kat == null)
                return false;
            foreach (Kategorija k in kategorije)
            {
                if (k.ImeKategorije == kat.ImeKategorije)
                {
                    kategorije.Remove(k);
                    return true;
                }
            }
            return false;
        }

        public bool DodajZabranu(Zabrana zab)
        {
            if (zab == null)
                return false;
            foreach (Zabrana z in zabrane)
            {
                if (z.Kategorija == zab.Kategorija)
                    return false;
            }
            zabrane.Add(zab);
            return true;
        }

        public bool ObrisiZabranu(Zabrana zab)
        {
            if (zab == null)
                return false;
            foreach (Zabrana z in zabrane)
            {
                if (z.Kategorija == zab.Kategorija)
                {
                    zabrane.Remove(zab);
                    return true;
                }
            }
            return false;
        }

        public bool Zameni(Vozac v)
        {
            if (v == null)
                return false;
            else
            {
                this.ime = v.ime;
                this.prezime = v.prezime;
                this.datRodjenja = v.datRodjenja;
                this.brojDozvole = v.brojDozvole;
                this.dozvolaOd = v.dozvolaOd;
                this.dozvolaDo = v.dozvolaDo;
                this.mestoIzdavanja = v.mestoIzdavanja;
                this.pol = v.pol;
                this.slika = v.slika;
                this.kategorije = v.kategorije;
                this.zabrane = v.zabrane;
                return true;
            }
        }

        #endregion Metodi
    }
}
