#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <limits>
#include <cmath>
#include <iomanip>
#include <functional>
#include <random>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int group_number(string &S){
    ll group_start;
    for(int i = 0;i < S.size();i++){
        if(S[i] == 'g'){
            group_start = i;
        }
    }
    ll value = 0;
    ll i = group_start + 5;
    while(i < S.size() && 0 <= S[i] - '0' && S[i] - '0' < 10){
        value *= 10;
        value += S[i] - '0';
        i++;
    }
    return value;
}

vector<bool> adversarials(string &S){
    ll current_count = 0;;
    vector<bool> ans;
    for(int i = S.size() - 1;i>=0;i--){
        if (S[i] == 'w'){
            current_count++;
        }else if(S[i] == '"'){
            if (current_count == 0){
                ans.push_back(false);
            }else{
                ans.push_back(true);
            }
            current_count = 0;
        }else{
            if (current_count == 0){
                ans.push_back(false);
            }else{
                ans.push_back(true);
            }
            break;
        }
    }
    reverse(ans.begin(),ans.end());
    return ans;
}
int main(){
    ll N,M;
    cin >> N >> M;
    vector<pair<ll,ll>> edges(M);
    for(int i = 0;i < M;i++){
        cin >> edges[i].first >> edges[i].second;
    }
    string S;
    cin >> S;
    ll number = group_number(S);
    vector<bool> advs = adversarials(S);
    // cout << number << endl;
    // for(auto a:advs){
    //     cout << a;
    // }
    // cout << endl;
    bool others = false;
    set<ll> groups = {number};
    for(auto adv:advs){
        if (adv){
            if (others){
                set<ll> next;
                for(auto e:edges){
                    if (groups.find(e.second) == groups.end()){
                        next.insert(e.first);
                    }
                }
                groups = next;
                others = false;
            }else{
                set<ll> next;
                for(auto e:edges){
                    if (groups.find(e.second) != groups.end()){
                        next.insert(e.first);
                    }
                }
                groups = next;
                others = false;
            }
        }else{
            if (others){
                map<ll,ll> next;
                for(auto e:edges){
                    if (groups.find(e.second) == groups.end()){
                        next[e.first]++;
                    }
                }
                ll group_count = groups.size();
                groups.clear();
                for(auto p:next){
                    if (p.second >= N - group_count){
                        groups.insert(p.first);
                    }
                }
                others = true;
            }else{
                map<ll,ll> next;
                for(auto e:edges){
                    if (groups.find(e.second) != groups.end()){
                        next[e.first]++;
                    }
                }
                ll group_count = groups.size();
                groups.clear();
                for(auto p:next){
                    if (p.second >= group_count){
                        groups.insert(p.first);
                    }
                }
                others = true;
            }
        }
    }
    if (others){
        cout << N - groups.size() << endl;
    }else{
        cout << groups.size() << endl;
    }
    return 0;

}