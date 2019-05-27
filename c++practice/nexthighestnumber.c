#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
//Complete the following function.


void calculate_the_maximum(int n, int k) {
  //Write your code here.
    int i,j,mand,mor,mxor;
    
    
    mand=1&2;
    mor=1|2;
    mxor=1^2;
        
    for(i=1;i<n;i++)
    {
        for(j=i+1;j<=n;j++)
        {
           // printf("\na=%d ,b=%d, %d\n", i,j,(i&j));
            if((i&j)>mand && (i&j) <k  )
            {  
                  mand=(i&j);
             //     printf("mand= %d",mand);
                
                
            }
                
            if((i|j)>mor && ((i|j) <k ))
                mor=(i|j);
            if((i^j)>mxor && ((i^j) <k ))
                mxor=(i^j);
            
            
        }
    }
    
    
    printf("%d\n%d\n%d",mand,mor,mxor);
}

int main() {
    int n, k;
  
    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);
 
    return 0;
}

