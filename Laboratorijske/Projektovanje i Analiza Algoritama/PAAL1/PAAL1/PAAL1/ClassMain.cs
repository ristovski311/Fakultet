﻿using System.Diagnostics;

namespace PAAL1
{

    //Laboratorijska vezba 1 - Ristovski Nikola - Projektovanje i analiza algoritama
    //Broj indeksa: 19347
    //              19347 % 2 = 1 => Zadatak radim pomocu Knuth Moris Pratt algoritma
    //              (1+9+3+4+7[=24]) % 2 = 0 => Radim zadatak 1 tj. Levenstein distancu

    internal class Program
    {
        static void Main(string[] args)
        {
            //                                     ZADATAK 1 - KMP SEARCH


            //Pattern duzine 5 - every

            //Text sa 100 reci
            string Text100 = File.ReadAllText(@"C:\Users\risto\source\repos\PAAL1\PAAL1\bin\Debug\net8.0\AnnaKarenina100.txt");
            Testing.Test("every", Text100);

            ////Text sa 1k reci
            //Testing.Test("every", "AnnaKarenina1k.txt");

            ////Text sa 10k reci
            //Testing.Test("every", "AnnaKarenina10k.txt");

            ////Text sa 100k reci
            //Testing.Test("every", "AnnaKarenina100k.txt");


            // =============================================

            /*
            //Pattern duzine 10 - everything

            //Text sa 100 reci
            Testing.Test("everything", "AnnaKarenina100.txt");

            //Text sa 1k reci
            Testing.Test("everything", "AnnaKarenina1k.txt");

            //Text sa 10k reci
            Testing.Test("everything", "AnnaKarenina10k.txt");

            //Text sa 100k reci
            Testing.Test("everything", "AnnaKarenina100k.txt");

            */

            // =============================================

            //Pattern duzine 20 - then she had refused

            /*
            //Text sa 100 reci
            Testing.Test("then she had refused", "AnnaKarenina100.txt");

            //Text sa 1k reci
            Testing.Test("then she had refused", "AnnaKarenina1k.txt");

            //Text sa 10k reci
            Testing.Test("then she had refused", "AnnaKarenina10k.txt");

            //Text sa 100k reci
            Testing.Test("then she had refused", "AnnaKarenina100k.txt");

            */

            // =============================================

            /*

            //Pattern duzine 50 - But who can have told you so? No one has said that

            //Text sa 100 reci
            Testing.Test("But who can have told you so? No one has said that", "AnnaKarenina100.txt");

            //Text sa 1k reci
            Testing.Test("But who can have told you so? No one has said that", "AnnaKarenina1k.txt");

            //Text sa 10k reci
            Testing.Test("But who can have told you so? No one has said that", "AnnaKarenina10k.txt");

            //Text sa 100k reci
            Testing.Test("But who can have told you so? No one has said that", "AnnaKarenina100k.txt");

            */



            // ==============================================



            //                                            LEVENSTEIN

            //Pattern duzine oko 5.

            //Levenstein.LevenstenDistance("butter", "AnnaKarenina100.txt");
            //Levenstein.LevenstenDistance("butter", "AnnaKarenina1k.txt");
            //Levenstein.LevenstenDistance("butter", "AnnaKarenina10k.txt");
            //Levenstein.LevenstenDistance("butter", "AnnaKarenina100k.txt");


            //Pattern duzine oko 10.

            //Levenstein.LevenstenDistance("reconnection", "AnnaKarenina100.txt");
            //Levenstein.LevenstenDistance("reconnection", "AnnaKarenina1k.txt");
            //Levenstein.LevenstenDistance("reconnection", "AnnaKarenina10k.txt");
            //Levenstein.LevenstenDistance("reconnection", "AnnaKarenina100k.txt");


            //Pattern duzine oko 20.  Najduza rec u ovoj knjizi koju sam pronasao je misunderstanding sa 16 slova.

            //Levenstein.LevenstenDistance("misunderstanding", "AnnaKarenina100.txt");
            //Levenstein.LevenstenDistance("misunderstanding", "AnnaKarenina1k.txt");
            //Levenstein.LevenstenDistance("misunderstanding", "AnnaKarenina10k.txt");
            //Levenstein.LevenstenDistance("misunderstanding", "AnnaKarenina100k.txt");
        }
    }
}
