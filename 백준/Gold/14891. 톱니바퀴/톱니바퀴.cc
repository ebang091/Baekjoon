#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void rotate_right(int setting[][8], int number, int direction);

void rotate_right_utils(int setting[][8], int number)
{
    int temp = setting[number][7];
    for(int j = 7; j >= 1; j--)
    {
        setting[number][j] = setting[number][j - 1];
    }
    setting[number][0] = temp;
}

void rotate_left_utils(int setting[][8], int number)
{
    int temp = setting[number][0];
    for(int j = 0; j < 8; j++)
    {
        setting[number][j] = setting[number][(j + 1) % 8];
    }
    setting[number][7] = temp;
}

void rotate_left(int setting[][8], int number, int direction)
{
    /*
    돌릴 톱니바퀴가 2,3 번이라면 양쪽을 검사
    1이면 2만 검사 
    4이면 1만 검사
    */
//    cout << "rotate left" << " " << number <<endl;
   if (number == 1)
    {
        if (setting[number + 1][6] != setting[number][2] && direction != -1)
            rotate_right(setting, number + 1, 1);
    }
    else if(number == 2 || number == 3)
    {
        if (setting[number + 1][6] != setting[number][2] && direction != -1)
            rotate_right(setting, number + 1, 1);

        if (setting[number - 1][2] != setting[number][6] && direction != 1)
            rotate_right(setting, number - 1, -1);
    }
    else if(number == 4)
    {
        if (setting[number - 1][2] != setting[number][6] && direction != 1)
            rotate_right(setting, number - 1, -1);
    }
    rotate_left_utils(setting, number);
}

void rotate_right(int setting[][8], int number, int direction)
{
    // cout << "rotate right " << number << "\n";
    if (number == 1)
    {
        if (setting[number + 1][6] != setting[number][2] && direction != -1)
            rotate_left(setting, number + 1, 1);
        
    }
    else if(number == 2 || number == 3)
    {
        if (setting[number + 1][6] != setting[number][2] && direction != -1)
            rotate_left(setting, number + 1, 1);

        if (setting[number - 1][2] != setting[number][6] && direction != 1)
            rotate_left(setting, number - 1 , -1);
    }
    else if(number == 4)
    {
        if (setting[number - 1][2] != setting[number][6] && direction != 1)
            rotate_left(setting, number - 1, -1);
    }
    rotate_right_utils(setting, number);
}

void rotate_setting(int setting[][8], int number, int rotate)
{
    // cout << "\nnumber , rotate : " << number << " " << rotate << "\n";
    if (rotate == -1)
        rotate_left(setting, number, 0);
    else
        rotate_right(setting, number, 0);
}

void print(int setting[][8])
{
       for(int i = 1; i <= 4; i++)
    {
        for(int j = 0; j < 8; j ++)
            cout << setting[i][j] << " ";
        cout << "\n";
    }
}

int main()
{
    int setting[5][8];
    string str;
    for(int i = 1; i <= 4; i++)
    {
        cin >> str;
        for(int j = 0; j < 8; j ++)
            setting[i][j] = str[j] - '0';
    }
    
   
    int M, rotate, number;
    
    cin >> M;
    for(int i = 0; i < M; i++)
    {
        cin >> number >> rotate;
        
        rotate_setting(setting, number, rotate);
        // cout << "\n\n";
    }

    int r = 1;
    int score = 0;
    for(int i = 1; i <= 4; i++)
    {
        if (setting[i][0] == 1)
        {
            score += r;
        }
        r *= 2;
    }
    
   
    
    cout << score;
}