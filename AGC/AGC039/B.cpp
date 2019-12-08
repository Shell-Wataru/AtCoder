#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <list>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 998244353;


int main()
{
    // 整数の入力
    string S;
    ll N,total;
    cin >> N;
    vector<set<ll>> G(N);
    deque<pair<ll,ll>> q;
    vector<ll> group(N,-1);
    vector<ll> distance(N,-1);
    for(int i = 0;i<N;i++){
        string s;
        cin >> s;

        for(int j = 0;j<N;j++){
            if (s[j] - '0' == 1){
                G[i].insert(j);
            }
        }
    }
    q.push_back(make_pair(0LL,0LL));
    pair<ll,ll> far_point;
    while(!q.empty()){
        pair<ll,ll> &p = q.front();
        q.pop_front();
        ll node = p.first;
        ll depth = p.second;

        if (distance[node] != -1){
            continue;
        }

        far_point = p;
        distance[node] = depth;

        for(auto i:G[node]){
            if (distance[i] == -1){
                q.push_back(make_pair(i,depth+1));
            }else if(abs((depth+1) - distance[i]) % 2 != 0){
                // cout << "odds cycle!!!" << endl;
                cout << -1 << endl;
                return 0;
            }
        }

    }

    // for(auto d:distance){
    //     cout << d << endl;
    // }
    // cout << far_point.first << far_point.second << endl;

    q.push_back(make_pair(far_point.first,0LL));
    while(!q.empty()){
            pair<ll,ll> &p = q.front();
            q.pop_front();

            ll node = p.first;
            ll depth = p.second;
            if (group[node] != -1){
                continue;
            }
            far_point = p;
            group[node] = depth;
            for(auto i:G[node]){
                if (group[i] == -1){
                    q.push_back(make_pair(i,depth+1));
                }else if(abs((depth+1) - group[i]) % 2 != 0){
                    cout << "odds cycle!!!" << endl;
                }
            }

    }

    // for(auto d:group){
    //     cout << d << endl;
    // }
    // cout << far_point.first << far_point.second << endl;
    cout << far_point.second + 1 << endl;

    return 0;
}