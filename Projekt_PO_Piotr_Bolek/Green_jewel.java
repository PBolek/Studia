import java.io.*;
import java.awt.*;
import javax.swing.*;

public class Green_jewel{
    private int number;

    public Green_jewel(){
        number = 0;
    }

    public void picked(){
        number++;
    }

    public int number(){
        return number;
    }
}