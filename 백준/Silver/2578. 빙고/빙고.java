import java.io.*;
import java.util.*;

public class Main { 
	static Map<Integer, Pair> map = new HashMap<>();
	static int [][]board;
	static int bingo;

	static final int CHECK = 4;
	static int [][]dir = {{0, 1}, {0, -1} , {1, 0}, {-1, 0}, {1, 1} , {-1, -1}, {-1, 1}, {1, -1}};
	

	static class Pair {
		int y;
		int x;

		public Pair(int y, int x){
			this.y = y;
			this.x = x;
		}
	}

	public static int countCheck(int r, int c, int k) {
		
		int i = 0;
		int y = r;
		int x = c;

		while (0 <= y && y < 5 && 0 <= x && x < 5 && (board[y][x] == CHECK)) {
			i++;
			y = r + i * dir[k][0];
			x = c + i * dir[k][1];
		}

		return i;
	}
	public static int isBingo(){
		int bingo = 0;
		for(int i = 0; i < 5; i++){
			int j = 0;
			while(j < 5 && board[i][j] == CHECK)
				j++;
			if(j == 5) {
				// System.out.println("가로 빙고 발견" + i);
				bingo++;
			}
		}

		for(int i = 0; i < 5; i++){
			int j = 0;
			while(j < 5 && board[j][i] == CHECK)
				j++;
			if(j == 5){
				// System.out.println("세로 빙고 발견 " + i);
				bingo++;
			}
		}

		int j = 0;
		for(int i = 0; i < 5; i++){
			if(board[i][i] != CHECK)
				break;
			j++;
		}
		if(j == 5){
			// System.out.println("대각선 아래 빙고 빌견");
			bingo++;
		}

		j = 0;
		for (int i = 0; i < 5; i++) {
			if(board[i][4 - i] != CHECK)
				break;
			j++;
		}
		if(j == 5){
			// System.out.println("대각선 위 빙고 발견");
			bingo++;
		}
		
		return bingo;

	}
	public static void search(int r, int c) {

		int garo = countCheck(r, c , 0);
		garo += countCheck(r, c, 1) - 1;

		if(garo == 5){
			bingo++;
			return;
		}

		int sero = countCheck(r, c, 2);
		sero += countCheck(r, c, 3) -1;

		if(sero == 5){
			bingo++;
			return;
		}

		int daegakRight = countCheck(r, c, 4);
		daegakRight += countCheck(r, c, 5) -1;
		if(daegakRight == 5) {
			bingo++;
			return;
		}

		int daegakLeft = countCheck(r, c, 6);
		daegakLeft += countCheck(r, c, 7) -1;
		if(daegakLeft == 5) {
			bingo++;
			return;
		}
	}

	public static void main(String[] args) throws IOException {

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		board = new int[5][5];


		for (int i = 0 ; i < 5; i++){
			String []input = br.readLine().split(" ");
			for (int j = 0; j < 5; j++){
				int number = Integer.parseInt(input[j]);
				map.put(number , new Pair(i, j));
			}
		}

		boolean isEnd = false;
		int answer = 0;
		for(int i = 0; i < 5; i++){
			String []input = br.readLine().split(" ");
			for (int j = 0; j < 5; j++) {
				int number = Integer.parseInt(input[j]);
				Pair position = map.get(number);
				// System.out.println(number + " search " + position.y + " " + position.x );
				board[position.y][position.x] = CHECK;
				// System.out.println(number + " search");
				// search(position.y, position.x);
				int result = isBingo();
				// System.out.println("bingo count " + result);
				if (result >= 3 && isEnd == false) {
					// System.out.println("find " + i + " " + j );
					answer = i * 5 + j + 1;
					// System.out.println(i * 5 + j + 1) ;
					isEnd = true;
					break;
				}
				// bfs(position.y, position.x);

			}
		}
		System.out.println(answer);

		
	}
}