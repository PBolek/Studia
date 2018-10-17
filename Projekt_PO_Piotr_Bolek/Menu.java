import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Menu extends JPanel{
    private Image image;
    private ImageIcon ii;
    private String string = "projekt";
    public enum STATE{
        MENU,
        PLAY
    };
    public STATE state = STATE.MENU;

    public Menu(){
        super();
        setBounds(0, 0, 1500, 820);
        setBackground(Color.black);
        setVisible(true);
    }

    public void play(){
        state = STATE.PLAY;
        repaint();
    }

    public void quit(){
        System.exit(1);
    }

    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D graphics = (Graphics2D)g;
        if(state == STATE.MENU){
            for(int i = 1; i <= string.length(); i++){
                ii = new ImageIcon("Images/" + string.charAt(i - 1) + ".png");
                image = ii.getImage();
                graphics.drawImage(image, 550 + i * 50, 20, 50, 50, this);
            }
            string = "programowanie obiektowe";
            for(int i = 1; i <= string.length(); i++){
                ii = new ImageIcon("Images/" + string.charAt(i - 1) + ".png");
                image = ii.getImage();
                graphics.drawImage(image, 150 + i * 50, 120, 50, 50, this);
            }
            string = "piotr bolek";
            for(int i = 1; i <= string.length(); i++){
                ii = new ImageIcon("Images/" + string.charAt(i - 1) + ".png");
                image = ii.getImage();
                graphics.drawImage(image, 450 + i * 50, 220, 50, 50, this);
            }
            string = "1play";
            for(int i = 1; i <= string.length(); i++){
                ii = new ImageIcon("Images/" + string.charAt(i - 1) + ".png");
                image = ii.getImage();
                graphics.drawImage(image, 600 + i * 50, 370, 50, 50, this);
            }
            string = "2quit";
            for(int i = 1; i <= string.length(); i++){
                ii = new ImageIcon("Images/" + string.charAt(i - 1) + ".png");
                image = ii.getImage();
                graphics.drawImage(image, 600 + i * 50, 470, 50, 50, this);
            }
        }
        else if(state == STATE.PLAY){
            string = "set number of teams";
            for(int i = 1; i <= string.length(); i++){
                ii = new ImageIcon("Images/" + string.charAt(i - 1) + ".png");
                image = ii.getImage();
                graphics.drawImage(image, 200 + i * 50, 300, 50, 50, this);
            }
            string = "2 4 8";
            for(int i = 1; i <= string.length(); i++){
                ii = new ImageIcon("Images/" + string.charAt(i - 1) + ".png");
                image = ii.getImage();
                graphics.drawImage(image, 550 + i * 50, 400, 50, 50, this);
            }
        }
    }
}