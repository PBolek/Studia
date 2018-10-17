import java.util.Scanner;
import geometria.Punkt;
import geometria.Wektor;
import geometria.Prosta;
import geometria.Odcinek;

public class Main{
    public static void main(String[] args){
        double temp1, temp2, temp3;
        Scanner scanner = new Scanner(System.in);
        int c = 0;
        print_menu();
        c = scanner.nextInt();
        while(c != 0){
            if(c == 1){
                System.out.println("Podaj parametry dwoch wektorow: ");
                temp1 = scanner.nextDouble();
                temp2 = scanner.nextDouble();
                Wektor w1 = new Wektor(temp1, temp2);
                temp1 = scanner.nextDouble();
                temp2 = scanner.nextDouble();
                Wektor w2 = new Wektor(temp1, temp2);
                w1 = w1.add(w2);
                System.out.println("Wynik skladania: " + w1.get_dx_val() + " " + w1.get_dy_val());
                w2 = null;
                w1 = null;
            }
            else if(c == 2){
                System.out.println("Podaj dwa razy A, B, C (postac Ax + By + C = 0): ");
                try{
                    temp1 = scanner.nextDouble();
                    temp2 = scanner.nextDouble();
                    temp3 = scanner.nextDouble();
                    Prosta p1 = new Prosta(temp1, temp2, temp3);
                    temp1 = scanner.nextDouble();
                    temp2 = scanner.nextDouble();
                    temp3 = scanner.nextDouble();
                    Prosta p2 = new Prosta(temp1, temp2, temp3);
                    Prosta.czy_rownolegle(p1, p2);
                    p1 = null;
                    p2 = null;
                }
                catch(IllegalArgumentException e){
                    System.err.println(e.getMessage());
                    break;
                }
            }
            else if(c == 3){
                System.out.println("Podaj dwa razy A, B, C (postac Ax + By + C = 0): ");
                try{
                    temp1 = scanner.nextDouble();
                    temp2 = scanner.nextDouble();
                    temp3 = scanner.nextDouble();
                    Prosta p1 = new Prosta(temp1, temp2, temp3);
                    temp1 = scanner.nextDouble();
                    temp2 = scanner.nextDouble();
                    temp3 = scanner.nextDouble();
                    Prosta p2 = new Prosta(temp1, temp2, temp3);
                    Prosta.czy_prostopadle(p1, p2);
                    p1 = null;
                    p2 = null;
                }
                catch(IllegalArgumentException e){
                    System.err.println(e.getMessage());
                    break;
                }
            }
            else if(c == 4){
                System.out.println("Podaj dwa razy A, B, C (postac Ax + By + C = 0): ");
                try{
                    temp1 = scanner.nextDouble();
                    temp2 = scanner.nextDouble();
                    temp3 = scanner.nextDouble();
                    Prosta p1 = new Prosta(temp1, temp2, temp3);
                    temp1 = scanner.nextDouble();
                    temp2 = scanner.nextDouble();
                    temp3 = scanner.nextDouble();
                    Prosta p2 = new Prosta(temp1, temp2, temp3);
                    Prosta.punkt_przeciecia_prostych(p1, p2);
                    p1 = null;
                    p2 = null;
                }
                catch(IllegalArgumentException e){
                    System.err.println(e.getMessage());
                    break;
                }
            }
            else if(c == 5){
                System.out.println("Podaj punkt");
                temp1 = scanner.nextDouble();
                temp2 = scanner.nextDouble();
                Punkt p = new Punkt(temp1, temp2);
                System.out.println("Podaj wektor");
                temp1 = scanner.nextDouble();
                temp2 = scanner.nextDouble();
                Wektor w1 = new Wektor(temp1, temp2);
                p.przesun(w1);
                System.out.println("Wynik: " + "(" + p.get_x() + ", " + p.get_y() + ")");
                p = null;
                w1 = null;
            }
            else if(c == 6){
                System.out.println("Podaj 2 punkty");
                temp1 = scanner.nextDouble();
                temp2 = scanner.nextDouble();
                Punkt p = new Punkt(temp1, temp2);
                temp1 = scanner.nextDouble();
                temp2 = scanner.nextDouble();
                Punkt p2 = new Punkt(temp1, temp2);
                System.out.println("Podaj kat");
                temp3 = scanner.nextDouble();
                p.obroc(p, temp3);
                System.out.println("Wynik: " + "(" + p.get_x() + ", " + p.get_y() + ")");
                p = null;
                p2 = null;
            }
            else if(c == 7){
                try{
                    System.out.println("Podaj punkt");
                    temp1 = scanner.nextDouble();
                    temp2 = scanner.nextDouble();
                    Punkt p = new Punkt(temp1, temp2);
                    System.out.println("Podaj prosta");
                    temp1 = scanner.nextDouble();
                    temp2 = scanner.nextDouble();
                    temp3 = scanner.nextDouble();
                    Prosta p1 = new Prosta(temp1, temp2, temp3);
                    p.odbij(p1);
                    System.out.println("Wynik: " + "(" + p.get_x() + ", " + p.get_y() + ")");
                    p = null;
                    p1 = null;
                }
                catch(IllegalArgumentException e){
                    System.err.println(e.getMessage());
                    break;
                } 
            }
            System.out.println("___________________");
            print_menu();
            c = scanner.nextInt();
        }
    }
    private static void print_menu(){
        System.out.println("1 - Skladanie dwoch wektorow");
        System.out.println("2 - Czy dwie proste sa rownolegle?");
        System.out.println("3 - Czy dwie proste sa prostopadle?");
        System.out.println("4 - Podaj punkt przeciecia dwoch prostych");
        System.out.println("5 - Przesun punkt o wektor");
        System.out.println("6 - Obroc punkt wokol punktu o zadany kat");
        System.out.println("7 - Odbij punkt symetrycznie wobec podanej prostej");
        System.out.println("0 - Zakoncz dzialanie programu");
    }
}