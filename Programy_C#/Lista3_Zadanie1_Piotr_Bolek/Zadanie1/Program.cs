//Piotr Bolek Lista3 Zadanie 1

using System;
using DLL;

namespace Zadanie1
{
	class Program
	{
		public static void Main(string[] args)
		{	
			// TODO: Implement Functionality Here
			string a = "1";
			string b = "0";
			int val = 0;
			Lista<int> list = new Lista<int>();
			while(a != "0"){
				Console.WriteLine();
				Console.WriteLine("1 - Dodaj element na koniec listy");
				Console.WriteLine("2 - Dodaj element na poczatek listy");
				Console.WriteLine("3 - Usun element z poczatku listy");
				Console.WriteLine("4 - Usun element z konca listy");
				Console.WriteLine("0 - Zakoncz dzialanie programu");
				a = Console.ReadLine();
				if(a == "1"){
					Console.WriteLine("Podaj element ktory chcesz dodac");
					b = Console.ReadLine();
					val = Int32.Parse(b);
					list.add_top(val);
				}
				else if(a == "2"){
					Console.WriteLine("Podaj element ktory chcesz dodac");
					b = Console.ReadLine();
					val = Int32.Parse(b);
					list.add_begin(val);
				}
				else if(a == "3"){
					try{
						Console.WriteLine("Usunieto: {0}", list.delete_begin());
					}
					catch(ArgumentException){
						Console.WriteLine("Lista jest pusta");
					}
				}
				else if(a == "4"){
					try{
						Console.WriteLine("Usunieto: {0}", list.delete_top());
					}
					catch(ArgumentException){
						Console.WriteLine("Lista jest pusta");
					}
				}
			}
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
	}
}