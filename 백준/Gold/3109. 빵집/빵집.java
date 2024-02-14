import java.io.*;
import java.util.*;

public class Main {

    static int N, M; //행 열을 입력받는다. (각각 C, R 을 의미)
    static char [][]map;
    static char [][]draw;
    static char [][]DP; //갈 수 없다는 것을 의미할 때 표시해두기
    static final char POSSIBLE = '1';
    static final char IMPOSSIBLE = '2';
    static final char NONE = '.';
    static final char BUILDING = 'x';
    static int answer = 0;
    //C * 2의 배열을 입력받았을 때, 이동할 수 있는 칸의 결과 (left- > right 방향으로)

    public static boolean cango(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M;
    }

    public static boolean dfs(int col, int row) {
        
        // System.out.println("visit " + row + " " + col);
        if(col == M - 1){
            // System.out.println("도착!");

            // for (int i = 0; i < N; i++) {
            //     for (int j = 0; j < M; j++) {
            //         System.out.print(draw[i][j] + " ");
            //     }
            //     System.out.println();
            // }
            answer++;
            return true;
        }

        // System.out.println("visit " + row + " " + col + " " + map[row][col]);

        int dx[] = {-1, 0, 1};
        int nextcol = col + 1;
        boolean result = false;
        boolean canGo = false;
        draw[row][col] = POSSIBLE;
        for(int i = 0; i < 3; i++) {
            int nextrow = row + dx[i];
            if (cango(nextrow, nextcol) && map[nextrow][nextcol] != BUILDING) {
                canGo = true;
                if (draw[nextrow][nextcol] == NONE && DP[nextrow][nextcol] == 0) {
                    result = dfs(nextcol, nextrow);
                    if(result)
                        break;
                    else
                        DP[nextrow][nextcol] = IMPOSSIBLE;
                }
            }
        }

        if (result)
            return true;
        if (canGo == false)
            DP[row][col] = IMPOSSIBLE;
        
        draw[row][col] = NONE;
        return false;
    }

    public static void main(String []args) throws IOException {
        //열, 행을 입력받는다. 
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(br.readLine());
        N = sc.nextInt();
        M = sc.nextInt();
        map = new char[N][M];
        draw = new char[N][M];
        DP = new char[N][M];

        for(int i = 0; i < N; i++ ){
            String input = br.readLine();
            for(int j = 0; j < M; j++){
                map[i][j] = input.charAt(j);
            }
        }

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < M; j++)
                draw[i][j] = NONE;
        }

        for(int i = 0; i < N; i++){
            if(map[i][1] == NONE){
                // List<Integer> rows = new ArrayList<>();
                // rows.add(i);
                dfs(1, i);

            }
        }

        System.out.println(answer);
    }
}