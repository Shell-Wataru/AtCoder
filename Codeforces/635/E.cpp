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

bool is_starts_with(const std::string& s, const std::string& prefix) {
   auto size = prefix.size();
   if (s.size() < size) return false;
   return std::equal(std::begin(prefix), std::end(prefix), std::begin(s));
}

bool is_ends_with(const std::string& s, const std::string& suffix) {
   if (s.size() < suffix.size()) return false;
   return std::equal(std::rbegin(suffix), std::rend(suffix), std::rbegin(s));
}

int solve()
{
    string S;
    string T;
    vector<map<string,ll>> A(2);
    cin >> S >> T;
    A[0]["$"] = 1;
    ll total = 0;
    for(int i = 0;i< S.size();i++){
        A[(i+1) % 2].clear();
        cout << "====" << i << endl;
        for(auto p: A[i % 2]){

            if(p.first.back() == '$'){
                string key1 = p.first;
                key1.pop_back();
                key1 += S[i];
                // cout << "key1" << key1 << endl;
                if(is_ends_with(T,key1) || is_starts_with(T,key1)){
                    A[(i+1)%2][key1 + '$'] += p.second;
                }else{
                    while(!is_ends_with(T,key1)){
                        key1.pop_back();
                    }
                    A[(i+1)%2][key1] += p.second;
                }
                string key2 = p.first;
                key2.pop_back();
                key2 = S[i] + key2;
                if(is_ends_with(T,key2)){
                    A[(i+1)%2][key2 + '$'] += p.second;
                }else{
                    while(!is_ends_with(T,key2)){
                        key2.pop_back();
                    }
                    A[(i+1)%2][key2] += p.second;
                }
            }else{
                // 後ろにつけるとprefixは変わらない
                A[(i+1)%2][p.first] += p.second;
                // 前につける
                string Key = S[i] + p.first;
                while(!is_ends_with(T,Key)){
                    Key.pop_back();
                }
                A[(i+1)%2][Key] += p.second;
            }
        }
        for(auto p:A[(i+1)%2]){
            cout << p.first << " " << p.second << endl;
        }
        total += A[(i+1)%2][T];
        total += A[(i+1)%2][T+'$'];
    }

    cout << total << endl;
    return 0;
}
int main()
{
    // int t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
        solve();
    // }
    return 0;
}