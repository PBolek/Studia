
public class Dodawanie extends Operator2Arg{
    private double first_value;
    private double second_value;
    private double value;

    public Dodawanie(double first_value, double second_value){
        this.first_value = first_value;
        this.second_value = second_value;
        this.value = first_value + second_value;
    }

    public double get_first(){
        return this.first_value;
    }

    public double get_second(){
        return this.second_value;
    }

    public double get_value(){
        return this.value;
    }

    public String toString(){
        return first_value + "+" + second_value;
    }

    public boolean equals(Dodawanie x){
        return x.get_first() == this.first_value && x.get_second() == this.second_value;
    }
}