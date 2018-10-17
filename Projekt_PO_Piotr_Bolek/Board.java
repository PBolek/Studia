import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
import java.util.Random;

public class Board extends JFrame{
    private Turn turn = new Turn();
    private Equipement equipement = new Equipement();
    private Map map = new Map();
    private Player player1 = new Player(1, map.map_int, false);
    private Player player2 = new Player(2, map.map_int, false);
    private Player player3 = new Player(3, map.map_int, false);
    private Player player4 = new Player(4, map.map_int, false);
    private Player player5 = new Player(5, map.map_int, false);
    private Player player6 = new Player(6, map.map_int, false);
    private Player player7 = new Player(7, map.map_int, false);
    private Player player8 = new Player(8, map.map_int, false);
    private End_game end_game = new End_game(map);
    private Game_stats game_stats = new Game_stats(0, 0, 0, 0);
    private Random_events random_events = new Random_events(map.map_int);
    private boolean bomb_use = false;
    private boolean pickaxe_use = false;
    private boolean item_use = false;
    private int player_floor_position;
    private int player_x;
    private int player_y;
    private int number_of_players = 8;
    private int number_of_teams = 8;
    private Menu menu = new Menu();
    private enum STATE{
        MENU,
        GAME,
        END_GAME
    };
    private STATE state = STATE.MENU;
    public Board(int c){
        super("Board");
        if(c == 1)
            state = STATE.MENU;
        else if(c == 2)
            state = STATE.GAME;
        else if(c == 3)
            state = STATE.END_GAME;
        setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        setSize(1500,820);
        setResizable(false);
        addKeyListener(new TAdapter());
        setFocusable(true);
        setBackground(Color.black);
        //Set players order
        int first_player = 0;
        for(int i = 1; i <= number_of_players; i++){
            if(turn.get_playerX_order(i) == 1)
                first_player = i;
        }
        if(first_player == 1){
            player1.your_turn();
            game_stats.set_stats(player1.green_jewel.number(), player1.blue_jewel.number(), player1.yellow_jewel.number(), player1.white_jewel.number(),
                                player1.get_movement_points(), player1.shovel.number(), player1.bomb.number(), player1.pickaxe.number());
        }
        else if(first_player == 2){
            player2.your_turn();
            game_stats.set_stats(player2.green_jewel.number(), player2.blue_jewel.number(), player2.yellow_jewel.number(), player2.white_jewel.number(),
                                                player2.get_movement_points(), player2.shovel.number(), player2.bomb.number(), player2.pickaxe.number());
        }
        else if(first_player == 3){
            player3.your_turn();
            game_stats.set_stats(player3.green_jewel.number(), player3.blue_jewel.number(), player3.yellow_jewel.number(), player3.white_jewel.number(), 
                                                player3.get_movement_points(), player3.shovel.number(), player3.bomb.number(), player3.pickaxe.number());
        }
        else if(first_player == 4){
            player4.your_turn();
            game_stats.set_stats(player4.green_jewel.number(), player4.blue_jewel.number(), player4.yellow_jewel.number(), player4.white_jewel.number(),
                                                player4.get_movement_points(), player4.shovel.number(), player4.bomb.number(), player4.pickaxe.number()); 
        }
        else if(first_player == 5){
            player5.your_turn();
            game_stats.set_stats(player5.green_jewel.number(), player5.blue_jewel.number(), player5.yellow_jewel.number(), player5.white_jewel.number(),
                                                player5.get_movement_points(), player5.shovel.number(), player5.bomb.number(), player5.pickaxe.number());
        }
        else if(first_player == 6){
            player6.your_turn();
            game_stats.set_stats(player6.green_jewel.number(), player6.blue_jewel.number(), player6.yellow_jewel.number(), player6.white_jewel.number(),
                                                player6.get_movement_points(), player6.shovel.number(), player6.bomb.number(), player6.pickaxe.number());
        }
        else if(first_player == 7){
            player7.your_turn();
            game_stats.set_stats(player7.green_jewel.number(), player7.blue_jewel.number(), player7.yellow_jewel.number(), player7.white_jewel.number(),
                                                player7.get_movement_points(), player7.shovel.number(), player7.bomb.number(), player7.pickaxe.number());
        }
        else if(first_player == 8){
            player8.your_turn();
            game_stats.set_stats(player8.green_jewel.number(), player8.blue_jewel.number(), player8.yellow_jewel.number(), player8.white_jewel.number(),
                                                player8.get_movement_points(), player8.shovel.number(), player8.bomb.number(), player8.pickaxe.number());
        }

        player1.set_player_order(turn.get_playerX_order(1));
        player2.set_player_order(turn.get_playerX_order(2));
        player3.set_player_order(turn.get_playerX_order(3));
        player4.set_player_order(turn.get_playerX_order(4));
        player5.set_player_order(turn.get_playerX_order(5));
        player6.set_player_order(turn.get_playerX_order(6));
        player7.set_player_order(turn.get_playerX_order(7));
        player8.set_player_order(turn.get_playerX_order(8));

        if(state == STATE.MENU){
            add(menu);
        }
        else if(state == STATE.GAME){
            add(player1);
            add(player2);
            add(player3);
            add(player4);
            add(player5);
            add(player6);
            add(player7);
            add(player8);
            add(map);
            add(game_stats);
            add(turn);
            add(equipement);  
        }
        else if(state == STATE.END_GAME){
            add(end_game);
        }
        setVisible(true);
    }

