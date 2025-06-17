package domacinstvo;

import java.io.*;
import java.util.*;
import halucinacije.*;
import funghi.*;

public class Zamrzivac {

	private ArrayList<Pecurka> brdoPecuraka = new ArrayList<Pecurka>();
	
	public void ubaciPecurku(Pecurka p)
	{
		this.brdoPecuraka.add(p);
		System.out.println("Upravo dodata u brdo pecuraka nova pecurka tipa: " + p.getTip() + " nivoa psilo: " + p.nivoPsilocibina() + " i ona je:  " + p.getDomaca());
	}
	
	public void klasirajPecurke() throws Zmajevi
	{
		this.brdoPecuraka.sort(null);
		
		try
		{
			if(this.brdoPecuraka.get(this.brdoPecuraka.size()-1).nivoPsilocibina() > 8)
				throw new Zmajevi("Psilo je prejak");
			FileWriter fr = new FileWriter("najjaca.txt");
			BufferedWriter br = new BufferedWriter(fr);
			br.write(this.brdoPecuraka.get(this.brdoPecuraka.size()-1).getTip()); 
			System.out.println("\nAzurirana datoteka najjace pecurke: " + this.brdoPecuraka.get(this.brdoPecuraka.size()-1).getTip() + " nivoa psilocibina: " + this.brdoPecuraka.get(this.brdoPecuraka.size()-1).nivoPsilocibina() + "\n");
			//Ovde kaze upisuje ime najjace pecurke, nije u
			//zadatku navedeno da pecurka ima ime kao atribut pa sam stavio
			//njen tip u datoteku, ako treba ime isti postupak samo jos jedan
			//string kao atribut u klasi pecurka dodamo
			br.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
		
		try
		{
			FileOutputStream fos = new FileOutputStream("najslabija.txt");
			BufferedOutputStream bos = new BufferedOutputStream(fos);
			DataOutputStream dos = new DataOutputStream(bos);
			dos.writeInt(this.brdoPecuraka.get(0).nivoPsilocibina());
			System.out.println("\nAzurirana datoteka najslabije pecurke: " + this.brdoPecuraka.get(0).getTip() + " nivoa psilocibina: " + this.brdoPecuraka.get(0).nivoPsilocibina());
			//Svakim pozivom metode za nivo psilo. poziva se random pa uvek ima drugaciju vrednost pecurka koja nije pobrljavka ili bunika,
			//pa moze da se desi da u trenutku sortiranja ona ima najmanju vrednost pa je prva u listi, a kad joj pristupam da bih je
			//ispisao na ekran ili da je sortiram moze da joj se promeni taj broj da bude veci ili manji (to je malo zbunjujuce u konzoli), 
			//moze da se resi da se doda jedan int atribut nivoPsilo u pecurci i da prvi
			//poziv metode nivo odredi taj nivo i na osnovu njega posle sortiram itd.
			dos.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
		
	}
	
	
	
		
}
