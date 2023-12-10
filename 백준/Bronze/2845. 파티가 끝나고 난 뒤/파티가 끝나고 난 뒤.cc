#include <stdio.h>

int main() {
	int n, m, i, news;
	scanf("%d %d", &n, & m);

	for (i = 0; i < 5; i++) {
		scanf("%d", &news);
		printf("%d ", news - n*m);
	}
	return 0;
}