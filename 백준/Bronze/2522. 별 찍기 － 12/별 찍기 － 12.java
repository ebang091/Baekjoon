/*
  *
 **
***
 **
  *
*/

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());
        
        for(int i = 0 ; i < N; i++){
            int whiteSpace = N - 1 - i;
            for(int j = 0; j < whiteSpace; j++)
                System.out.print(' ');
            for(int j = 0; j < i+1; j++)
                System.out.print('*');
            System.out.println();
            
        }
        for(int i = 0; i < N - 1; i++){
            int whiteSpace = i + 1;
            for(int j = 0; j < whiteSpace; j++)
                System.out.print(' ');
            for(int j = 0; j < N - 1 - i; j++)
                System.out.print('*');
            System.out.println();
        }
        
    }
}