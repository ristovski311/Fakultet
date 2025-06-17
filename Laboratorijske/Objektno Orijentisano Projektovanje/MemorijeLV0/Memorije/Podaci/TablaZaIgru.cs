using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Xml.Serialization;

namespace Podaci
{
    [Serializable]

    public class TablaZaIgru
    {
        public static int selectedButtons = 0;

        List<List<PoljeZaSerijalizaciju>> poljaZaSerijalizaciju;
        List<List<Polje>> polja;

        DimenzijeTable dimenzija;

        int pronadjeniParovi;
        int potrebnoPronaciParova;

        Polje prvoSelektovanoDugme = null;
        Polje drugoSelektovanoDugme = null;

        public static bool isChecking = false;

        int timeElapsed;

        #region Attributes

        [XmlIgnore]
        public int N 
        { 
            get { return dimenzija.Vrste; } 
            set { this.dimenzija.Parovi = value; }
        }

        [XmlIgnore]
        public int M 
        { 
            get { return dimenzija.Kolone; } 
            set { this.dimenzija.Kolone = value; } 
        }

        [XmlElementAttribute("PronadjeniParovi")]
        public int PronadjeniParovi 
        {  
            get { return pronadjeniParovi; } 
            set { this.pronadjeniParovi = value; } 
        }

        [XmlIgnore]
        public int RazliciteSlike
        { 
            get { return dimenzija.RazliciteSlike; }
            set { dimenzija.RazliciteSlike = value; }
        }

        [XmlIgnore]
        public int Parovi 
        { 
            get { return dimenzija.Parovi; } 
            set { this.dimenzija.Parovi = value; } 
        }

        [XmlIgnore]
        public List<List<Polje>> Polja
        {
            get { return polja; }
            set {  polja = value; }
        }

        [XmlElementAttribute("PotrebnoPronaciParova")]
        public int PotrebnoPronaciParova
        {
            get { return potrebnoPronaciParova; }
            set { potrebnoPronaciParova = value; }
        }

        [XmlElementAttribute("Dimenzija")]
        public DimenzijeTable Dimenzija
        {
            get { return dimenzija; }
            set {  dimenzija = value; }
        }

        [XmlElementAttribute("TimeElapsed")]
        public int TimeElapsed
        { 
            get { return timeElapsed; }
            set { timeElapsed = value; }
        }

        [XmlArray("Polja")]
        [XmlArrayItem("Red", typeof(List<PoljeZaSerijalizaciju>))]
        public List<List<PoljeZaSerijalizaciju>> PoljaZaSerijalizaciju
        {
            get { return poljaZaSerijalizaciju; }
            set { poljaZaSerijalizaciju = value; }
        }

        #endregion Attributes

        #region Methods
        public void OtvoriPolje(object sender, EventArgs e)
        {
            ((Polje)sender).OtvoriPolje();
        }

        public void OsveziSvaPolja()
        {
            foreach(List<Polje> lista in polja)
            {
                foreach(Polje polje in lista)
                {
                    polje.OsveziPoljaPosleDeserijalizacije();
                }
            }
        }

        public void OtvoriSvaPolja()
        {
            foreach (List<Polje> lp in polja)
            {
                foreach (Polje p in lp)
                {
                    p.Enabled = false;
                    p.OtvoriPolje();
                }
            }
        }

        public List<Polje> DisableButtonsTemp()
        {
            List<Polje> res = new List<Polje>();
            foreach(List<Polje> lp in polja)
            {
                foreach(Polje polje in lp)
                {
                    if(polje.Enabled && polje != prvoSelektovanoDugme && polje != drugoSelektovanoDugme)
                    {
                        polje.Enabled = false;
                        res.Add(polje);
                    }
                }
            }
            return res;
        }

        public void EnableDisabledTempButtons(List<Polje> lp)
        {
            foreach(Polje polje in lp)
            {
                polje.Enabled = true;
            }
        }

