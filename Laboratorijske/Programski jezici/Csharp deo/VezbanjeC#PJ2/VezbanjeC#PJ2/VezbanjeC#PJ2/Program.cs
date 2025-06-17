namespace VezbanjeC_PJ2
{
    internal class Program
    {
        static void Main(string[] args)
        {
            //BotanickaBasta botanickaBasta = new BotanickaBasta("Bastica", 100, 30);

            //SaksijskaBiljka sk1 = new SaksijskaBiljka("Saksija1", true, 10, 2, 200);
            //SaksijskaBiljka sk2 = new SaksijskaBiljka("Saksija2", false, 13, 4, 150);
            //SaksijskaBiljka sk3 = new SaksijskaBiljka("Saksija3", false, 12, 7, 100);

            //StablastaBiljka st1 = new StablastaBiljka("Stablasta1", false, 14, new DateTime(2024, 5, 13));
            //StablastaBiljka st2 = new StablastaBiljka("Stablasta2", false, 12, new DateTime(2026, 5, 13));
            //StablastaBiljka st3 = new StablastaBiljka("Stablasta3", true, 9, new DateTime(2025, 5, 13));

            //botanickaBasta.Dodaj(sk1);
            //botanickaBasta.Dodaj(sk2);
            //botanickaBasta.Dodaj(sk3);

            //botanickaBasta.Dodaj(st1);
            //botanickaBasta.Dodaj(st2);
            //botanickaBasta.Dodaj(st3);

            //botanickaBasta.Ispisi("biljkeSve2.bin");

            //BotanickaBasta botanickaBasta2 = new BotanickaBasta();

            //botanickaBasta2.Citaj("biljkeSve2.bin");

            //botanickaBasta2.IzbaciVisakBiljaka();
            //botanickaBasta2.SortirajPoVodi();
            //botanickaBasta2.proveriRaspored();

            //botanickaBasta2.Ispisi("drugaBasta2.txt");

            Restoran kebaKraba = new Restoran("Keba");

            Stavka pljeksa = new Jelo("pljeska", new DateTime(2024, 6, 1), false, 100, Kvalitet.Odlican);
            Stavka pomfrit = new Jelo("pomfrit", new DateTime(2024, 5, 16), false, 80, Kvalitet.Dobar);
            Stavka pizza = new Jelo("pizza", new DateTime(2024, 3, 1), false, 70, Kvalitet.Odlican);
            Stavka pasta = new Jelo("pasta", new DateTime(2024, 4, 1), false, 60, Kvalitet.Dobar);


            Stavka kola = new Pice("Kola", new DateTime(2024, 7, 1), false, 3, 50, true);
            Stavka fanta = new Pice("Fanta", new DateTime(2024, 2, 10), true, 2, 90, true);
            Stavka voda = new Pice("Voda", new DateTime(2024, 8, 8), true, 1, 10, true);
            Stavka jabuka = new Pice("Jabuka", new DateTime(2024, 1, 10), true, 4, 30, false);

            kebaKraba.Dodaj(pljeksa);
            kebaKraba.Dodaj(pomfrit);
            kebaKraba.Dodaj(pizza);
            kebaKraba.Dodaj(kola);
            kebaKraba.Dodaj(fanta);
            kebaKraba.Dodaj(jabuka);
            kebaKraba.Dodaj(voda);
            kebaKraba.Dodaj(pasta);

            kebaKraba.Ispisi("Keba.bin");

            Restoran plankton = new Restoran();

            plankton.Citaj("Keba.bin");

            plankton.izbaciIstekle();
            plankton.SortirajPoCeni();
            plankton.ImaVeganskih();

            plankton.Ispisi("Plankton.txt");




        }
    }
}
