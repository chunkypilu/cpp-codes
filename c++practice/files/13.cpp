#include<bits/stdc++.h>
using namespace std;
int n,m,dx,dy;
int a[25][25];
bool vis[25][25];
const int INT=1000000000;
int dist[25][25];
#define mp make_pair

bool ok(int x,int y){
    return x>=0 && y>=0 && x<n && y<m;
}

void bfs(int x,int y){
    queue<pair<int,int> > q;
    q.push(mp(x,y));
    dist[x][y]=0;
    
    while(!q.empty()){
        pair<int,int> p = q.front();
        q.pop();
        
        int xx = p.first;
        int yy = p.second;
        
        if(vis[xx][yy]) continue;
        vis[xx][yy]=true;
        
        if(ok(xx+1,yy) && !vis[xx+1][yy] && a[xx+1][yy]==1){
            dist[xx+1][yy]=min(dist[xx+1][yy],dist[xx][yy]+1);
            q.push(mp(xx+1,yy));
        }
        if(ok(xx,yy+1) && !vis[xx][yy+1] && a[xx][yy+1]==1){
            dist[xx][yy+1]=min(dist[xx][yy+1],dist[xx][yy]+1);
            q.push(mp(xx,yy+1));
        }
        if(ok(xx-1,yy) && !vis[xx-1][yy] && a[xx-1][yy]==1){
            dist[xx-1][yy]=min(dist[xx-1][yy],dist[xx][yy]+1);
            q.push(mp(xx-1,yy));
        }
        if(ok(xx,yy-1) && !vis[xx][yy-1] && a[xx][yy-1]==1){
            dist[xx][yy-1]=min(dist[xx][yy-1],dist[xx][yy]+1);
            q.push(mp(xx,yy-1));
        }
    }
}
int main()
{
    int t;
    cin>>t;
    
    while(t--){
        cin>>n>>m;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++) {cin>>a[i][j];dist[i][j]=INT;}
        }
        
        memset(vis,false,sizeof vis);
        
        cin>>dx>>dy;
        
        if(a[0][0]==0){
            cout<<-1<<endl;
            continue;
        }
        
        bfs(0,0);
        
        if(dist[dx][dy]>=INT) cout<<"-1"<<endl;
        else cout<<dist[dx][dy]<<endl;
    }
	return 0;
}
