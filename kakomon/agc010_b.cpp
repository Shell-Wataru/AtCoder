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
    ll add_total = 0;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        add_total += A[i];
    }
    if (add_total % (N *(N+1)/2) != 0){
        cout << "NO" << endl;
        return 0;
    }
    // cout << "!!" << endl;
    add_total /= N *(N+1)/2;
    // cout << add_total << endl;
    // cout << "!!" << endl;
    vector<ll> ans(N);
    for(int i = 0;i < N;i++){
        ans[i] = A[i] - A[(N+i+1)%N] + add_total;
        // cout << ans[i] << endl;
        if (ans[i] % N != 0 || ans[i] < 0){
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}