﻿//Piotr Bolek Zadanie 1 Lista 2

using System;

public class IntStream{
	public int x = 0;
	virtual public int next(){
		this.x = this.x + 1;
		return this.x;
	}
	virtual public bool eos(){
		if(this.x == 2147483647){
			Console.WriteLine("Strumien sie skonczyl");
			return true;
		}
		else{
			Console.WriteLine("Strumien sie nie skonczyl");
			return false;
		}
	}
	public void reset(){
		this.x = 0;
	}
}

public class PrimeStream : IntStream{
	private bool is_prime(int a){
		if(a == 0 || a == 1)
			return false;
		int licznik = 0;
		for(int i = 2; i <= a; i++){
			if(a%i == 0)
				licznik = licznik + 1;
		}
		if(licznik != 1){
			return false;
		}
		return true;
	}
	override public int next(){
		while(is_prime(this.x) != true){
			this.x = this.x + 1;
		}
		this.x = this.x + 1;
		return this.x - 1;
	}
}

public class RandomStream : IntStream{
	Random rnd = new Random();
	override public int next(){
		int a = rnd.Next(0, 2147483647);
		return a;
	}
	override public bool eos(){
		return false;
	}
}

public class RandomWordStream{
	private RandomStream rs = new RandomStream();
	private PrimeStream ps = new PrimeStream();
	public string s = string.Empty;
	private int mod(int a){
		a = a%127;
		return a;
	}
	public string next(){
		int size = ps.next();
		s = string.Empty;
		for(int i = 0; i < size; i++){
			s = s + (char)(mod(rs.next()));
		}
		return s;
	}
	public bool eos(){
		return ps.eos();
	}
	public void reset(){
		rs.reset();
		ps.reset();
		s = string.Empty;
	}
}

namespace Zadanie1_Lista2_Piotr_Bolek
{
	class Program
	{
		public static void Main(string[] args)
		{

			// TODO: Implement Functionality Here
			int command = 0;
			RandomWordStream rws = new RandomWordStream();
			string s = string.Empty;
			Console.WriteLine("1 - next");
			Console.WriteLine("2 - eos");
			Console.WriteLine("3 - reset");
			Console.WriteLine("4 - exit");
			command = Console.Read();
			while(command != 52){
				if(command == 49){
					s = rws.next();
					Console.WriteLine(s);
				}
				else if(command == 50){
					rws.eos();
				}
				else if(command == 51){
					rws.reset();
				}
				s = string.Empty;
				command = Console.Read();
			}
			Console.Write("Press any key to continue . . . ");
			Console.ReadKey(true);
		}
	}
}