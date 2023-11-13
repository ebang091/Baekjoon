import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.lang.reflect.Array;
import java.math.BigInteger;
import java.io.IOException;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.function.BiFunction;

/*  
 */
public class Main {
    public static void main(String[] args) throws IOException {
       int number = 1;
       BufferedReader bfn = new BufferedReader(new InputStreamReader(System.in));
       String input[] = bfn.readLine().split(" ");
       int a = Integer.parseInt(input[0]);
       int b = Integer.parseInt(input[1]);
       
       int[] nums = new int[1010];
        for(int i = 1; i <= 1001;){
            int count = 0;
            while(count++ < number && i <= 1001){
                nums[i++] = number;
            }
            number++;
       }
       int sum = 0;
       for(int i = a; i <= b; i++){
            sum += nums[i];
       }
       System.out.println(sum);
    }
 }