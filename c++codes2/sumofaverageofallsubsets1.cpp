#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;
int main()
{

    int t;
    cin>>t;
    while(t--)
    {
        int set_size,i;
        cin>>set_size;
        int arr[set_size];
        for(i=0;i<set_size;i++)
        {
            cin>>arr[i];
        }
        
    unsigned int pow_set_size = pow(2, set_size);
	int counter, j;
    float overall_sum=0;
    cout<<fixed<<setprecision(6);
	/*Run from counter 000..0 to 111..1*/
	for(counter = 0; counter < pow_set_size; counter++)
	{
	
           float avg,no=0,sum=0;
			
	for(j = 0; j < set_size; j++)
	{
		/* Check if jth bit in the counter is set
			If set then pront jth element from set */
			
			
		if(counter & (1<<j))
			{
			        //cout<<arr[j];
			        sum+=arr[j];
			        no++;
//			        int no=0,sum=0,digit;
//			        float avg;
//			        while(arr[j]!=0)
//			        {
//			          digit=arr[j]%10;
//			          sum=+digit;
//			          arr[j]/=10;
//			          no++;
//			          
//			        }
//			        avg=sum/no;
//			        
//			
//			    overall_sum+=avg;
//			    cout<<"overall_sum="<<overall_sum<<endl;
			}
			
			
			
	}
	
	if(sum!=0)
	{avg=sum/no;
	//cout<<"avg= "<<avg;
	}
	//cout<<endl;
	overall_sum+=avg;
    }
    //cout<<fixed<<setprecision(6);
    //int  k=(int)overall_sum;
    float a=overall_sum-(int)overall_sum;
    //cout<<"a="<<a<<endl;
    int b=a*100000;
    b=b*10;
    //cout<<"b="<<b<<endl;
    //float c=b*pow(10,-6);
    //cout<<"c="<<c<<endl;
    //a=(int)a*pow(10,5);
    //a=a*10;
   // a=a/pow(10,6);
    //overall_sum=k+a;
    int k=overall_sum*pow(10,5);   cout<<"overall_sum="<<k<<endl;
    int rem=k%10;              cout<<"rem="<<rem<<endl;
     k=k*10;                  cout<<"overall_sum="<<k<<endl;
     //float f=(float)k*pow(10,-6);  cout<<"overall_sum="<<f<<endl;
    //rem=(float)rem*pow(10,-6);           cout<<"rem="<<rem<<endl;
    //overall_sum=overall_sum+rem;         cout<<"overall_sum="<<overall_sum<<endl;
    
    cout<<overall_sum<<endl;
    }
    return 0;
    
}


//1
//3
//2 3 5
