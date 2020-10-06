#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;

int solve(){
    ll n;
    cin >> n;
    for(int i = 0;i< n/2;i++){
        if (i == 0 && n % 2 == 1){
            cout << 7;
        }else{
            cout << 1;
        }
    }
    cout << endl;
    return 0;
}
int main()
{
    // 整数の入力
    long long T;
    cin >> T;
    for(int i = 0;i< T;i++){
        solve();
    }

    return 0;
}