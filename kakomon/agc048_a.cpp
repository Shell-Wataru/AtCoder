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

const long long BASE_NUM = 1000000000000000009ll;

int solve(){
    // 整数の入力
    string S;
    string AtCoder = "atcoder";
    cin >> S;
    if (AtCoder < S){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0;i < S.size();i++){
        if(S[i] > 't'){
            if (i != 0){
                cout << i - 1 << endl;
            }else{
                cout << i << endl;
            }
            return 0;
        }else if(S[i] > 'a'){
            cout << i << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
int main()
{
    ll T;
    cin >> T;
    for(int i = 0 ;i < T;i++){
        solve();
    }
   return 0;
}