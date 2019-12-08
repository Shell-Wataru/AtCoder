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
ll BASE_NUM = 1000000007;



int main()
{
    // 整数の入力
    ll N,p;
    cin >> N >> p;
    for(int i = 1; i < 40 ;i++){
        ll current = N - i * p;
        if (current <= 0){
            continue;
        }else{
            ll total = 0;
            while(current > 0){
                if ((current & 1) == 1){
                    total++;
                }
                current = current>>1;
            }
            if (total <= i){
                cout << i << endl;
                return 0;
            }
            // cout << i << " "<< current << " " << total << endl;

        }
    }
    cout << -1 << endl;
    return 0;
}
