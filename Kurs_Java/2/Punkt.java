package geometria;

public class Punkt{
    protected double x,y;

    public Punkt(){
        this.x = 0.0;
        this.y = 0.0;
    }

    public Punkt(double x, double y){
        this.x = x;
        this.y = y;
    }

    private double sqr(double x){
        return x * x;
    }

    public double get_x(){
        return x;
    }

    public double get_y(){
        return y;
    }

    public void przesun(Wektor v){
        x = x + v.get_dx_val();
        y = y + v.get_dx_val();
    }

    public void obroc(Punkt p, double kat){
        double x_help = x;
        double y_help = y;
        x = x_help * Math.cos(Math.toRadians(kat)) - y_help * Math.sin(Math.toRadians(kat));
        y = x_help * Math.sin(Math.toRadians(kat)) - y_help * Math.cos(Math.toRadians(kat));
    }

    public void odbij(Prosta p){
        double x_help = x;
        double y_help = y;
        x = (((1 - sqr(p.a)) / (1 + sqr(p.a))) * x_help) + (((2 * p.a) / (1 + sqr(p.a))) * y_help);
        y = (((2 * p.a) / (1 + sqr(p.a))) * x_help) - (((1 - sqr(p.a)) / (1 + sqr(p.a))) * y_help);
    }
}