import java.io.*;
import java.awt.*;
import javax.swing.*;

public class Pickaxe{
    private int number;

    public Pickaxe(){
        number = 5;
    }

    public Pickaxe(int number){
        this.number = number;
    }

    public int number(){
        return number;
    }

    public void used(){
        number--;
    }

    public void fill(){
        number = 5;
    }

    public void add(){
        number++;
    }
}