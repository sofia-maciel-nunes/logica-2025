#include <stdio.h>

int main() {
	for (int N=2; N<=100; N += 2) {
		printf("%d\n",N);
	}
	return 0;

// outra solução possível

#include <stdio.h>

int main() {
	int N = 0;
	while (1) {
		N+=2;
		printf("%d\n",N);
		if (N>=100) {
			break;
		}
		else {
			continue;
		}
