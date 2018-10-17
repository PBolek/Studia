import java.io.*;

class Osoba{
    private String Nazwisko;
    private int wzrost;
    Osoba(String Nazwisko, int wzrost){
        this.Nazwisko = Nazwisko;
        this.wzrost = wzrost;
    }
    public void drukuj(){
        System.out.println("Nazwisko: " + this.Nazwisko);
        System.out.println("Wzrost: " + this.wzrost);
    }
}

public class Student extends Osoba{
    String kierunek;
    Student(String Nazwisko, int wzrost, String kierunek){
        super(Nazwisko, wzrost);
        this.kierunek = kierunek;
    }
    
    public void drukuj(){
        super.drukuj();
        System.out.println("Kierunek: " + this.kierunek);
    }

    public static void main(String[] args){
        Osoba obj = new Student("Kubuś Puchatek", 35, "inf");
        obj.drukuj();
    }
}