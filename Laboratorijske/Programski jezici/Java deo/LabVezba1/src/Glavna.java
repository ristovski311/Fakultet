import izuzeci.*;
import literatura.*;
import java.io.*;

public class Glavna 
{
	public static void main(String[] args) 
	{
		Biblioteka<Referenca> b1 = new Biblioteka<Referenca>();
		Referenca r1, r2, r3, r4, r5, r6;
		
		r1 = new Knjiga(2001, "The bridge on the Drina");
		r2 = new Knjiga(2009, "Anna Karenina");
		r3 = new Rad(1666, 1974289);
		r4 = new Knjiga(2017, "Ex Ponto");
		r5 = new Rad(1740, 7326523);
		
		b1.staviNaPolicu(r1);
		b1.staviNaPolicu(r2);
		b1.staviNaPolicu(r3);
		b1.staviNaPolicu(r4);
		b1.staviNaPolicu(r5);
		
		int godinaKorisnik = 2024;
		String naslovKorisnik = "Ris papira";
		try
		{
			InputStreamReader fis = new InputStreamReader(System.in);
			BufferedReader br = new BufferedReader(fis);
			String pom;
			System.out.println("Unesite godinu izdanja zeljene knjige: ");
			pom = br.readLine();
			godinaKorisnik = Integer.valueOf(pom);
			if(godinaKorisnik == 0)
				throw new Bozic("Godina broj 0 ne postoji...");
			System.out.println("Unesite naslov knjige: ");
			naslovKorisnik = br.readLine();
			br.close();
		}
		catch(Bozic e)
		{
			System.out.println(e);
		}
		catch(Exception e)
		{
			System.out.println(e);
		}
		finally
		{
			r6 = new Knjiga(godinaKorisnik, naslovKorisnik);
			b1.staviNaPolicu(r6);
		}
		
		b1.urediPolicu();
	}
}
