import java.io.*;
import java.awt.*;
import javax.swing.*;

public class Blue_jewel{
    private int number;

    public Blue_jewel(){
        number = 0;
    }

    public void picked(){
        number++;
    }

    public int number(){
        return number;
    }
}