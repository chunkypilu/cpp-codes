#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char *func(char *s)
{

char *s1=(char *)malloc(strlen(s)*sizeof(char)); 
strcpy(s1,s);
int left,right;
char temp;
left=0;
right=strlen(s1)-1;
while(left<right)
 {
   temp=s1[left];
   s1[left]=s1[right];
   s1[right]=temp;
   left++;
   right--;
 }
return s1;
}



int main()
{
   char *s=(char *)malloc(7*sizeof(char));
   
   scanf("%s",s);
   printf("%s",s);
   printf("\n%s",func(s));
   printf("\n%s",s);


  return 0;
}

