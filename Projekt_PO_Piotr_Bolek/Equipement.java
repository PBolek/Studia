import java.io.*;
import java.awt.*;
import javax.swing.*;

public class Equipement extends JPanel{
    private ImageIcon ii = new ImageIcon("Images/Eq_background.png");
    private String string;
    private ImageIcon ii1;

    //Buttons
    private ImageIcon iiUP = new ImageIcon("Images/UP.png");
    private ImageIcon iiDOWN = new ImageIcon("Images/DOWN.png");
    private ImageIcon iiLEFT = new ImageIcon("Images/LEFT.png");
    private ImageIcon iiRIGHT = new ImageIcon("Images/RIGHT.png");
    private ImageIcon iiENTER = new ImageIcon("Images/enter.png");
    private ImageIcon iiz_button = new ImageIcon("Images/z_button.png");
    private ImageIcon iix_button = new ImageIcon("Images/x_button.png");
    private ImageIcon iic_button = new ImageIcon("Images/c_button.png");

    private Image image;

    public Equipement(){
        super();
        setBounds(0, 600, 1200, 220);
        setVisible(true);
    }

    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D graphics = (Graphics2D)g;

        //draw background 
        image = ii.getImage();
        graphics.drawImage(image, 0, 0, 1200, 220, this);
        string = "move up";
        image = iiUP.getImage();
        graphics.drawImage(image, 30, 20, 30, 30, this);
        for(int i = 0; i < string.length(); i++){
            ii1 = new ImageIcon("Images/" + string.charAt(i) + ".png");
            image = ii1.getImage();
            graphics.drawImage(image, 70 + i * 14, 30, this);
        }
        string = "move right";
        image = iiRIGHT.getImage();
        graphics.drawImage(image, 30, 60, 30, 30, this);
        for(int i = 0; i < string.length(); i++){
            ii1 = new ImageIcon("Images/" + string.charAt(i) + ".png");
            image = ii1.getImage();
            graphics.drawImage(image, 70 + i * 14, 70, this);
        }
        string = "move down";
        image = iiDOWN.getImage();
        graphics.drawImage(image, 30, 100, 30, 30, this);
        for(int  i = 0; i < string.length(); i++){
            ii1 = new ImageIcon("Images/" + string.charAt(i) + ".png");
            image = ii1.getImage();
            graphics.drawImage(image, 70 + i * 14, 110, this);
        }
        string = "move left";
        image = iiLEFT.getImage();
        graphics.drawImage(image, 30, 140, 30, 30, this);
        for(int i = 0; i < string.length(); i++){
            ii1 = new ImageIcon("Images/" + string.charAt(i) + ".png");
            image = ii1.getImage();
            graphics.drawImage(image, 70 + i * 14, 150, this);
        }
        string = "end turn";
        image = iiENTER.getImage();
        graphics.drawImage(image, 300, 20, 30, 30, this);
        for(int i = 0; i < string.length(); i++){
            ii1 = new ImageIcon("Images/" + string.charAt(i) + ".png");
            image = ii1.getImage();
            graphics.drawImage(image, 340 + i * 14, 30, this);
        }
        string = "use pickaxe";
        image = iiz_button.getImage();
        graphics.drawImage(image, 300, 60, 30, 30, this);
        for(int i = 0; i < string.length(); i++){
            ii1 = new ImageIcon("Images/" + string.charAt(i) + ".png");
            image = ii1.getImage();
            graphics.drawImage(image, 340 + i * 14, 70, this);
        }
        string = "use shovel";
        image = iix_button.getImage();
        graphics.drawImage(image, 300, 100, 30, 30, this);
        for(int i = 0; i < string.length(); i++){
            ii1 = new ImageIcon("Images/" + string.charAt(i) + ".png");
            image = ii1.getImage();
            graphics.drawImage(image, 340 + i * 14, 110, this);
        }
        string = "use bomb";
        image = iic_button.getImage();
        graphics.drawImage(image, 300, 140, 30, 30, this);
        for(int i = 0; i < string.length(); i++){
            ii1 = new ImageIcon("Images/" + string.charAt(i) + ".png");
            image = ii1.getImage();
            graphics.drawImage(image, 340 + i * 14, 150, this);
        }
    }
}
