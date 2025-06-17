using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace PAAL1
{
    public static class MakeARandomFile
    {

        public static void MakeHexFile(string path, int numOfWords)
        {
            int currNumOfWords = 0;
            Random random = new Random(DateTime.Now.Microsecond);
            String text = "";

            while (currNumOfWords < numOfWords)
            {
                int generatedNum = random.Next(0, 17);
                if (generatedNum == 16)
                {
                    if (text.Length == 0)
                        text = text + "1";
                    else
                    {
                        text = text + " ";
                        currNumOfWords++;
                    }
                }
                else
                {
                    text = text + generatedNum.ToString("X");
                }

            }

            File.WriteAllText(path, text);

        }


        public static void MakeASCIIFile(string path, int numOfWords)
        {
            int currNumOfWords = 0;
            Random random = new Random(DateTime.Now.Microsecond);
            String text = "";

            while (currNumOfWords < numOfWords)
            {
                int generatedNum = random.Next(0, 128);
                if (generatedNum == 32)
                    currNumOfWords++;

                char character = (char)generatedNum;

                text = text + character.ToString();

            }

            File.WriteAllText(path, text);
        }

    }
}
