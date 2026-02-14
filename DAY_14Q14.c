/*Problem: Write a program to check whether a given square matrix is an Identity Matrix. An identity matrix is a square matrix in which all diagonal elements are 1 and all non-diagonal elements are 0.

Input:
- First line: integer n representing number of rows and columns
- Next n lines: n integers each representing the matrix elements

Output:
- Print "Identity Matrix" if the matrix satisfies the condition
- Otherwise, print "Not an Identity Matrix"

Example:
Input:
3
1 0 0
0 1 0
0 0 1

Output:
Identity Matrix*/
#include<stdio.h>
int main()
{
    int n,count=0;
    printf("enter the number of rows and columns of the matrix : ");
    scanf("%d",&n);
    printf("enter the elements of the matrix : ");
    int arr[n][n];
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j && arr[i][j]==1)
            {
                count++;
            }
            else if(i!=j && arr[i][j]==0)
            {
                count++;
            }
            else
            {
                count--;
                break;
            }
        }
        if(count<0)
        {
            break;
        }
    }
    if(count==n)
    {
        printf("Identity Matrix");
    }
    else
    {
        printf("Not an Identity Matrix");
    }
}