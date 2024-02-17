import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static int y;
    static int x;
    static int sequence;
    static int answer;
/*
1 2 
3 4 구역

*/
    public static void draw(int r, int c, int size, int number) {
        if(size == 0){
            // System.out.println(r + " " + c + "도착!");
            answer = number;
            return;
        }

        // System.out.println("visit " + r + " " + c + " " + number + " size :" + size);

        if(x >= c + size /2) {
            if(y >= r + size / 2) //4구역
                draw(r + size /2, c + size /2 , size /2 , number + (int)Math.pow(size /2 , 2) * 3);
            else //2구역
                draw(r , c + size / 2, size /2 , number + (int)Math.pow(size /2 , 2) * 1);
        }
        else { 
            if(y >= r + size / 2) //3구역
                draw(r + size /2, c , size /2 , number + (int)Math.pow(size /2 , 2) * 2);
            else //1구역
                draw(r , c , size /2 , number + (int)Math.pow(size /2 , 2) * 0);
        }




        

    }
    public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        N = input[0];
        y = input[1];
        x = input[2];

        sequence = 0;
        draw(0,0, (int) Math.pow(2, N) , 0);
        System.out.println(answer);
    }
}