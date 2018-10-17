package geometria;
import java.lang.Exception.*;

public class Prosta{
    public final double a, b, c;
    private double dx, dy;
    public Prosta(double a, double b, double c){
        if(a == 0 && b == 0)
            throw new IllegalArgumentException("a == 0 && b == 0");
        this.a = a;
        this.b = b;
        this.c = c;
    }
    //przesunięcie prostej o wektor
    public Prosta(Prosta p, Wektor v){
        this.a = p.a;
        this.b = p.b;
        this.c = p.c - p.a * v.get_dx_val() - p.b * v.get_dy_val();
    }

    static public boolean czy_rownolegle(Prosta p1, Prosta p2){
        if(p1.a * p2.b - p2.a * p1.b == 0)
            return true;
        return false;
    }

    static public boolean czy_prostopadle(Prosta p1, Prosta p2){
        if(p1.a * p2.a + p1.b * p2.b == 0)
            return true;
        return false;
    }

    static public Punkt punkt_przeciecia_prostych(Prosta p1, Prosta p2){
        if(czy_prostopadle(p1, p2) == true)
            throw new IllegalArgumentException("czy_prostopadle(p1, p2) == true");
        Punkt wynik = new Punkt();
        double wx, wy, w;
        wx = (-p1.c) * p2.b - (-p2.c) * p1.b;
        wy = p1.a * (-p2.c) - p2.a * (-p1.c);
        w = p1.a * p2.b - p2.a * p1.b;
        wynik.x = wx / w;
        wynik.y = wy /w;
        return wynik;
    }
}