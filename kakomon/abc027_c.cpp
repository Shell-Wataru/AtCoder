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

using namespace std;
using ll = long long;

int solve(){
    ll N;
    cin >> N;
    ll first_one_index = -1;
    ll first_zero_index = -1;
    for(int i = 60;i >= 0;i--){
        if (N & (1ll<<i)){
            first_one_index = i;
            break;
        }
    }
    // cout << first_one_index << endl;
    if (first_one_index % 2 == 0){
        for(int i = first_one_index-1;i >= 0;i--){
            if ( (first_one_index - i)  % 2 == 1){
                if (!(N & (1ll<<i))){
                    cout << "Takahashi" << endl;
                    return 0;
                }
            }else{
                if ((N & (1ll<<i))){
                    cout << "Aoki" << endl;
                    return 0;
                }
            }
        }
        cout << "Aoki" << endl;
        return 0;
    }else{
        for(int i = first_one_index-1;i >= 0;i--){
            if ( (first_one_index - i)  % 2 == 1){
                if ((N & (1ll<<i))){
                    cout << "Takahashi" << endl;
                    return 0;
                }
            }else{
                if (!(N & (1ll<<i))){
                    cout << "Aoki" << endl;
                    return 0;
                }
            }
        }
        cout << "Takahashi" << endl;
        return 0;
    }
    return 0;
}

int main()
{
    // 整数の入力
    // ll T;
    // cin >> T;
    // for (size_t i = 0; i < T; i++)
    // {
        solve();
    // }
    // cout << flush;
    return 0;
}