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
    // 整数の入力
    ll n,k;
    string s;
    cin >> n >> k;
    cin >> s;
    priority_queue<ll> q;
    char last_char = '-';
    ll continues = 0;
    for(auto c:s){
        if (last_char == c){
            continues++;
        }else{
            if (continues != 0){
                q.push(continues);
            }
            continues = 1;
        }
        last_char = c;
    }
    q.push(continues);
    // cout << q.size() - 2*k << endl;
    cout << n - max((ll)q.size() - 2*k,1ll) << endl;
    return 0;
}