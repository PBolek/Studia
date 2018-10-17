import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.Random;

public class Map extends JPanel{
    //bombed field with jewel lvl1 = 2341
    //bombed field with jewel lvl2 = 2342
    //bombed field with jewel lvl3 = 2343
    //bombed field with jewel lvl4 = 2344
    //bombed field = 23
    //bombed black field = 2306
    //field with jewel lvl1 = 41
    //field with jewel lvl2 = 42
    //field with jewel lvl3 = 43
    //field with jewel lvl4 = 44
    public int[][] map_int = new int[50][40];
    private int x;
    private int y;
    private ImageIcon ii0 = new ImageIcon("Images/field0_black.png");
    private ImageIcon ii1 = new ImageIcon("Images/field1_green.png");
    private ImageIcon ii2 = new ImageIcon("Images/field2_yellow.png");
    private ImageIcon ii3 = new ImageIcon("Images/field3_brown.png");
    private ImageIcon ii4 = new ImageIcon("Images/field4_blue.png");
    private ImageIcon ii5 = new ImageIcon("Images/field5_violet.png");
    private ImageIcon ii6 = new ImageIcon("Images/field6_black.png");
    private ImageIcon ii7 = new ImageIcon("Images/field7_landing.png");
    private ImageIcon ii8 = new ImageIcon("Images/field8_fall_start.png");
    private ImageIcon ii9 = new ImageIcon("Images/field9_fall.png");
    private ImageIcon ii10 = new ImageIcon("Images/field10_trader_down_left.png");
    private ImageIcon ii11 = new ImageIcon("Images/field11_trader_down_right.png");
    private ImageIcon ii12 = new ImageIcon("Images/field12_trader_middle.png");
    private ImageIcon ii13 = new ImageIcon("Images/field13_trader_middle_down.png");
    private ImageIcon ii14 = new ImageIcon("Images/field14_trader_middle_left.png");
    private ImageIcon ii15 = new ImageIcon("Images/field15_trader_middle_right.png");
    private ImageIcon ii16 = new ImageIcon("Images/field16_trader_middle_up.png");
    private ImageIcon ii17 = new ImageIcon("Images/field17_trader_up_left.png");
    private ImageIcon ii18 = new ImageIcon("Images/field18_trader_up_right.png");
    private ImageIcon ii19 = new ImageIcon("Images/field19_city1.png");
    private ImageIcon ii20 = new ImageIcon("Images/field20_city2.png");
    private ImageIcon ii21 = new ImageIcon("Images/field21_city3.png");
    private ImageIcon ii22 = new ImageIcon("Images/field22_city4.png");
    private ImageIcon ii23 = new ImageIcon("Images/field23_stone.png");
    private static final int number_of_field_types = 23;
    private Image image;
    private Random random = new Random();
    private int item_rank = 0;
    private int random_x;
    private int random_y;
    private int flag = 0;
    private int flag2 = 0;
    private int first_floor_item1 = 0;
    private int first_floor_item2 = 0;
    private int first_floor_item3 = 0;
    private int first_floor_item4 = 0;
    private int second_floor_item1 = 0;
    private int second_floor_item2 = 0;
    private int second_floor_item3 = 0;
    private int second_floor_item4 = 0;
    private int first_floor_black_fields = 0;
    private int second_floor_black_fields = 0;
    private int first_yellow_fields = 0;
    private int second_yellow_fields = 0;
    private final static int first_max_yellow_fields = 8;
    private final static int second_max_yellow_fields = 10;
    private int sum;
    private int score[] = new int[8];
    public Map(){
        super();
        setBounds(0, 0, 1200, 600);

        //City
        //row number 0
        map_int[0][10] = 21;
        map_int[0][11] = 22;
        map_int[0][12] = 19;
        map_int[0][13] = 20;
        map_int[0][14] = 21;
        map_int[0][15] = 22;
        map_int[0][16] = 19;
        map_int[0][17] = 20;
        //Green fields
        //row number 1
        for(int i = 9; i < 19; i++){
            map_int[1][i] = 1;
        }

        //row number 2
        map_int[2][10] = 1;
        map_int[2][17] = 1;
        map_int[2][31] = 1;

        //row number 3
        map_int[3][6] = 1;
        for(int i = 8; i < 12; i++){
            map_int[3][i] = 1;
        }
        map_int[3][12] = 6;
        map_int[3][13] = 9;
        map_int[3][14] = 9;
        map_int[3][15] = 6;
        for(int i = 16; i < 20; i++){
            map_int[3][i] = 1;
        }
        map_int[3][21] = 1;
        map_int[3][22] = 1;
        map_int[3][25] = 1;
        map_int[3][31] = 1;

        //row number 4
        map_int[4][4] = 1;
        map_int[4][5] = 1;
        map_int[4][6] = 1;
        map_int[4][8] = 1;
        //fill the fall
        for(int i = 4; i < 8; i++){
            for(int j = 12; j < 16; j++){
                map_int[i][j] = 9;
            }
        }
        map_int[4][19] = 1;
        map_int[4][22] = 1;
        for(int i = 25; i < 29; i++){
            map_int[4][i] = 1;
        }
        map_int[4][31] = 1;
        map_int[4][34] = 1;

        //row number 5
        map_int[5][4] = 1;
        map_int[5][8] = 1;
        map_int[5][9] = 1;
        for(int i = 17; i < 20; i++){
            map_int[5][i] = 1;
        }
        for(int i = 21; i < 24; i++){
            map_int[5][i] = 1;
        }
        map_int[5][25] = 1;
        map_int[5][28] = 1;
        for(int i = 30; i < 33; i++){
            map_int[5][i] = 1;
        }
        map_int[5][34] = 1;

        //row number 6
        for(int i = 3; i < 7; i++){
            map_int[6][i] = 1;
        }
        map_int[6][9] = 1;
        map_int[6][10] = 1;
        map_int[6][17] = 1;
        map_int[6][21] = 1;
        map_int[6][23] = 1;
        map_int[6][25] = 1;
        for(int i = 28; i < 35; i++){
            if(i % 2 == 0)
                map_int[6][i] = 1;
        }

        //row number 7
        map_int[7][3] = 1;
        map_int[7][6] = 1;
        map_int[7][10] = 1;
        for(int i = 17; i < 35; i++){
            if(i != 19 && i != 22 && i != 27 && i != 29 && i != 31 && i != 33)
                map_int[7][i] = 1;
        }

        //row number 8
        for(int i = 3; i < 11; i++){
            if(i != 5)
                map_int[8][i] = 1;
        }
        //fill the fall landing
        for(int i = 12; i < 16; i++){
            map_int[8][i] = 7;
        }
        for(int i = 18; i < 21; i++){
            map_int[8][i] = 1;
        }
        for(int i = 24; i < 35; i++){
            if(i != 25 && i != 27 && i != 31)
                map_int[8][i] = 1;
        }

        //row number 9
        map_int[9][3] = 1;
        map_int[9][7] = 1;
        map_int[9][12] = 1;
        map_int[9][15] = 1;
        map_int[9][20] = 1;
        map_int[9][22] = 1;
        map_int[9][23] = 1;
        map_int[9][24] = 1;
        map_int[9][26] = 1;
        map_int[9][34] = 1;

        //row numeber 10
        for(int i = 3; i < 35; i++){
            if( i != 6 && i != 10 && i != 13 && i != 14 && 
                i != 17 && i != 18 && i != 21 && i != 23 && 
                i != 24 && i != 25 && i != 29 )
                map_int[10][i] = 1;
        }

        //row number 11
        map_int[11][5] = 1;
        map_int[11][9] = 1;
        map_int[11][10] = 1;
        map_int[11][11] = 1;
        for(int i = 16; i < 20; i++){
            map_int[11][i] = 1;
        }
        map_int[11][28] = 1;
        map_int[11][30] = 1;
        map_int[11][32] = 1;
        //End of green fields
        
        //Brown Fields
        //row number 12
        map_int[12][5] = 3;
        map_int[12][7] = 3;
        map_int[12][13] = 3;
        map_int[12][14] = 3;
        map_int[12][17] = 3;
        for(int i = 22; i < 35; i++){
            if(i != 29 && i != 31 && i != 33)
                map_int[12][i] = 3;
        }

        //row number 13
        for(int i = 3; i < 14; i++){
            map_int[13][i] = 3;
        }
        map_int[13][17] = 3;
        for(int i = 19; i < 23; i++){
            map_int[13][i] = 3;
        }
        for(int i = 32; i < 35; i++){
            map_int[13][i] = 3;
        }

        //row number 14
        map_int[14][3] = 3;
        map_int[14][12] = 3;
        map_int[14][15] = 3;
        map_int[14][16] = 3;
        map_int[14][17] = 3;
        map_int[14][19] = 3;
        map_int[14][22] = 3;
        map_int[14][25] = 3;
        map_int[14][26] = 3;
        map_int[14][27] = 3;
        map_int[14][33] = 3;

        //row number 15
        map_int[15][3] = 3;
        map_int[15][6] = 3;
        for(int i = 9; i < 13; i++){
            map_int[15][i] = 3;
        }
        map_int[15][15] = 3;
        map_int[15][19] = 3;
        map_int[15][20] = 3;
        for(int i = 22; i < 26; i++){
            map_int[15][i] = 3;
        }
        map_int[15][27] = 3;
        for(int i = 29; i < 34; i++){
            map_int[15][i] = 3;
        }

        //row number 16
        map_int[16][3] = 3;
        map_int[16][5] = 3;
        map_int[16][6] = 3;
        map_int[16][7] = 3;
        map_int[16][9] = 3;
        map_int[16][11] = 3;
        map_int[16][14] = 17;
        map_int[16][15] = 16;
        map_int[16][16] = 18;
        map_int[16][20] = 3;
        map_int[16][27] = 3;
        map_int[16][29] = 3;

        //row number 17
        for(int i = 3; i < 6; i++){
            map_int[17][i] = 3;
        }
        map_int[17][7] = 3;
        map_int[17][9] = 3;
        for(int i = 11; i < 14; i++){
            map_int[17][i] = 3;
        }
        map_int[17][14] = 14;
        map_int[17][15] = 12;
        map_int[17][16] = 15;
        for(int i = 17; i < 21; i++){
            map_int[17][i] = 3;
        }
        for(int i = 24; i < 28; i++){
            map_int[17][i] = 3;
        }

        //row number 18
        map_int[18][4] = 3;
        map_int[18][7] = 3;
        map_int[18][9] = 3;
        map_int[18][11] = 3;
        map_int[18][14] = 10;
        map_int[18][15] = 13;
        map_int[18][16] = 11;
        map_int[18][22] = 3;
        map_int[18][23] = 3;
        map_int[18][24] = 3;
        map_int[18][27] = 3;

        //row number 19
        map_int[19][3] = 3;
        map_int[19][4] = 3;
        for(int i = 7; i < 10; i++){
            map_int[19][i] = 3;
        }
        map_int[19][11] = 3;
        map_int[19][12] = 3;
        map_int[19][15] = 3;
        for(int i = 20; i < 23; i++){
            map_int[19][i] = 3;
        }
        map_int[19][26] = 3;

        //Set blue fields
        while(flag != 1){
            random_x = random.nextInt(50);
            random_y = random.nextInt(40);
            if(map_int[random_x][random_y] == 1){
                while(flag2 != 1){
                    item_rank = random.nextInt(5);
                    if(item_rank == 1 && first_floor_item1 != 10){
                        map_int[random_x][random_y] = 41;
                        first_floor_item1 = first_floor_item1 + 1;
                        flag2 = 1;
                    }
                    if(item_rank == 2 && first_floor_item2 != 4){
                        map_int[random_x][random_y] = 42;
                        first_floor_item2 = first_floor_item2 + 1;
                        flag2 = 1;
                    }
                    if(item_rank == 3 && first_floor_item3 != 2){
                        map_int[random_x][random_y] = 43;
                        first_floor_item3 = first_floor_item3 + 1;
                        flag2 = 1;
                    }
                    if(item_rank == 4 && first_floor_item4 != 1){
                        map_int[random_x][random_y] = 44;
                        first_floor_item4 = first_floor_item4 + 1;
                        flag2 = 1;
                    }
                }
                flag2 = 0;
            }
            else if(map_int[random_x][random_y] == 3){
                while(flag2 != 1){
                    item_rank = random.nextInt(5);
                    if(item_rank == 1 && second_floor_item1 != 7){
                        map_int[random_x][random_y] = 41;
                        second_floor_item1 = second_floor_item1 + 1;
                        flag2 = 1;
                    }
                    if(item_rank == 2 && second_floor_item2 != 4){
                        map_int[random_x][random_y] = 42;
                        second_floor_item2  = second_floor_item2 + 1;
                        flag2 = 1;
                    }
                    if(item_rank == 3 && second_floor_item3 != 4){
                        map_int[random_x][random_y] = 43;
                        second_floor_item3 = second_floor_item3 + 1;
                        flag2 = 1;
                    }
                    if(item_rank == 4 && second_floor_item4 != 2){
                        map_int[random_x][random_y] = 44;
                        second_floor_item4 = second_floor_item4 + 1;
                        flag2 = 1;
                    }
                }
                flag2 = 0;
            }
            if(first_floor_item1 == 10 && first_floor_item2 == 4 && first_floor_item3 == 2 && first_floor_item4 == 1)
                flag = 1;
        }
        flag = 0;

        //Set black fields
        while(flag != 1){
            random_x = random.nextInt(50);
            random_y = random.nextInt(40);
            if(map_int[random_x][random_y] == 1 && first_floor_black_fields != 4){
                map_int[random_x][random_y] = 6;
                first_floor_black_fields = first_floor_black_fields + 1;
            }
            else if(map_int[random_x][random_y] == 3 && second_floor_black_fields != 8){
                map_int[random_x][random_y] = 6;
                second_floor_black_fields = second_floor_black_fields + 1;
            }
            if(first_floor_black_fields == 4 && second_floor_black_fields == 8)
                flag = 1;
        }
        flag = 0;
        //set yellow fields
        while(flag != 1){
            random_x = random.nextInt(50);
            random_y = random.nextInt(20);
            if(map_int[random_x][random_y] == 1 && first_yellow_fields < first_max_yellow_fields){
                map_int[random_x][random_y] = 2;
                first_yellow_fields++;
            }
            else if(map_int[random_x][random_y] == 3 && second_yellow_fields < second_max_yellow_fields){
                map_int[random_x][random_y] = 2;
                second_yellow_fields++;
            }
            if(first_yellow_fields == first_max_yellow_fields && second_yellow_fields == second_max_yellow_fields)
                flag = 1;
        }
        flag = 0;

        //set violet fields
        map_int[3][6] = 5;
        map_int[3][25] = 5;
        map_int[19][3] = 5;
        map_int[19][27] = 5;
        map_int[12][15] = 5;
        map_int[11][22] = 5;
        map_int[19][15] = 5;

        sum = first_floor_item1 + first_floor_item2 + first_floor_item3 + first_floor_item4 + second_floor_item1 + second_floor_item2 + second_floor_item3 + second_floor_item4;
        setVisible(true);
    }

