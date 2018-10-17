import java.io.*;
import java.util.Hashtable;

class Wyrazenie{
    public int oblicz(){
        return 0;
    }

    public String toString(){
        return "";
    }

    public int pochodna(){
        return 0;
    }
}

class Dodaj extends Wyrazenie{
    private Wyrazenie left;
    private Wyrazenie right;

    Dodaj(Wyrazenie a, Wyrazenie b){
        this.left = a;
        this.right = b;
    }

    public int oblicz(){
        int wynik;
        wynik = this.left.oblicz() + this.right.oblicz();
        return wynik;
    }

    public String toString(){
        String wynik;
        wynik = "" + this.left.oblicz() + "+" + this.right.oblicz();
        return wynik;
    }

    public int pochodna(){
        int wynik = this.left.pochodna() + this.right.pochodna();
        return wynik;
    }
}

class Odejmij extends Wyrazenie{
    private Wyrazenie left;
    private Wyrazenie right;

    Odejmij(Wyrazenie a, Wyrazenie b){
        this.left = a;
        this.right = b;
    }

    public int oblicz(){
        int wynik;
        wynik = this.left.oblicz() - this.right.oblicz();
        return wynik;
    }

    public String toString(){
        String wynik;
        wynik = "" + this.left.oblicz() + "-" + this.right.oblicz();
        return wynik;
    }

    public int pochodna(){
        int wynik = this.left.pochodna() - this.right.pochodna();
        return wynik;
    }
}

class Iloraz extends Wyrazenie{
    private Wyrazenie left;
    private Wyrazenie right;

    Iloraz(Wyrazenie a, Wyrazenie b){
        this.left = a;
        this.left = b;
    }

    public int oblicz(){
        int wynik;
        if(this.right.oblicz() == 0){
            throw new ArithmeticException("Dzielenie przez 0!");
        }
        wynik = this.left.oblicz() / this.right.oblicz();
        return wynik;
    }

    public String toString(){
        String wynik;
        wynik = "" + this.left.oblicz() + "/" + this.right.oblicz();
        return wynik;
    }

    public int pochodna(){
        int wynik;
        wynik = (this.left.pochodna() * this.right.oblicz() + this.left.oblicz() * this.right.pochodna()) / (this.right.oblicz() * this.right.oblicz());
        return wynik;
    }
}

class Iloczyn extends Wyrazenie{
    private Wyrazenie left;
    private Wyrazenie right;

    Iloczyn(Wyrazenie a, Wyrazenie b){
        this.left = a;
        this.right = b;
    }

    public int oblicz(){
        int wynik;
        wynik = this.left.oblicz() * this.right.oblicz();
        return wynik;
    }

    public String toString(){
        String wynik;
        wynik = "" + this.left.oblicz() + "*" + this.right.oblicz();
        return wynik;
    }

    public int pochodna(){
        int wynik;
        wynik = this.left.pochodna() * this.right.oblicz() - this.left.oblicz() * this.right.pochodna();
        return wynik;
    }
}

class Stala extends Wyrazenie{
    private int stala;

    Stala(int stala){
        this.stala = stala;
    }

    public int oblicz(){
        return this.stala;
    }

    public String toString(){
        String wynik = "" + this.stala;
        return wynik;
    }

    public int pochodna(){
        return 0;
    }
}

class Zmienna extends Wyrazenie{
    private String zmienna;
    private Hashtable<String, Integer> tab;

    Zmienna(String zmienna, Hashtable<String, Integer> tab){
        this.zmienna = zmienna;
        this.tab = tab;
    }

    public int oblicz(){
        int wynik;
        wynik = tab.get(this.zmienna);
        return wynik;
    }

    public int pochodna(){
        return 1;
    }
}

public class Zadanie4{
    public static void main(String[] args){
        Hashtable<String, Integer> tab = new Hashtable<String, Integer>();
        tab.put("x", 10);
        Wyrazenie wyrazenie;
        wyrazenie = new Dodaj(new Stala(5), new Stala(5));
        System.out.println(wyrazenie.toString());
        System.out.println(wyrazenie.pochodna());
        System.out.println(wyrazenie.oblicz());
        wyrazenie = new Dodaj(new Stala(5), new Zmienna("x", tab));
        System.out.println(wyrazenie.toString());
        System.out.println(wyrazenie.pochodna());
        System.out.println(wyrazenie.oblicz());
    }
}