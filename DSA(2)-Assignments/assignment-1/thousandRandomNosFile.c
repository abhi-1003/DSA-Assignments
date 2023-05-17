#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include<string.h>
void printRandoms(long long upper,
							long long count)
{
	int i;
	for (i = 0; i < count; i++) {
		int num = (rand() %	(upper + 1));
		printf("%d\n", num);
	}
}

int main(int argc, char const *argv[])
{
    long long count = atoi(argv[1]);
    long long upper = atoi(argv[2]);
    printRandoms(upper,count);
    return 0;
}
