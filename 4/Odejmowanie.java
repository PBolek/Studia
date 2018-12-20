
public class Odejmowanie extends Operator2Arg{
    private double first_value;
    private double second_value;
    private double value;

    public Odejmowanie(double first, double second){
        this.first_value = first;
        this.second_value = second;
        this.value = first - second;
    }

    public double get_value(){
        return this.value;
    }

    public double get_first(){
        return this.first_value;
    }

    public double get_second(){
        return this.second_value;
    }

    public String toString(){
        return first_value + "-" + second_value;
    }

    public boolean equals(Odejmowanie x){
        return x.get_first() == this.first_value && x.get_second() == second_value;
    }
}