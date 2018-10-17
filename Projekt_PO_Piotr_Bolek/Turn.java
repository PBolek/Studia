import javax.swing.*;
import javax.imageio.*;
import java.awt.*;
import java.awt.event.ActionListener;
import java.awt.event.*;
import java.awt.image.*;
import java.io.*;
import java.util.Random;

public class Turn extends JPanel{
    private int turn = 1;
    private int[] order = new int[9];
    private ImageIcon ii = new ImageIcon("Images/turn_background.png");
    private ImageIcon iip = new ImageIcon("Images/p.png");
    private ImageIcon iil = new ImageIcon("Images/l.png");
    private ImageIcon iia = new ImageIcon("Images/a.png");
    private ImageIcon iiy = new ImageIcon("Images/y.png");
    private ImageIcon iie = new ImageIcon("Images/e.png");
    private ImageIcon iir = new ImageIcon("Images/r.png");
    private ImageIcon ii_player;
    private String string_number;
    private Image image;
    public int turn_number = 0;
    
    public Turn(){
        super();
        rand_order(8);
        setBounds(1200, 600, 300, 300);
    }

    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D graphics = (Graphics2D)g;
        image = ii.getImage();
        graphics.drawImage(image, 0, 0, this);
        image = iip.getImage();
        graphics.drawImage(image, 30, 30, 30, 30, this);
        image = iil.getImage();
        graphics.drawImage(image, 60, 30, 30, 30, this);
        image = iia.getImage();
        graphics.drawImage(image, 90, 30, 30, 30, this);
        image = iiy.getImage();
        graphics.drawImage(image, 120, 30, 30, 30, this);
        image = iie.getImage();
        graphics.drawImage(image, 150, 30, 30, 30, this);
        image = iir.getImage();
        graphics.drawImage(image, 180, 30, 30, 30, this);
        string_number = Integer.toString(who_should_move_in_this_turn(turn));
        ii_player = new ImageIcon("Images/" + string_number + ".png");
        image = ii_player.getImage();
        graphics.drawImage(image, 240, 30, 30, 30, this);
        ii_player = new ImageIcon("Images/player" + string_number + ".png");
        image = ii_player.getImage();
        graphics.drawImage(image, 120, 100, 50, 50, this);
    }

    public void rand_order(int number_of_players){
        Random random = new Random();
        int flag = 0;
        int ready_numbers = 0;
        int rand_number;
        while(ready_numbers != number_of_players){
            rand_number = random.nextInt(number_of_players + 1);
            if(rand_number != 0){
                for(int i = 0; i < number_of_players; i++){
                    if(rand_number == order[i])
                        flag = 1;
                }
                if(flag == 0){
                    order[ready_numbers++] = rand_number; 
                }
                flag = 0;
            }
        }
    }

    public int get_playerX_order(int X){
        return order[X-1];
    }

    public int who_should_move_in_this_turn(int turn){
        int i = 0;
        while(order[i] != turn){
            i++;
        }
        return ++i;
    }

    public int get_turn(){
        return turn;
    }

    public void next_turn(){
        turn++;
        if(turn == 9){
            turn = 1;
        }
    }
}