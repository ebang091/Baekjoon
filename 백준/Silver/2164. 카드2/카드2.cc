#include <iostream>
#include <vector>
#include <algorithm>
#include <stdlib.h>
#include <string.h>

using namespace std;
int N;
typedef struct stack_{
    int data;
    struct stack_ *next;
    struct stack_ *prev;
}stack;

stack *number; //stack 이자 헤드. 헤드부터 데이터 넣음,  원형 양방향 연결리스트로 구현



stack * newnode(int n)
{
    stack * node = (stack *)malloc(sizeof(stack));
    node->data = n;
    node->next = NULL;
    node->prev = NULL;
    return node;
}
int remove_first()
{
    stack *ptr = number;
    int ret = number->data;

    if(number->next == number){
        free(number);
        return ret;
    }
    number->next->prev = number->prev;
    number->prev->next = number->next;
    number = number->next;
    return ret;


}
int remove_last()
{
    stack *ptr = number->prev;//삭제 대상
    if(ptr == number)//하나밖에 없는 경우
    {
        free(ptr);
        return 0;
    }
    ptr->prev->next = number;
    number->prev = ptr->prev;
    int ret = ptr->data;
    free(ptr);
    return ret;
}

void lst_addLast(int n)
{

    stack * ptr = number;
    if(number->next == NULL) //아무것도 없을 때
    {
        number->data = n;
        number->next=  number;
        number->prev = number;
        return ;
    }
    ptr = number->prev; // 제일 마지막 노드
    ptr->next = newnode(n);
    ptr->next->next= number;
    ptr->next->prev = ptr;
    number->prev = ptr->next;
    return ;


}

void lst_addFirst(int n)
{
    stack *node = newnode(n);
    node->prev = number->prev;
    node->next = number;
    number->prev->next = node;
    number->prev = node;
    number = node;
}

int Sizeof()
{
    stack *ptr = number;
    if(!number)
        return 0;
    int cnt=1;
    ptr = ptr->next;
    while(ptr->next != number){
        cnt++;
        ptr = ptr->next;
    }
    return cnt;
}

void print_stack()
{
    stack * ptr = number;

    if(ptr)
        printf("Stack : %d", ptr->data);
    ptr = ptr->next;
    while(ptr != number)
    {
        printf(" %d", ptr->data);
        ptr  = ptr->next;
    }
    printf("\n");
}
void do_work()
{
    while(1)
    {
        int i = remove_first();
        int j = remove_first();
        lst_addLast(j);
//        print_stack();
        if(Sizeof() == 1)
            return ;
    }
}

int main()
{
    cin >> N;
    number = (stack *)malloc(sizeof(stack));
    number->next = 0;
    if(N == 1) {
        printf("1");
        return 0;
    }
    else if(N==2)
    {
        printf("2");
        return 0;
    }
    for(int i=1;i<=N;i++)
    {
        lst_addLast(i);
    }
    do_work();
    printf("%d" , remove_last());

}