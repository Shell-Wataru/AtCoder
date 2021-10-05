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

int main()
{
    ll N,K;
    string S;
    cin >> N >> K;
    cin >> S;
    vector<pair<ll,ll>> runlength;
    for(int i = 0;i < N;i++){
        if (runlength.empty()){
            runlength.emplace_back(S[i] - '0',1);
        }else{
            if (runlength.back().first == S[i] - '0'){
                runlength.back().second++;
            }else{
                runlength.emplace_back(S[i] - '0',1);
            }
        }
    }
    ll max_ans = 0;
    ll ans = 0;
    ll from = 0;
    ll to = 0;
    ll use = 0;
    while(from < runlength.size()){
        if(to < runlength.size()){
            if (runlength[to].first == 1){
                ans += runlength[to].second;
                max_ans = max(max_ans,ans);
                to++;
            }else if(use < K){
                ans += runlength[to].second;
                max_ans = max(max_ans,ans);
                to++;
                use++;
            }else if (runlength[from].first == 1){
                ans -= runlength[from].second;
                max_ans = max(max_ans,ans);
                from++;
            }else{
                ans -= runlength[from].second;
                max_ans = max(max_ans,ans);
                from++;
                use--;
            }
        }else{
            if (runlength[from].first == 1){
                ans -= runlength[from].second;
                max_ans = max(max_ans,ans);
                from++;
            }else{
                ans -= runlength[from].second;
                max_ans = max(max_ans,ans);
                from++;
                use--;
            }
        }
    }
    cout << max_ans << endl;
    return 0;
}