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
            this.Ime = v.Ime;
            this.Prezime = v.Prezime;
            this.DatRodjenja = v.DatRodjenja;
            this.BrojDozvole = v.BrojDozvole;
            this.DozvolaOd = v.DozvolaOd;
            this.DozvolaDo = v.DozvolaDo;
            this.MestoIzdavanja = v.MestoIzdavanja;
            this.Pol = v.Pol;
            this.Slika = v.Slika;
            this.Kategorije = new List<Kategorija>(v.Kategorije);
            this.Zabrane = new List<Zabrana>(v.Zabrane);
        }


        #endregion Konstruktori

        #region Svojstva
        public string Ime
        {
            get { return ime; }
            set { ime = value; }
        }

        public string Prezime
        {
            get { return prezime; }
            set { prezime = value; }
        }
        [DisplayName("Broj dozvole")]
        public string BrojDozvole
        {
            get { return brojDozvole; }
            set { brojDozvole = value; }
        }

        [Browsable(false)]
        public DateTime DatRodjenja
        {
            get { return datRodjenja; }
            set { datRodjenja = value; }
        }

        [Browsable(false)]
        public DateTime DozvolaOd
        {
            get { return dozvolaOd; }
            set { dozvolaOd = value; }
        }

        [Browsable(false)]
        public DateTime DozvolaDo
        {
            get { return dozvolaDo; }
            set { dozvolaDo = value; }
        }

        [Browsable(false)]

        public string MestoIzdavanja
        {
            get { return mestoIzdavanja; }
            set { mestoIzdavanja = value; }
        }


        [Browsable(false)]

        public char Pol
        {
            get { return pol; }
            set { pol = value; }
        }

        [Browsable(false)]

        public string Slika
        { get { return slika; }
        set { slika = value; }
        }
        
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
                    ObrisiZabranu(new Zabrana(k.ImeKategorije, new DateTime(2024, 1, 1), new DateTime(2024, 1, 1)));
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
                    zabrane.Remove(z);
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
