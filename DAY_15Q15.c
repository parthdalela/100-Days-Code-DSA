/*Problem: Given a matrix, calculate the sum of its primary diagonal elements. The primary diagonal consists of elements where row index equals column index.

Input:
- First line: two integers m and n
- Next m lines: n integers each

Output:
- Print the sum of the primary diagonal elements

Example:
Input:
3 3
1 2 3
4 5 6
7 8 9

Output:
15

Explanation:
1 + 5 + 9 = 15*/
#include<stdio.h>
int main()
{
    int m,n,sum=0;
    printf("enter the number of rows and columns of the matrix : ");
    scanf("%d %d",&m,&n);
    printf("enter the elements of the matrix : ");
    int arr[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(i==j)
            {
                sum+=arr[i][j];
            }
        }
    }
    printf("sum of primary diagonal elements is : %d",sum);
    return 0;
}