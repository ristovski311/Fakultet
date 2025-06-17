using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Podaci
{
    [Serializable]
    public class PoljeZaSerijalizacijuLista
    {
        List<PoljeZaSerijalizaciju> listaPolja;

        public PoljeZaSerijalizacijuLista(List<PoljeZaSerijalizaciju> listaPolja)
        {
            this.listaPolja = listaPolja;
        }

        public PoljeZaSerijalizacijuLista()
        {
            listaPolja = new List<PoljeZaSerijalizaciju>();
        }

        [XmlArrayItem("Button")]
        public List<PoljeZaSerijalizaciju> ListaPolja
        {
            get { return listaPolja; }
            set { listaPolja = value; }
        }

        public void Dodaj(PoljeZaSerijalizaciju p)
        {
            listaPolja.Add(p);
        }

    }
}
