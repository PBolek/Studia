import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class End_game extends JPanel{
    private Map map;
    private Player p1, p2, p3, p4, p5, p6, p7, p8;
    private int number_of_teams = 1;
    private ImageIcon ii;
    private Image image;
    private String team_score;
    private String string;
    public End_game(Map map){
        super();
        setBounds(0, 0, 1500, 820);
        this.map = map;
        setVisible(true);
    }
    public End_game(Map map, Player p1, Player p2, Player p3, Player p4, Player p5, Player p6, Player p7, Player p8, int number_of_teams){
        setBounds(0, 0, 1500, 820);
        setBackground(Color.black);
        this.map = map;
        this.p1 = p1;
        this.p2 = p2;
        this.p3 = p3;
        this.p4 = p4;
        this.p5 = p5;
        this.p6 = p6;
        this.p7 = p7;
        this.p8 = p8;
        this.number_of_teams = number_of_teams;
        setVisible(true);
    }

    public void draw_string(Graphics2D graphics, int x, int y, String string){
        for(int i = 1; i <= string.length(); i++){
            ii = new ImageIcon("Images/" + string.charAt(i - 1) + ".png");
            image = ii.getImage();
            graphics.drawImage(image, x + i * 50, y, 50, 50, this);
        }
    }

    public void quit(){
        System.exit(1);
    }

    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D graphics = (Graphics2D)g;
        if(number_of_teams == 2){
            string = "team 1";
            draw_string(graphics, 100, 100, string);
            team_score = Integer.toString(p1.get_score() + p2.get_score() + p3.get_score() + p4.get_score());
            draw_string(graphics, 500, 100, team_score);
            string = "team 2";
            draw_string(graphics, 100, 200, string);
            team_score = Integer.toString(p5.get_score() + p6.get_score() + p7.get_score() + p8.get_score());
            draw_string(graphics, 500, 200, team_score);
        }
        else if(number_of_teams == 4){
            string = "team 1";
            draw_string(graphics, 100, 100, string);
            string = "team 2";
            draw_string(graphics, 100, 200, string);
            string = "team 3";
            draw_string(graphics, 100, 300, string);
            string = "team 4";
            draw_string(graphics, 100, 400, string);
            team_score = Integer.toString(p1.get_score() + p2.get_score());
            draw_string(graphics, 500, 100, team_score);
            team_score = Integer.toString(p3.get_score() + p4.get_score());
            draw_string(graphics, 500, 200, team_score);
            team_score = Integer.toString(p5.get_score() + p6.get_score());
            draw_string(graphics, 500, 300, team_score);
            team_score = Integer.toString(p7.get_score() + p8.get_score());
            draw_string(graphics, 500, 400, team_score);
        }
        else if(number_of_teams == 8){
            string = "player 1";
            draw_string(graphics, 100, 0, string);
            string = "player 2";
            draw_string(graphics, 100, 100, string);
            string = "player 3";
            draw_string(graphics, 100, 200, string);
            string = "player 4";
            draw_string(graphics, 100, 300, string);
            string = "player 5";
            draw_string(graphics, 100, 400, string);
            string = "player 6";
            draw_string(graphics, 100, 500, string);
            string = "player 7";
            draw_string(graphics, 100, 600, string);
            string = "player 8";
            draw_string(graphics, 100, 700, string);
            team_score = Integer.toString(p1.get_score());
            draw_string(graphics, 550, 0, team_score);
            team_score = Integer.toString(p2.get_score());
            draw_string(graphics, 550, 100, team_score);
            team_score = Integer.toString(p3.get_score());
            draw_string(graphics, 550, 200, team_score);
            team_score = Integer.toString(p4.get_score());
            draw_string(graphics, 550, 300, team_score);
            team_score = Integer.toString(p5.get_score());
            draw_string(graphics, 550, 400, team_score);
            team_score = Integer.toString(p6.get_score());
            draw_string(graphics, 550, 500, team_score);
            team_score = Integer.toString(p7.get_score());
            draw_string(graphics, 550, 600, team_score);
            team_score = Integer.toString(p8.get_score());
            draw_string(graphics, 550, 700, team_score);
        }
        string = "press esc";
        draw_string(graphics, 800, 300, string);
        string = "to exit";
        draw_string(graphics, 850, 400, string);
    }
}