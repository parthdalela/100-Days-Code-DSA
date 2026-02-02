/*Delete an Element from an Array

Problem: Write a C program to delete the element at a given 1-based position pos from an array of n integers. Shift remaining elements to the left.

Input:
- First line: integer n
- Second line: n space-separated integers
- Third line: integer pos (1-based position to delete)

Output:
- Print the updated array with (n-1) elements, space-separated

Example:
Input:
5
10 20 30 40 50
2

Output:
10 30 40 50

Explanation: Delete position 2 (element 20), remaining elements shift left*/
#include<stdio.h>
int main()
{
    int n,p;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
    {
        printf("enter the %d element of the array : ",i);
        scanf("%d",&arr[i]);
    }
    printf("enter the position of the element to be deleted :" );
    scanf("%d",&p);
    for(int i=p-1;i<n;i++)
    {
        int t=arr[i];
        arr[i]=arr[n-1];
        arr[n-1]=t;
    }
    printf("the new array is : ");
    for(int i=0;i<n-1;i++)
    {
        printf("%d\t",arr[i]);
    }
}