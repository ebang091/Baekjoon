import java.io.*;
import java.util.*;

import javax.sound.midi.Soundbank;

public class Main {

    static int N;
    static byte []primes;
    static int MAX_N = 1100001;
    public static boolean isPalindrome(int n){
        String number =  n + "";

        for(int i = 0; i < number.length()/2; i++) {
            //0123
            if(number.charAt(i) != number.charAt(number.length()-1-i))
                return false;
        }
        return true;
    }

    public static boolean isPrime(int n){
        if(n == 1)
            return false;
        return (primes[n/8] & (1 << (n % 8))) == 0;
    }

    public static void main(String []args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());

        primes = new byte[(MAX_N + 7)/8];

        for (int i = 2; i <= MAX_N; i++) {
            for(int j = i * 2; j <= MAX_N; j +=i){
                primes[j/8] |= (1 << (j % 8));
            }
        }

        for(int i = N; i <= MAX_N; i++){
            if(isPalindrome(i) && isPrime(i)){
                System.out.println(i);
                return;
            }

        }


    }
    
}