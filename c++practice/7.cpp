#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int n;
    float d;
    cin >> n >> d;
    vector< vector<float> > points(n,vector<float>(2));
    for(int points_i = 0;points_i < n;points_i++){
    	for(int points_j = 0;points_j < 2;points_j++){
    		cin >> points[points_i][points_j];
    	}
    }
    
    int s=points.size();
    cout<<"s= "<<s;
    
    // your code goes here
    return 0;
}


/*
4 4.05
-4.05 0
4 8.05
8.05 0
0 8.05
*/
