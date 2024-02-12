import java.io.*;
import java.util.*;

public class Main {
	static int []nam;
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

		nam = new int[42];
		for(int i = 0; i < 10; i++){
			int n = Integer.parseInt(br.readLine());
			nam[n  % 42]++;
		}

		int answer = 0;
		for(int i = 0; i < 42; i++){
			if(nam[i] != 0)
				answer++;
		}
		System.out.println(answer);
	}
}