//Piotr Bolek Lista 6 Zadanie 3

import java.io.*;

class List<T>{
    public List<T> next;
    public List<T> prev;
    public T val;
}

class bufor<T>{
    private int elements = 0;
    private int size = 0;
    public bufor(int size){
        this.size = size;
    }

    private List<T> box = new List<T>();

    public int show_max_size(){
        return size;
    }
    
    public int show_elements(){
        return elements;
    }

    public void add(T element){
        if(box.next != null){
            box = box.next;
        }
        else if(elements < size){
            box.next.prev = box;
            box = box.next;
            box.next = null;
            box.val = element;
            elements++;
        }
        throw new IllegalArgumentException("Bufor jest pelny!");
    }

    public T pick(){
        if(box != null){
            T element = box.val;
            box = box.prev;
            elements--;
            return element;
        }
        throw new IllegalArgumentException("Bufor jest pusty!");
    }
}

class Thread<T>{
    Thread(int size){
        protected bufor<String> buf = new bufor<String>(size);
    }
    public void run();
}

class producent extends Thread{
    public void run(){
        while(this.buf.show_elements() < this.buf.show_max_size()){
            
        }
    }
}

class konsument extends Thread{
    
}

public class Zadanie3{
    public static void main(String[] agrs){

    }
}