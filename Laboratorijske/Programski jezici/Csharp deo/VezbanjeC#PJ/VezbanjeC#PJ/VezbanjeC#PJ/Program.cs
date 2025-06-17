namespace VezbanjeC_PJ
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Televizija RTS = new Televizija("RTS", 60000);
            Emisija emisijaStudijska1 = new StudijskaEmisija("Emisija Studijska 1", 4, Dani.Thursday, 10000, 20, 100);
            Emisija emisijaStudijska2 = new StudijskaEmisija("Emisija Studijska 2", 6, Dani.Friday, 13000, 15, 150);
            Emisija emisijaStudijska3 = new StudijskaEmisija("Emisija Studijska 3", 9, Dani.Saturday, 20000, 10, 200);

            Emisija serija1 = new Serija("Serija 1", 2, Dani.Thursday, 10, 90000, true);
            Emisija serija2 = new Serija("Serija 2", 8, Dani.Friday, 20, 120000, true);
            Emisija serija3 = new Serija("Serija 3", 4, Dani.Saturday, 50, 500000, false);

            RTS.DodajEmisiju(serija3);
            RTS.DodajEmisiju(emisijaStudijska1);
            RTS.DodajEmisiju(serija1);
            RTS.DodajEmisiju(emisijaStudijska2);
            RTS.DodajEmisiju(emisijaStudijska3);
            RTS.DodajEmisiju(serija2);

            RTS.IzbaciEmisijePoGledanosti("log.txt");
            RTS.SortirajPoDanima();
            RTS.IspisiSortirano("sortirano.txt");
            
            try
            {
                RTS.proveriRaspored();
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }

        }
    }
}
