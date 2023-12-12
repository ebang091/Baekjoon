import java.util.*;
import java.io.*;

public class Main {
    public static int N;
    public static int[] boards = new int[15];    
    public static int answer = 0;

    public static void DFS(int row, int col){
        // System.out.println("visit " + row + " " + col);
        
        if(row == 0){
            boards[row] = col;
        }
        else {
            //검증 후.
            for(int i = 0; i < row; i++) {
                // int j1 = i + (col - row);
                // int j2 = i + (row + col);
                if (boards[i] == col || boards[i] - i == col - row || boards[i] + i == col + row)
                    return;
            }
            boards[row] = col;
        }

        if(row == N-1) {
            answer++;
            return;
        }
        for(int i = 0; i < N; i++){
            DFS(row + 1, i);
        }
        
    }

    public static void NQueen() {
        for(int i = 0; i < N; i++){
            // boards[0] = i;
            DFS(0, i);
        }
    }

    public static void main(String[] args) throws IOException {

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(bf.readLine());
        NQueen();
        System.out.print(answer);



    }

}