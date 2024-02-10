import java.io.*;
import java.util.*;

public class Main {
    static int N;
    static Data []tree;
    static int size = 1; //실제 개수보다 1개 더 많은 값. 트리가 1부터 저장되기 때문이다.

    public static class Data implements Comparable<Data>{
        int data;

        @Override
        public int compareTo(Data d){
            if(Math.abs(this.data) < Math.abs(d.data))
                return -1;
            else if(Math.abs(this.data) > Math.abs(d.data))
                return +1;

            if(this.data < d.data)
                    return -1;
            else if (this.data > d.data)
                    return +1;         
            return 0;
        }

        public Data(int n){
            this.data = n;
        }

    }
    public static void main(String []args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        N = Integer.parseInt(br.readLine());
        //힙에 절댓값을 기준으로 작은 값이 루트가 오게 구현한다.
        tree = new Data[(1 << (int)(Math.log(N) / Math.log(2)) + 1)];
        for(int i = 0; i < N; i++) {
            int n = Integer.parseInt(br.readLine());
            if(n != 0) {
                //add
                // System.out.println("lets' add " + n);
                addTree(new Data(n));
            }
            else {
                //poll
                Data poll = pollTree();
                System.out.println(poll.data);
            }
        }
    }

    public static Data pollTree(){
        if(size == 1){
            return new Data(0);
        }
        else if(size == 2){
            size--;
            return tree[1];
        }

        // System.out.println("let's poll");
        Data temp = tree[1];
        
        swap(tree, 1, size - 1);
        int removeIdx = 1;
        int childIdx = removeIdx * 2;
        
        size--;
        if (size - 1 >= removeIdx * 2 + 1 && tree[childIdx + 1].compareTo(tree[childIdx]) < 0) {
            childIdx += 1;
        }
        while (childIdx < size) {
            if (tree[childIdx] != null && tree[removeIdx].compareTo(tree[childIdx]) > 0) {
                swap(tree, removeIdx, childIdx);
                removeIdx = childIdx;
                childIdx = removeIdx * 2;
                if(size - 1 >= removeIdx * 2+ 1 && tree[removeIdx * 2 + 1].compareTo(tree[childIdx]) < 0) {
                    childIdx += 1;
                }
            } else {
                break;
            }
        }
        // System.out.println("root ended up into " + childIdx);
        return temp;
    }

    public static void addTree(Data d) {

        if(size == 1){
            // System.out.println("add into " + size);
            tree[size++] = d;
            return ;
        }

        tree[size] = d;
        int addIdx = size;
        int parent = addIdx / 2;
        // System.out.println("initial idx : " + addIdx);
        while(parent >= 1) {
            if(tree[addIdx].compareTo(tree[parent]) < 0){
                swap(tree, addIdx, parent);
                addIdx = parent;
                parent = addIdx /2;
            }
            else {
                break;
            }
        }
        // System.out.println("add into " + addIdx);
        size++;
    }   

    public static void swap(Data[] tree, int a, int b){
        // System.out.println("swap between " + a + " " + b);
        Data temp = tree[a];
        tree[a] = tree[b];
        tree[b] = temp;
    }
}