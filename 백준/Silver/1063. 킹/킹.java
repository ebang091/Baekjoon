import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.*;

//R L B T 
//RT LT RB LB
//킹을 주어진 입력대로 움직이되,
        //이동하려는 곳에 돌이 있으면 밀린다. 
        //돌이 밀려날 때, 판을 벗어나면 킹은 움직이지 않는다. 
        //돌이 밀려나지 않아도 킹이 판을 벗어나려고 할 때 킹은 움직이지 않는다.

/*
C1 B1 3
L
T
LB

*/
public class Main {
    
    private static class Position{
        
        int row;
        int col;
        

        Position(int row, int col){
            this.row = row;   
            this.col = col;
        }

        Position(){}
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

    private static Position King = new Position();
    private static Position Stone = new Position();
    private static String direction;
    private static int directionY;
    private static int directionX;

    
    private static boolean Cango(int y, int x){
        // System.out.println("Cango check" + y + " " + x);
        return 1 <= x && x <= 8 && 1 <= y && y <= 8;
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

    private static void move(int y, int x){
        King.setPosition(y,x);
        if(King.samePosition(Stone)){
            Stone.setPosition(Stone.row + directionY, Stone.col + directionX);
            // System.out.println("after stone move" + Stone);
        }
            
    }
    private static boolean samePosition(int rx, int ry, int cx, int cy){
        return rx == cx && ry == cy;
    }

    public static void main(String[] args) throws IOException {
        
        BufferedReader bfn = new BufferedReader(new InputStreamReader(System.in));
        String input = bfn.readLine();
        String[] inputs = input.split(" ");
        King.setPosition(inputs[0].charAt(1) - '0', charToInt(inputs[0].charAt(0)));
        Stone.setPosition(inputs[1].charAt(1) - '0', charToInt(inputs[1].charAt(0)));

        int commands = Integer.parseInt(inputs[2]);
        for(int command = 0; command < commands; command++){
        
           direction = bfn.readLine();

            //setter
           directionY = Direction.getDirectionY(direction);
           directionX = Direction.getDirectionX(direction);
           int nextY = King.row + directionY;
           int nextX = King.col + directionX;
            boolean Cango = false;
            if(Cango(nextY, nextX)){
                Cango = true;
                
                if(samePosition(nextY, nextX, Stone.row, Stone.col)){
                    int stoneY = Stone.row + directionY;
                    int stoneX = Stone.col + directionX;
                    //돌도 갈 수 있는 곳인지 확인
                    if(!Cango(stoneY, stoneX))
                        Cango = false;
                }
            }

            if(Cango){
                move(nextY, nextX);
                // System.out.println("After move: " + King);
            } 
        }
        System.out.println(King);
        System.out.println(Stone);
    }
   
    
 }