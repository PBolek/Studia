package geometria;

class Punkt{
    protected double x,y;
    public Punkt(){
        this.x = 0.0;
        this.y = 0.0;
    }
    public Punkt(double x, double y){
        this.x = x;
        this.y = y;
    }

    public double get_x(){
        return x;
    }

    public double get_y(){
        return y;
    }
}