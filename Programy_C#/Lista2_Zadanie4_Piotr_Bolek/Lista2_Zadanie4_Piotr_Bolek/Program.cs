//Piotr Bolek Lista 2 Zadanie 4

using System;
using System.Collections.Generic;

class ListaLeniwa{
	List<int> lista = new List<int>();
	Random rnd = new Random();
	private int rozmiar = 0;
	private int dodaj = 0;
	virtual public int element(int i){
		if(this.rozmiar == 0){
			for(int a = 0; a <= i; a++){
				lista.Add(rnd.Next(0, 2147483647));
			}
		}
		else if(this.rozmiar >= i){
			return lista[i];
		}
		else{
			this.dodaj = i - this.rozmiar;
			for(int a = 0; a < this.dodaj; a++){
				lista.Add(rnd.Next(0, 2147483647));
			}
		}
		this.rozmiar = i;
		int element = lista[i];
		return element;
	}
	virtual public int size(){
		int size = lista.Count;
		return size;
	}
}

class Pierwsze : ListaLeniwa{
	private List<int> prime_list = new List<int>();
	private int rozmiar = 0;
	private int liczba = 2;
	private int dodaj = 0;
	private bool is_prime(int a){
		int licznik = 0;
		if(a == 0 || a == 1)
			return false;
		for(int i = 2; i <= a; i++){
			if(a%i == 0)
				licznik++;
		}
		if(licznik != 1)
			return false;
		return true;
	}
	override public int element (int i){
		int licznik2 = 0;
		if(this.rozmiar == 0){
			while(this.rozmiar != i){
				if(is_prime(this.liczba) == true){
					prime_list.Add(this.liczba);
					this.rozmiar++;
				}
				this.liczba++;
			}
		}
		else if(rozmiar >= i){
			return prime_list[i-1];
		}
		else{
			this.dodaj = i - this.rozmiar;
			while(licznik2 != this.dodaj){
				if(is_prime(this.liczba) == true){
					prime_list.Add(this.liczba);
					licznik2++;
					this.rozmiar++;
				}
				this.liczba++;
			}
		}
		return prime_list[i-1];
	}
	override public int size(){
		int size = prime_list.Count;
		return size;
	}
}
	
namespace Lista2_Zadanie4_Piotr_Bolek
{
	class Program
	{
		public static void Main(string[] args)
		{	
			// TODO: Implement Functionality Here
			ListaLeniwa lista = new ListaLeniwa();
			Pierwsze prime_list = new Pierwsze();
			Console.WriteLine("1 - lista.element(int i)");
			Console.WriteLine("2 - lista.size()");
			Console.WriteLine("3 - prime_list.element(int i)");
			Console.WriteLine("4 - prime_list.size()");
			Console.WriteLine("5 - exit");
			int i = 0;
			int command = Console.Read();
			while(command != 53){
				if(command == 49){
					Console.ReadLine();
					Int32.TryParse(Console.ReadLine(), out i);
					Console.WriteLine("lista.element({0}) = {1}", i, lista.element(i));
				}
				else if(command == 50){
					Int32.TryParse(Console.ReadLine(), out i);
					Console.WriteLine("lista.size() = {0}", lista.size());
				}
				else if(command == 51){
					Console.ReadLine();
					Int32.TryParse(Console.ReadLine(), out i);
					Console.WriteLine("prime_list.element({0}) = {1}", i, prime_list.element(i));
				}
				else if(command == 52){
					Int32.TryParse(Console.ReadLine(), out i);
					Console.WriteLine("prime_list.size() = {0}", prime_list.size());
				}
				command = Console.Read();
			}
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
	}
}