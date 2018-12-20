
public class Minimum extends Operator2Arg{
    private double first;
    private double second;
    private double value;

    public Minimum(double first, double second){
        this.first = first;
        this.second = second;
        this.value = Math.min(first, second);
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
        return "(" + this.first + ", " + this.second + ")";
    }

    public boolean equals(Minimum x){
        return x.value == this.value;
    }
}
