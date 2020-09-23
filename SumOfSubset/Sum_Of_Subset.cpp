
#include <stdio.h>

bool isSubsetSum(int set[], int n, int sum)
{
    bool subset[n + 1][sum + 1];

    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    for (int i = 1; i <= sum; i++)
        subset[0][i] = false;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j < set[i - 1])
                subset[i][j] = subset[i - 1][j];
            if (j >= set[i - 1])
                subset[i][j] = subset[i - 1][j] ||
                            subset[i - 1][j - set[i - 1]];
        }
    }

    //code to print table
     for (int i = 0; i <= n; i++)
     {
       for (int j = 0; j <= sum; j++)
          printf ("%4d", subset[i][j]);
       printf("\n");
     }

    return subset[n][sum];
}


int main()
{
    int i;
    int set[50],n,sum;
    printf("Enter the sum\n");
    scanf("%d",&sum);


    printf("Number of elements in the set\n");
    scanf("%d",&n);

    printf("Enter the values\n");
    for(i=0;i<n;i++)
        scanf("%d",&set[i]);

    if (isSubsetSum(set, n, sum) == true)
        printf("Found a subset with given sum");
    else
        printf("No subset with given sum");
    return 0;
}
