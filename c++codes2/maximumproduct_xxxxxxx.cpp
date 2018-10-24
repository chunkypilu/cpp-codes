// Geeks Maximum product
#include <cstdio>
#include <algorithm>
using namespace std;

struct descending{
  template<class T>
  bool operator()(T const &a,T const &b) const{ return a>b;}
};

long long big[2008];
int a[10004];
char line[50008]={0},*iptr;

int geti(){
  int v=0;

  while(*iptr==' ') iptr++;
  while(*iptr>' ') v=v*10+*iptr++-'0';
  return v;
}

int main(){
  long long tmp,carry,d;
  int t,n,k,i,j,bigsize,dig;
  char *optr;
  
  fgets(line,sizeof(line),stdin);
  iptr=line;
  t=geti();
  while(t--){
    fgets(line,sizeof(line),stdin);
    iptr=line;
    n=geti();
    k=geti();
    fgets(line,sizeof(line),stdin);
    iptr=line;
    for(i=0;i<n;i++) a[i]=geti();
    sort(a,a+n,descending());
    big[0]=a[0];
    bigsize=1;
    for(i=1;i<k;i++){
      for(carry=j=0;j<bigsize;j++){
        tmp=big[j]*a[i]+carry;
        if(tmp>999999999999999L){
          carry=tmp/1000000000000000L;
          big[j]=tmp-carry*1000000000000000L;
        }
        else{
          carry=0;
          big[j]=tmp;
        }
      }
      if(carry) big[bigsize++]=carry;
    }
    optr=line+50000;
    for(i=0;i<bigsize-1;i++){
      d=big[i];
      *--optr=(d%10)+'0';
      dig=1;
      while(d/=10){
        *--optr=(d%10)+'0';
        dig++;
      }
      while(dig++<15) *--optr='0';
    }
    d=big[i];
    *--optr=(d%10)+'0';
    while(d/=10) *--optr=(d%10)+'0';
    puts(optr);
  }
}
