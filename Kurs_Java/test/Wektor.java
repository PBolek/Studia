class Wektor{
    public final double dx, dy;

    public Wektor(double dx, double dy){
        this.dx = dx;
        this.dy = dy;
    }

    public Wektor(){
        this.dx = 0.0;
        this.dy = 0.0;
    }

    public double get_dx_val(){
        return dx;
    }

    public double get_dy_val(){
        return dy;
    }

    public Wektor add(Wektor v){
        Wektor res = new Wektor(dx + v.get_dx_val(), dy + v.get_dy_val());
        return res;
    }
}