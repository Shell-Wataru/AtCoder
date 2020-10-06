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

void move_up(ll &median,set<ll> &used){
    // cout << "up" << endl;
    median++;
    while(used.find(median) != used.end()){
        median++;
    }
}

void move_down(ll &median,set<ll> &used){
    // cout << "down" << endl;
    median--;
    while(used.find(median) != used.end()){
        median--;
    }
}
int solve()
{

    ll N, M;
    cin >> N >> M;
    set<ll> used;
    ll median = ((1ll<<M) - 1)/2;
    // cout << median << endl;
    for(int i = 0;i < N;i++){
        string s;
        cin >> s;
        ll a = stoll(s,0,2);
        // for(int j = 0;j < M;j++){
        //     if (s[j] == '1'){
        //         a += 1<<(M-1 - j);
        //     }
        // }
        // cout << "a" << a << endl;
        used.insert(a);
        if (i % 2 == 0){
            if (a > median){
            }else if (a< median){
                move_up(median,used);
            }else{
                move_up(median,used);
            }
        }else{
            if (a > median){
                move_down(median,used);
            }else if (a < median){
                // move_up(median,used);
            }else{
                move_down(median,used);
            }
        }
        // cout << median << endl;
    }
    for(int i = 0;i < M;i++){
        if (median & 1ll<<(M-1-i)){
            cout << 1;
        }else{
            cout << 0;
        }
    }
    cout << endl;
    return 0;
}
int main()
{
    int t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}