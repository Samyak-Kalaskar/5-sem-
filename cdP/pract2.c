#include <stdio.h> 
#include<string.h> 
int main() 
{ 
    char str[20]; 
    int l; 
    printf("Enter the string"); 
    scanf("%s",str); 
    l=strlen(str); 
   // printf("%s",str); 
    if(str[0]=='/' && str[1]=='/' && str[2]!='/')  
    { 
    printf("It is single line comment"); 
    
    } 
  else if(str[l-2]=='*' && str[l-1]=='/' && str[0]=='/' && str[1]=='*') 
  { 
  printf("It is a multiline comment"); 
  } 
  else 
  printf("It is not comment");  
    return 0; 
}