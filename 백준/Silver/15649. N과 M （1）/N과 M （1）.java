import java.io.*;
import java.util.*;

public class Main {
	static int[] selected;
	static int[] numbers;
	static int N, M;

	public static void dfs(int depth){

		if(depth == M){
			for(int i = 0; i < M; i++){
				System.out.print(numbers[i] + " ");
			}
			System.out.println();
			return;
		}
		for(int i = 1; i <= N; i++){
			if(selected[i] == 0){
				selected[i] = 1;
				numbers[depth] = i;
				dfs(depth + 1);
				selected[i] = 0;
			}
		}
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
		N = input[0];
		M = input[1];
		selected = new int[N+1];
		numbers = new int[M + 1];
		
		dfs(0);
		
		
	}
}