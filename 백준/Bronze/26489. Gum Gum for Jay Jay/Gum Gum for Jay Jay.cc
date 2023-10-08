#include <iostream>

int main(){
    int n = 0;
    std::string str;
    while(true){
        getline(std::cin, str);
        if(std::cin.eof())
                break;
        n++;
    }
    std::cout << n;
}