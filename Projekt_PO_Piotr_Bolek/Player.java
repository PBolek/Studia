import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.awt.event.KeyEvent;
import java.util.Random;

//Dopisac klasy dla wszystkich przedmiotow - bedzie latwiej

public class Player extends JPanel{
    private boolean player_turn = false;
    private int player_order = 0;
    private int banned_fields_size = 0;
    private int banned_fields[] = new int[50];
    private ImageIcon ii;
    private Image image;
    private int player_number = 0;
    private int map_position_x = 0;
    private int map_position_y = 0;
    private int player_position_X;
    private int player_position_y = 0;
    private int movement_points = 0;
    public Shovel shovel = new Shovel();
    public Pickaxe pickaxe = new Pickaxe();
    public Bomb bomb = new Bomb();
    public Yellow_jewel yellow_jewel = new Yellow_jewel();
    public Blue_jewel blue_jewel = new Blue_jewel();
    public White_jewel white_jewel = new White_jewel();
    public Green_jewel green_jewel = new Green_jewel();
    private int player_map[][] = new int[50][40];
    private int score;
    
    public Player(int player_number, int map[][], boolean turn){
        banned_fields[banned_fields_size++] = 0;
        banned_fields[banned_fields_size++] = 9;
        banned_fields[banned_fields_size++] = 10;
        banned_fields[banned_fields_size++] = 11;
        banned_fields[banned_fields_size++] = 17;
        banned_fields[banned_fields_size++] = 18;
        banned_fields[banned_fields_size++] = 23;
        this.player_turn = turn;
        this.player_number = player_number;
        this.player_map = map;
        if(this.player_number == 1){
            ii = new ImageIcon("Images/Player1.png");
            player_position_X = 300;
            map_position_x = 10;
        }
        else if(this.player_number == 2){
            ii = new ImageIcon("Images/Player2.png");
            player_position_X = 330;
            map_position_x = 11;
        }
        else if(this.player_number == 3){
            ii = new ImageIcon("Images/Player3.png");
            player_position_X = 360;
            map_position_x = 12;
        }
        else if(this.player_number == 4){
            ii = new ImageIcon("Images/Player4.png");
            player_position_X = 390;
            map_position_x = 13;
        }
        else if(this.player_number == 5){
            ii = new ImageIcon("Images/Player5.png");
            player_position_X = 420;
            map_position_x = 14;
        }
        else if(this.player_number == 6){
            ii = new ImageIcon("Images/Player6.png");
            player_position_X = 450;
            map_position_x = 15;
        }
        else if(this.player_number == 7){
            ii = new ImageIcon("Images/Player7.png");
            player_position_X = 480;
            map_position_x = 16;
        }
        else if(this.player_number == 8){
            ii = new ImageIcon("Images/Player8.png");
            player_position_X = 510;
            map_position_x = 17;
        }
        setBounds(player_position_X, player_position_y, 30, 30);
        setVisible(true);
    }

    //Functions to check if move is correct
    private boolean is_up_move_ok(){
        if(player_turn == false || movement_points == 0 || map_position_y == 0)
            return false;
        for(int i = 0; i < banned_fields_size; i++){
            if(player_map[map_position_y - 1][map_position_x] == banned_fields[i])
                return false;
        }
        return true;
    }

    private boolean is_down_move_ok(){
        if(player_turn == false || movement_points == 0 || map_position_y == 20)
            return false;
        for(int i = 0; i < banned_fields_size; i++)
            if(player_map[map_position_y + 1][map_position_x] == banned_fields[i])
                return false;
        return true;
    }

    private boolean is_left_move_ok(){
        if(player_turn == false || movement_points == 0 || map_position_x == 0)
            return false;
        for(int i = 0; i < banned_fields_size; i++)
            if(player_map[map_position_y][map_position_x - 1] == banned_fields[i])
                return false;
        return true;
    }

    private boolean is_right_move_ok(){
        if(player_turn == false || movement_points == 0 || map_position_x == 40)
            return false;
        for(int i = 0; i < banned_fields_size; i++)
            if(player_map[map_position_y][map_position_x + 1] == banned_fields[i])
                return false;
        return true;
    }

    private void update_score(){ 
        score = green_jewel.number() + blue_jewel.number() * 2 + yellow_jewel.number() * 3 + white_jewel.number() * 4;
    }

    public int get_score(){
        return score;
    }

    //Dopisac uzywanie przedmiotow z klawiatury
    public void keyPressed(KeyEvent e){
        int key = e.getKeyCode();
        if(key == KeyEvent.VK_UP && is_up_move_ok() == true){
            map_position_y = map_position_y - 1;
            player_position_y = player_position_y - 30;
            movement_points--;
            if(player_map[map_position_y][map_position_x] == 19 || player_map[map_position_y][map_position_x] == 20 || player_map[map_position_y][map_position_x] == 21
               || player_map[map_position_y][map_position_x] == 22){
                   shovel.fill();
                   pickaxe.fill();
                   bomb.fill();
               }
            setBounds(player_position_X, player_position_y, 30, 30);
        }
        else if(key == KeyEvent.VK_DOWN && is_down_move_ok() == true){
            map_position_y = map_position_y + 1;
            player_position_y = player_position_y + 30;
            movement_points--;
            setBounds(player_position_X, player_position_y, 30, 30);
        }
        else if(key == KeyEvent.VK_LEFT && is_left_move_ok() == true){
            map_position_x = map_position_x - 1;
            player_position_X = player_position_X - 30;
            movement_points--;
            setBounds(player_position_X, player_position_y, 30, 30);
        }
        else if(key == KeyEvent.VK_RIGHT && is_right_move_ok() == true){
            map_position_x = map_position_x + 1;
            player_position_X = player_position_X + 30;
            movement_points--;
            setBounds(player_position_X, player_position_y, 30, 30);
        }
        else if(key == KeyEvent.VK_ENTER){
            movement_points = 0;
        }
        update_score();
    }

    public void your_turn(){
        Random random = new Random();
        while(movement_points == 0){
            movement_points = random.nextInt(11);
        }
        player_turn = true;
    }

    public void not_your_turn(){
        player_turn = false;
        movement_points = 0;
    }

    public boolean get_player_turn(){
        return player_turn;
    }

    public int get_player_number(){
        return player_number;
    }

    public int get_player_position_x(){
        return player_position_X;
    }

    public int get_player_position_y(){
        return player_position_y;
    }

    public int get_player_map_position_x(){
        return map_position_x;
    }

    public int get_player_map_position_y(){
        return map_position_y;
    }

    public void set_player_order(int order){
        if(player_order == 0)
            this.player_order = order;
    }

    public int get_player_order(){
        return this.player_order;
    }

    public int get_movement_points(){
        return this.movement_points;
    }    

    public void movement_point_used(){
        movement_points--;
    }

    public void add_move(int number){
        movement_points += number;
    }

    public void decrease_move(int number){
        if(number >= movement_points){
            movement_points = 0;
            return;
        }
        movement_points -= number;
    }

    public void set_x(int number){
        this.map_position_x = number;
        this.player_position_X = this.map_position_x * 30;
    }

    public void set_y(int number){
        this.map_position_y = number;
        this.player_position_y = this.map_position_y * 30;
    }

    public void set_move(int number){
        this.movement_points = number;
    }

    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D graphics = (Graphics2D)g;
        image = ii.getImage();
        graphics.drawImage(image, 0, 0, 30, 30, this);
    }
}