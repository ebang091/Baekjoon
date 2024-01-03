import java.util.*;
import java.io.*;


public class Main {
    static int N;
    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());

        int [][]graph = new int[N][N];

        for(int i = 0 ; i < N; i++){
            graph[i] = Arrays.stream(bf.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        for(int k = 0; k < N; k++){ 
            for(int i = 0 ; i < N; i++) {
                for(int j = 0; j < N; j++) {
               
                    if(graph[i][k] == 1 && graph[k][j] == 1)
                        graph[i][j] = 1;
                }
            }
        }        

       for (int i = 0 ; i < N; i++) {
            for (int j = 0; j < N; j++) {
                System.out.print(graph[i][j] + " " );
            }
            System.out.print("\n");       
        }   
    }
}