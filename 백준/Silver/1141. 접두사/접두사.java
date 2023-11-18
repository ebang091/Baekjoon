import java.util.*;
import java.io.*;

public class Main {

    public static void main(String[] args) throws IOException {
        BufferedReader bfn = new BufferedReader(new InputStreamReader(System.in));

        int n = Integer.parseInt(bfn.readLine());
        String[] inputs = new String[n];

        for(int i = 0 ; i < n; i++){
            String input = bfn.readLine();
            inputs[i] = input;
        }

        
        ArrayList<String>wordGroup =  new ArrayList();
        
        //문자열의 길이 순으로 정렬
        //짧은 순서대로 확인하면서 접두사 여부를 확인한다. 
        Arrays.sort(inputs, (str1, str2) -> str2.length() - str1.length());
    
        for(String input : inputs) {
        //처음
        if (wordGroup.size() == 0){
            wordGroup.add(input);
            continue;
        }

        boolean isNewWord = true;

        for(String existingString : wordGroup){
            if(existingString.indexOf(input) == 0){
                isNewWord = false;
                break;
            }
        }
        if(isNewWord == true)
            wordGroup.add(input);
        
    }
        System.out.print(wordGroup.size());
    }
    


}