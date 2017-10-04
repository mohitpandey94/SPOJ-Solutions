import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
public class Main{

     public static void main(String []args){
        BigInteger n;
        BigInteger p,temp;
        Scanner sc = new Scanner(System.in);
        for (int i=0;i<10;i++) {
            n = sc.nextBigInteger();
            p = sc.nextBigInteger();
            temp=n;
            n = n.add(p);
            p = new BigInteger("2");
            n = n.divide(p);
            System.out.println(n);
            temp=temp.subtract(n);
            //System.out.println("h");
            System.out.println(temp);
        }
     }
}
