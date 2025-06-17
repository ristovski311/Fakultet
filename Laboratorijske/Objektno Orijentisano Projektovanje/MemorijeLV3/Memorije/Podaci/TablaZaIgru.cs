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
        int n;
        int m;
        int parovi;
        int razliciteSlike;
        int pronadjeniParovi;
        public static int selectedButtons = 0;
        Polje prevSelectedButton = null;

        [XmlElementAttribute("BrojVrsta")]
        public int N { get { return n; } set { this.n = value; } }

        [XmlElementAttribute("BrojKolona")]
        public int M { get { return m; } set { this.m = value; } }

        [XmlElementAttribute("PronadjeniParovi")]
        public int PronadjeniParovi {  get { return pronadjeniParovi; } set { this.pronadjeniParovi = value; } }

        [XmlElementAttribute("Parovi")]
        public int Parovi { get { return parovi; } set { this.parovi = value; } }

        [XmlArrayItem(("Polja"), typeof(List<Polje>))]
        public List<List<Polje>> Polja
        {
            get { return polja; }
            set {  polja = value; }
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
            this.n = 6;
            this.m = 5;
            this.parovi = 7;
            this.razliciteSlike = 5;
            this.pronadjeniParovi = 0;

            polja = new List<List<Polje>>();

            for (int i = 0; i < n; i++)
            {
                polja.Add(new List<Polje>());
            }
            int posx = 0;
            int posy = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    polja[i].Add(new Polje());
                    polja[i][j].PostaviPoziciju(posx, posy);
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

        public TablaZaIgru(int n, int m, int parovi, int razliciteSlike)
        {
            this.n = n;
            this.m = m;
            this.parovi = parovi;
            this.razliciteSlike = razliciteSlike;
            this.pronadjeniParovi = 0;


            polja = new List<List<Polje>>();


            for (int i = 0; i < n; i++)
            {
                polja.Add(new List<Polje>());
            }
            int posx = 0;
            int posy = 0;
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                {
                    polja[i].Add(new Polje());
                    polja[i][j].PostaviPoziciju(posx, posy);
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
            Random random = new Random();
            int singles = 0;
            int postavljeniParovi = 0;
            while(postavljeniParovi < parovi)
            {
                string slika = "C:\\Users\\risto\\source\\repos\\Memorije\\Slike\\" + postavljeniParovi%razliciteSlike + ".png";
                for (int i = 0; i < 2; i++)
                {
                    //Logika za generisanje singlova
                    random = new Random();
                    int broj = random.Next(0, 100);
                    if (i == 1 && broj % 3 == 0 && postavljeniParovi/razliciteSlike == 0)
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
                            int posx = random.Next(0, n * n);
                            int posy = random.Next(0, m * m);
                            if (polja[posx % n][posy % m].Picture == null)
                            {
                                polja[posx % n][posy % m].Picture = slika;
                                pogodak = true;
                            }
                        }
                    }
                }
                postavljeniParovi++;
            }
            parovi -= singles;
        }
    }
}
