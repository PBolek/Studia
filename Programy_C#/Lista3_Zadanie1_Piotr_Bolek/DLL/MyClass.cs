//Piotr Bolek Zadanie 1 Lista 3
using System;
using System.Collections.Generic;

namespace DLL
{
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
		else{
			element = list.val;
			list = list.next;
		}
		return element;
	}
	
	public T delete_begin(){
		T element = default(T);
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
		else{
			element = list.val;
			list = list.prev;
		}	
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
}