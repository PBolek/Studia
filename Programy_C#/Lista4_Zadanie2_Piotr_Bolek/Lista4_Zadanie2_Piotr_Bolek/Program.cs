//Piotr Bolek Lista 4 Zadanie 2

using System;
using System.Collections;

public class PrimeEnumerator : IEnumerator
{
	private int currentItem = 2;
	
	private bool is_prime(int current){
		int counter = 0;
		for(int i = 2; i*i < current; i++){
			if(current % i == 0)
				counter++;
		}
		if(counter == 0)
			return true;
		return false;
	}
	
	private void next_prime(){
		int wynik = currentItem + 1;
		while(is_prime(wynik) != true){
			wynik++;
		}
		currentItem = wynik;
	}
	
	public void Reset(){
		currentItem = 2;
	}
	
	public bool MoveNext(){
		currentItem++;
		next_prime();
		if(currentItem < int.MaxValue)
			return true;
		return false;
	}
	
	public object Current{
		get{return currentItem;}
	}
}

public class PrimeCollection : IEnumerable
{
	public IEnumerator GetEnumerator(){
		return new PrimeEnumerator();
	}
}

namespace Lista4_Zadanie2_Piotr_Bolek
{
	class Program
	{
		public static void Main(string[] args)
		{	
			// TODO: Implement Functionality Here
			
			PrimeCollection pc = new PrimeCollection();
			foreach(int p in pc){
				Console.WriteLine(p);
			}
			
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
	}
}