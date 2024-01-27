/*
  *
 ***
 
  *
 * *
***** 
*/

import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(br.readLine());
        
        for(int i = 0; i < N - 1; i++) {
            int whiteSpace = N - 1 - i;
            for(int j = 0; j < whiteSpace; j++)
                System.out.print(" ");
            System.out.print("*");
            int midSpace = i * 2 - 1;
            for(int j = 0; j < midSpace; j++)
                System.out.print(" ");
            if(i != 0)
                System.out.print("*");
            System.out.println();
        }
        
        for(int j = 0; j < N * 2 - 1; j++)
            System.out.print("*");
        System.out.println();
        
    }
}