#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, m;
    long limit, total;
    long i;

    printf("Enter two numbers: ");
    scanf("%d %d", &n, &m);
    limit = n;

    for (i = 0; i < m; i++) {
        total = 0;
        total += (limit * (limit + 1)) / 2;
        printf("1 + ... + %ld = %ld\n", limit, total);
        limit = total;
    }

    printf("\nSum(%d, %d) = %ld\n", n, m, total);

    return EXIT_SUCCESS;
}
