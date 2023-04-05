#include <stdio.h>
#include <string.h>
#include <assert.h>
//左旋字符    例：ABCD  ->  BCDA

void reverse(char* arr1 , char* arr2)
{
    assert(arr1);
    assert(arr2);
    while (arr1<arr2)
    {
        char ret = *arr1;
        *arr1 = *arr2;
        *arr2 = ret;
        arr1++;
        arr2--;
    }
}
void move(char* arr , int n)
{
    assert(arr);
    int len = strlen(arr);
    
    reverse(arr,arr+n-1);
    reverse(arr+n,arr+len-1);
    reverse(arr, arr+len-1);
}
int is_move(char* arr11,char* arr22)
{
    int len = strlen(arr11);
    int i = 0;
    for (i=0 ; i<len ; i++)
    {
        move(arr11 , 1);
        int ret = strcmp( arr11 , arr22 );
        if(ret==0)
        return 1;
    }
    return 0;
}
int main()
{
    char arr1[] = "abcdef" ;
    char arr2[] = "cdefab" ;
    int ret1 = is_move (arr1 , arr2);
    if(ret1==1)
    {
        printf("YES!\n");
    }
    else 
    {  
        printf("NO\n");
    }
    return 0;
}