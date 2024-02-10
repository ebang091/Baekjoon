import java.io.*;
import java.util.*;

public class Main {

	static int N;
	static int answer;

	static int[][]map = new int[111][111];

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		N = Integer.parseInt(br.readLine());

		for(int i = 0; i < N; i++) {
			Scanner sc = new Scanner(br.readLine());
			int x = sc.nextInt();
			int y = sc.nextInt();
			// answer += 100;
			for(int r = y; r < y + 10; r++) {
				for(int c = x; c < x + 10; c++){
					map[r][c] = 1;
				}
			}
			
		}
		for(int r = 0; r < 101; r++){
			for(int c = 0; c < 101; c++){
				answer += map[r][c];
			}
		}

		System.out.println(answer);

	}

}