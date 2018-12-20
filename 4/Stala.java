import obliczenia.Wyrazenie;

public class Stala extends Wyrazenie{
    private final double value;

    public Stala(String name){
        if(name == "pi" || name == "PI")
            value = Math.PI;
        else if(name == "E" || name == "e")
            value = Math.E;
        else if(name == "FI" || name == "fi")
            value = 1.6180339887;
        else
            value = 0.0;
    }

    public double oblicz(){
        return this.value;
    }

    public double PI(){
        return Math.PI;
    }

    public double E(){
        return Math.E;
    }

    public double FI(){
        return 1.6180339887;
    }
}