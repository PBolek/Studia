//Lista 3 Zadanie 4 Piotr Bolek

using System;

public class List<T>{
	public List<T> next;
	protected T val;
	public void Add(T val){
		if(this.next != null)
			this.next.Add(val);
		else{
			this.next = new List<T>();
			this.next.val = val;
		}
	}
	public T Top(){
		return this.val;
	}
}

public class punkt{
	public float x;
	public float y;
}

public class Wektor : punkt{
	protected float w1;
	protected float w2;
	public Wektor(punkt A, punkt B){
		w1 = B.x - A.x;
		w2 = B.y - A.y;
	}
	
	public Wektor(){
	}
	
	public Wektor dodaj_wektory(Wektor A, Wektor B){
		Wektor wynik = new Wektor();
		wynik.w1 = A.w1 + B.w1;
		wynik.w2 = A.w2 + B.w2;
		return wynik;
	}
	
	public float iloczyn_skalarny(Wektor A, Wektor B){
		Wektor wynik = new Wektor();
		wynik.w1 = A.w1 * B.w1;
		wynik.w2 = A.w2 * B.w2;
		float iloczyn = wynik.w1 + wynik.w2;
		return iloczyn;
	}
	
	public Wektor iloczyn_przez_liczbe(Wektor A, float liczba){
		Wektor wynik = new Wektor();
		wynik.w1 = A.w1 * liczba;
		wynik.w2 = A.w2 * liczba;
		return wynik;
	}
}

public class Macierz : Wektor{
	private int n = 0;
	protected Wektor[] wektory;
	public Macierz(){
		wektory = new Wektor[0];
	}
	
	public Macierz(int size_of_tab){
		wektory = new Wektor[size_of_tab];
	}
	
	public void add_m(Wektor A){
		wektory[n] = A;
		this.n++;
	}
}

namespace Lista3_Zadanie4_Piotr_Bolek
{
	class Program
	{
		public static void Main(string[] args)
		{
			
			// TODO: Implement Functionality Here
			
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
	}
}