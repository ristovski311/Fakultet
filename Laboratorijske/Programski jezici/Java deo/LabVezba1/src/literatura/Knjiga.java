package literatura;

import java.io.*;

public class Knjiga extends Literatura implements Referenca, Comparable<Referenca>
{
	private String naslov;
	
	public Knjiga()
	{
		super();
		this.naslov = null;
	}
	
	public Knjiga(int n, String s)
	{
		super(n);
		this.naslov = s;
	}

	public int vratiGodinuObj() 
	{
		return this.godObj;
	}
	
	public void upisi() 
	{
		String file = new String(String.valueOf(this.godObj));
		file = file.concat(".txt");
		try
		{
			FileWriter fw = new FileWriter(file);
			BufferedWriter bw = new BufferedWriter(fw);
			String[] pom = this.naslov.split(" "); 
			bw.write(pom[0]);
			bw.close();
			
		}
		catch(IOException e)
		{
			System.out.println();
		}
	}
	
	public int compareTo(Referenca o) 
	{
		if(this.godObj < o.vratiGodinuObj())
			return -1;
		else if(this.godObj == o.vratiGodinuObj())
			return 0;
		else
			return 1;
	}
		
}
