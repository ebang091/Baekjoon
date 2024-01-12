import java.io.*;
import java.util.*;

import javax.sound.midi.Soundbank;

public class Main {
    static int N, M, K;
    static int [][]board;
    static int [][]visited;
    static int INF =  Integer.MAX_VALUE;


    static class Node{
        int y;
        int x;
        public Node(int y, int x){
            this.y = y;
            this.x = x;
        }
    }

    public static boolean canGo(int y, int x){
        return 0 <= y && y < M && 0 <= x && x < N;
    }

    public static int BFS(int r, int c, int count) {
        Queue<Node> Q = new LinkedList<>();

        int [][]dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        int nodeCount = 1;
        Q.add(new Node(r, c));
        board[r][c] = count;
        while (!Q.isEmpty()){
            Node cur = Q.poll();
            // System.out.println("visit " + count + " " + cur.y + " " + cur.x);
            nodeCount++;

            for (int i = 0; i < 4; i++) {
                int nextY = cur.y + dir[i][0];
                int nextX = cur.x + dir[i][1];

                if(canGo(nextY, nextX) && board[nextY][nextX] == 0){
                    // visited[nextY][nextX] = count;
                    board[nextY][nextX] = count;
                    Q.add(new Node(nextY, nextX));
                }
            }
        }
        return nodeCount -1;
    }

    public static void main(String []args) throws IOException {
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        int []inputs = Arrays.stream(bf.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        M = inputs[0];
        N = inputs[1];
        K = inputs[2];
        board = new int[M+1][N+1];
        // visited = new int[N+1][M+1];

        int x1, y1, x2, y2;
        //직사각형 표시
        for(int i = 0; i < K; i++){
            int []squareInfo = Arrays.stream(bf.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
            x1 = squareInfo[0];
            y1 = M - squareInfo[1];
            x2 = squareInfo[2];
            y2 = M - squareInfo[3];
            for(int y = y2; y < y1; y++){
                for(int x = x1; x < x2; x++){
                    // System.out.println(y + " " + x);
                    board[y][x] = INF; 
                }
                 
            }
        }

        // System.out.println("");

        // for(int i = 0; i < M; i++){
        //     for(int j = 0; j < N; j++){
        //         if(board[i][j] == INF)
        //             System.out.print("." );
        //         else
        //             System.out.print(board[i][j]);
        //     }
        //     System.out.println("");

        // }
        

        //BFS로 단지 순회
        ArrayList<Integer> answer = new ArrayList<>();
        int count = 0;
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                if (board[i][j] == 0){
                    int result = BFS(i, j, ++count);
                    answer.add(result);
                }
            }
        }
        Collections.sort(answer);
        System.out.println(answer.size());

        for(int i = 0; i < answer.size(); i++)
            System.out.print(answer.get(i) + " ");


    }
}