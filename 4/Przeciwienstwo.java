
public class Przeciwienstwo extends Operator1Arg{
    private double value;

    public Przeciwienstwo(double value){
        this.value = -value;
    }

    public double get_value(){
        return this.value;
    }

    public String toString(){
        return Double.toString(this.value);
    }

    public boolean equals(Przeciwienstwo x){
        return x.get_value() == this.value;
    }
}