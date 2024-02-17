import java.io.*;
import java.util.*;

public class Main {
    static int N, M, D;
    static int [][]board;
    static int [][]deadEmemies;
    static int []position;
    static int answer = -1;

    static final int ENEMY = 1;
    static final int NONE = Integer.MAX_VALUE;
    
    static class Node {
        int r;
        int c;
        int time;
        int distance;

        public Node(int r, int c, int time, int distance){
            this.r = r;
            this.c = c;
            this.time = time;
            this.distance = distance;
        }
    }

    public static boolean canGo(int r, int c) {
        return 0 <= r && r < N && 0 <= c && c < M;
    }

    public static void findEnemy(Node arrow) {
        //거리 D이하이고 가장 가까이, 최대한 왼쪽에 있는 적을 없앤다.
        //arrow.time 이전에 죽은 적은 취급하지 않는다.

        int time = arrow.time;
        int r = arrow.r - 1; //한칸 위에서 출발
        int c = arrow.c;

        int [][]visited = new int[N][M];
        int []dy = {0, -1, 0};
        int []dx = {-1, 0, 1};

        Queue<Node> queue = new ArrayDeque<>();
        queue.offer(new Node(r, c, time, 1));
        visited[r][c]  = 1;

        while (!queue.isEmpty()) {
            Node cur = queue.poll();
            // System.out.println("visit " + cur.r + " " + cur.c);
            //distance가 D를 넘으면 break;
            if(cur.distance > D)
                break;
            
            
            //적을 만났다면 break
            if (board[cur.r][cur.c] == ENEMY && deadEmemies[cur.r][cur.c] >= cur.time) {
                // System.out.println(" 궁수 " + (r + 1) + ", " + c + " 가 시간 " + cur.time + " 초에" + cur.r + " " + cur.c + "죽임"  );
                deadEmemies[cur.r][cur.c] = cur.time; //죽은 시간 표시
                break;
            }

            for(int i = 0; i < 3; i++) {
                int nextr = cur.r + dy[i];
                int nextc = cur.c + dx[i];

                if(canGo(nextr, nextc) && visited[nextr][nextc] == 0) {
                    visited[cur.r][cur.c] = 1;
                    queue.offer(new Node(nextr, nextc, time, cur.distance + 1));
                }
            }
        }
    }

    public static void beginScenario() {
        Queue<Node> queue = new ArrayDeque<>();

        for(int i = 0; i < 3; i++) {
            queue.offer(new Node(N, position[i], 0, 1));
        }

        while(!queue.isEmpty()) {
            Node cur = queue.poll();

            findEnemy(cur);
            if(cur.time == N)   
                break;
            
            if(canGo(cur.r - 2, cur.c))
                queue.offer(new Node(cur.r - 1, cur.c, cur.time + 1, 1));
        }
    }

    public static void makeArrows(int depth, int idx) {

        if(depth == 3) {
          
            for(int i = 0; i < N; i++) {
                Arrays.fill(deadEmemies[i], NONE);
            }
            beginScenario();

            int deadEmemyCount = 0;
            for(int i = 0; i < N; i++) {
                for(int j = 0; j < M; j++){
                    if(deadEmemies[i][j] != NONE) {
                        deadEmemyCount++;
                        deadEmemies[i][j] = NONE;
                    }
                }
            }

            answer = Math.max(answer, deadEmemyCount);
            return;
        }

        if(idx >= M)
            return;
        position[depth] = idx;
        makeArrows(depth + 1, idx + 1);
        makeArrows(depth, idx + 1);


    }

    public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        Scanner sc = new Scanner(br.readLine());

        N = sc.nextInt();
        M = sc.nextInt();
        D = sc.nextInt();
        
        board = new int[N][];
        deadEmemies = new int[N][M];

        position = new int[3];

        for(int i = 0; i < N; i++) {
            board[i] = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        }

        //M에서 3개 조합
        //뽑은 후 시나리오 진행.
        //BFS 사용. 
        makeArrows(0, 0);
        System.out.println(answer);


        
    }
}