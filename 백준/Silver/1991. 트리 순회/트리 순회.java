import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static Node []tree = new Node[(1 << 26)];


    static class Node {
        int left;
        int right;
    }

    public static void visitPre(int root){
        if(root == 0)
            return;
        System.out.print((char)(root + 'A' - 1));
        visitPre(tree[root].left);
        visitPre(tree[root].right);
    }

    public static void visitMid(int root){
       if(root == 0)
            return;
        visitMid(tree[root].left);
        System.out.print((char)(root + 'A' - 1));
        visitMid(tree[root].right);
    }

    public static void visitPost(int root){
        if(root == 0)
            return;
        visitPost(tree[root].left);
        visitPost(tree[root].right);
        System.out.print((char)(root + 'A' - 1));
    }
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        N = Integer.parseInt(br.readLine());
        for(int i = 0; i < N; i++) {
            int[] input = Arrays.stream(br.readLine().split(" ")).mapToInt((e) -> e.charAt(0) - 'A' + 1).toArray();
            int rootIdx = input[0];
            tree[rootIdx] = new Node();
            tree[rootIdx].left = input[1] != -18 ? input[1] : 0;
            tree[rootIdx].right = input[2] != -18 ? input[2] : 0; 
        }

       
        visitPre(1);
        System.out.println();
        visitMid(1);
        System.out.println();
        visitPost(1);
        System.out.println(); 


        
    }
}