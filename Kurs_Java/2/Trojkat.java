package geometria;

public class Trojkat{
    protected Odcinek a, b, c;

    public Trojkat(Odcinek a, Odcinek b, Odcinek c){
        if(a.length() + b.length() <= c.length())
            throw new IllegalArgumentException("a + b <= c");
        else if(a.length() + c.length() <= b.length())
            throw new IllegalArgumentException("a + c <= b");
        else if(b.length() + c.length() <= a.length())
            throw new IllegalArgumentException("b + c <= a");
        this.a = a;
        this.b = b;
        this.c = c;
    }

    //przesun o wektor
    public void przesun(Wektor v){
        a.przesun(v);
        b.przesun(v);
        c.przesun(v);
    }

    //obroc wokol ustalonego punktu wszystkich punktow figury o zadany kat
    public void obroc(Punkt p, double kat){
        a.obroc(p, kat);
        b.obroc(p, kat);
        c.obroc(p, kat);
    }

    //odbij symetrycznie wzgledem prostej
    public void odbij(Prosta p){
        a.odbij(p);
        b.odbij(p);
        c.odbij(p);
    }
}