    private void where_to_use_pickaxe(int keyCode, Player player){
        //green fields 1->11
        //brown fields 12->19
        int player_field = 0;
        int key = keyCode;
        int player_position_y = player.get_player_map_position_y();
        int player_position_x = player.get_player_map_position_x();

        if(player_position_y == 0)
            return;
        else if(key == KeyEvent.VK_RIGHT && player_position_x == 40)
            return;
        else if(key == KeyEvent.VK_DOWN && player_position_y == 20)
            return;
        else if(key == KeyEvent.VK_LEFT && player_position_x == 0)
            return;

        int player_up_field = map.map_int[player_position_y - 1][player_position_x];
        int player_right_field = map.map_int[player_position_y][player_position_x + 1];
        int player_down_field = map.map_int[player_position_y + 1][player_position_x];
        int player_left_field = map.map_int[player_position_y][player_position_x - 1];

        if(key == KeyEvent.VK_UP && player_up_field == 19 || key == KeyEvent.VK_UP && player_up_field == 20 ||
           key == KeyEvent.VK_UP && player_up_field == 21 || key == KeyEvent.VK_UP && player_up_field == 22){
            return;
        }
        
        player.pickaxe.used();
        game_stats.set_pickaxe(player.pickaxe.number());

        if(player_position_y >= 1 || player_position_y <= 11)
            player_field = 1;
        else if(player_position_y >= 12 || player_position_y <= 19)
            player_field = 2;
        
        if(key == KeyEvent.VK_UP){
            if(player_up_field == 2341 || player_up_field == 2342 || player_up_field == 2343 || player_up_field == 2344 || player_up_field == 2306)
                map.map_int[player_position_y - 1][player_position_x] = player_right_field % 100;
            else
                map.map_int[player_position_y - 1][player_position_x] = player_field;
        } 
        else if(key == KeyEvent.VK_RIGHT){
            if(player_right_field == 2341 || player_right_field == 2342 || player_right_field == 2343 || player_right_field == 2344 || player_right_field == 2306)
                map.map_int[player_position_y][player_position_x + 1] = player_right_field % 100;
            else
                map.map_int[player_position_y][player_position_x + 1] = player_field;
        }
        else if(key == KeyEvent.VK_DOWN){
            if(player_down_field == 2341 || player_down_field == 2342 || player_down_field == 2343 || player_down_field == 2344 || player_down_field == 2306)
                map.map_int[player_position_y + 1][player_position_x] = player_down_field % 100;
            else
                map.map_int[player_position_y + 1][player_position_x] = player_field;
        }
        else if(key == KeyEvent.VK_LEFT){
            if(player_left_field == 2341 || player_left_field == 2342 || player_left_field == 2343 || player_left_field == 2344 || player_left_field == 2306)
                map.map_int[player_position_y][player_position_x - 1] = player_left_field % 100;
            else
                map.map_int[player_position_y][player_position_x - 1] = player_field;
        }
    }

    private void where_to_use_bomb(int keyCode, Player player){
        int key = keyCode;
        int player_position_y = player.get_player_map_position_y();
        int player_position_x = player.get_player_map_position_x();

        if(player_position_y == 0)
            return;
        else if(key == KeyEvent.VK_RIGHT && player_position_x == 40)
            return;
        else if(key == KeyEvent.VK_DOWN && player_position_y == 20)
            return;
        else if(key == KeyEvent.VK_LEFT && player_position_x == 0)
            return;

        int player_up_field = map.map_int[player_position_y - 1][player_position_x];
        int player_right_field = map.map_int[player_position_y][player_position_x + 1];
        int player_down_field = map.map_int[player_position_y + 1][player_position_x];
        int player_left_field = map.map_int[player_position_y][player_position_x - 1];

        if(key == KeyEvent.VK_UP && player_up_field == 19 || key == KeyEvent.VK_UP && player_up_field == 20 || key == KeyEvent.VK_UP && player_up_field == 21 ||
        key == KeyEvent.VK_UP && player_up_field == 22){
            return;
        }

        player.bomb.used();
        game_stats.set_bomb(player.bomb.number());

        if(key == KeyEvent.VK_UP){
            if(player_up_field == 41 || player_up_field == 42 || player_up_field == 43 || player_up_field == 44 || player_up_field == 6)
                map.map_int[player_position_y - 1][player_position_x] = 2300 + player_up_field;
            else
                map.map_int[player_position_y - 1][player_position_x] = 23;
        }
        else if(key == KeyEvent.VK_RIGHT){
            if(player_right_field == 41 || player_right_field == 42 || player_right_field == 43 || player_right_field == 44 || player_right_field == 6)
                map.map_int[player_position_y][player_position_x + 1] = 2300 + player_right_field;
            else
                map.map_int[player_position_y][player_position_x + 1] = 23;
        }
        else if(key == KeyEvent.VK_DOWN){
            if(player_down_field == 41 || player_down_field == 42 || player_down_field == 43 || player_down_field == 44 || player_down_field == 6)
                map.map_int[player_position_y + 1][player_position_x] = 2300 + player_down_field;
            else
                map.map_int[player_position_y + 1][player_position_x] = 23;
        }
        else if(key == KeyEvent.VK_LEFT){
            if(player_left_field == 41 || player_left_field == 42 || player_left_field == 43 || player_left_field == 44 || player_left_field == 6)
                map.map_int[player_position_y][player_position_x - 1] = 2300 + player_left_field;
            else
                map.map_int[player_position_y][player_position_x - 1] = 23;
        }
    }

