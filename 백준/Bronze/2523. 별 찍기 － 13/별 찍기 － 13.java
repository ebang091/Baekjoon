import java.io.*;
import java.util.*;

public class Main {
    public static void main(String []args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        int N = Integer.parseInt(bf.readLine());
        for(int i = 0; i < N; i++){
            for(int j = 0; j < i+1; j++)
                System.out.print('*');
            System.out.println();
        }
        for(int i = 0; i < N; i++){
            if(i == 0)
                 continue;
            int star = N - i;
            for(int j = 0; j < star; j++)
                System.out.print('*');
            System.out.println();
        }
    }
}