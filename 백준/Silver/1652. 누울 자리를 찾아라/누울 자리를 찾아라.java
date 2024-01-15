import java.io.*;
import java.util.*;




public class Main {
    static int N;
    static int [][]board;
	public static void main(String[] args) throws IOException {
		BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(bf.readLine());
        board = new int[N+1][N+1];
        for(int i = 0; i < N; i++) {
            String input = bf.readLine();
            for(int j = 0; j < input.length(); j++){
                board[i][j] = input.charAt(j);
            }
        }

        int garo = 0;
        int sero  = 0;

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++){
                int count = 0;
                while(board[i][j] == '.' && j++ < N)
                    count++;
                // System.out.println("garo " + i + " " + j + " " + count);
                if(count >= 2 && (board[i][j] == 'X' || j == 0 || j == N)){
                    garo++;
                }
            }
            
        }

         for(int  j = 0; j < N; j++) {
            for(int i = 0; i < N; i++){
            int count = 0;
                while(board[i][j] == '.' && i++ < N)
                    count++;
            if(count >= 2 && (board[i][j] == 'X' || i == 0 || i == N)){
                // System.out.println("sero " + i + " " + j + " " + count);
                sero++;
            }
            }
        }
        System.out.println(garo + " " + sero);



		
	}
}
