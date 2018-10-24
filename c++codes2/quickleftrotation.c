#include<stdio.h>
int main()
 {
     int x,no_elements,no_times,i,j,k,l,c=0,a1;
     scanf("%d",&x);
     while(x--)
     {
       
       scanf("%d",&no_elements);
       scanf("%d",&no_times);
       int arr[no_elements];
       
       for(i=0;i<no_elements;i++)
       {
           scanf("%d",&arr[i]);
       }
       
       for(j=0;j<no_times;j++)
       {
          c=0;
       for(l=0;l<no_elements;l++)
        {
          
          if(c==0)
             a1=arr[0];
          
           if(l==no_elements-1)
            arr[l]=a1;
          else
           arr[l]=arr[l+1];
            
            c++;
           }
       }
       
       
       for(k=0;k<no_elements;k++)
       {
           printf("%d\t",arr[k]);
       }
       cout<<"\n";
     }
	return 0;
}
