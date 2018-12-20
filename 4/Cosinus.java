
public class Cosinus extends Operator1Arg{
    private double value;
    private double number;

    public Cosinus(double number){
        this.number = number;
        this.value = Math.cos(number);
    }

    public double get_value(){
        return this.value;
    }

    public double get_number(){
        return this.number;
    }

    public String toString(){
        return "cos(" + this.number + ")";
    }

    public boolean equals(Cosinus x){
        return x.get_number() == this.number;
    }
}