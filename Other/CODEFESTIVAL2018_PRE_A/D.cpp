#include<iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <set>
#include <map>

using namespace std;


long long Distance(map<long long ,map<long long,long long> > G ,long long L ,long long R,set<long long > visited){
    visited.insert(L);
    if (G[L].count(R) != 0){
        return G[L][R];
    }

    for(auto itr = G[L].begin(); itr != G[L].end(); ++itr) {
        if (visited.count(itr->first) == 0){
            long long result = Distance(G,itr->first,R,visited);
            if (itr->first == R){
                return itr->second;
            }else if (result != 0){
                G[L][R] = result + itr->second;
                G[R][L] = -(result + itr->second);
                return result + itr->second;
            }
        }
    }
    return 0;
}

int main()
{
    // 整数の入力
    long long N,M,i,L,R,D;
    bool isCleared = true;
    map<long long ,map<long long,long long> > G;
    cin >> N >> M;
    for (i= 1;i<= M;i++){
        cin >> L >> R >> D;
        if (G.count(L) == 0){
            map<long long,long long> To;
            G[L] = To;
        }
        if (G.count(R) == 0){
            map<long long,long long> from;
            G[R] = from;
        }
        set<long long> visited;
        long long _d = Distance(G,L,R,visited);
        if(_d== 0){
            G[L][R] = D;
            G[R][L] = -D;
        }else if (_d != D ){
            isCleared = false;
            break;
        }
    }

    if (isCleared){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}