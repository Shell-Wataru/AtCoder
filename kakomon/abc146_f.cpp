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
#include <stack>
#include <boost/multiprecision/cpp_int.hpp>

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    string S;
    cin >> S;
    vector<ll> next_ok_mass(N+1);
    for(int i = N;i >= 0;i--){
        if (S[i] == '0'){
            next_ok_mass[i] = i;
        }else{
            next_ok_mass[i] = next_ok_mass[i+1];
        }
    }
    stack<ll> s;
    s.push(N);
    while(s.top() != 0){
        ll current = s.top();
        ll target = max(current - M,0ll);
        ll next = next_ok_mass[target];
        if (next == current){
            cout << -1 << endl;
            return 0;
        }else{
            s.push(next);
        }
    }
    ll current = s.top();
    s.pop();
    bool is_first = true;
    while(!s.empty()){
        if (!is_first){
            cout << " ";
        }
        is_first = false;
        cout << s.top() - current;
        current = s.top();
        s.pop();
    }
    cout << endl;
    return 0;
}