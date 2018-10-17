import java.io.*;

public class Wyrażenie{}

private class Dodaj extends Wyrażenie{
    private int a;
    private int b;

    Dodaj(int a, int b){
        this.a = a;
        this.b = b;
    }

    public int oblicz(){
        return a + b;
    }

    String toString(){
        String wynik;
        wynik = "" + this.a + "+" + this.b;
        return wynik;
    }
}

private class Stala extends Wyrażenie{
    private int stala;

    Stala(int liczba){
        this.stala = liczba;
    }

    public int oblicz(){
        return this.stala;
    }

    String toString(){
        String wynik;
        wynik = "" + this.a;
        return wynik;
    }
}

private class Odejmij extends Wyrażenie{
    private int a;
    private int b;

    Odejmij(int a, int b){
        this.a = a;
        this.b = b;
    }

    public int oblicz(){
        return a - b;
    }

    String toString(){
        String wynik;
        wynik = "" + this.a + "-" + this.b;
        return wynik;
    }
}

private class Iloczyn extends Wyrażenie{
    private int a;
    private int b;

    Iloczyn(int a, int b){
        this.a = a;
        this.b = b;
    }

    public int oblicz(){
        return a * b;
    }

    String toString(){
        String wynik;
        wynik = "" + this.a + "*" + this.b;
        return wynik;
    }
}

private class Iloraz extends Wyrażenie{
    private int a;
    private int b;

    Iloraz(int a, int b){
        this.a = a;
        this.b = b;
    }

    public int oblicz(){
        return a / b;
    }

    String toString(){
        String wynik;
        wynik = "" + this.a + "/" + this.b;
        return wynik;
    }
}