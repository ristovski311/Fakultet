
import funghi.*;
import halucinacije.*;
import domacinstvo.*;

public class Glavna {
	public static void main(String[] args) 
	{
		Zamrzivac ladnjak = new Zamrzivac();
		
		Pecurka bunikaDomaca = new Pecurka("Bunika", true);
		Pecurka bunikaStrana = new Pecurka("Bunika", false);
		Pecurka pobrljavkaDomaca = new Pecurka("Pobrljavka", true);
		Pecurka pobrljavkaStrana = new Pecurka("Pobrljavka", false);
		Pecurka randomDomaca = new Pecurka("Gljiva", true);
		Pecurka randomStrana = new Pecurka("Gljiva", false);
		
		ladnjak.ubaciPecurku(pobrljavkaStrana);
		ladnjak.ubaciPecurku(randomDomaca);
		ladnjak.ubaciPecurku(bunikaStrana);
		ladnjak.ubaciPecurku(bunikaDomaca);
		ladnjak.ubaciPecurku(pobrljavkaDomaca);
		ladnjak.ubaciPecurku(randomStrana);
		
		try
		{
			ladnjak.klasirajPecurke();
		}
		catch(Zmajevi dragon)
		{
			System.out.println(dragon);
		}
	}
}
