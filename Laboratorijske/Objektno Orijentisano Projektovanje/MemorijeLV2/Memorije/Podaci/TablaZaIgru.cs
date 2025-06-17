using System;
using System.Collections.Generic;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Podaci
{
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

        public int N { get { return n; } }
        public int M { get { return m; } }

        public int PronadjeniParovi {  get { return pronadjeniParovi; } }
        public int Parovi { get { return parovi; } }


        public void OtvoriPolje(object sender, EventArgs e)
        {
            ((Polje)sender).OtvoriPolje();
        }

        public async void CheckPairing(object sender, EventArgs e)
        {
            await Task.Delay(700);

            if (selectedButtons == 0)
            {
                selectedButtons++;
                prevSelectedButton = (Polje)sender;
            }
            else if (selectedButtons == 1)
            {
                if (prevSelectedButton == null)
                {
                    selectedButtons = 0;
                    return;
                }
                if (prevSelectedButton == (Polje)sender)
                    return;

                await Task.Delay(500);
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
            }
        }

        public void OpenAllButtons()
        {
            foreach(List<Polje> lp in polja)
            {
                foreach(Polje p in lp)
                {
                    p.Enabled = false;
                    p.Image = Image.FromFile(p.Picture);
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

            int postavljeniParovi = 0;
            while(postavljeniParovi < parovi)
            {
                string slika = "C:\\Users\\risto\\source\\repos\\Memorije\\Slike\\" + postavljeniParovi%razliciteSlike + ".png";

                for (int i = 0; i < 2; i++)
                {
                    bool pogodak = false;
                    while (!pogodak)
                    {
                        random = new Random();
                        int posx = random.Next(0, n*n);
                        int posy = random.Next(0, m*m);
                        if (polja[posx%n][posy%m].Picture == null)
                        {
                            polja[posx%n][posy%m].Picture = slika;
                            pogodak = true;
                        }
                    }
                }
                postavljeniParovi++;
            }
        }

        public List<List<Polje>> Polja
        {
            get {  return polja; }
        }



    }
}