        public async void CheckPairing(object sender, EventArgs e)
        {
            if (isChecking) return;
            if (!isChecking && prvoSelektovanoDugme == null)
            {
                prvoSelektovanoDugme = (Polje)sender;
                return;
            }

            else if (!isChecking && drugoSelektovanoDugme == null)
            {
                drugoSelektovanoDugme = (Polje)sender;
            }

            if(prvoSelektovanoDugme == drugoSelektovanoDugme)
            {
                drugoSelektovanoDugme = null;
                return;
            }

            if (prvoSelektovanoDugme != null && drugoSelektovanoDugme != null)
            {
                //List<Polje> disabled = DisableButtonsTemp();
                isChecking = true;
                await Task.Delay(400);
                if(prvoSelektovanoDugme.Picture == drugoSelektovanoDugme.Picture)
                {
                    pronadjeniParovi++;
                    prvoSelektovanoDugme.Enabled = false;
                    prvoSelektovanoDugme.Pogodjeno = true;
                    ((Polje)sender).Enabled = false;
                    ((Polje)sender).Pogodjeno = true;
                    prvoSelektovanoDugme = null;
                    drugoSelektovanoDugme = null;
                }
                else
                {
                    prvoSelektovanoDugme.Image = null;
                    drugoSelektovanoDugme.Image = null;
                    prvoSelektovanoDugme = null;
                    drugoSelektovanoDugme = null;
                }
                //EnableDisabledTempButtons(disabled);
                isChecking = false;
            }

        }

        public void PostaviProveruPara()
        {
            foreach (List<Polje> lp in polja)
            {
                foreach (Polje p in lp)
                {
                    if (p.Picture != null)
                        p.Click += CheckPairing;
                }
            }
        }

        public void PostaviSlikePoljima()
        {
            Random random;
            int singles = 0;
            int postavljeniParovi = 0;
            while (postavljeniParovi < potrebnoPronaciParova)
            {
                string slika = "C:\\Users\\risto\\source\\repos\\Memorije\\Slike\\" + postavljeniParovi % dimenzija.RazliciteSlike + ".png";
                for (int i = 0; i < 2; i++)
                {
                    //Logika za generisanje singlova
                    random = new Random();
                    int broj = random.Next(0, 100);
                    if (i == 1 && broj % 3 == 0 && postavljeniParovi / dimenzija.RazliciteSlike == 0)
                    {
                        singles++;
                        continue;
                    }
                    else
                    {
                        bool pogodak = false;
                        while (!pogodak)
                        {
                            random = new Random();
                            int posx = random.Next(0, dimenzija.Vrste * dimenzija.Vrste);
                            int posy = random.Next(0, dimenzija.Kolone * dimenzija.Kolone);
                            if (polja[posx % dimenzija.Vrste][posy % dimenzija.Kolone].Picture == null)
                            {
                                polja[posx % dimenzija.Vrste][posy % dimenzija.Kolone].Picture = slika;
                                pogodak = true;
                            }
                        }
                    }
                }
                postavljeniParovi++;
            }
            potrebnoPronaciParova -= singles;
        }

        public void SpremiZaSerijalizaciju()
        {
            poljaZaSerijalizaciju = new List<List<PoljeZaSerijalizaciju>>();
            int row = 0;
            foreach (List<Polje> lp in polja)
            {
                List<PoljeZaSerijalizaciju> lista = new List<PoljeZaSerijalizaciju>();
                foreach (Polje polje in lp)
                {
                    PoljeZaSerijalizaciju pzs = new PoljeZaSerijalizaciju(polje);
                    lista.Add(pzs);
                }
                poljaZaSerijalizaciju.Add(lista);
                row++;
            }
        }

        public void Deserijalizuj()
        {
            polja = new List<List<Polje>>();
            polja.Clear();
            int row = 0;
            foreach (List<PoljeZaSerijalizaciju> lp in poljaZaSerijalizaciju)
            {
                List<Polje> lista = new List<Polje>();
                polja.Add(lista);
                foreach (PoljeZaSerijalizaciju pzs in lp)
                {
                    Polje p = new Polje(pzs);
                    p.PostaviPoziciju();
                    p.Click += OtvoriPolje;
                    p.TabStop = false;
                    polja[row].Add(p);
                }
                row++;
            }
            PostaviProveruPara();
        }

