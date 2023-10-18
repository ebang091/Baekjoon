import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.BufferedInputStream;
import java.io.BufferedReader;

public class Main {
    public static void main(String[] args)throws IOException {


        InputStream input = System.in;
        InputStreamReader reader = new InputStreamReader(input);
        BufferedReader bs = new BufferedReader(reader);

        String str = bs.readLine();
        int integer = Integer.parseInt(str);

        for(int i = 0 ; i < integer; i++){
            System.out.println("SciComLove");
        }

    }

}