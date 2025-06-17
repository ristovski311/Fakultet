using PAAL1;

namespace MakeAFile
{
    internal class Program
    {
        static void Main(string[] args)
        {
            MakeARandomFile.MakeASCIIFile("Slova100.txt", 100);
            MakeARandomFile.MakeASCIIFile("Slova1k.txt", 1000);
            //MakeARandomFile.MakeASCIIFile("Slova10k.txt", 10000);
            //MakeARandomFile.MakeASCIIFile("Slova100k.txt", 100000);

            //MakeARandomFile.MakeHexFile("Hex100.txt", 100);
            //MakeARandomFile.MakeHexFile("Hex1k.txt", 1000);
            //MakeARandomFile.MakeHexFile("Hex10k.txt", 10000);
            //MakeARandomFile.MakeHexFile("Hex100k.txt", 100000);
        }
    }
}
