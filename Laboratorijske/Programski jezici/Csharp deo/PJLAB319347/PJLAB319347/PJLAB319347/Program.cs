namespace PJLAB319347
{
    internal class Program
    {
        static void Main(string[] args)
        {
            Auto auto1 = new AutoSUS("Golf 5", 2004, 9, 185);
            Auto auto2 = new AutoSUS("Peugeot 206", 2005, 4, 197);
            Auto auto3 = new AutoSUS("Skoda Fabia", 2010, 7, 190);

            Auto auto4 = new EAuto("Tesla 3", 2018, 450, 23, new DateTime(2030, 1, 1, 0, 0, 0));
            Auto auto5 = new EAuto("Tesla S", 2018, 700, 30, new DateTime(2026, 10, 15, 19, 30, 0));
            Auto auto6 = new EAuto("Tesla X", 2018, 800, 20, new DateTime(2027, 2, 1, 6, 0, 0));

            TaksiSluzba PrviTaxi = new TaksiSluzba("PrviTaxi", 1000, 20000000);

            PrviTaxi.Dodaj(ref auto5);
            PrviTaxi.Dodaj(ref auto3);
            PrviTaxi.Dodaj(ref auto6);
            PrviTaxi.Dodaj(ref auto4);
            PrviTaxi.Dodaj(ref auto1);
            PrviTaxi.Dodaj(ref auto2);

            PrviTaxi.Upisi("PrviTaxi.txt");


            TaksiSluzba DrugiTaxi = new TaksiSluzba();

            DrugiTaxi.Citaj("PrviTaxi.txt");

            //DrugiTaxi.proveriBaterije();

            try
            {
                DrugiTaxi.proveriBaterije();
            }
            catch(PotencijalnaEksplozija ex)
            {
                Console.WriteLine(ex.Message);
            }

            DrugiTaxi.IzbaciPreskupaVozila();

            DrugiTaxi.SortirajPoGodiniProizvodnje();

            DrugiTaxi.Upisi("DrugiTaxi.txt");
        }
    }
}
