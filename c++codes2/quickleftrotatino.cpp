            #include<iostream>
            using namespace std;
            int main()
             {
                 int x,no_elements,no_times,i,j,k,l,c=0,a1;
                 cin>>x;
                 while(x--)
                 {
                   
                   cin>>no_elements;
                   cin>>no_times;
                   int arr[no_elements];
                   
                   for(i=0;i<no_elements;i++)
                   {
                       cin>>arr[i];
                   }
                   
                   while(no_times--)
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
                       cout<<arr[k]<<"\t";
                   }
                   
                 }
	            return 0;
            }
