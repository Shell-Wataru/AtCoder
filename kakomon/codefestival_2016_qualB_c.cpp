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
#include <stack>

using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;
ll BASE_NUM = 2;

int main()
{
    // 整数の入力
    ll W,H;
    cin >> W >> H;
    priority_queue<ll,vector<ll>,greater<ll>> q_row;
    priority_queue<ll,vector<ll>,greater<ll>> q_colmun;
    for(int i = 0;i < W;i++){
        ll p;
        cin >> p;
        q_row.push(p);
    }
    for(int i = 0;i < H;i++){
        ll p;
        cin >> p;
        q_colmun.push(p);
    }
    ll ans = 0;
    ll row_count = 0;
    ll column_count = 0;
    // cout << q_row.top() << endl;
    // cout << q_colmun.top() << endl;
    for(int i = 0;i < W+H;i++){
        if (q_row.empty()){
            // cout <<  (W + 1- row_count) * q_colmun.top() << endl;
            ans += (W + 1- row_count) * q_colmun.top();
            column_count++;
            q_colmun.pop();
        }else if(q_colmun.empty()){
            // cout << (H + 1 - column_count) * q_row.top() << endl;
            ans += (H + 1- column_count) * q_row.top();
            row_count++;
            q_row.pop();
        }else if (q_colmun.top() < q_row.top()){
            // cout << "c" << endl;
            // cout <<  (W + 1- row_count) * q_colmun.top() << endl;
            ans += (W + 1 - row_count) * q_colmun.top();
            column_count++;
            q_colmun.pop();
        }else{
            // cout << "d" << endl;
            // cout << (H + 1 - column_count) * q_row.top() << endl;
            ans += (H + 1 - column_count) * q_row.top();
            row_count++;
            q_row.pop();
        }
    }
    cout << ans << endl;
    return 0;
}