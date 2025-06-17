using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
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

        public int N { get { return n; } }
        public int M { get { return m; } }

        public TablaZaIgru()
        {
            this.n = 6;
            this.m = 5;
            this.parovi = 7;
            this.razliciteSlike = 5;

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
                    posx += polja[i][j].Width;
                }
                posx = 0;
                posy += polja[0][0].Height;
            }
            PostaviSlikePoljima();
        }


        public TablaZaIgru(int n, int m, int parovi, int razliciteSlike)
        {
            this.n = n;
            this.m = m;
            this.parovi = parovi;
            this.razliciteSlike = razliciteSlike;

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
                    posx += polja[i][j].Width;
                }
                posx = 0;
                posy += polja[0][0].Height;
            }
            PostaviSlikePoljima();
        }

        public void PostaviSlikePoljima()
        {
            Random random = new Random();
            int postavljeniParovi = 0;
            while(postavljeniParovi < parovi)
            {
                int imgNum = random.Next(1, razliciteSlike);
                string slika = "C:\\Users\\risto\\source\\repos\\Memorije\\Slike\\" + imgNum + ".png";

                for (int i = 0; i < 2; i++)
                {
                    int posx = random.Next(0, n - 1);
                    int posy = random.Next(0, m - 1);
                    polja[posx][posy].Picture = slika;
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
