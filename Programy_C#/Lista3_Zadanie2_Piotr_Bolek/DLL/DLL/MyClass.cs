/*
 * Created by SharpDevelop.
 * User: Piotr
 * Date: 18.03.2018
 * Time: 15:27
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;
using System.Collections.Generic;

namespace DLL
{
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
}