//Piotr Bolek Lista 3 Zadanie 2

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
		return this.next.val;
	}
}

public class Pair<K, V> 
	where K : IComparable
{
	public K First { get; set; }
	public V Second { get; set; }
	
	public Pair(){
	}
	
	public Pair(K first, V second){
		this.First = first;
		this.Second  = second;
	}
}

public class Slownik<K, V>
	where K: IComparable
{
	private List<Pair<K, V>> lista = new List<Pair<K, V>>();
	private Pair<K, V> para;
	private Pair<K,V> para2 = new Pair<K, V>();
	public void add(K first, V second){
		para = new Pair<K, V>(first, second);
		lista.Add(para);
	}
	
	public Pair<K, V> search(K key){
		while(this.lista.next != null){
			para2 = this.lista.Top();
			if(para2.First.CompareTo(key) == 0){
				return this.lista.Top();
			}
			this.lista = this.lista.next;
		}
		throw new System.ArgumentException();
	}
	
	public void delete(K key){
		while(this.lista.next != null){
			para2= this.lista.Top();
			if(para2.First.CompareTo(key) == 0){
				this.lista = this.lista.next;
				return;
			}
			this.lista = this.lista.next;
		}
		throw new System.ArgumentException();
	}
}

namespace Lista3_Zadanie2_Piotr_Bolek
{
	class Program
	{
		public static void Main(string[] args)
		{
			
			// TODO: Implement Functionality Here
			
			Slownik<string, int> slownik = new Slownik<string, int>();
			Pair<string, int> pair = new Pair<string, int>();
			string a = "1";
			int val = 0;
			string key = "0";
			while(a != "0"){
				Console.WriteLine();
				Console.WriteLine("1 - Dodaj element do slownika");
				Console.WriteLine("2 - Wyszukaj element w slowniku");
				Console.WriteLine("3 - Usun element ze slownika");
				Console.WriteLine("0 - Zakoncz dzialanie programu");
				a = Console.ReadLine();
				if(a == "1"){
					Console.WriteLine("Podaj wartosc elementu");
					key = Console.ReadLine();
					val = Int32.Parse(key);
					Console.WriteLine("Podaj klucz elementu");
					key = Console.ReadLine();
					slownik.add(key, val);
				}
				else if(a == "2"){
					Console.WriteLine("Podaj klucz szukanego elementu");
					key = Console.ReadLine();
					try{
						pair = new Pair<string, int>(slownik.search(key).First, slownik.search(key).Second);
						Console.WriteLine(pair.Second);
					}
					catch(ArgumentException){
						Console.WriteLine("Nie ma takiego elementu w slowniku");
					}
				}
				else if(a == "3"){
					Console.WriteLine("Podaj klucz elemntu do usuniecia");
					key = Console.ReadLine();
					try{
						slownik.delete(key);
					}
					catch(ArgumentException){
						Console.WriteLine("Nie ma takiego elementu w slowniku");
					}
				}
			}
			
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
	}
}