import java.io.*;
import java.awt.*;
import javax.swing.*;

public class White_jewel{
    private int number;

    public White_jewel(){
        number = 0;
    }

    public void picked(){
        number++;
    }

    public int number(){
        return number;
    }
}