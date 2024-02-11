import java.io.*;
import java.util.*;


public class Main {
	static int N;
	static int[] sour;
	static int[] bitter;
	static int answer = Integer.MAX_VALUE;

	public static void chooseRecipe(int idx, int selected){

		if (idx >= N){
			int s = 1;
			int b = 0;
			int r = 0;
			for (int i = 0; i < N; i++){
				if ((selected & (1 << i)) == (1 << i)) {
					b += bitter[i];
					s *= sour[i];
					r++;
				}

			}

			if(r == 0)
				return;
	
			answer = Math.min(answer, Math.abs(s - b));
		
			return;
		}

		chooseRecipe(idx + 1, selected | (1 << idx));
		chooseRecipe(idx + 1, selected);
	}
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		N = Integer.parseInt(br.readLine());
 		sour = new int[N];
		bitter = new int[N];
		for(int i = 0; i < N; i++){
			Scanner sc = new Scanner(br.readLine());
			sour[i] = sc.nextInt();
			bitter[i] = sc.nextInt();
		}

		chooseRecipe(0, 0);
		System.out.println(answer);

	}
}