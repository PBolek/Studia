import java.io.*;
import javax.swing.*;
import java.awt.*;

public class Game_stats extends JPanel{
    private int yellow_jewels = 0;
    private int green_jewels = 0;
    private int white_jewels = 0;
    private int blue_jewels = 0;
    private int bomb = 3;
    private int shovel = 3;
    private int pickaxe = 3;
    private int move = 0;
    private String string_move = "0";
    private String string_yellow;
    private String string_green;
    private String string_white;
    private String string_blue;
    private String string_pickaxe;
    private String string_shovel;
    private String string_bomb;
    private ImageIcon ii = new ImageIcon("Images/Game_stats_background.png");
    private ImageIcon ii0 = new ImageIcon("Images/jewel_green.png");
    private ImageIcon ii1 = new ImageIcon("Images/jewel_blue.png");
    private ImageIcon ii2 = new ImageIcon("Images/jewel_yellow.png");
    private ImageIcon ii3 = new ImageIcon("Images/jewel_white.png");
    private ImageIcon ii5 = new ImageIcon("Images/boots.png");
    private ImageIcon ii_pickaxe = new ImageIcon("Images/pickaxe.png");
    private ImageIcon ii_shovel = new ImageIcon("Images/shovel.png");
    private ImageIcon ii_bomb = new ImageIcon("Images/bomb.png");
    private Image image;
    public Game_stats(int yellow, int green, int white, int blue){
        this.yellow_jewels = yellow;
        this.green_jewels = green;
        this.white_jewels = white;
        this.blue_jewels = blue;
        string_yellow = Integer.toString(yellow_jewels);
        string_green = Integer.toString(green_jewels);
        string_blue = Integer.toString(blue_jewels);
        string_white = Integer.toString(white_jewels);
        setBounds(1200, 0, 300, 600);
        setVisible(true);
    }

    public void set_stats(int green, int blue, int yellow, int white, int movement, int shovel, int bomb, int pickaxe){
        this.shovel = shovel;
        this.pickaxe = pickaxe;
        this.bomb = bomb;
        green_jewels = green;
        blue_jewels = blue;
        yellow_jewels = yellow;
        white_jewels = white;
        move = movement;
        string_bomb = Integer.toString(this.bomb);
        string_pickaxe = Integer.toString(this.pickaxe);
        string_shovel = Integer.toString(this.shovel);
        string_yellow = Integer.toString(yellow_jewels);
        string_green = Integer.toString(green_jewels);
        string_blue = Integer.toString(blue_jewels);
        string_white = Integer.toString(white_jewels);
        string_move = Integer.toString(move);
        repaint();
    }

    public void set_pickaxe(int number){
        pickaxe = number;
        string_pickaxe = Integer.toString(pickaxe);
        repaint();
    }

    public void set_bomb(int number){
        bomb = number;
        string_bomb = Integer.toString(bomb);
        repaint();
    }

    public void set_shovel(int number){
        shovel = number;
        string_shovel = Integer.toString(shovel);
        repaint();
    }

    public void set_move(int move){
        this.move = move;
        this.string_move = Integer.toString(move);
        repaint();
    }

    public void set_green(int number){
        green_jewels = number;
        string_green = Integer.toString(green_jewels);
        repaint();
    }

    public void set_yellow(int number){
        yellow_jewels = number;
        string_yellow = Integer.toString(yellow_jewels);
        repaint();
    }

    public void set_blue(int number){
        blue_jewels = number;
        string_blue = Integer.toString(blue_jewels);
        repaint();
    }

    public void set_white(int number){
        white_jewels = number;
        string_white = Integer.toString(white_jewels);
        repaint();
    }

    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);

        Graphics2D graphics = (Graphics2D)g;
        ImageIcon ii4;
        
        image = ii.getImage();
        graphics.drawImage(image, 0, 0, this);
        image = ii0.getImage();
        graphics.drawImage(image, 30, 20, this);
        for(int i = 0; i < string_green.length(); i++){
            ii4 = new ImageIcon("Images/" + string_green.charAt(i) + ".png");
            image = ii4.getImage();
            graphics.drawImage(image, 90 + i * 30, 30, 30, 55, this);
        }
       
        image = ii1.getImage();
        graphics.drawImage(image, 30, 120, this);
        for(int i = 0; i < string_blue.length(); i++){
            ii4 = new ImageIcon("Images/" + string_blue.charAt(i) + ".png");
            image = ii4.getImage();
            graphics.drawImage(image, 90 + i * 30, 130, 30, 55, this);
        }
        
        image = ii2.getImage();
        graphics.drawImage(image, 30, 220, this);
        for(int i = 0; i < string_yellow.length(); i++){
            ii4 = new ImageIcon("Images/" + string_yellow.charAt(i) + ".png");
            image = ii4.getImage();
            graphics.drawImage(image, 90 + i * 30, 230, 30, 55, this);
        }
        
        image = ii3.getImage();
        graphics.drawImage(image, 30, 320, this);
        for(int i = 0; i < string_white.length(); i++){
            ii4 = new ImageIcon("Images/" + string_white.charAt(i) + ".png");
            image = ii4.getImage();
            graphics.drawImage(image, 90 + i * 30, 330, 30, 55, this);
        }

        image = ii5.getImage();
        graphics.drawImage(image, 30, 430, 50, 50, this);
        for(int i = 0; i < string_move.length(); i++){
            ii4 = new ImageIcon("Images/" + string_move.charAt(i) + ".png");
            image = ii4.getImage();
            graphics.drawImage(image, 90 + i * 30, 430, 30, 55, this);
        }

        image = ii_pickaxe.getImage();
        graphics.drawImage(image, 140, 25, 70, 70, this);
        for(int i = 0; i < string_pickaxe.length(); i++){
            ii4 = new ImageIcon("Images/" + string_pickaxe.charAt(i) + ".png");
            image = ii4.getImage();
            graphics.drawImage(image, 210 + i * 30, 30, 30, 55, this);
        }

        image = ii_bomb.getImage();
        graphics.drawImage(image, 150, 135, 50, 50, this);
        for(int i = 0; i < string_bomb.length(); i++){
            ii4 = new ImageIcon("Images/" + string_bomb.charAt(i) + ".png");
            image = ii4.getImage();
            graphics.drawImage(image, 210 + i * 30, 130, 30, 55, this);
        }

        image = ii_shovel.getImage();
        graphics.drawImage(image, 150, 225, 70, 60, this);
        for(int i = 0; i < string_bomb.length(); i++){
            ii4 = new ImageIcon("Images/" + string_shovel.charAt(i) + ".png");
            image = ii4.getImage();
            graphics.drawImage(image, 210 + i * 30, 230, 30, 55, this);
        }
    }

}