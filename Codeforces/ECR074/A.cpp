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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    for(int i = 0;i<N;i++){
        ll x,y;
        cin >> x >> y;
        if (x - y == 1){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
   return 0;
}