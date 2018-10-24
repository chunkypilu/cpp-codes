#include <bits/stdc++.h>
using namespace std;

long long int a[10005];
long long int prod[10005];
#define FACT 10000000000

int main() {
	long long int t,n,k,i,j,key,size,temp, num;
	scanf("%lld",&t);
	while(t--){
	    scanf("%lld%lld",&n,&k);
	    for(i=0;i<n;i++){
	        scanf("%lld",&a[i]);
	    }
	    
	    sort(a,a + n,greater<int>());
	    
	    prod[0] = 1;
	    size = 1;
	    
	    for(i=0;i<k;i++){
	        temp = 0; num;
	        for(j=0;j<size;j++){
	            num = prod[j]*a[i] + temp;
	            prod[j] = num%FACT;
	            temp = num/FACT;
	        }
	        
	        while(temp){
	            prod[size] = temp%FACT;
			    temp /= FACT;
			    size++;
	        }
	    }
	    
	    printf("%lld",prod[size-1]);
	    for(i=size-2;i>=0;i--){
		    printf("%010lld",prod[i]);
	    }
	    printf("\n");
	}
	return 0;
}
