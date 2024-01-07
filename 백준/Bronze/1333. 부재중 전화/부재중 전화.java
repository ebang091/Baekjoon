/*
 * 방향 그래프
 * 지름 길의 개수  N, 고속도로의 길이 D
 * 
 * 
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.*;
import java.util.*;

public class Main {
    static int answer = 0;
    public static void main(String []args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N, L, D;
        int []inputs = Arrays.stream(bf.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        N = inputs[0];
        L = inputs[1];
        D = inputs[2];

        int phoneRingStart = 0;
        boolean find = false;
       for(int i = 1; i < N; i++) {
            int breakStart = L * (i) + 5 * (i - 1);
            int breakEnd = breakStart + 5;
            while(breakStart > phoneRingStart){ //phoneRingStart > breakStart 전제로 탐색
                phoneRingStart += D;

            }
            // System.out.println("break start " + breakStart + "end " + breakEnd + " phone start" + phoneRingStart + " end "+ phoneRingEnd);
            
            if(breakStart - 1 <  phoneRingStart && phoneRingStart < breakEnd){
                find = true;
                answer = phoneRingStart;
                break;
            }
       }
       if(find) 
            System.out.println(answer);
       else{
            int songEnd = N * L + 5 * (N-1);
            answer = 0;
            while(answer < songEnd){
                answer +=D;
            }
            System.out.println(answer);
       }
        



    }
    
}
