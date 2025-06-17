using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Podaci
{
    public class ListaVozaca
    {
        List<Vozac> vozaci;

        public delegate void SortDel();

        public SortDel SortingDel
        {
            get;
            set;
        }

        public void ClearSort()
        {
            SortingDel = null;
        }

        public void Sort()
        {
            if (this.SortingDel == null)
                return;
            SortingDel();
        }
        
        
        private static ListaVozaca instanca = null;

        public static ListaVozaca Instanca
        {
            get
            {
                if (instanca == null)
                    instanca = new ListaVozaca();

                return instanca;
            }
        }

        private ListaVozaca()
        {
            vozaci = new List<Vozac>();
        }
        private ListaVozaca(List<Vozac> vozaci)
        {
            this.vozaci = vozaci;
        }
        private ListaVozaca(ListaVozaca lv)
        {
            this.vozaci = lv.vozaci;
        }

        public List<Vozac> ListaVozacaValue { get { return vozaci; } }

        public bool DodajVozaca(Vozac voz)
        {
            if (voz == null)
                return false;
            foreach (Vozac v in vozaci)
            {
                if (v.BrojDozvole == voz.BrojDozvole)
                    return false;
            }
            vozaci.Add(voz);
            return true;
        }

        public bool ObrisiVozaca(Vozac voz)
        {
            if (voz == null)
                return false;
            foreach (Vozac v in vozaci)
            {
                if (v.BrojDozvole == voz.BrojDozvole)
                {
                    vozaci.Remove(v);
                    return true;
                }
            }
            return false;
        }

        public bool ZameniVozaca(Vozac voz)
        {
            if (voz == null)
                return false;
            foreach (Vozac v in vozaci)
            {
                if (v.BrojDozvole == voz.BrojDozvole)
                {
                    v.Zameni(voz);
                    return true;
                }
            }
            return false;

        }
        
    }
}
