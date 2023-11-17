import java.io.*;
import java.util.*;

public class Main {
    
    private static void input() throws IOException{
        int wRate;
        int hRate;
        int length;
        double rateValue;

        BufferedReader bfn = new BufferedReader(new InputStreamReader(System.in));
        String input = bfn.readLine();
        String[] parsedInput = input.split(" ");

        length = Integer.parseInt(parsedInput[0]);
        hRate = Integer.parseInt(parsedInput[1]);
        wRate = Integer.parseInt(parsedInput[2]);

        //(ah)^2 + (aw)^2 = r^2
        //a^2(h^2 + w^2) = r^2
        rateValue = (double)Math.sqrt((double)length*length /(hRate*hRate + wRate*wRate));
        
        System.out.print((int)(rateValue*hRate) + " " + (int)(rateValue*wRate));



    }

    public static void main(String[] args) throws IOException{
        input();
        
    }
}