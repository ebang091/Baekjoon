import java.util.*;
import java.io.*;

public class Main{
    static int k;
    static int []selected;
    static int []input;
    
    public static void dfs(int count, int idx){
        
        if(count == 6){
            for(int i = 0; i < k; i++){
                 if(selected[i] == 1){
                     System.out.print(input[i + 1] + " ");
                 }
            }
             System.out.println();
            return;
        }
        
        if(idx >= k)
             return;
        
        selected[idx] = 1;
        dfs(count + 1, idx + 1);
        selected[idx] = 0;
        dfs(count, idx + 1);
    }
     public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
         while(true){
            input = Arrays.stream(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
             
             if(input[0] == 0)
                break;
             k = input[0];
             selected = new int[k];
             dfs(0, 0);
             System.out.println();
         }
     }
}