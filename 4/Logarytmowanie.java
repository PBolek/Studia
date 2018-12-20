
public class Logarytmowanie extends Operator2Arg{
    private double number;
    private double x;
    private double value;

    public Logarytmowanie(double number, double x){
        this.number = number;
        this.x = x;
        if(x == 10)
            this.value = Math.log10(number);
        else
            this.value = Math.log(number) / Math.log(x);
    }

    public double get_value(){
        return this.value;
    }

    public double get_number(){
        return this.number;
    }

    public double get_x(){
        return this.x;
    }

    public String toString(){
        return "log" + x + "(" + this.number + ")";
    }

    public boolean equals(Logarytmowanie x){
        return x.get_x() == this.x && x.get_number() == this.number;
    }
}