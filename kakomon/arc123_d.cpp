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

using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    ll total = 0;
    ll current_b = numeric_limits<ll>::min();
    ll current_c = numeric_limits<ll>::max();
    for(int i  = 0;i < N;i++){
        if (A[i] >= 0){
            ll new_b= 0;
            ll new_c = A[i];
            if (current_b <= new_b && current_c >= new_c){
                current_b = new_b;
                current_c = new_c;
            }else if (current_b <=  A[i] - current_c){
                current_b = A[i] - current_c;
            }else{
                current_c = A[i] - current_b;
            }
        }else{
            ll new_b= A[i];
            ll new_c = 0;
            if (current_b <= new_b && current_c >= new_c){
                current_b = new_b;
                current_c = new_c;
            }else if (current_b <=  A[i] - current_c){
                current_b = A[i] - current_c;
            }else{
                current_c = A[i] - current_b;
            }
        }
        total += abs(current_b) + abs(current_c);
    }
    cout << total<< endl;
    return 0;
}