/* Problem: Given an array of integers, count the frequency of each distinct element and print the result.

Input:
- First line: integer n (size of array)
- Second line: n integers

Output:
- Print each element followed by its frequency in the format element:count

Example:
Input:
5
1 2 2 3 1

Output:
1:2 2:2 3:1*/
#include<stdio.h>
int main()
{
    int n;
    printf("enter the size of array : ");
    scanf("%d",&n);
    printf("enter the elements of the array : ");
    int arr[n];
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("element:count\n");
    for(int i=0;i<n;i++)
    {
        int count=1;
        if(arr[i]!=-1)
        {
            for(int j=i+1;j<n;j++)
            {
                if(arr[i]==arr[j])
                {
                    count++;
                    arr[j]=-1; // Mark as counted
                }
            }
            printf("%d:%d ",arr[i],count);
        }
    }
}