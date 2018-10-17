import javax.swing.*;
import java.awt.*;
import java.io.*;
import java.util.Random;

public class Random_events{
    public int map_int[][] = new int[50][40];
    private final static int number_of_yellow_cases = 4;
    private final static int number_of_black_cases = 4;
    private final static int number_of_violet_fields = 7;
    private Random random = new Random();
    public Random_events(int map_int[][]){
        this.map_int = map_int;
    }

    public void yellow_field_event(Player player){
        Random random = new Random();
        int case_number;
        if(map_int[player.get_player_map_position_y()][player.get_player_map_position_x()] != 2)
            return;
        else{
            case_number = random.nextInt(number_of_yellow_cases);
            if(case_number == 0){
                player.shovel.add();
            }
            else if(case_number == 1){
                player.bomb.add();
            }
            else if(case_number == 2){
                player.bomb.add();
            }
            else if(case_number == 3){
                player.add_move(random.nextInt(5));
            }
        }
    }

    public void black_field_event(Player player){
        int case_number;
        if(map_int[player.get_player_map_position_y()][player.get_player_map_position_x()] != 6)
            return;
        else{
            case_number = random.nextInt(number_of_black_cases);
            if((player.get_player_map_position_x() == 12 && player.get_player_map_position_y() == 3) || (player.get_player_map_position_x() == 15 && player.get_player_map_position_y() == 3)){
                player.set_y(8);
                player.decrease_move(random.nextInt(10));
                if(case_number == 0){
                    player.shovel.used();
                }
                else if(case_number == 1){
                    player.bomb.used();
                }
                else if(case_number == 2){
                    player.pickaxe.used();
                }
                player.setBounds(player.get_player_position_x(), player.get_player_position_y(), 30, 30);
            }
            else if(case_number == 0){
                player.shovel.used();
            }
            else if(case_number == 1){
                player.pickaxe.used();
            }
            else if(case_number == 2){
                player.bomb.used();
            }
            else if(case_number == 3){
                player.decrease_move(random.nextInt(5));
            }
        }
    }

    public void violet_field_event(Player player){
        int previous_x = player.get_player_map_position_x();
        int previous_y = player.get_player_map_position_y();
        int case_number;
        if(map_int[previous_y][previous_x] != 5)
            return;
        else{
            while(previous_y == player.get_player_map_position_y() && previous_x == player.get_player_map_position_x()){
                case_number = random.nextInt(number_of_violet_fields);
                if(case_number == 0){
                    player.set_y(3);
                    player.set_x(6);
                }
                else if(case_number == 1){
                    player.set_y(3);
                    player.set_x(25);
                }
                else if(case_number == 2){
                    player.set_y(19);
                    player.set_x(3);
                }
                else if(case_number == 3){
                    player.set_y(19);
                    player.set_x(27);
                }
                else if(case_number == 4){
                    player.set_y(12);
                    player.set_x(15);
                }
                else if(case_number == 5){
                    player.set_y(11);
                    player.set_x(22);
                }
                else if(case_number == 6){
                    player.set_y(19);
                    player.set_x(15);
                }
                player.setBounds(player.get_player_position_x(), player.get_player_position_y(), 30, 30);
            }
            player.set_move(1);
        }
    }
}