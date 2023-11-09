import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

/*
 * 케이크 수 : (a.x, a.y, a.z)
 *  
 */

public class Main {

     class Cake {
        public int x;
        public int y;
        public int z;
        
        public Cake(int x, int y, int z) {
            this.x = x;
            this.y = y;
            this.z = z;
        }

        public boolean equls(Cake compare) {
            return (compare.x == this.x && compare.y == this.y && compare.z == this.z);
        }

        public Cake operator(Cake operand){
            return new Cake(operand.x - this.z, operand.y / this.y, operand.z - this.x);
        }
    }

    public static void main(String[] args) throws IOException{

       solve();
    }

    public static void solve(){
         BufferedReader bfn = new BufferedReader(new InputStreamReader(System.in));
        java.util.ArrayList<Cake> cakes = new ArrayList<Cake>();    
        
        for(int i = 0; i < 2; i++){
            try {
                String[] inputs = bfn.readLine().split(" ");
                java.util.ArrayList<Integer> cakeValues = new ArrayList<Integer>();    
                for(String input : inputs){
                    cakeValues.add(Integer.parseInt(input));
                }
                Cake newCake = new Main().new Cake((int)cakeValues.get(0), (int)cakeValues.get(1), (int)cakeValues.get(2));
                cakes.add(newCake);
            }
            catch(Exception e){
                System.out.println((e.getMessage()));
            }

        }
        Cake result = cakes.get(0).operator(cakes.get(1));
        System.out.println(result.x + " " + result.y + " " + result.z);
    }
}