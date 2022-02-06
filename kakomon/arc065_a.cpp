#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
using namespace std;
using ll = long long;

int solve()
{
    string S;
    cin >> S;
    while(!S.empty()){
        ll n = S.size();
        // cout << S << endl;
        if (n >= 5 && S.substr(n-5,5) == "dream"){
            for(int i = 0;i < 5;i++){
                S.pop_back();
            }
        }else if(n >= 7 && S.substr(n-7,7) == "dreamer"){
            for(int i = 0;i < 7;i++){
                S.pop_back();
            }
        }else if(n >= 5 && S.substr(n-5,5) == "erase"){
            for(int i = 0;i < 5;i++){
                S.pop_back();
            }
        }else if(n >= 6 && S.substr(n-6,6) == "eraser"){
            for(int i = 0;i < 6;i++){
                S.pop_back();
            }
        }else{
            cout << "NO" << "\n";
            return 0;
        }
    }
    cout << "YES" << "\n";
    return 0;
}

int main()
{
    // // 整数の入力
    // ll t;
    // cin >> t;
    // for (size_t i = 0; i < t; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