        public void PromeniVelicinuPolja()
        {
            switch (dimenzija.Vrste)
            {
                case 6:
                    Polje.Velicina = 100;
                    break;
                case 7:
                    Polje.Velicina = 90;
                    break;
                case 8:
                    Polje.Velicina = 80;
                    break;
                case 9:
                    Polje.Velicina = 70;
                    break;
            }
        }

        public void PostaviVelicinuPoljima()
        {
            foreach (List<Polje> lp in polja)
            {
                foreach (Polje p in lp)
                {
                    p.Height = Polje.Velicina;
                    p.Width = Polje.Velicina;
                }
            }
        }

        #endregion Methods

        #region Contructors

        public TablaZaIgru()
        {
            timeElapsed = 0;
            poljaZaSerijalizaciju = new List<List<PoljeZaSerijalizaciju>>();
            dimenzija = new DimenzijeTable();
            PromeniVelicinuPolja();
            potrebnoPronaciParova = dimenzija.Parovi;
            
            polja = new List<List<Polje>>();

            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                polja.Add(new List<Polje>());
            }
            
            int posx = 0;
            int posy = 23; //ZBOG MENUSTRIP-A
            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                for (int j = 0; j < dimenzija.Kolone; j++)
                {
                    polja[i].Add(new Polje());
                    polja[i][j].PosX = posx;
                    polja[i][j].PosY = posy;
                    polja[i][j].PostaviPoziciju();
                    polja[i][j].TabStop = false;
                    polja[i][j].Click += OtvoriPolje;
                    polja[i][j].Cursor = Cursors.Hand;
                    posx += polja[i][j].Width;
                }
                posx = 0;
                posy += polja[0][0].Height;
            }

            PostaviSlikePoljima();
            PostaviProveruPara();
        }

        public TablaZaIgru(DimenzijeTable dt)   
        {
            timeElapsed = 0;
            poljaZaSerijalizaciju = new List<List<PoljeZaSerijalizaciju>>();
            dimenzija = dt;
            PromeniVelicinuPolja();
            potrebnoPronaciParova = dt.Parovi;

            polja = new List<List<Polje>>();

            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                polja.Add(new List<Polje>());
            }
            
            int posx = 0;
            int posy = 23; //ZBOG MENUSTRIP-A
            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                for (int j = 0; j < dimenzija.Kolone; j++)
                {
                    polja[i].Add(new Polje());
                    polja[i][j].PosX = posx;
                    polja[i][j].PosY = posy;
                    polja[i][j].PostaviPoziciju();
                    polja[i][j].TabStop = false;
                    polja[i][j].Click += OtvoriPolje;
                    posx += polja[i][j].Width;
                    polja[i][j].Cursor = Cursors.Hand;
                }
                posx = 0;
                posy += polja[0][0].Height;
            }

            PostaviSlikePoljima();
            PostaviProveruPara();
        }

        public TablaZaIgru(int n, int m, int parovi, int razliciteSlike)
        {
            timeElapsed = 0;
            dimenzija = new DimenzijeTable(n,m,parovi,razliciteSlike);
            PostaviVelicinuPoljima();
            poljaZaSerijalizaciju = new List<List<PoljeZaSerijalizaciju>>();
            potrebnoPronaciParova = dimenzija.Parovi;

            polja = new List<List<Polje>>();

            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                polja.Add(new List<Polje>());
            }
            int posx = 0;
            int posy = 23; //ZBOG MENUSTRIP-A
            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                for (int j = 0; j < dimenzija.Kolone; j++)
                {
                    polja[i].Add(new Polje());
                    polja[i][j].PosX = posx;
                    polja[i][j].PosY = posy;
                    polja[i][j].PostaviPoziciju();
                    polja[i][j].TabStop = false;
                    polja[i][j].Click += OtvoriPolje;
                    polja[i][j].Cursor = Cursors.Hand;
                    posx += polja[i][j].Width;
                }
                posx = 0;
                posy += polja[0][0].Height;
            }

            PostaviSlikePoljima();
            PostaviProveruPara();
        }

        #endregion Constructors

    }
}
