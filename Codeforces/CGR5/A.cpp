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
    ll N,counter;
    cin >> N;
    counter = 0;
    for(int i = 0;i<N;i++){
        ll a;
        cin >> a;
        if (a % 2 == 0){
            cout << a/2 << endl;
        }else{
            if (counter % 2 == 0){
                cout << (a+1)/2 << endl;
            }else{
                cout << (a-1)/2 << endl;
            }
            counter++;
        }
    }
   return 0;
}