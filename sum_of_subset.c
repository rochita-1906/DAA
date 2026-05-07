#include <stdio.h>
#include <stdlib.h>

int n, d, W[10], X[10];

void sum_of_subsets(int S, int K, int r)
{
    int i;
    static int count = 1;

    X[K] = 1;

    if (S + W[K] == d)
    {
        printf("\nSolution %d = ", count++);

        for (i = 1; i <= K; i++)
        {
            if (X[i] == 1)
                printf("%d\t", W[i]);
        }
    }
    else if (S + W[K] + W[K + 1] <= d)
    {
        sum_of_subsets(S + W[K], K + 1, r - W[K]);
    }

    if ((S + r - W[K] >= d) && (S + W[K + 1] <= d))
    {
        X[K] = 0;
        sum_of_subsets(S, K + 1, r - W[K]);
    }
}

int main()
{
    int i, sum = 0;

    printf("\nRead number of elements: ");
    scanf("%d", &n);

    printf("\nRead elements in ascending order:\n");

    for (i = 1; i <= n; i++)
    {
        scanf("%d", &W[i]);
        sum = sum + W[i];
    }

    printf("\nRead value of d: ");
    scanf("%d", &d);

    sum_of_subsets(0, 1, sum);

    return 0;
}
