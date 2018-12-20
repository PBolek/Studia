
public class Sinus extends Operator1Arg{
    private double value;
    private double number;

    public Sinus(double value){
        this.number = value;
        this.value = Math.sin(value);
    }

    public double get_value(){
        return this.value;
    }
    
    public double get_number(){
        return this.number;
    }

    public String toString(){
        return "sin(" + number + ")";
    }

    public boolean equals(Sinus x){
        return x.get_number() == this.number;
    }
}