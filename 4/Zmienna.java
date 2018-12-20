import obliczenia.Wyrazenie;
import java.util.*;
import java.lang.Object;
import javafx.util.*;

public class Zmienna extends Wyrazenie{
    private List<Pair<String, Double>> list;
    private String name;
    private double value;

    public Zmienna(String name){
        boolean is_there_pair_with_that_key = false;
        Pair<String, Double> our_pair = new Pair(name, 0.0);
        int i = 0;
        while(this.list.get(i) != null){
            if(this.list.get(i).equals(our_pair)){
                this.list.set(i, our_pair);
                is_there_pair_with_that_key = true;
                break;
            }
            i++;
        }
        if(!is_there_pair_with_that_key){
            this.list.add(our_pair);
        }
        this.name = name;
        this.value = 0.0;
    }

    public Zmienna(String name, double value){
        boolean is_there_pair_with_that_key = false;
        Pair<String, Double> our_pair = new Pair(name, value);
        int i = 0;
        while(this.list.get(i) != null){
            if(this.list.get(i).equals(our_pair)){
                this.list.set(i, our_pair);
                is_there_pair_with_that_key = true;
                break;
            }
            i++;
        }
        if(!is_there_pair_with_that_key){
            this.list.add(our_pair);
        }
        this.name = name;
        this.value = value;
    }

    public double get_value(){
        return this.value;
    }

    public String get_name(){
        return this.name;
    }

    public String toString(){
        return "(" + this.name + " = " + this.value + ")";
    }

    public boolean equals(Zmienna x){
        return (x.get_value() == this.value && x.get_name() == this.name);
    }

    public double oblicz(){
        return get_value();
    }
}