/*Problem: A secret system stores code names in forward order. To display them in mirror format, you must transform the given code name so that its characters appear in the opposite order.

Input:
- Single line: a lowercase string containing only alphabetic characters (no spaces)

Output:
- Print the transformed code name after applying the mirror operation

Example:
Input:
hello

Output:
olleh

Explanation: The first character moves to the last position, the second to the second-last, and so on until the entire string is mirrored*/
#include<stdio.h>
#include<string.h>
int main()
{
    char str[100];
    printf("Enter a string = ");
    scanf("%s",str);
    int n=strlen(str);
    for(int i=0;i<(n/2);i++)
    {
        /*str[i]=str[i]+str[strlen(str)-i-1];
        str[strlen(str)-i-1]=str[i]-str[strlen(str)-1-i];
        str[i]= str[i]-str[strlen(str)-1-i];*/
        char ch=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=ch;
    }
    printf("%s",str);
    return 0;
}