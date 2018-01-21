// Ruang2D.java
// Menggunakan class Pair yang sudah dibuat sebelumnya
import java.io.*;
import java.util.Scanner;
import static java.lang.Math.*;

class Segitiga {
   Pair<Double,Double> t1;
   Pair<Double,Double> t2;
   Pair<Double,Double> t3;
   public Segitiga(Double x1, Double y1, Double x2, Double y2, Double x3, Double y3) {
      t1=new Pair<Double,Double>(x1,y1);
      t2=new Pair<Double,Double>(x2,y2);
      t3=new Pair<Double,Double>(x3,y3);
   }
   public double luas() {
      double a=t2.getFirst()*t3.getSecond()+t1.getFirst()*t2.getSecond()+t3.getFirst()*t1.getSecond();
      double b=t2.getFirst()*t1.getSecond()+t3.getFirst()*t2.getSecond()+t1.getFirst()*t3.getSecond();
      return Math.abs(a-b)/2.0;
   }
}

class Lingkaran {
   Pair<Double,Double> pusat;
   Double radius;
   
   public Lingkaran(Double x, Double y){
       pusat = new Pair<Double,Double>(x, y);
   }

    public Double luas(Double r){
        return 3.14 * r *r;
    }


}

public class Ruang2D{
   public static void main(String[] args){
      String inp = "";
       String delim="[ ]+";
       String[] temp;
       Segitiga[] segitiga=new Segitiga[100];
       Lingkaran[] lingkaran=new Lingkaran[100];

       Double jumlah_lingkaran=0.00;

      
        Scanner s = new Scanner(System.in);

        Double n = s.nextDouble();
        Double m = s.nextDouble();

        for(int i =0 ; i<n; i++){
            Double x = s.nextDouble();
            Double y = s.nextDouble();
            Double r = s.nextDouble();
            //jumlah_lingkaran = jumlah_lingkaran + lingkaran[0].luas(r);
        }
        //Double rataan = jumlah_lingkaran/n;
        
        //System.out.printf("%.2f\n", rataan);

    //    try {
    //        //...

    //    } catch(IOException e) {
    //        System.out.println("Error!");
    //    }
   }
}