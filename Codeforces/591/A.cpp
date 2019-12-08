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
        ll a;
        cin >> a;
        if (a == 2){
            cout << 2 << endl;
        }else if(a % 2 == 0){
            cout << 0 << endl;
        }else{
            cout << 1 << endl;
        }
    }
   return 0;
}