    private void item_used(int keyCode, Player player){
        int player_floor = 0;
        int pos_x = player.get_player_map_position_x();
        int pos_y = player.get_player_map_position_y();
        int key = keyCode;
        if(pos_y >= 1 && pos_y <= 11)
            player_floor = 1;
        else if(pos_y >= 12 && pos_y <= 20)
            player_floor = 3;
        if(key == KeyEvent.VK_Z){
            //Pickaxe used
            if(player.pickaxe.number() == 0){
                pickaxe_use = false;
                return;
            }
            pickaxe_use = true;
        }
        else if(key == KeyEvent.VK_X){
            //Shovel used
            if(player.shovel.number() == 0)
                return;
            if(map.map_int[pos_y][pos_x] == 41){
                player.shovel.used();
                player.green_jewel.picked();
                game_stats.set_green(player.green_jewel.number());
                game_stats.set_shovel(player.shovel.number());
                map.map_int[pos_y][pos_x] = player_floor;
                map.dec_sum_of_jewels();
            }
            else if(map.map_int[pos_y][pos_x] == 42){
                player.shovel.used();
                player.blue_jewel.picked();
                game_stats.set_blue(player.blue_jewel.number());
                game_stats.set_shovel(player.shovel.number());
                map.map_int[pos_y][pos_x] = player_floor;
                map.dec_sum_of_jewels();
            }
            else if(map.map_int[pos_y][pos_x] == 43){
                player.shovel.used();
                player.yellow_jewel.picked();
                game_stats.set_blue(player.blue_jewel.number());
                game_stats.set_shovel(player.shovel.number());
                map.map_int[pos_y][pos_x] = player_floor;
                map.dec_sum_of_jewels();
            }
            else if(map.map_int[pos_y][pos_x] == 44){
                player.shovel.used();
                player.white_jewel.picked();
                game_stats.set_white(player.white_jewel.number());
                game_stats.set_shovel(player.shovel.number());
                map.map_int[pos_y][pos_x] = player_floor;
                map.dec_sum_of_jewels();
            }
        }
        else if(key == KeyEvent.VK_C){
            //Bomb used
            if(player.bomb.number() == 0){
                bomb_use = false;
                return;
            }
            bomb_use = true;
        }
        else if(bomb_use == true){
            where_to_use_bomb(key, player);
            bomb_use = false;
            repaint();
        }
        else if(pickaxe_use == true){
            where_to_use_pickaxe(key, player);
            pickaxe_use = false;
            repaint();
        }
    }

    private void end_game(){
        state = STATE.END_GAME;
        remove(player1);
        remove(player2);
        remove(player3);
        remove(player4);
        remove(player5);
        remove(player6);
        remove(player7);
        remove(player8);
        remove(map);
        remove(equipement);
        remove(game_stats);
        remove(turn);
        end_game = new End_game(map, player1, player2, player3, player4, player5, player6, player7, player8, number_of_teams);
        add(end_game);
        repaint();
    }

    private void end_menu(){
        state = STATE.GAME;
        remove(menu);
        add(player1);
        add(player2);
        add(player3);
        add(player4);
        add(player5);
        add(player6);
        add(player7);
        add(player8);
        add(map);
        add(equipement);
        add(game_stats);
        add(turn);
        repaint();
    }

