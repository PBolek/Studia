import java.io.*;
import java.awt.*;
import javax.swing.*;

public class Bomb{
    private int number;

    public Bomb(){
        number = 5;
    }

    public Bomb(int number){
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