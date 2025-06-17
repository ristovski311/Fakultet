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
        List<List<Polje>> polja;
        List<PoljeZaSerijalizacijuLista> poljaZaSerijalizaciju;
        DimenzijeTable dimenzija;
        int pronadjeniParovi;
        int potrebnoPronaciParova;
        public static int selectedButtons = 0;
        Polje prevSelectedButton = null;


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

        [XmlArray("Polja")]
        [XmlArrayItem("Red", typeof(List<PoljeZaSerijalizaciju>))]
        public List<PoljeZaSerijalizacijuLista> PoljaZaSerijalizaciju
        {
            get { return poljaZaSerijalizaciju; }
            set { poljaZaSerijalizaciju = value; }
        }

        public void OtvoriPolje(object sender, EventArgs e)
        {
            ((Polje)sender).OtvoriPolje();
        }

        public List<Polje> DisableButtonsTemp(Polje p)
        {
            List<Polje> res = new List<Polje>();
            foreach(List<Polje> lp in polja)
            {
                foreach(Polje polje in lp)
                {
                    if(polje.Enabled && polje != p && polje != prevSelectedButton)
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
            if (prevSelectedButton == (Polje)sender)
                return;
            if (selectedButtons == 0)
            {
                selectedButtons++;
                prevSelectedButton = (Polje)sender;
            }
            else if (selectedButtons == 1)
            {
                List<Polje> disabled = DisableButtonsTemp((Polje)sender);
                if (prevSelectedButton == null)
                {
                    selectedButtons = 0;
                    return;
                }
                if (prevSelectedButton == (Polje)sender)
                    return;

                await Task.Delay(700);
                if (prevSelectedButton.Picture == ((Polje)sender).Picture)
                {
                    selectedButtons = 0;
                    pronadjeniParovi++;
                    prevSelectedButton.Enabled = false;
                    ((Polje)sender).Enabled = false;
                    prevSelectedButton = null;
                }
                else
                {
                    selectedButtons = 0;
                    prevSelectedButton.Image = null;
                    ((Polje)sender).Image = null;
                }
                EnableDisabledTempButtons(disabled);
            }
        }

        public void OpenAllButtons()
        {
            foreach(List<Polje> lp in polja)
            {
                foreach(Polje p in lp)
                {
                    p.Enabled = false;
                    p.OtvoriPolje();
                }
            }
        }

        public TablaZaIgru()
        {
            poljaZaSerijalizaciju = new List<PoljeZaSerijalizacijuLista>();

            dimenzija = new DimenzijeTable();

            potrebnoPronaciParova = dimenzija.Parovi;

            polja = new List<List<Polje>>();

            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                polja.Add(new List<Polje>());
            }
            if(poljaZaSerijalizaciju.Count != 0)
            {
                Deserijalizuj();
            }
            else
            {
                int posx = 0;
                int posy = 0;
                for (int i = 0; i < dimenzija.Vrste; i++)
                {
                    for (int j = 0; j < dimenzija.Kolone; j++)
                    {
                        polja[i].Add(new Polje());
                        polja[i][j].PostaviPoziciju(posx, posy + 23);
                        polja[i][j].TabStop = false;
                        polja[i][j].Click += OtvoriPolje;
                        posx += polja[i][j].Width;
                    }
                    posx = 0;
                    posy += polja[0][0].Height;
                }
                PostaviSlikePoljima();
            }
            foreach (List<Polje> lp in polja)
            {
                foreach (Polje p in lp)
                {
                    if (p.Picture != null)
                        p.Click += CheckPairing;
                }
            }
        }

        public TablaZaIgru(DimenzijeTable dt)
        {
            poljaZaSerijalizaciju = new List<PoljeZaSerijalizacijuLista>();

            dimenzija = dt;

            potrebnoPronaciParova = dt.Parovi;

            polja = new List<List<Polje>>();

            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                polja.Add(new List<Polje>());
            }
            if (poljaZaSerijalizaciju.Count != 0)
            {
                Deserijalizuj();
            }
            else
            {
                int posx = 0;
                int posy = 0;
                for (int i = 0; i < dimenzija.Vrste; i++)
                {
                    for (int j = 0; j < dimenzija.Kolone; j++)
                    {
                        polja[i].Add(new Polje());
                        polja[i][j].PostaviPoziciju(posx, posy + 23);
                        polja[i][j].TabStop = false;
                        polja[i][j].Click += OtvoriPolje;
                        posx += polja[i][j].Width;
                    }
                    posx = 0;
                    posy += polja[0][0].Height;
                }
                PostaviSlikePoljima();
            }
            
            foreach (List<Polje> lp in polja)
            {
                foreach (Polje p in lp)
                {
                    if (p.Picture != null)
                        p.Click += CheckPairing;
                }
            }


        }

        public TablaZaIgru(int n, int m, int parovi, int razliciteSlike)
        {
            dimenzija = new DimenzijeTable(n,m,parovi,razliciteSlike);

            potrebnoPronaciParova = dimenzija.Parovi;


            polja = new List<List<Polje>>();


            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                polja.Add(new List<Polje>());
            }
            int posx = 0;
            int posy = 0;
            for (int i = 0; i < dimenzija.Vrste; i++)
            {
                for (int j = 0; j < dimenzija.Kolone; j++)
                {
                    polja[i].Add(new Polje());
                    polja[i][j].PostaviPoziciju(posx, posy + 23);
                    polja[i][j].TabStop = false;
                    polja[i][j].Click += OtvoriPolje;
                    posx += polja[i][j].Width;
                }
                posx = 0;
                posy += polja[0][0].Height;
            }

            PostaviSlikePoljima();

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
            while(postavljeniParovi < potrebnoPronaciParova)
            {
                string slika = "C:\\Users\\risto\\source\\repos\\Memorije\\Slike\\" + postavljeniParovi%dimenzija.RazliciteSlike + ".png";
                for (int i = 0; i < 2; i++)
                {
                    //Logika za generisanje singlova
                    random = new Random();
                    int broj = random.Next(0, 100);
                    if (i == 1 && broj % 3 == 0 && postavljeniParovi/dimenzija.RazliciteSlike == 0)
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
            poljaZaSerijalizaciju = new List<PoljeZaSerijalizacijuLista>();
            int row = 0;
            foreach(List<Polje> lp in polja)
            {
                PoljeZaSerijalizacijuLista lista = new PoljeZaSerijalizacijuLista();
                foreach(Polje polje in lp)
                {
                    PoljeZaSerijalizaciju pzs = new PoljeZaSerijalizaciju(polje);
                    lista.Dodaj(pzs);
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
            foreach (PoljeZaSerijalizacijuLista lp in poljaZaSerijalizaciju)
            {
                List<Polje> lista = new List<Polje>();
                foreach (PoljeZaSerijalizaciju pzs in lp.ListaPolja)
                {
                    Polje p = new Polje(pzs);
                    polja[row].Add(p);
                }
                polja.Add(lista);
                row++;
            }
        }

    }
}
