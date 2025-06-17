package funghi;

public class Pecurka implements Comparable<Pecurka> {
	
	private String tip;
	private boolean domaca;
	
	public Pecurka(String tip, boolean domaca)
	{
		this.tip = tip;
		this.domaca = domaca;
		System.out.println("Upravo kreirana pecurka tipa: " + this.tip + " koja je: " + this.getDomaca() + "\n\n");
	}
	
	public int nivoPsilocibina()
	{
		if(this.tip.compareTo("Bunika") == 0)
			return 5;
		else if(this.tip.compareTo("Pobrljavka") == 0)
			return 7;
		else
		{
			int result = (int)(Math.random() * 10);
			if(!domaca)
				result++;
			return result;
		}
	}
	
	public String getTip()
	{
		return this.tip;
	}
	
	public String getDomaca()
	{
		if(this.domaca)
			return "domaca";
		else
			return "strana";
	}

	public int compareTo(Pecurka o) {
		
		if(this.nivoPsilocibina() > o.nivoPsilocibina())
			return 1;
		else if(this.nivoPsilocibina() < o.nivoPsilocibina())
			return -1;
		else
			return 0;
		
	}
	
}
