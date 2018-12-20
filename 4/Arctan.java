
public class Arctan extends Operator1Arg{
    private double value;
    private double number;

    public Arctan(double number){
        this.number = number;
        this.value = Math.atan(number);
    }

    public double get_value(){
        return this.value;
    }

    public double get_number(){
        return this.number;
    }

    public String toString(){
        return "arctan(" + this.number + ")";
    }

    public boolean equals(Arctan x){
        return x.get_number() == this.number;
    }
}