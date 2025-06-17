using System;
using System.Collections.Generic;
using System.ComponentModel.DataAnnotations.Schema;
using System.Linq;
using System.Security.Principal;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;
using static System.Net.Mime.MediaTypeNames;

namespace PAAL1
{
    public static class Levenstein
    {
        public static void FindWord(int length, int k, string path)
        {
            string Text = File.ReadAllText(path);
            string[] WordsFromText = Regex.Matches(Text, @"\b\w+\b")
                     .OfType<Match>()
                     .Select(m => m.Value)
                     .ToArray();
            foreach(string m in WordsFromText)
            {
                if(m.Length >= length-k && m.Length <= length+k)
                    Console.WriteLine(m + "  " + m.Length);
            }
        }

        public static void CountWords(string path)
        {
            string Text = File.ReadAllText(path);
            string[] WordsFromText = Regex.Matches(Text, @"\b\w+\b")
                     .OfType<Match>()
                     .Select(m => m.Value)
                     .ToArray();
            int words = 0;
            foreach (string m in WordsFromText)
            {
                words++;
            }

            Console.WriteLine(words);
        }




        public static void LevenstenDistance(string pattern, string path)
        {
            string Text = File.ReadAllText(path);

            //Pokusao sam da koristim split funkciju, ali uvek se dogodi neki bug pa mi ne isece reci kako treba, ostane poneki " ili '.

            //string[] WordsFromText = Text.Split(new char[] { ' ', '.', ',', ';', ':', '\"', '\'' , '`', '-', '(', ')', '?', '!', '\"'}, StringSplitOptions.RemoveEmptyEntries); ;

            //Zato sam pronasao ovaj nacin, on izdeli text na sve reci kako i treba.

            string[] WordsFromText = Regex.Matches(Text, @"\b\w+\b")
                     .OfType<Match>()
                     .Select(m => m.Value)
                     .ToArray();

            foreach (string word in WordsFromText)
            {
                int[,] LDMatrix = new int[pattern.Length, word.Length];

                int Price = 0;

                for(int i = 0; i <  LDMatrix.GetLength(0); i++)
                {
                    LDMatrix[i, 0] = i;
                }

                for (int j = 0; j < LDMatrix.GetLength(1); j++)
                {
                    LDMatrix[0, j] = j;
                }

                for (int i = 1; i < LDMatrix.GetLength(0); i++)
                {
                    for(int j = 1; j < LDMatrix.GetLength(1); j++)
                    {
                        Price = (pattern[i] == word[j]) ? 0 : 1;
                        LDMatrix[i,j] = int.Min(int.Min(LDMatrix[i-1,j] + 1, LDMatrix[i, j-1] + 1), LDMatrix[i-1,j-1] + Price);
                    }
                }

                //Udaljenost:
                int distance = LDMatrix[pattern.Length - 1, word.Length - 1];

                //Stampanje ako je ispunjen uslov zadatka. Malo sam formatirao stampu da bi se videli rec i pattern sa strana matrice.

                if (distance > 0 && distance < (0.2 * pattern.Length))
                {
                    Console.WriteLine($"\nWord : {word} | pattern : {pattern} | distance : {distance}");
                    for (int i = -1; i < LDMatrix.GetLength(0); i++)
                    {
                        Console.Write("| ");
                        if (i == -1)
                        {
                            Console.Write("  ");
                            for(int j = 0; j < LDMatrix.GetLength(1); j++)
                            {
                                Console.Write($" {word[j]} ");
                            }
                        }
                        else
                        {
                            for (int j = -1; j < LDMatrix.GetLength(1); j++)
                            {
                                if(j == -1)
                                    Console.Write($"{pattern[i]} ");
                                else
                                    Console.Write($" {LDMatrix[i, j]} ");
                            }
                        }
                        Console.Write("  |\n");
                    }
                }
            }

        }
    }
}
