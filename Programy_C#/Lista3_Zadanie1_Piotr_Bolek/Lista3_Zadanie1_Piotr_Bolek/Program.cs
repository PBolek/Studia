//Piotr Bolek Lista 3 Zadnaie 1

using System;

public class List<T>{
	public List<T> next;
	public List<T> prev;
	public T val;
}

public class Lista<T>{
	private int size = 0;
	private List<T> list = new List<T>();
	public void add_top(T element){
		if(size == 0){
			list = new List<T>();
			list.val = element;
			size++;
			return;
		}
		if(list.next == null){
			list.next = new List<T>();
			list.next.prev = list;
			list = list.next;
			list.val = element;
			size++;
			return;
		}
		else
			list = list.next;
	}
	
	public T delete_top(){
		T element = default(T);
		if(size == 0)
			throw new System.ArgumentException();
		if(list.next == null && list.prev == null){
			element = list.val;
			list = null;
			size--;
			return element;
		}
		else if(list.next == null && list.prev != null){
			element = list.val;
			list = list.prev;
			list.next = null;
			size--;
			return element;
		}
		else
			list = list.next;
		return element;
	}
	
	public T delete_begin(){
		T element = default(T);
		Console.WriteLine(element);
		if(size == 0)
			throw new System.ArgumentException();
		if(list.prev == null && list.next == null){
			element = list.val;
			list = null;
			size--;
			return element;
		}
		else if(list.prev == null && list.next != null){
			element = list.val;
			list = list.next;
			list.prev = null;
			size--;
			return element;
		}
		else
			list = list.prev;
		return element;
	}
	
	public void add_begin(T element){
		if(size == 0){
			list = new List<T>();
			list.val = element;
			size++;
			return;
		}
		if(list.prev == null){
			list.prev = new List<T>();
			list.prev.next = list;
			list = list.prev;
			list.val = element;
			size++;
			return;
		}
		else
			list = list.prev;
	}
}

namespace Lista3_Zadanie1_Piotr_Bolek
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