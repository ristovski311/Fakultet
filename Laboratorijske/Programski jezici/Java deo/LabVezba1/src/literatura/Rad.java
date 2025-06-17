package literatura;

import java.io.*;

public class Rad extends Literatura implements Referenca, Comparable<Referenca>
{
	private int ISBN;
	
	public Rad()
	{
		super();
		this.ISBN = 0;
	}
	
	public Rad(int n, int isbn)
	{
		super(n);
		this.ISBN = isbn;
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
			String lastDigit = String.valueOf(this.ISBN%10);
			bw.write(lastDigit);
			bw.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
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

