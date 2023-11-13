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
        ArrayList<Long> dp = new ArrayList<>();
        
        dp.add(1L);
        dp.add(2L);
        BufferedReader bfn  = new BufferedReader(new InputStreamReader(System.in));
        Integer N = Integer.parseInt(bfn.readLine());
        for(int i = 2; i < N; i++){
           Long total = dp.get(i-1) + dp.get(i-2);
            dp.add(total%15746);
        }
        System.out.print(dp.get(N-1));
    }
 }