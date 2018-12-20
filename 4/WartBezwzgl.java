
public class WartBezwzgl extends Operator1Arg{
    private double value;

    public WartBezwzgl(double value){
        this.value = Math.abs(value);
    }

    public double get_value(){
        return this.value;
    }

    public String toString(){
        return "|" + this.value + "|";
    }

    public boolean equals(WartBezwzgl x){
        return x.get_value() == this.value;
    }
}