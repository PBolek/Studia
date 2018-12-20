
public class Mnozenie extends Operator2Arg{
    private double first;
    private double second;
    private double value;

    public Mnozenie(double first, double second){
        this.first = first;
        this.second = second;
        this.value = first * second;
    }

    public double get_value(){
        return this.value;
    }

    public double get_first(){
        return this.first;
    }

    public double get_second(){
        return this.second;
    }

    public String toString(){
        return first + "*" + second;
    }

    public boolean equals(Mnozenie x){
        return x.get_first() == this.first && x.get_second() == this.second;
    }
}