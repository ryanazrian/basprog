//import java.io.*;
import java.util.Scanner;
import static java.lang.Math.*;


public class Pengenalan{
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);

        double a = 0, b = 0, c = 0, suma = 0, sumb = 0;

        c=sc.nextDouble();

        for(int i =0 ; i<c ; i++){
            suma = suma +sc.nextDouble();
            sumb = sumb + sc.nextDouble();
        }
        a = suma / c;
        b = sumb / c;
              System.out.printf("%.2f %.2f\n",a, b);  
    }
}