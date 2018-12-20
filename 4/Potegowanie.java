
public class Potegowanie extends Operator2Arg{
    private double number;
    private double x;
    private double value;

    public Potegowanie(double number, double x){
        this.number = number;
        this.x = x;
        this.value = Math.pow(number, x);
    }

    public double get_value(){
        return this.value;
    }

    public double get_x(){
        return this.x;
    }

    public double get_number(){
        return this.number;
    }

    public String toString(){
        return this.number + "^" + this.x;
    }

    public boolean equals(Potegowanie x){
        return x.get_number() == this.number && x.get_x() == this.x;
    }
}