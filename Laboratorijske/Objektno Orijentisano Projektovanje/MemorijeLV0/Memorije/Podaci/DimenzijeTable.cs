using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Xml.Serialization;

namespace Podaci
{
    [Serializable]
    public class DimenzijeTable
    {
        int vrste;
        int kolone;
        int parovi;
        int razliciteSlike;

        #region Constructors
        public DimenzijeTable()
        {
            vrste = 6;
            kolone = 5;
            parovi = 7;
            razliciteSlike = 5;
        }
        public DimenzijeTable(DimenzijeTable dt)
        {
            vrste = dt.Vrste;
            kolone = dt.Kolone;
            parovi = dt.Parovi;
            razliciteSlike = dt.RazliciteSlike;
        }
        public DimenzijeTable(int vrste, int kolone, int parovi, int razliciteSlike)
        {
            Vrste = vrste;
            Kolone = kolone;
            Parovi = parovi;
            RazliciteSlike = razliciteSlike;
        }

        #endregion Constructors

        #region Attributes

        [XmlElementAttribute("Vrste")]

        public int Vrste
        {
            get { return vrste; }
            set { vrste = value; }
        }

        [XmlElementAttribute("Kolone")]


        public int Kolone
        { 
            get { return kolone; }
            set { kolone = value; }
        }

        [XmlElementAttribute("Parovi")]

        public int Parovi
        {
            get { return parovi; }
            set { parovi = value; }
        }

        [XmlElementAttribute("RazliciteSlike")]

        public int RazliciteSlike
        {
            get { return razliciteSlike; }
            set {  razliciteSlike = value; }
        }

        #endregion Attributes
    }
}
