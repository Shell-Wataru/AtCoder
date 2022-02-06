#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

ll left_drop(ll l,ll r,string &S,vector<pair<char,char>> &queries){
    if (l+1 == r){
        return l;
    }
    ll center = (l+r)/2;
    ll current = center;
    for(auto p:queries){
        if(S[current] == p.first){
            if (p.second == 'L'){
                current--;
                if (current < 0){
                    return left_drop(center,r,S,queries);
                }
            }else{
                current++;
                if (current >= S.size()){
                    return left_drop(l,center,S,queries);
                }
            }
        }
    }
    return left_drop(l,center,S,queries);
}

ll right_drop(ll l,ll r,string &S,vector<pair<char,char>> &queries){
    if (l+1 == r){
        return r;
    }
    ll center = (l+r)/2;
    ll current = center;
    for(auto p:queries){
        if(S[current] == p.first){
            if (p.second == 'L'){
                current--;
                if (current < 0){
                    return right_drop(center,r,S,queries);
                }
            }else{
                current++;
                if (current >= S.size()){
                    return right_drop(l,center,S,queries);
                }
            }
        }
    }
    return right_drop(center,r,S,queries);
}
int main()
{
    ll N, Q;
    cin >> N >> Q;
    string S;
    cin >> S;
    vector<pair<char,char>> queries(Q);
    for(int i = 0;i < Q;i++){
        cin >> queries[i].first >> queries[i].second;
    }
    ll l_drop = left_drop(-1,S.size(),S,queries);
    ll r_drop = right_drop(-1,S.size(),S,queries);
    cout << r_drop - l_drop - 1 << endl;
    return 0;
}
