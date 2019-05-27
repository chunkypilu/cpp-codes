#include<stdio.h>
#include<string.h>

int main()
{
    freopen("altercharinput.in","r",stdin);
    char s[1000000];
    //scanf("%[^\n]s",s);
    fgets(s,1000000,stdin);
    
    if(s[0]>=65&&s[0]<=90)
       s[0]=s[0]+32;
    
    printf("%s",s);
    //fputs(s,stdout);
    
    int i,j;
   // printf("l=%lu",strlen(s));
    
    
    char key[1000000];
    //printf("l=%lu",strlen(s));
    
    
    for(i=0;i<1000000;i++)
    {
        for(j=0;j<strlen(key);j++)
        {
           if(s[i]==key[j])
           {
               break;
           }
        }
        if(j==strlen(key))
        {
            key[j]=s[i];
            printf("%c",s[i]);
        }
        else
        {
            key[j]='@';
        }
    }
    
    
return 0;
}
