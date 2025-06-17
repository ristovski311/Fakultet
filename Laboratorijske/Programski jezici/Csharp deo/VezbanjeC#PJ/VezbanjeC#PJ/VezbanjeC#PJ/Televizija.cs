using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace VezbanjeC_PJ
{
    internal class Televizija
    {
        string naziv;
        double novacKojimRaspolazeZa7Dana;
        List<Emisija> listaEmisija;
        
        public Televizija()
        {
            naziv = "";
            novacKojimRaspolazeZa7Dana = 0;
            listaEmisija = new List<Emisija>();
        }

        public Televizija(string naziv, double novacKojimRaspolazeZa7Dana, List<Emisija> listaEmisija)
        {
            this.naziv = naziv;
            this.novacKojimRaspolazeZa7Dana = novacKojimRaspolazeZa7Dana;
            this.listaEmisija = listaEmisija;
        }

        public Televizija(string naziv, double novacKojimRaspolazeZa7Dana)
        {
            this.naziv = naziv;
            this.novacKojimRaspolazeZa7Dana = novacKojimRaspolazeZa7Dana;
            this.listaEmisija = new List<Emisija>();
        }

        public void DodajEmisiju(Emisija e)
        {
            if (!listaEmisija.Contains(e))
                listaEmisija.Add(e);
            else
                return;
        }

        public void ObrisiEmisiju(Emisija e)
        {
            if (listaEmisija.Contains(e))
                listaEmisija.Remove(e);
            else
                return;
        }

        public double CenaSvihEmisija
        {
            get
            {
                double res = 0;
                foreach (Emisija e in listaEmisija)
                    res += e.cenaEmisije();
                return res;
            }
        }

        public void IzbaciEmisijePoGledanosti(string fajl)
        {
            while(CenaSvihEmisija > novacKojimRaspolazeZa7Dana)
            {
                Emisija zaIzbacivanje = PronadjiNajmanjuGledanost();
                listaEmisija.Remove(zaIzbacivanje);
                IspisiEmisiju(zaIzbacivanje, fajl);
            }
        }

        public Emisija PronadjiNajmanjuGledanost()
        {
            Emisija ret = listaEmisija[0];
            for(int i = 1; i<listaEmisija.Count; i++)
            {
                if(ret.Gledanost > listaEmisija[i].Gledanost)
                    ret = listaEmisija[i];
            }
            return ret;
        }

        public void IspisiEmisiju(Emisija e, string fajl)
        {
            using(StreamWriter sw = new StreamWriter(fajl, true))
            {
                e.Ispisi(sw);
            }
        }

        public void SortirajPoDanima()
        {
            listaEmisija.Sort();
        }

        public void proveriRaspored()
        {
            for(int i = 0; i < 7; i++)
            {
                bool nadjen = false;
                foreach(Emisija e in listaEmisija)
                    if(e.DanPrikazivanja == (Dani)i)
                        nadjen = true;
                if (!nadjen)
                    throw new PogresanRaspored("Raspored je jako pogresan!");
            }
        }

        public void IspisiSortirano(string file)
        {
            foreach (Emisija e in listaEmisija)
                IspisiEmisiju(e, file);
        }


    }
}
