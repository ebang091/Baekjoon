import java.io.*;
import java.util.*;

public class Main{
    static int N;
    static int M;
    static int []selected;

    public static void dfs(int count, int number) {
        if(count == 0) {
            for(int i = 1 ; i <= N; i++) {
                if(selected[i] == 1)
                    System.out.print(i + " ");
            }
            System.out.println();
            return;
        }

        if(number > N)
            return;

        selected[number] = 1;
        dfs(count - 1, number + 1);
        selected[number] = 0;
        dfs(count, number + 1);
    }  

    public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] input = Arrays.stream(br.readLine().split(" " )).mapToInt(Integer::parseInt).toArray();

        N = input[0];
        M = input[1];

        selected = new int[N  + 1];
        dfs(M, 1);
    }

}