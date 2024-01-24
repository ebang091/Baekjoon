import java.io.*;
public class Main {
    public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        
        int N = Integer.parseInt(br.readLine());
        
        for(int i = 0 ; i < N; i++){
            int whiteSpace = N - i - 1;
            for(int j = 0; j < whiteSpace; j++)
                System.out.print(" ");
            for(int j = 0; j < i + 1; j++){
                if(j == i)
                    System.out.print("*");
                else
                    System.out.print("* ");
            }
                System.out.println();
        }
    }
}