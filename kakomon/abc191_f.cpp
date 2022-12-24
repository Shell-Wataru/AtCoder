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
#include <set>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

ll solve()
{
    ll N;
    cin >> N;
    vector<ll> A(N);
    ll minimum = numeric_limits<ll>::max();
    for(int i = 0;i < N;i++){
        cin >> A[i];
        minimum = min(minimum,A[i]);
    }
    unordered_set<ll> answers = {minimum};
    unordered_set<ll> currents;
    for(int i = 0;i < N;i++){
        for(int j = i+1;j < N;j++){
            ll g = gcd(A[i],A[j]);
            if (g < A[i] && g < A[j]){
                currents.insert(g);
                answers.insert(g);
            }
        }
    }
    while(currents.size() > 1){
        unordered_set<ll> next_currents;
        for(auto c1:currents){
            for(auto c2:currents){
                ll g = gcd(c1,c2);
                if (g != c1 && g != c2){
                    next_currents.insert(g);
                    answers.insert(g);
                }
            }
        }
        // cout << next_currents.size() << endl;
        swap(currents,next_currents);
    }
    ll ans = 0;
    for(auto c:answers){
        // cout << c << endl;
        if (c <= minimum){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}

int main()
{
    // ll N;
    // cin >> N;
    // for(int i = 1; i <= N;i++){
    solve();
    // }
    cout << flush;
    return 0;
}
