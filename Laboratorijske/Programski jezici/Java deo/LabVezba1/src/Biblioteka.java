import literatura.*;

import java.io.*;
import java.util.*;

public class Biblioteka <T extends Referenca>
{
	private ArrayList<T> refs = new ArrayList<T>();
	
	public void staviNaPolicu(T r)
	{
		refs.add(r);
	}
	
	public void urediPolicu()
	{
		refs.sort(null);
		refs.get(0).upisi();
		refs.get(refs.size()-1).upisi();
		
		int numOfRefs = refs.size();
		
		try
		{
			FileOutputStream fos = new FileOutputStream("broj.bin");
			BufferedOutputStream bos = new BufferedOutputStream(fos);
			DataOutputStream dos = new DataOutputStream(bos);
			dos.writeInt(numOfRefs);
			dos.close();
		}
		catch(IOException e)
		{
			System.out.println(e);
		}
		
	}
}
