/*Insert an Element in an Array

Problem: Write a C program to insert an element x at a given 1-based position pos in an array of n integers. Shift existing elements to the right to make space.

Input:
- First line: integer n
- Second line: n space-separated integers (the array)
- Third line: integer pos (1-based position)
- Fourth line: integer x (element to insert)

Output:
- Print the updated array (n+1 integers) in a single line, space-separated

Example:
Input:
5
1 2 4 5 6
3
3

Output:
1 2 3 4 5 6

Explanation: Insert 3 at position 3, elements [4,5,6] shift right*/

#include<stdio.h>
int main() 
{
    int n,x,p;
    printf("enter the size of array : ");
    scanf("%d",&n);
    int arr[n+1];
    for(int i=0;i<n;i++)
    {
        printf("enter the %d element of array : ",i);
        scanf("%d",&arr[i]);
    }
    printf("enter the element to be added : ");
    scanf("%d",&x);
    printf("enter the position at which element should be added : "); 
    // Here I want to clarify that position here means not the index number but the serial number where the user wants to enter the element
    scanf("%d",&p);
    for(int i=n;i>=p;i--)
    {
        int t=arr[i];
        arr[i]=arr[i-1];
        arr[i-1]=t;
    }
    arr[p-1]=x;
    printf("The new array is : ");
    for(int i=0;i<=n;i++)
    {
        printf("%d\t",arr[i]);
    }
    return 0;
}