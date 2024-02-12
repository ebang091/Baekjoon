import java.io.*;
import java.util.*;


public class Main {
	static int N;
	static int [][]map;
	static int [][]visited;
	static int [][]dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
	static int answer;

	static final int SMALL = 10;
	static final int LARGE = 100;

	static class Pair {
		int y;
		int x;

		public Pair(int y, int x) {
			this.y = y;
			this.x = x;
		}
	}

	public static boolean canGo(int r, int c){
		return 0 <= r && r < 100 && 0 <= c && c < 100;
	}

	public static void BFS(int r, int c) {
		Queue<Pair> queue = new ArrayDeque<>();

		queue.offer(new Pair(r, c));
		int edges  = 0;
		
		while (!queue.isEmpty()) {
			Pair cur = queue.poll();
			boolean isEdge = false;
			for(int i = 0; i < 4; i++) {
				int y = cur.y + dir[i][0];
				int x = cur.x + dir[i][1];

				if (canGo(y, x) && visited[y][x] == 0){
					visited[y][x]  = 1;
					if (map[y][x] == 1)
						queue.offer(new Pair(y,x));
					else
						isEdge = true;
				}
			}

			if (isEdge){
				System.out.println("edge : " + cur.y + " " + cur.x);
				edges++;
			}
				
		}
		answer += edges;
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());

		map = new int[LARGE][LARGE];
		visited = new int[LARGE][LARGE];
		for(int i = 0; i < N; i++) {
			Scanner sc = new Scanner(br.readLine());
			int x = sc.nextInt();
			int y = sc.nextInt();
			for(int r = y ; r < y + SMALL; r++) {
				for(int c = x; c < x + SMALL; c++){
					map[r][c] = 1;
				}
			}
		}


		answer = 0;
		for(int i = 0; i < LARGE; i++) {
			for(int j = 0; j < LARGE; j++){
				boolean isEdge = false;
				if(map[i][j] == 1){

					
					if(i == 0 || (i -1 >= 0 && map[i-1][j] == 0))
						answer++;
					if(j == 0 || (j-1 >= 0 && map[i][j-1] == 0))
						answer++;
					if(i == LARGE - 1|| (i + 1 < LARGE && map[i+1][j] == 0))
						answer++;
					if( j == LARGE - 1 || (j + 1 < LARGE && map[i][j+1] == 0))
						answer++;

					

				}

				
				// if(map[i][j] == 1 && visited[i][j] == 0){

				// }
					// BFS(i, j);
			}
		}

		System.out.println(answer);



	}
}