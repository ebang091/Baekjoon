/*
 * 방향 그래프
 * 지름 길의 개수  N, 고속도로의 길이 D
 * 
 * 
 */

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        int N;
        String englishName;

        BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

        englishName = bf.readLine();
        N = Integer.parseInt(bf.readLine());
        int maxScore = -1;
        String maxTeam = "";
        int L,O,V,E;
        int yL = 0, yO = 0, yV = 0, yE = 0;
        for(int j = 0; j < englishName.length(); j++){
            if(englishName.charAt(j) == 'L')
                    yL++;
                else if(englishName.charAt(j) == 'O')
                    yO++;
                else if(englishName.charAt(j) == 'V')
                    yV++;
                else if(englishName.charAt(j)== 'E')
                    yE++;
        }
        // System.out.println(yL + " " + yO + " " + yV+ " " + yE);

        for(int i = 0; i < N; i++){
            int score= 0;
            L = yL;
            O = yO;
            V = yV;
            E = yE;
            String teamName = bf.readLine();
            for(int j = 0; j < teamName.length(); j++){
                if(teamName.charAt(j) == 'L')
                    L++;
                else if(teamName.charAt(j) == 'O')
                    O++;
                else if(teamName.charAt(j) == 'V')
                    V++;
                else if(teamName.charAt(j)== 'E')
                    E++;
            }
            score = ((L + O) * (L + V) * (L + E) * (O + V) * (O + E) * (V + E)) % 100;
                if(score > maxScore){
                    maxScore = score;
                    maxTeam = teamName;
                }
                else if(score == maxScore){
                    if(teamName.compareTo(maxTeam) < 0){
                        maxScore = score;
                        maxTeam = teamName;
                    }
                }
          
        }
          System.out.println(maxTeam);
    }
}
