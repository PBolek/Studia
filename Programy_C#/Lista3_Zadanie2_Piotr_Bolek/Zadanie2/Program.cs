//Piotr Bolek Lista 3 Zadanie 2

using System;
using DLL;

namespace Zadanie2
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