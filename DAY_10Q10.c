/*Problem: Read a string and check if it is a palindrome using two-pointer comparison.

Input:
- Single line: string s

Output:
- Print YES if palindrome, otherwise NO

Example:
Input:
level

Output:
YES

Explanation: String reads same forwards and backwards*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter a string = ");
    scanf("%s",str);
    int n=strlen(str);
    int flag=1;
    for(int i=0;i<(n/2);i++)
    {
        if(str[i]!=str[n-i-1])
        {
            flag=0;
            break;
        }
    }
    if(flag)
        printf("YES");
    else
        printf("NO");
    return 0;
}