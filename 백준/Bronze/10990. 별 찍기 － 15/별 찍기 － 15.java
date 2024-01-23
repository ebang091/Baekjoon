import java.io.*;
import java.util.*;
/*
   *
  * *
 *   *
*     *

*/
public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());
        
        for(int i = 0; i < N; i++){
            int whiteSpace = N - 1 - i;
            int midSpace = (i) * 2 - 1;
            for(int j = 0; j < whiteSpace; j++)
                System.out.print(' ');
            System.out.print('*');
            if(i == 0){
                System.out.println();
                continue;
            }
            for(int j = 0; j < midSpace; j++)
                System.out.print(' ');
            System.out.println('*');
        }
    }
}