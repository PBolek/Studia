import java.*;
import java.util.Random;

public class random{
    public static void main(String args[]){
        Random random = new Random();
        int counter = 0;
        while(counter != 50){
            System.out.print(random.nextInt(5)+" ");
            counter ++;
        }
        System.out.print(random.nextInt(5));
    }
}