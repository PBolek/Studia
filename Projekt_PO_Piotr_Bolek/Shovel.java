import java.io.*;
import java.awt.*;
import javax.swing.*;

public class Shovel{
    private int number;

    public Shovel(){
        number = 5;
    }

    public Shovel(int number){
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