
public class Odwrotnosc extends Operator1Arg{
    private double value;

    public Odwrotnosc(double value){
        this.value = 1.0 / value;
    }

    public double get_value(){
        return this.value;
    }

    public String toString(){
        return Double.toString(this.value);
    }

    public boolean equals(Odwrotnosc x){
        return x.get_value() == this.value;
    }
}