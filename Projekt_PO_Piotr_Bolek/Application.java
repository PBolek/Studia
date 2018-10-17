import java.awt.*;
import javax.swing.*;

public class Application extends JFrame {
    private Board board;
    public static void main(String[] args) {
        EventQueue.invokeLater(new Runnable(){
            public void run(){
                new Board(1);
            }
        });
    }
}