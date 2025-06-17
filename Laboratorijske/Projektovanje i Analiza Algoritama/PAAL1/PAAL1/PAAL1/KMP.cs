using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAAL1
{
    public static class KMP
    {
        public static int[] LPSFunction(string pattern)
        {
            //Slucaj ako je pattern prazan.
            if (String.IsNullOrEmpty(pattern))
                return new int[0];

            //Nasa funkcija prefiksa i sufiksa.
            int[] fun = new int[pattern.Length];

            //Prvi clan lps funkcije je uvek 0, string od 1 karaktera nema pravi prefiks.
            fun[0] = 0;

            int k = 0; //Brojac duzine trenutnog najduzeg pravog prefiksa.

            for (int q = 1; q < pattern.Length; q++)
            {
                if (pattern[q] == pattern[k])
                {
                    fun[q] = k + 1;
                    k++;
                }
                else if (k > 0)
                {
                    k = fun[k - 1];
                }
                else
                {
                    fun[q] = 0;
                }
            }

            return fun;
        }

        public static void KMPSearch(string pattern, string Text)
        {
            if (String.IsNullOrEmpty(pattern) || pattern.Length == 1 || String.IsNullOrEmpty(Text) || Text.Length < pattern.Length)
            {
                Console.WriteLine("Uneti pattern mora imati bar 2 slova. Text mora biti bar jednake duzine kao pattern!");
                return;
            }

            int[] LPSFunction = KMP.LPSFunction(pattern);

            int pointerInText = 0;
            int pointerInPattern = 0;

            while (pointerInText < Text.Length)
            {
                if (pattern[pointerInPattern] == Text[pointerInText])
                {
                    pointerInText++;
                    pointerInPattern++;
                }
                else
                {
                    pointerInPattern = (pointerInPattern > 0) ? LPSFunction[pointerInPattern - 1] : 0;
                    if (pointerInPattern == 0) pointerInText++;
                }

                //Za slucaj da smo pronasli uspesno pattern u Textu, prikazacemo ga i njegov indeks.

                if (pointerInPattern == pattern.Length)
                {
                    int indexOfPattern = pointerInText - pattern.Length;
                    Console.WriteLine($"[KMPS] Uneti pattern: {pattern} je pronadjen na indeksu: {indexOfPattern} u tekstu.\n");

                    //Nastavljamo sa pretragom patterna, pokazivac na trenutni indeks u patternu vracamo na pocetak.

                    pointerInPattern = 0;
                }

            }


        }

    }
}