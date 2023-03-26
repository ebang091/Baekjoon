#include <stdio.h>
 
int main() {
 
    int n, k;
    int cnt = 0;
    int i;
    scanf("%d %d", &n, &k);
    
 
    for (i = 1; i <= n; i++) {
        if (n % i == 0)
            cnt++;
        if (cnt == k)
            break;
    }
    if (i <= n) printf("%d", i);
    else printf("0");
 
    
}

 

