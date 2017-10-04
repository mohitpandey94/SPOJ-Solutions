/* package whatever; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;
import java.math.BigInteger;
/* Name of the class has to be "Main" only if the class is public. */

public class Main{

     public static void main(String []args){
        BigInteger s;
        BigInteger p=new BigInteger("2");
        Scanner sc=new Scanner(System.in);
        while (sc.hasNextBigInteger()) {
        s=sc.nextBigInteger();
        if (s.equals(BigInteger.ONE)) {
        	System.out.println(s);
        }
        else {
        	s=s.subtract(BigInteger.ONE).multiply(p);;
        	System.out.println(s);
        }
     }
     }
}
