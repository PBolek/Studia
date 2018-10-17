import java.util.*;

public class Lista1{

    private static void solve(int a){
        int a2 = a;
        String string = Integer.toString(a);
        int dlugosc_liczby = string.length();
        int[] tab = new int[11];
        for(int i = 0; i < 11; i++){
            tab[i] = 0;
        }
        int licznik = 0;
        String[][] tablica_jednostek = new String[][]{
        {"zero", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć", "dziesięć",
         "jedenaście", "dwanaście", "trzynaście", "czternaście", "piętnaście", "szesnaście", "siedemnaście", "osiemnaście", "dziewiętnaście"},
        {"dwadzieścia", "trzydzieści", "czterdzieści", "pięćdziesiąt", "sześćdziesiąt", "siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt"},
        {"sto", "dwieście", "trzysta", "czterysta", "pięćset", "sześćset", "siedemset", "osiemset", "dziewięćset"},
        {"tysiąc", "tysiące", "tysięcy"},
        {"milion", "miliony", "milionów"},
        {"miliard", "miliardy", "miliardów"}
        };

        while(a > 0){
            tab[licznik] = a % 10;
            a = a / 10;
            licznik++;
        }
        if(dlugosc_liczby >= 1 && dlugosc_liczby <= 3){
            if(dlugosc_liczby == 1 && tab[0] != 0)
                System.out.print(tablica_jednostek[0][tab[0]] + " ");
            else if(dlugosc_liczby == 2){
                if(tab[1] == 1)
                    System.out.print(tablica_jednostek[0][tab[0] + (tab[1] * 10)] + " ");
                else if(tab[0] != 0)
                    System.out.print(tablica_jednostek[1][tab[1] - 2] + " " + tablica_jednostek[0][tab[0]] + " ");
                else
                    System.out.print(tablica_jednostek[1][tab[1] - 2] + " ");
            }  
            else if(dlugosc_liczby == 3){
                System.out.print(tablica_jednostek[2][tab[2] - 1] + " ");
                solve(a2 % 100);
            }
        }
        else if(dlugosc_liczby >= 4 && dlugosc_liczby <= 6){
            if(dlugosc_liczby == 4){
                if(tab[3] == 1)
                    System.out.print(tablica_jednostek[3][0] + " ");
                else{
                    solve(a2 / 1000);
                    if(tab[3] >= 2 && tab[3] <= 4)
                        System.out.print(tablica_jednostek[3][1] + " ");
                    else if(tab[3] >= 5 && tab[3] <= 9)
                        System.out.print(tablica_jednostek[3][2] + " ");
                }
                solve(a2 % 1000);
            }
            else if (dlugosc_liczby == 5 || dlugosc_liczby == 6){
                solve(a2 / 1000);
                if(tab[3] >= 2 && tab[3] <= 4 && tab[3] + tab[4] * 10 >= 20)
                    System.out.print(tablica_jednostek[3][1] + " ");
                else
                    System.out.print(tablica_jednostek[3][2] + " ");
                solve(a2 % 1000);
            }
        }
        else if(dlugosc_liczby >= 7 && dlugosc_liczby <= 9){
            if(dlugosc_liczby == 7){
                if(tab[6] == 1)
                    System.out.print(tablica_jednostek[4][0] + " ");
                else{
                    solve(a2 / 1000000);
                    if(tab[6] >= 2 && tab[6] <= 4)
                        System.out.print(tablica_jednostek[4][1] + " ");
                    else
                        System.out.print(tablica_jednostek[4][2] + " ");
                }
                solve(a2 % 1000000); 
            }
            if(dlugosc_liczby == 8 || dlugosc_liczby == 9){
                solve(a2 / 1000000);
                if(tab[6] >= 2 && tab[6] <= 4 && tab[6] + tab[7] * 10 >= 20)
                    System.out.print(tablica_jednostek[4][1] + " ");
                else
                    System.out.print(tablica_jednostek[4][2] + " ");
                solve(a2 % 1000000);
            }
        }
        else if(dlugosc_liczby == 10){
            if(tab[9] == 1)
                System.out.print(tablica_jednostek[5][0] + " ");
            else{
                solve(a2 / 1000000000);
                if(tab[9] >= 2 && tab[9] <= 4)
                    System.out.print(tablica_jednostek[5][1] + " ");
                else
                    System.out.print(tablica_jednostek[5][2] + " ");
                solve(a2 % 1000000000);
            }
            solve(a % 1000000000);
        }
    }

    public static void main(String[] args){
        int a = 0;
        Long b;
        try{
            Scanner scanner = new Scanner(System.in);
            b = scanner.nextLong();
            if(b > Integer.MAX_VALUE)
                System.err.println("Wartość przekracza zakres Integer");
            else if(b < Integer.MIN_VALUE)
                System.err.println("Wartość przekracza zakres Integer");
            else{
                a = b.intValue();
                if(a == 0){
                    System.out.print("zero");
                    return;
                }
                else if(a < 0){
                    System.out.print("minus ");
                    a *= -1;
                }
                solve(a);
            }    
        }
        catch(InputMismatchException exception){
            System.out.println("Blad formatu argumentu");
        }
    }
}