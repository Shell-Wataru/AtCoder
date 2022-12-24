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

using namespace std;
using ll = long long;

int main()
{
    ll N;
    cin >> N;
    string S;
    cin >> S;
    N = S.size();
    priority_queue<ll> q;
    ll a_count = 0;
    ll r_count = 0;
    ll c_count = 0;
    for(int i = 0;i < N;i++){
        if (a_count == 0 && r_count == 0 && c_count == 0){
            if (S[i] == 'A'){
                a_count++;
            }
        }else if (a_count > 0 && r_count == 0 && c_count == 0){
            if (S[i] == 'A'){
                a_count++;
            }else if (S[i] == 'R'){
                r_count++;
            }else{
                a_count = 0;
                r_count = 0;
                c_count = 0;
            }
        }else if (a_count > 0 && r_count > 0){
            if (S[i] == 'A'){
                if (c_count > 0){
                    q.push(min(a_count,c_count));
                }
                a_count = 1;
                r_count = 0;
                c_count = 0;
            }else if (S[i] == 'R'){
                if (c_count > 0){
                    q.push(min(a_count,c_count));
                }
                a_count = 0;
                r_count = 0;
                c_count = 0;
            }else{
                c_count++;
            }
        }
    }
    if (c_count > 0){
        q.push(min(a_count,c_count));
    }
    ll ans = 0;
    ll removed = 0;
    // cout << q.size() << endl;
    while(q.size() > removed){
        if (ans % 2 == 0){
            ans++;
            ll c = q.top();
            q.pop();
            c--;
            if (c != 0){
                q.push(c);
            }
        }else{
            ans++;
            removed++;
        }
    }
    cout << ans << endl;
    return 0;
}