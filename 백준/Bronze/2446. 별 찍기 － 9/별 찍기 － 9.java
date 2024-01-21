import java.io.*;
import java.util.*;

public class Main{
    public static void main(String []args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        
        int N  =  Integer.parseInt(bf.readLine());
        for(int i = 0 ; i < N; i++){
            //9 7 5 3 1
            int star = (N - i)* 2 -1;
            int whiteSpace = i;
            for(int j = 0; j < whiteSpace; j++)
                System.out.print(' ');
            for(int j = 0; j < star; j++)
                System.out.print('*');
            System.out.println();
        }
        
        //3 5 7 9
        for(int i = 0; i < N; i++){
            if(i == 0)
                 continue;
            int star = i * 2 + 1;
            int whiteSpace = (N - 1 - i);
            for(int j = 0; j < whiteSpace; j++)
                System.out.print(' ');
            for(int j = 0; j < star; j++)
                System.out.print('*');
            System.out.println();
            
        }
    }    
}
