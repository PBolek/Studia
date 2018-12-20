
public class Maksimum extends Operator2Arg{
    private double first;
    private double second;
    private double value;

    public Maksimum(double first, double second){
        this.first = first;
        this.second = second;
        this.value = Math.max(first, second);
    }

    public double get_first(){
        return this.first;
    }

    public double get_second(){
        return this.second;
    }

    public double get_value(){
        return this.value;
    }

    public String toString(){
        return "(" + this.first + ", " + this.second + ")";
    }

    public boolean equals(Maksimum x){
        return this.value == x.get_value();
    }
}