    private class TAdapter extends KeyAdapter{
        @Override
        public void keyPressed(KeyEvent e){
            int key = e.getKeyCode();
            if(state == STATE.MENU){
                if(key == KeyEvent.VK_ENTER){
                    add(menu);
                    repaint();
                }
                if(menu.state == Menu.STATE.PLAY){
                    if(key == KeyEvent.VK_2){
                        number_of_teams = 2;
                        end_menu();
                    }
                    else if(key == KeyEvent.VK_4){
                        number_of_teams = 4;
                        end_menu();
                    }
                    else if(key == KeyEvent.VK_8){
                        number_of_teams = 8;
                        end_menu();
                    }
                }
                else{
                    if(key == KeyEvent.VK_1){
                        menu.play();
                    }
                    else if(key == KeyEvent.VK_2){
                        menu.quit();
                    }
                }
            }
            else if(state == STATE.GAME){
                repaint();
                game_stats.repaint();
                if(key == KeyEvent.VK_ESCAPE){
                    end_game();
                }
                if(turn.get_turn() == player1.get_player_order()){
                    if(key == KeyEvent.VK_Z || key == KeyEvent.VK_X || key == KeyEvent.VK_C){
                        item_used(key, player1);
                        item_use = true;
                    }
                    else if((item_use && key == KeyEvent.VK_UP) || (item_use && key == KeyEvent.VK_DOWN) || (item_use && key == KeyEvent.VK_RIGHT) || (item_use && key == KeyEvent.VK_LEFT)){
                        item_used(key, player1);
                        item_use = false;
                    }
                    else{
                        item_use = false;
                        player1.keyPressed(e);
                        player_x = player1.get_player_map_position_x();
                        player_y = player1.get_player_map_position_y();
                        if(map.map_int[player_y][player_x] == 2){
                            if(player_y >= 1 && player_y <= 11)
                                player_floor_position = 1;
                            else if(player_y >= 12 && player_y <= 19)
                                player_floor_position = 3;
                            random_events.yellow_field_event(player1);
                            map.map_int = random_events.map_int;
                            map.map_int[player_y][player_x] = player_floor_position;
                        }
                        else if(map.map_int[player_y][player_x] == 6){
                            random_events.black_field_event(player1);
                        }
                        else if(map.map_int[player_y][player_x] == 5){
                            random_events.violet_field_event(player1);
                        }
                        game_stats.set_move(player1.get_movement_points());
                        if(player1.get_movement_points() == 0){
                            player1.not_your_turn();
                            turn.next_turn();
                            if(turn.who_should_move_in_this_turn(turn.get_turn()) == 2){
                                player2.your_turn();
                                game_stats.set_stats(player2.green_jewel.number(), player2.blue_jewel.number(), player2.yellow_jewel.number(), player2.white_jewel.number(),
                                                    player2.get_movement_points(), player2.shovel.number(), player2.bomb.number(), player2.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 3){
                                player3.your_turn();
                                game_stats.set_stats(player3.green_jewel.number(), player3.blue_jewel.number(), player3.yellow_jewel.number(), player3.white_jewel.number(), 
                                                    player3.get_movement_points(), player3.shovel.number(), player3.bomb.number(), player3.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 4){
                                player4.your_turn();
                                game_stats.set_stats(player4.green_jewel.number(), player4.blue_jewel.number(), player4.yellow_jewel.number(), player4.white_jewel.number(),
                                                    player4.get_movement_points(), player4.shovel.number(), player4.bomb.number(), player4.pickaxe.number()); 
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 5){
                                player5.your_turn();
                                game_stats.set_stats(player5.green_jewel.number(), player5.blue_jewel.number(), player5.yellow_jewel.number(), player5.white_jewel.number(),
                                                    player5.get_movement_points(), player5.shovel.number(), player5.bomb.number(), player5.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 6){
                                player6.your_turn();
                                game_stats.set_stats(player6.green_jewel.number(), player6.blue_jewel.number(), player6.yellow_jewel.number(), player6.white_jewel.number(),
                                                    player6.get_movement_points(), player6.shovel.number(), player6.bomb.number(), player6.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 7){
                                player7.your_turn();
                                game_stats.set_stats(player7.green_jewel.number(), player7.blue_jewel.number(), player7.yellow_jewel.number(), player7.white_jewel.number(),
                                                    player7.get_movement_points(), player7.shovel.number(), player7.bomb.number(), player7.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 8){
                                player8.your_turn();
                                game_stats.set_stats(player8.green_jewel.number(), player8.blue_jewel.number(), player8.yellow_jewel.number(), player8.white_jewel.number(),
                                                    player8.get_movement_points(), player8.shovel.number(), player8.bomb.number(), player8.pickaxe.number());
                            }
                        }
                    }
                    repaint();
                }
                else if(turn.get_turn() == player2.get_player_order()){
                    if(key == KeyEvent.VK_Z || key == KeyEvent.VK_X || key == KeyEvent.VK_C){
                        item_used(key, player2);
                        item_use = true;
                    }
                    else if((item_use && key == KeyEvent.VK_UP) || (item_use && key == KeyEvent.VK_DOWN) || (item_use && key == KeyEvent.VK_RIGHT) || (item_use && key == KeyEvent.VK_LEFT)){
                        item_used(key, player2);
                        item_use = false;
                    }
                    else{
                        player2.keyPressed(e);
                        player_x = player2.get_player_map_position_x();
                        player_y = player2.get_player_map_position_y();
                        if(map.map_int[player_y][player_x] == 2){
                            if(player_y >= 1 && player_y <= 11)
                                player_floor_position = 1;
                            else if(player_y >= 12 && player_y <= 19)
                                player_floor_position = 3;
                            random_events.yellow_field_event(player2);
                            map.map_int = random_events.map_int;
                            map.map_int[player_y][player_x] = player_floor_position;
                        }
                        else if(map.map_int[player_y][player_x] == 6){
                            random_events.black_field_event(player2);
                        }
                        else if(map.map_int[player_y][player_x] == 5){
                            random_events.violet_field_event(player2);
                        }
                        game_stats.set_move(player2.get_movement_points());
                        if(player2.get_movement_points() == 0){
                            player2.not_your_turn();
                            turn.next_turn();
                            if(turn.who_should_move_in_this_turn(turn.get_turn()) == 1){
                                player1.your_turn();
                                game_stats.set_stats(player1.green_jewel.number(), player1.blue_jewel.number(), player1.yellow_jewel.number(), player1.white_jewel.number(),
                                                    player1.get_movement_points(), player1.shovel.number(), player1.bomb.number(), player1.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 3){
                                player3.your_turn();
                                game_stats.set_stats(player3.green_jewel.number(), player3.blue_jewel.number(), player3.yellow_jewel.number(), player3.white_jewel.number(), 
                                                    player3.get_movement_points(), player3.shovel.number(), player3.bomb.number(), player3.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 4){
                                player4.your_turn();
                                game_stats.set_stats(player4.green_jewel.number(), player4.blue_jewel.number(), player4.yellow_jewel.number(), player4.white_jewel.number(),
                                                    player4.get_movement_points(), player4.shovel.number(), player4.bomb.number(), player4.pickaxe.number()); 
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 5){
                                player5.your_turn();
                                game_stats.set_stats(player5.green_jewel.number(), player5.blue_jewel.number(), player5.yellow_jewel.number(), player5.white_jewel.number(),
                                                    player5.get_movement_points(), player5.shovel.number(), player5.bomb.number(), player5.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 6){
                                player6.your_turn();
                                game_stats.set_stats(player6.green_jewel.number(), player6.blue_jewel.number(), player6.yellow_jewel.number(), player6.white_jewel.number(),
                                                    player6.get_movement_points(), player6.shovel.number(), player6.bomb.number(), player6.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 7){
                                player7.your_turn();
                                game_stats.set_stats(player7.green_jewel.number(), player7.blue_jewel.number(), player7.yellow_jewel.number(), player7.white_jewel.number(),
                                                    player7.get_movement_points(), player7.shovel.number(), player7.bomb.number(), player7.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 8){
                                player8.your_turn();
                                game_stats.set_stats(player8.green_jewel.number(), player8.blue_jewel.number(), player8.yellow_jewel.number(), player8.white_jewel.number(),
                                                    player8.get_movement_points(), player8.shovel.number(), player8.bomb.number(), player8.pickaxe.number());
                            }
                        }
                        repaint();
                    } 
                }
                else if(turn.get_turn() == player3.get_player_order()){
                    if(key == KeyEvent.VK_Z || key == KeyEvent.VK_X || key == KeyEvent.VK_C){
                        item_used(key, player3);
                        item_use = true;
                    }
                    else if((item_use && key == KeyEvent.VK_UP) || (item_use && key == KeyEvent.VK_DOWN) || (item_use && key == KeyEvent.VK_RIGHT) || (item_use && key == KeyEvent.VK_LEFT)){
                        item_used(key, player3);
                        item_use = false;
                    }
                    else{
                        player3.keyPressed(e);
                        player_x = player3.get_player_map_position_x();
                        player_y = player3.get_player_map_position_y();
                        if(map.map_int[player_y][player_x] == 2){
                            if(player_y >= 1 && player_y <= 11)
                                player_floor_position = 1;
                            else if(player_y >= 12 && player_y <= 19)
                                player_floor_position = 3;
                            random_events.yellow_field_event(player3);
                            map.map_int = random_events.map_int;
                            map.map_int[player_y][player_x] = player_floor_position;
                        }
                        else if(map.map_int[player_y][player_x] == 6){
                            random_events.black_field_event(player3);
                        }
                        else if(map.map_int[player_y][player_x] == 5){
                            random_events.violet_field_event(player3);
                        }
                        game_stats.set_move(player3.get_movement_points());
                        if(player3.get_movement_points() == 0){
                            player3.not_your_turn();
                            turn.next_turn();
                            if(turn.who_should_move_in_this_turn(turn.get_turn()) == 1){
                                player1.your_turn();
                                game_stats.set_stats(player1.green_jewel.number(), player1.blue_jewel.number(), player1.yellow_jewel.number(), player1.white_jewel.number(),
                                                    player1.get_movement_points(), player1.shovel.number(), player1.bomb.number(), player1.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 2){
                                player2.your_turn();
                                game_stats.set_stats(player2.green_jewel.number(), player2.blue_jewel.number(), player2.yellow_jewel.number(), player2.white_jewel.number(),
                                                    player2.get_movement_points(), player2.shovel.number(), player2.bomb.number(), player2.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 4){
                                player4.your_turn();
                                game_stats.set_stats(player4.green_jewel.number(), player4.blue_jewel.number(), player4.yellow_jewel.number(), player4.white_jewel.number(),
                                                    player4.get_movement_points(), player4.shovel.number(), player4.bomb.number(), player4.pickaxe.number()); 
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 5){
                                player5.your_turn();
                                game_stats.set_stats(player5.green_jewel.number(), player5.blue_jewel.number(), player5.yellow_jewel.number(), player5.white_jewel.number(),
                                                    player5.get_movement_points(), player5.shovel.number(), player5.bomb.number(), player5.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 6){
                                player6.your_turn();
                                game_stats.set_stats(player6.green_jewel.number(), player6.blue_jewel.number(), player6.yellow_jewel.number(), player6.white_jewel.number(),
                                                    player6.get_movement_points(), player6.shovel.number(), player6.bomb.number(), player6.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 7){
                                player7.your_turn();
                                game_stats.set_stats(player7.green_jewel.number(), player7.blue_jewel.number(), player7.yellow_jewel.number(), player7.white_jewel.number(),
                                                    player7.get_movement_points(), player7.shovel.number(), player7.bomb.number(), player7.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 8){
                                player8.your_turn();
                                game_stats.set_stats(player8.green_jewel.number(), player8.blue_jewel.number(), player8.yellow_jewel.number(), player8.white_jewel.number(),
                                                    player8.get_movement_points(), player8.shovel.number(), player8.bomb.number(), player8.pickaxe.number());
                            }
                        }
                        repaint();
                    }  
                }
                else if(turn.get_turn() == player4.get_player_order()){
                    if(key == KeyEvent.VK_Z || key == KeyEvent.VK_X || key == KeyEvent.VK_C){
                        item_used(key, player4);
                        item_use = true;
                    }
                    else if((item_use && key == KeyEvent.VK_UP) || (item_use && key == KeyEvent.VK_DOWN) || (item_use && key == KeyEvent.VK_RIGHT) || (item_use && key == KeyEvent.VK_LEFT)){
                        item_used(key, player4);
                        item_use = false;
                    }
                    else{
                        player4.keyPressed(e);
                        player_x = player4.get_player_map_position_x();
                        player_y = player4.get_player_map_position_y();
                        if(map.map_int[player_y][player_x] == 2){
                            if(player_y >= 1 && player_y <= 11)
                                player_floor_position = 1;
                            else if(player_y >= 12 && player_y <= 19)
                                player_floor_position = 3;
                            random_events.yellow_field_event(player4);
                            map.map_int = random_events.map_int;
                            map.map_int[player_y][player_x] = player_floor_position;
                        }
                        else if(map.map_int[player_y][player_x] == 6){
                            random_events.black_field_event(player4);
                        }
                        else if(map.map_int[player_y][player_x] == 5){
                            random_events.violet_field_event(player4);
                        }
                        game_stats.set_move(player4.get_movement_points());
                        if(player4.get_movement_points() == 0){
                        player4.not_your_turn();
                            turn.next_turn();
                            if(turn.who_should_move_in_this_turn(turn.get_turn()) == 1){
                                player1.your_turn();
                                game_stats.set_stats(player1.green_jewel.number(), player1.blue_jewel.number(), player1.yellow_jewel.number(), player1.white_jewel.number(),
                                                    player1.get_movement_points(), player1.shovel.number(), player1.bomb.number(), player1.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 2){
                                player2.your_turn();
                                game_stats.set_stats(player2.green_jewel.number(), player2.blue_jewel.number(), player2.yellow_jewel.number(), player2.white_jewel.number(),
                                                    player2.get_movement_points(), player2.shovel.number(), player2.bomb.number(), player2.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 3){
                                player3.your_turn();
                                game_stats.set_stats(player3.green_jewel.number(), player3.blue_jewel.number(), player3.yellow_jewel.number(), player3.white_jewel.number(), 
                                                    player3.get_movement_points(), player3.shovel.number(), player3.bomb.number(), player3.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 5){
                                player5.your_turn();
                                game_stats.set_stats(player5.green_jewel.number(), player5.blue_jewel.number(), player5.yellow_jewel.number(), player5.white_jewel.number(),
                                                    player5.get_movement_points(), player5.shovel.number(), player5.bomb.number(), player5.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 6){
                                player6.your_turn();
                                game_stats.set_stats(player6.green_jewel.number(), player6.blue_jewel.number(), player6.yellow_jewel.number(), player6.white_jewel.number(),
                                                    player6.get_movement_points(), player6.shovel.number(), player6.bomb.number(), player6.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 7){
                                player7.your_turn();
                                game_stats.set_stats(player7.green_jewel.number(), player7.blue_jewel.number(), player7.yellow_jewel.number(), player7.white_jewel.number(),
                                                    player7.get_movement_points(), player7.shovel.number(), player7.bomb.number(), player7.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 8){
                                player8.your_turn();
                                game_stats.set_stats(player8.green_jewel.number(), player8.blue_jewel.number(), player8.yellow_jewel.number(), player8.white_jewel.number(),
                                                    player8.get_movement_points(), player8.shovel.number(), player8.bomb.number(), player8.pickaxe.number());
                            }
                        }
                        repaint();
                    }
                }
                else if(turn.get_turn() == player5.get_player_order()){
                    if(key == KeyEvent.VK_Z || key == KeyEvent.VK_X || key == KeyEvent.VK_C){
                        item_used(key, player5);
                        item_use = true;
                    }
                    else if((item_use && key == KeyEvent.VK_UP) || (item_use && key == KeyEvent.VK_DOWN) || (item_use && key == KeyEvent.VK_RIGHT) || (item_use && key == KeyEvent.VK_LEFT)){
                        item_used(key, player5);
                        item_use = false;
                    }
                    else{
                        player5.keyPressed(e);
                        player_x = player5.get_player_map_position_x();
                        player_y = player5.get_player_map_position_y();
                        if(map.map_int[player_y][player_x] == 2){
                            if(player_y >= 1 && player_y <= 11)
                                player_floor_position = 1;
                            else if(player_y >= 12 && player_y <= 19)
                                player_floor_position = 3;
                            random_events.yellow_field_event(player5);
                            map.map_int = random_events.map_int;
                            map.map_int[player_y][player_x] = player_floor_position;
                        }
                        else if(map.map_int[player_y][player_x] == 6){
                            random_events.black_field_event(player5);
                        }
                        else if(map.map_int[player_y][player_x] == 5){
                            random_events.violet_field_event(player5);
                        }
                        game_stats.set_move(player5.get_movement_points());
                        if(player5.get_movement_points() == 0){
                            player5.not_your_turn();
                            turn.next_turn();
                            if(turn.who_should_move_in_this_turn(turn.get_turn()) == 1){
                                player1.your_turn();
                                game_stats.set_stats(player1.green_jewel.number(), player1.blue_jewel.number(), player1.yellow_jewel.number(), player1.white_jewel.number(),
                                                    player1.get_movement_points(), player1.shovel.number(), player1.bomb.number(), player1.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 2){
                                player2.your_turn();
                                game_stats.set_stats(player2.green_jewel.number(), player2.blue_jewel.number(), player2.yellow_jewel.number(), player2.white_jewel.number(),
                                                    player2.get_movement_points(), player2.shovel.number(), player2.bomb.number(), player2.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 3){
                                player3.your_turn();
                                game_stats.set_stats(player3.green_jewel.number(), player3.blue_jewel.number(), player3.yellow_jewel.number(), player3.white_jewel.number(), 
                                                    player3.get_movement_points(), player3.shovel.number(), player3.bomb.number(), player3.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 4){
                                player4.your_turn();
                                game_stats.set_stats(player4.green_jewel.number(), player4.blue_jewel.number(), player4.yellow_jewel.number(), player4.white_jewel.number(),
                                                    player4.get_movement_points(), player4.shovel.number(), player4.bomb.number(), player4.pickaxe.number()); 
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 6){
                                player6.your_turn();
                                game_stats.set_stats(player6.green_jewel.number(), player6.blue_jewel.number(), player6.yellow_jewel.number(), player6.white_jewel.number(),
                                                    player6.get_movement_points(), player6.shovel.number(), player6.bomb.number(), player6.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 7){
                                player7.your_turn();
                                game_stats.set_stats(player7.green_jewel.number(), player7.blue_jewel.number(), player7.yellow_jewel.number(), player7.white_jewel.number(),
                                                    player7.get_movement_points(), player7.shovel.number(), player7.bomb.number(), player7.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 8){
                                player8.your_turn();
                                game_stats.set_stats(player8.green_jewel.number(), player8.blue_jewel.number(), player8.yellow_jewel.number(), player8.white_jewel.number(),
                                                    player8.get_movement_points(), player8.shovel.number(), player8.bomb.number(), player8.pickaxe.number());
                            }
                        }
                        repaint();
                    }
                }
                else if(turn.get_turn() == player6.get_player_order()){
                    if(key == KeyEvent.VK_Z || key == KeyEvent.VK_X || key == KeyEvent.VK_C){
                        item_used(key, player6);
                        item_use = true;
                    }
                    else if((item_use && key == KeyEvent.VK_UP) || (item_use && key == KeyEvent.VK_DOWN) || (item_use && key == KeyEvent.VK_RIGHT) || (item_use && key == KeyEvent.VK_LEFT)){
                        item_used(key, player6);
                        item_use = false;
                    }
                    else{
                        player6.keyPressed(e);
                        player_x = player6.get_player_map_position_x();
                        player_y = player6.get_player_map_position_y();
                        if(map.map_int[player_y][player_x] == 2){
                            if(player_y >= 1 && player_y <= 11)
                                player_floor_position = 1;
                            else if(player_y >= 12 && player_y <= 19)
                                player_floor_position = 3;
                            random_events.yellow_field_event(player6);
                            map.map_int = random_events.map_int;
                            map.map_int[player_y][player_x] = player_floor_position;
                        }
                        else if(map.map_int[player_y][player_x] == 6){
                            random_events.black_field_event(player6);
                        }
                        else if(map.map_int[player_y][player_x] == 5){
                            random_events.violet_field_event(player6);
                        }
                        game_stats.set_move(player6.get_movement_points());
                        if(player6.get_movement_points() == 0){
                            player6.not_your_turn();
                            turn.next_turn();
                            if(turn.who_should_move_in_this_turn(turn.get_turn()) == 1){
                                player1.your_turn();
                                game_stats.set_stats(player1.green_jewel.number(), player1.blue_jewel.number(), player1.yellow_jewel.number(), player1.white_jewel.number(),
                                                    player1.get_movement_points(), player1.shovel.number(), player1.bomb.number(), player1.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 2){
                                player2.your_turn();
                                game_stats.set_stats(player2.green_jewel.number(), player2.blue_jewel.number(), player2.yellow_jewel.number(), player2.white_jewel.number(),
                                                    player2.get_movement_points(), player2.shovel.number(), player2.bomb.number(), player2.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 3){
                                player3.your_turn();
                                game_stats.set_stats(player3.green_jewel.number(), player3.blue_jewel.number(), player3.yellow_jewel.number(), player3.white_jewel.number(), 
                                                    player3.get_movement_points(), player3.shovel.number(), player3.bomb.number(), player3.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 4){
                                player4.your_turn();
                                game_stats.set_stats(player4.green_jewel.number(), player4.blue_jewel.number(), player4.yellow_jewel.number(), player4.white_jewel.number(),
                                                    player4.get_movement_points(), player4.shovel.number(), player4.bomb.number(), player4.pickaxe.number());  
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 5){
                                player5.your_turn();
                                game_stats.set_stats(player5.green_jewel.number(), player5.blue_jewel.number(), player5.yellow_jewel.number(), player5.white_jewel.number(),
                                                    player5.get_movement_points(), player5.shovel.number(), player5.bomb.number(), player5.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 7){
                                player7.your_turn();
                                game_stats.set_stats(player7.green_jewel.number(), player7.blue_jewel.number(), player7.yellow_jewel.number(), player7.white_jewel.number(),
                                                    player7.get_movement_points(), player7.shovel.number(), player7.bomb.number(), player7.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 8){
                                player8.your_turn();
                                game_stats.set_stats(player8.green_jewel.number(), player8.blue_jewel.number(), player8.yellow_jewel.number(), player8.white_jewel.number(),
                                                    player8.get_movement_points(), player8.shovel.number(), player8.bomb.number(), player8.pickaxe.number());;
                            }
                        }
                        repaint();
                    }
                }
                else if(turn.get_turn() == player7.get_player_order()){
                    if(key == KeyEvent.VK_Z || key == KeyEvent.VK_X || key == KeyEvent.VK_C){
                        item_used(key, player7);
                        item_use = true;
                    }
                    else if((item_use && key == KeyEvent.VK_UP) || (item_use && key == KeyEvent.VK_DOWN) || (item_use && key == KeyEvent.VK_RIGHT) || (item_use && key == KeyEvent.VK_LEFT)){
                        item_used(key, player7);
                        item_use = false;
                    }
                    else{
                        player7.keyPressed(e);
                        player_x = player7.get_player_map_position_x();
                        player_y = player7.get_player_map_position_y();
                        if(map.map_int[player_y][player_x] == 2){
                            if(player_y >= 1 && player_y <= 11)
                                player_floor_position = 1;
                            else if(player_y >= 12 && player_y <= 19)
                                player_floor_position = 3;
                            random_events.yellow_field_event(player7);
                            map.map_int = random_events.map_int;
                            map.map_int[player_y][player_x] = player_floor_position;
                        }
                        else if(map.map_int[player_y][player_x] == 6){
                            random_events.black_field_event(player7);
                        }
                        else if(map.map_int[player_y][player_x] == 5){
                            random_events.violet_field_event(player7);
                        }
                        game_stats.set_move(player7.get_movement_points());
                        if(player7.get_movement_points() == 0){
                            player7.not_your_turn();
                            turn.next_turn();
                            if(turn.who_should_move_in_this_turn(turn.get_turn()) == 1){
                                player1.your_turn();
                                game_stats.set_stats(player1.green_jewel.number(), player1.blue_jewel.number(), player1.yellow_jewel.number(), player1.white_jewel.number(),
                                                    player1.get_movement_points(), player1.shovel.number(), player1.bomb.number(), player1.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 2){
                                player2.your_turn();
                                game_stats.set_stats(player2.green_jewel.number(), player2.blue_jewel.number(), player2.yellow_jewel.number(), player2.white_jewel.number(),
                                                    player2.get_movement_points(), player2.shovel.number(), player2.bomb.number(), player2.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 3){
                                player3.your_turn();
                                game_stats.set_stats(player3.green_jewel.number(), player3.blue_jewel.number(), player3.yellow_jewel.number(), player3.white_jewel.number(), 
                                                    player3.get_movement_points(), player3.shovel.number(), player3.bomb.number(), player3.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 4){
                                player4.your_turn();
                                game_stats.set_stats(player4.green_jewel.number(), player4.blue_jewel.number(), player4.yellow_jewel.number(), player4.white_jewel.number(),
                                                    player4.get_movement_points(), player4.shovel.number(), player4.bomb.number(), player4.pickaxe.number());  
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 5){
                                player5.your_turn();
                                game_stats.set_stats(player5.green_jewel.number(), player5.blue_jewel.number(), player5.yellow_jewel.number(), player5.white_jewel.number(),
                                                    player5.get_movement_points(), player5.shovel.number(), player5.bomb.number(), player5.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 6){
                                player6.your_turn();
                                game_stats.set_stats(player6.green_jewel.number(), player6.blue_jewel.number(), player6.yellow_jewel.number(), player6.white_jewel.number(),
                                                    player6.get_movement_points(), player6.shovel.number(), player6.bomb.number(), player6.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 8){
                                player8.your_turn();
                                game_stats.set_stats(player8.green_jewel.number(), player8.blue_jewel.number(), player8.yellow_jewel.number(), player8.white_jewel.number(),
                                                    player8.get_movement_points(), player8.shovel.number(), player8.bomb.number(), player8.pickaxe.number());
                            }
                        }
                        repaint();
                    }
                }
                else if(turn.get_turn() == player8.get_player_order()){
                    if(key == KeyEvent.VK_Z || key == KeyEvent.VK_X || key == KeyEvent.VK_C){
                        item_used(key, player8);
                        item_use = true;
                    }
                    else if((item_use && key == KeyEvent.VK_UP) || (item_use && key == KeyEvent.VK_DOWN) || (item_use && key == KeyEvent.VK_RIGHT) || (item_use && key == KeyEvent.VK_LEFT)){
                        item_used(key, player8);
                        item_use = false;
                    }
                    else{
                        player8.keyPressed(e);
                        player_x = player8.get_player_map_position_x();
                        player_y = player8.get_player_map_position_y();
                        if(map.map_int[player_y][player_x] == 2){
                            if(player_y >= 1 && player_y <= 11)
                                player_floor_position = 1;
                            else if(player_y >= 12 && player_y <= 19)
                                player_floor_position = 3;
                            random_events.yellow_field_event(player8);
                            map.map_int = random_events.map_int;
                            map.map_int[player_y][player_x] = player_floor_position;
                        }
                        else if(map.map_int[player_y][player_x] == 6){
                            random_events.black_field_event(player8);
                        }
                        else if(map.map_int[player_y][player_x] == 5){
                            random_events.violet_field_event(player8);
                        }
                        game_stats.set_move(player8.get_movement_points());
                        if(player8.get_movement_points() == 0){
                            player8.not_your_turn();
                            turn.next_turn();
                            if(turn.who_should_move_in_this_turn(turn.get_turn()) == 1){
                                player1.your_turn();
                                game_stats.set_stats(player1.green_jewel.number(), player1.blue_jewel.number(), player1.yellow_jewel.number(), player1.white_jewel.number(),
                                                    player1.get_movement_points(), player1.shovel.number(), player1.bomb.number(), player1.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 2){
                                player2.your_turn();
                                game_stats.set_stats(player2.green_jewel.number(), player2.blue_jewel.number(), player2.yellow_jewel.number(), player2.white_jewel.number(),
                                                    player2.get_movement_points(), player2.shovel.number(), player2.bomb.number(), player2.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 3){
                                player3.your_turn();
                                game_stats.set_stats(player3.green_jewel.number(), player3.blue_jewel.number(), player3.yellow_jewel.number(), player3.white_jewel.number(), 
                                                    player3.get_movement_points(), player3.shovel.number(), player3.bomb.number(), player3.pickaxe.number());;
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 4){
                                player4.your_turn();
                                game_stats.set_stats(player4.green_jewel.number(), player4.blue_jewel.number(), player4.yellow_jewel.number(), player4.white_jewel.number(),
                                                    player4.get_movement_points(), player4.shovel.number(), player4.bomb.number(), player4.pickaxe.number());  
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 5){
                                player5.your_turn();
                                game_stats.set_stats(player5.green_jewel.number(), player5.blue_jewel.number(), player5.yellow_jewel.number(), player5.white_jewel.number(),
                                                    player5.get_movement_points(), player5.shovel.number(), player5.bomb.number(), player5.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 6){
                                player6.your_turn();
                                game_stats.set_stats(player6.green_jewel.number(), player6.blue_jewel.number(), player6.yellow_jewel.number(), player6.white_jewel.number(),
                                                    player6.get_movement_points(), player6.shovel.number(), player6.bomb.number(), player6.pickaxe.number());
                            }
                            else if(turn.who_should_move_in_this_turn(turn.get_turn()) == 7){
                                player7.your_turn();
                                game_stats.set_stats(player7.green_jewel.number(), player7.blue_jewel.number(), player7.yellow_jewel.number(), player7.white_jewel.number(),
                                                    player7.get_movement_points(), player7.shovel.number(), player7.bomb.number(), player7.pickaxe.number());
                            }
                        }
                        repaint();
                    }
                }     
            }
            else if(state == STATE.END_GAME){
                if(key == KeyEvent.VK_ESCAPE){
                    end_game.quit();
                }
            }
        }
    }
}