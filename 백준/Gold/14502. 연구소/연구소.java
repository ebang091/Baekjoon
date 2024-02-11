import java.io.*;
import java.util.*;

public class Main{
	static int N;
	static int M;
	static int [][]map;
	static List<Pair> blank = new ArrayList<>();
	static List<Pair> viruses = new ArrayList<>();
	static int []selected;
	static int answer;
	static int [][]visited;
	static int[][]newMap;

	
	static int [][]dir = {{0,1}, {0, -1}, {-1, 0}, {1, 0}};
	static class Pair {
		int y;
		int x;

		public Pair(int y, int x){
			this.y  = y;
			this.x = x;
		}
	}
	
	public static boolean canGo(int r, int c) {
		return 0 <= r && r < N && 0 <= c && c < M && map[r][c] != 1;
	}
	public static void BFS(int r, int c){
		Queue<Pair> queue = new ArrayDeque();

		queue.offer(new Pair(r, c));
		visited = new int[N][M];
		visited[r][c] = 1;
		
		while(!queue.isEmpty()){

			Pair cur = queue.poll();
			for(int i = 0; i < 4; i++){
				int y = cur.y + dir[i][0];
				int x = cur.x + dir[i][1];

				if(canGo(y, x) && visited[y][x] == 0){
					visited[y][x] =  1;
					newMap[y][x] = newMap[cur.y][cur.x];
					queue.offer(new Pair(y, x));
				}
			}
		}

	}

	public static void makeWalls(int depth, int idx){
		if(depth == 3){

		newMap = new int[N][M];
		for(int i = 0; i < N; i++){
			for(int j = 0; j < M; j++){
				newMap[i][j] = map[i][j];
			}
		}
			for(int i = 0; i < viruses.size(); i++){
				Pair virus = viruses.get(i);
				BFS(virus.y ,virus.x);
			}

			int cnt = 0;
			// System.out.println("\n");
			for(int i = 0 ; i < N; i++){
				for(int j = 0; j < M; j++){
					// System.out.print(newMap[i][j] + " ");
					if(newMap[i][j] == 0)
						cnt++;
				}
			}

			// System.out.println("cnt : "  + cnt);

			answer = Math.max(cnt, answer);
			return;
		}

		if(idx >= blank.size())
			return;

		map[blank.get(idx).y][blank.get(idx).x] = 1;
		makeWalls(depth + 1, idx + 1);
		map[blank.get(idx).y][blank.get(idx).x] = 0;
		makeWalls(depth, idx + 1);
	}
	public static void main(String[] args) throws IOException {
		//1. 벽을 3개 세우는 시나리오를 만든다.
		//2. 해당 시나리오에서 BFS 이후 안전영역의 크기를 구하고, 최댓값을 업데이트한다.
		//제약 조건 : N X M 크기의 연구소. 
		// 시간 복잡도 : 24개 중 3개의 벽 고르기 * (BFS 하기 + 전체 안전영역 개수)
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		Scanner sc = new Scanner(br.readLine());
		N = sc.nextInt();
		M = sc.nextInt();

		map = new int[N][];
		selected = new int[3];
		for(int i = 0; i < N; i++){
			int []input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
			map[i] = new int[M];
			for(int j = 0; j < M; j++){
				map[i][j] = input[j];
				if(map[i][j] == 0){
					blank.add(new Pair(i, j));
				}else if(map[i][j] == 2){
					viruses.add(new Pair(i, j));
				}
			}
		}	

		makeWalls(0, 0);
		System.out.println(answer);


		
	}

}