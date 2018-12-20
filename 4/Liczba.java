import obliczenia.Wyrazenie;

public class Liczba extends Wyrazenie{
    private double value;

    public Liczba(double value){
        this.value = value;
    }

    public double get_value(){
        return this.value;
    }

    public String toString(){
        return Double.toString(this.value);
    }

    public double oblicz(){
        return get_value();
    }

    public boolean equals(Liczba number){
        return (number.get_value() == this.value);
    }
}