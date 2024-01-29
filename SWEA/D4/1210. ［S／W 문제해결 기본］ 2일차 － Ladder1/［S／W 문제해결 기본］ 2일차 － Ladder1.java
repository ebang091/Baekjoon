import java.util.*;
import java.io.*;

public class Solution{
    public static int[][] board;
    public static int curCol = 0;
    public static int answer = 0;
    public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int T = 10;
        

        for(int tc = 0; tc < T; tc++) {
            boolean findAnswer = false;
            answer = 0;
            board = new int[100][100];
            String temp = br.readLine();
            for(int i = 0; i < 100; i++) {
                board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            }


            for (int j = 0; j < 100; j++) {
                // System.out.println(" check " + board[0][j]);
                if (board[0][j] == 1) {
                    curCol = j;
                    int row = 0;
                    int col = j;
                    while (row < 100) {
                        // if(curCol == 67)
                            // System.out.println("from "+ curCol +  "position " + row + " " + col + " " + board[row][col]);
                        if(col - 1 >= 0 && board[row][col-1] == 1){
                            while (col - 1 >= 0 && board[row][col-1] == 1) {//왼쪽 탐색
                                col--;
                            }
                        }
                        else if(col + 1 < 100 && board[row][col+1] == 1){ //오른쪽 탐색
                            while (col + 1 < 100 && board[row][col+1] == 1) {
                                col++;
                            }
                        }
                        row++;
                        if(row == 99) {
                            if(board[row][col] == 2) {
                                answer = curCol;
                                findAnswer = true;
                                break;
                            }
                        }
                    }
                }
                if(findAnswer)
                    break;
            }
            
            System.out.println("#" + (tc + 1) +  " " + answer);
            
        }
    }
}