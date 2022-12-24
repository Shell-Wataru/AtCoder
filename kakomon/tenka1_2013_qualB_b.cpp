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
    ll Q,L;
    cin >> Q >> L;
    stack<pair<ll,ll>> s;
    ll total = 0;
    for (size_t i = 0; i < Q; i++)
    {
        string t;
        cin >> t;
        if (t == "Push"){
            ll N,M;
            cin >> N >> M;
            total += N;
            if (total > L){
                cout << "FULL" << endl;
                return 0;
            }
            s.push({M,N});
        }else if (t == "Pop"){
            ll N;
            cin >> N;
            total -= N;
            if (total < 0){
                cout << "EMPTY" << endl;
                return 0;
            }
            while(N > 0){
                ll diff = min(N,s.top().second);
                N -= diff;
                // cout << s.top().second << endl;
                s.top().second -= diff;
                // cout << s.top().second << endl;
                if(s.top().second == 0){
                    s.pop();
                }
            }
        }else if(t == "Top"){
            if (total <= 0){
                cout << "EMPTY" << endl;
                return 0;
            }
            cout << s.top().first << endl;
        }else if(t == "Size"){
            cout << total << endl;
        }
    }
    cout << "SAFE" << endl;
    return 0;
}