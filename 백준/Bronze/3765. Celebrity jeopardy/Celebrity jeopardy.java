import java.util.*;
import java.io.*;

public class Main{
    public static void main(String args[]) throws IOException {
           BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

            while(true){
                String input = bf.readLine();
                if(input == null)
                        return;
                System.out.println(input);
            }
    }
}