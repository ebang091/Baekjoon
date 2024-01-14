import java.io.*;
import java.util.*;

import javax.sound.midi.Soundbank;

public class Main {
    static int N, M, T, u, v;
    static int []visited;
    static int []parent;

    static ArrayList<Integer> []treeInfo;

    static int lca, size;
    
    public static int findLca(){
        //u, v
        visited[u] = 1;
        while (u != parent[u]) {
            u = parent[u];
            visited[u] = 1;
        }

        while (true) {
            if(visited[v] == 1){
                return v;
            }
            v = parent[v];
        }
    }

    public static void main(String[] args) throws IOException{
        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        T = Integer.parseInt(bf.readLine());
        for(int tc = 0; tc < T; tc++){
            N = Integer.parseInt(bf.readLine());
            int []input; 
            size = 0;

            parent = new int[10010];
            for(int i = 0; i < 10000; i++)
                parent[i] = i;
            treeInfo = new ArrayList[(1 << 16)];
            visited = new int[(1 << 16)];
            
            for(int i = 0; i < (1 << 16); i++){
                treeInfo[i] = new ArrayList<Integer>();
            }
        for(int i = 0; i < N -1; i++){
            input = Arrays.stream(bf.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
                int p = input[0];
                int c = input[1];
                parent[c] = p;
                treeInfo[p].add(c);

        }
        input = Arrays.stream(bf.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
        u = input[0];
        v = input[1];
            lca = findLca();

            System.out.println(lca);

        }
    }


}