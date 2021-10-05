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
    ll N,A,B,C;
    cin >> N >> A >> B >> C;
    vector<ll> l(N);
    for(int i = 0;i < N;i++){
        cin >> l[i];
    }
    ll min_cost = numeric_limits<ll>::max();
    for(int i = 0; i < (1<<(2*N));i++){
        ll a = 0;
        ll a_lines = 0;
        ll b = 0;
        ll b_lines = 0;
        ll c = 0;
        ll c_lines = 0;
        for(int j = 0;j < N;j++){
            ll type = 0;
            if (i & 1<<(2*j)){
                type += 1;
            }
            if (i & 1<<(2*j+1)){
                type += 2;
            }
            if (type == 1){
                a += l[j];
                a_lines++;
            }
            if (type == 2){
                b += l[j];
                b_lines++;
            }
            if (type == 3){
                c += l[j];
                c_lines++;
            }
        }
        if (a_lines > 0 && b_lines > 0 && c_lines > 0){
            ll cost = 10 * (a_lines - 1) + abs(A - a) + 10 * (b_lines - 1) + abs(B - b) + 10 * (c_lines - 1) + abs(C - c);
            // cout << cost << endl;
            // cout << a << "," << b<< "," << c << endl;
            // cout << a_lines << "," << b_lines<< "," << c_lines << endl;
            min_cost = min(min_cost,cost);
        }
    }
    cout << min_cost << endl;
    return 0;
}