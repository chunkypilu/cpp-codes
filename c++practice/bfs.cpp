#include<iostream>
#include<queue>
using namespace std;
int x1[4]={-1,1,0,0},y1[4]={0,0,-1,1};




class node
{
   public:
   int x_;
   int y_;
};


bool isSafe(int a ,int b,int n,int m)
{
    if(a>=0&&b>=0&&a<n&&b<m)
     return true ;
    else
     return false; 
}



int dfs(char *arr,int i,int j,int n,int m,bool *visited)
{
 
  if(!*(visited+i*m+j))
  {
     *(visited+i*m+j)=true;
     for(int k=0;k<4;k++)
       {
            int x=i+x1[k];
            int y=j+y1[k];
                          
            if(isSafe(x,y,n,m) && *(arr+x*m+y)=='X' && *(visited+x*m+y)==false)
              {
                   
                  dfs((char *)arr,x,y,n,m,(bool *)visited);
              }
        }
     
     return 0;
      
  }


    
}

int ans(char *arr,int n,int m)
{
    int i,j,k,l,count=0;
    bool visited[n][m];
    for(i=0;i<n;i++)
     {
        for(j=0;j<m;j++)
         {
           visited[i][j]=false;         
         }
     }
     
        for(k=0;k<n;k++)
          {
             for(l=0;l<m;l++)
                 {
                   if(*(arr+k*m+l)=='X' && visited[k][l]==false)
                   {   
                    
                    count++;
	                
	                dfs((char *)arr,k,l,n,m,(bool *)visited);
	                
	                  }
                    }
                
        }
               
    return count;
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,m,i,j;
	    cin>>n>>m;
	    char arr[n][m];
	    for(i=0;i<n;i++)
	    {
	        for(j=0;j<m;j++)
	        {
	            cin>>arr[i][j];
	           }
	    }
	    
	    cout<<ans((char *)arr,n,m)<<endl;
	    
	}
	return 0;
}
