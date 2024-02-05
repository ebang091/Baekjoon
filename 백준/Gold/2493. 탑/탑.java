import java.io.*;
import java.util.*;
public class Main {
    static int N;
    static int[] tops;
    static int[] answer;

    static class Top {
        int height;
        int idx;
        public Top(int h, int i) {
            this.height = h;
            this.idx = i;
        }
    }
    public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        tops = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();

        answer = new int[N+1];
        Stack<Top> stack = new Stack();

        for(int i = N-1; i >= 0; i--){
            int height = tops[i];
            while (stack.isEmpty() == false && stack.peek().height < height ){
                answer[stack.pop().idx] = i + 1;
            }
            stack.push(new Top(height, i + 1));
        }

        while(stack.isEmpty() == false){
            answer[stack.pop().idx] = 0;
        }
        for(int i = 1; i <= N; i++){
            System.out.print(answer[i] + " ");
        }
    }
}