/*
* solution is based on help and direction of one of my friends who advised to use BigInteger java class, instead of C++.

*/


import java.math.BigInteger;
import java.util.Scanner;





public class Main {


    
    
    public static int[] say = new int[100];
    public static int[] tip = new int[100];
    
    public static int strtoint(String str, int idx1, int idx2){
        int t = 0;
        for(int i = idx1; i <= idx2; ++i){
            t = t * 10 + str.charAt(i) - '0';
        }
        return t;
    }
    
    
    public static void main(String[] args) {
    	
        Scanner sc = new Scanner(System.in);
        int t;
        t = sc.nextInt();
        
        int n, p, q;
        for(int c = 1; c <= t; ++c){
            n = sc.nextInt();
            p = sc.nextInt();
            q = sc.nextInt();
//            frac res = new frac(0,1);
            BigInteger den = BigInteger.valueOf(q);
            den = den.pow(n);
            
            BigInteger num = BigInteger.valueOf(0);
            
            
            for (int i = 1; i <= n; i++) {
            	
            	
    			BigInteger temp = BigInteger.valueOf(p);
    			temp = temp.pow(i);
    			temp = temp.multiply(BigInteger.valueOf(q).pow(n-i));
    			num = num.add(temp);
   
            	
			}
            BigInteger comm = num.gcd(den);
            System.out.println("Case #" +c+": " +num.divide(comm) + "/" + den.divide(comm));
            
        }
        
        
    }
    
}
