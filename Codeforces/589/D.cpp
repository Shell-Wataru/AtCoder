#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 998244353;

void pait_color(vector<ll> &colors,map<ll,set<ll>> edges,ll v){

}

int main()
{
    // 整数の入力
    long long N,M;
    map<ll,set<ll>> edges;

    cin >> N >> M;
    vector<ll> colors(N,0);
    for (int i = 0; i < M; i++)
    {
        ll a,b;
        cin >> a >> b;
        a--;b--;
        edges[a].insert(b);
        edges[b].insert(a);
    }
    bool painted = false;
    while(!painted){
        ll not_painted = -1;
        for(int i = 0;i<N;i++){
            if(colors[i] == 0){
                not_painted = i;
                break;
            }
        }
        if (not_painted != -1){
            pait_color(colors,edges,not_painted);
        }else{
            painted = true;
        }
    }
   return 0;
}