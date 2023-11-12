import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Main {
    public static void main(String[] args) throws IOException{
        BufferedReader bfn = new BufferedReader(new InputStreamReader(System.in));
        int generalCake = Integer.parseInt(bfn.readLine());
        int smallCake = Integer.parseInt(bfn.readLine());

        int totalCake = generalCake * 8 + smallCake * 3;
        int leftCake = totalCake - 28;
        // System.out.println(leftCake);
        if(leftCake >= 0){
            System.out.println(leftCake);
            return;
        }
        System.out.println("0");

            
        
        
    }
}