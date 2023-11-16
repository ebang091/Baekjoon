import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.*;
public class Main {
    
    private static class Position{
        
        int row;
        int col;
        

        Position(int row, int col){
            this.row = row;   
            this.col = col;
        }

        Position(){}

        public void setPosition(Position e){
            this.row = e.row;
            this.col = e.col;
        }

        public void setPosition(int row, int col){
            this.row = row;
            this.col = col;
        }


        public boolean samePosition(Position e){
            return this.col == e.col && this.row == e.row;
        }

        @Override
        public String toString(){
            String r = intToCharString(this.col);
            String c = intToString(this.row);
            return r + c;
        }
    }

    public static enum Direction {
    
    R(0,1, "R"),
    L(0,-1, "L"),
    B(-1,0, "B"),
    T(1,0, "T"),
    RT(1,1, "RT"),
    LT(1,-1, "LT"),
    RB(-1,1, "RB"),
    LB(-1,-1, "LB");

    private int y;
    private int x;
    private String naming;

    Direction(int y, int x, String naming){
        this.y = y;
        this.x = x;
        this.naming = naming;
    }

    public static int getDirectionY(String direction){
        return Arrays.stream(values()).filter(d -> d.naming.equals(direction)).findFirst().get().y;
    }

        public static int getDirectionX(String direction){    
        return Arrays.stream(values()).filter(d -> d.naming.equals(direction)).findFirst().get().x;
    }

    }

    private static int commandSize = 0;
    private static Position King = new Position();
    private static Position Stone = new Position();
    private static Position[] moveDirections = new Position[commandSize + 1];
    private static int current = 0;
    
    private static boolean canGo(Position pos){
        return 1 <= pos.row && pos.row <= 8 && 1 <= pos.col && pos.col <= 8;
    }

    private static int charToInt(char c){
        return c - 'A' + 1;
    }

    private static String intToCharString(int c){
        return Character.toString(c + 'A' - 1);
    }

    private static String intToString(int c){
        String str = Character.toString(c + '0');

        return str;
    }

    private static void move(Position king, Position stone){
        King.setPosition(king);
        if(King.samePosition(Stone)){
            Stone.setPosition(stone);
        }   
    }

    private static void input() throws IOException{

        BufferedReader bfn = new BufferedReader(new InputStreamReader(System.in));
        String input = bfn.readLine();
        String[] inputs = input.split(" ");
        King.setPosition(inputs[0].charAt(1) - '0', charToInt(inputs[0].charAt(0)));
        Stone.setPosition(inputs[1].charAt(1) - '0', charToInt(inputs[1].charAt(0)));

        moveDirections = new Position[10001];

        commandSize = Integer.parseInt(inputs[2]);


        //이동 방향 저장
        for(int command = 0; command < commandSize; command++){
           String direction = bfn.readLine();
           moveDirections[current++] = new Position(Direction.getDirectionY(direction), Direction.getDirectionX(direction));
        }
    }

    private static void solve(){
        current = 0;
        while (current < commandSize){

            Position moveDirection = moveDirections[current++];
            Position nextKing = new Position(King.row + moveDirection.row, King.col + moveDirection.col);
            
            boolean canGoCheck = false;
            Position nextStone = new Position(Stone.row + moveDirection.row, Stone.col + moveDirection.col);
            if(canGo(nextKing)){
                canGoCheck = true;
                if(nextKing.samePosition(Stone)){
                    if(!canGo(nextStone))
                        canGoCheck = false;
                }
            }

            if(canGoCheck)
                move(nextKing, nextStone);

        }
    }
    

    private static void output(){
                  
        System.out.println(King);
        System.out.println(Stone);
    }

    public static void main(String[] args) throws IOException {
        input();
        solve();
        output();
    }
   
 }