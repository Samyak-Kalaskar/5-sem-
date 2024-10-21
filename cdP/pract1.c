#include <stdio.h> 
int main() 
{ 
   char str[20],opp[10],id[10],numb[10]; 
   int i,j=0,k=0,l=0,n=5; 
   printf("Enter the equation:\n"); 
   scanf("%s",str); 
   for(i=0;i<=n;i++) 
   { 
       if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) 
       { 
           id[j]=str[i]; 
           j++; 
            
       } 
        else if(str[i]>='0' && str[i]<='9') 
        { 
            numb[l]=str[i]; 
            l++; 
        } 
        else 
          { 
            opp[k]=str[i]; 
            k++; 
        } 
   } 
   printf("\nOPERATOR:"); 
   for(i=0;i<k;i++) 
   { 
     printf("%c",opp[i]); 
    printf(","); 
      
   } 
   printf("\nIDENTIFIER:"); 
   for(i=0;i<j;i++) 
   { 
       printf("%c",id[i]); 
        printf(","); 
   } 
   printf("\nNUMBER:"); 
   for(i=0;i<l;i++) 
   { 
      printf("%c",numb[i]); 
       printf(","); 
   } 
    
    return 0; 
}