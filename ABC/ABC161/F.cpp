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
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    if (N == 2){
        cout << 1 << endl;
        return 0;
    }
    // for(int i = 2;i <= N;i++){
    //     ll ans = N;
    //     while(ans >= i){
    //         if (ans % i == 0){
    //             ans = ans/i;
    //         }else{
    //             ans = ans % i;
    //         }
    //     }
    //     if (ans == 1){
    //         cout << i << endl;
    //     }
    // }
    ll counter = 2;
    set<ll> answers;
    answers.insert(N);
    answers.insert(N-1);
    for(ll i = 2;i * i <= N;i++){
        if( N % i == 0){
            ll ans = N;
            while(ans >= i){
                if (ans % i == 0){
                    ans = ans/i;
                }else{
                    ans = ans % i;
                }
            }
            if (ans == 1){
                // cout << i << endl;
                answers.insert(i);
            }
        }
    }

    for(ll i = 2;i * i <= N - 1;i++){
        if( (N - 1) % i == 0){
            // cout << i << endl;
            // cout << (N-1)/i << endl;
            answers.insert(i);
            answers.insert((N-1)/i);
        }
    }
    cout << answers.size() << endl;
    return 0;
}