    public int get_total_number_of_jewels(){
        return sum;
    }

    public void dec_sum_of_jewels(){
        this.sum--;
    }

    public void set_the_score(int p1_score, int p2_score, int p3_score, int p4_score, int p5_score, int p6_score, int p7_score, int p8_score){
        /*score[0] = p1_score;
        score[1] = p2_score;
        score[2] = p3_score;
        score[3] = p4_score;
        score[4] = p5_score;
        score[5] = p6_score;
        score[6] = p7_score;
        score[7] = p8_score;*/
    }
    
    @Override
    public void paintComponent(Graphics g){
        super.paintComponent(g);
        Graphics2D graphics = (Graphics2D)g;
        x = 0;
        y = 0;
        //Draw map
        for(int i = 0; i < 20; i++){
            for(int  j = 0; j < 40; j++){
                if(map_int[i][j] == 0)
                    image = ii0.getImage();
                else if(map_int[i][j] == 1)
                    image = ii1.getImage();
                else if(map_int[i][j] == 2)
                    image = ii2.getImage();
                else if(map_int[i][j] == 3)
                    image = ii3.getImage();
                else if(map_int[i][j] == 41 || map_int[i][j] == 42 || map_int[i][j] == 43 || map_int[i][j] == 44)
                    image = ii4.getImage();
                else if(map_int[i][j] == 5)
                    image = ii5.getImage();
                else if(map_int[i][j] == 6)
                    image = ii6.getImage();
                else if(map_int[i][j] == 7)
                    image = ii7.getImage();
                else if(map_int[i][j] == 8)
                    image = ii8.getImage();
                else if(map_int[i][j] == 9)
                    image = ii9.getImage();
                else if(map_int[i][j] == 10)
                    image = ii10.getImage();
                else if(map_int[i][j] == 11)
                    image = ii11.getImage();
                else if(map_int[i][j] == 12)
                    image = ii12.getImage();
                else if(map_int[i][j] == 13)
                    image = ii13.getImage();
                else if(map_int[i][j] == 14)
                    image = ii14.getImage();
                else if(map_int[i][j] == 15)
                    image = ii15.getImage();
                else if(map_int[i][j] == 16)
                    image = ii16.getImage();
                else if(map_int[i][j] == 17)
                    image = ii17.getImage();
                else if(map_int[i][j] == 18)
                    image = ii18.getImage();
                else if(map_int[i][j] == 19)
                    image = ii19.getImage();
                else if(map_int[i][j] == 20)
                    image = ii20.getImage();
                else if(map_int[i][j] == 21)
                    image = ii21.getImage();
                else if(map_int[i][j] == 22)
                    image = ii22.getImage();
                else if(map_int[i][j] == 23 || map_int[i][j] == 2341 || map_int[i][j] == 2342 || map_int[i][j] == 2343 || map_int[i][j] == 2344 || map_int[i][j] == 2306)
                    image = ii23.getImage();
                graphics.drawImage(image, x, y, 30, 30, this);
                x = x + 30;
            }
            y = y + 30;
            x = 0;
        }
    }
}