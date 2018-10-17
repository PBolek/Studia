package geometria;

class Odcinek{
    private double square(double x){
        return x*x;
    }
    protected Punkt a,b;
    public Odcinek(Punkt a, Punkt b){
        if(a.get_x() == b.get_x() && a.get_y() == b.get_y())
            throw new IllegalArgumentException("a == b");
        this.a = new Punkt(a.get_x(), a.get_y());
        this.b = new Punkt(b.get_x(), b.get_y());
    }

    public double length(){
        return square(a.get_x() - b.get_x()) + square(a.get_y() - b.get_y());
    }

    //przesun o wektor
    public void przesun(Wektor v){

    }

    //obroc wokol ustalonego punktu wszystkich punktow figury o zadany kat
    public void obroc(Punkt p, double kat){

    }

    //odbij symetrycznie wzgledem prostej
    public void odbij(Prosta p){
        
    }
}