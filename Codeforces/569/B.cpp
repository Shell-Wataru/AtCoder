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
    long long N;
    vector<ll> A;
    cin >> N;
    ll min_index = -1;
    ll min_value = 0;
    for(int i = 0;i< N;i++){
        ll a;
        cin >> a;
        if (a >= 0){
            A.push_back(- a - 1);
            if (- a - 1 < min_value){
                min_index = i;
                min_value = - a - 1;
            }
        }else{
            A.push_back(a);
            if (a < min_value){
                min_index = i;
                min_value = a;
            }
        }
   }

    if (N % 2 == 1){
        A[min_index] = - A[min_index] - 1;
    }

    for(int i = 0;i<N;i++){
        if (i != 0){
            cout << " ";
        }
        cout << A[i];
    }
    cout << endl;

    return 0;
}