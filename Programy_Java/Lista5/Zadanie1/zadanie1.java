import java.io.*;
import java.util.ArrayList;
import java.util.List;

private interface Comparable<T>{
    int compareTo(T o);
}

class zadanie1<T> implements Comparable<T>{
    List<T> lista1 = new ArrayList<T>(2);

    public void dodaj(T element){
        List<T> helper = new ArrayList<T>(this.lista1.size());
        int licznik = 0;
        for(int i = 0; i < this.lista1.size(); i++){
            if(this.lista1.get(0).compareTo(element) > 0 && licznik == 0){
                helper.add(element);
                helper.add(this.lista1.get(i));
                licznik = 1;
            }
            else 
                helper.add(this.lista1.get(i));
        }
    }

    public T pobierz(){
        T element = this.lista1.get(0);
        this.lista1.remove(0);
        return element;
    }

    public void wypisz(){
        for(int i = 0; i < this.lista1.size(); i++){
            System.out.print(this.lista1.get(i) + " ");
        }
    }
}
