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
#include <set>
using namespace std;
using ll = long long;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> A(N);
    for(int i = 0;i< N;i++){
        cin >> A[i];
    }
    if (N % 2 == 0){
        ll odd_sum = 0;
        ll even_sum = 0;
        for(int i = 0;i < N;i++){
            if(i % 2 == 0){
                even_sum += A[i];
            }else{
                odd_sum +=  A[i];
            }
        }
        cout << max(even_sum,odd_sum) << endl;
    }else{
        vector<ll> odd_sum;
        vector<ll> even_sum;
        odd_sum.push_back(0);
        even_sum.push_back(0);
        for(int i = 0;i < N;i++){
            if(i % 2 == 0){
                even_sum.push_back(even_sum.back() + A[i]);
                odd_sum.push_back(odd_sum.back());
            }else{
                even_sum.push_back(even_sum.back());
                odd_sum.push_back(odd_sum.back() + A[i]);
            }
        }
        ll ans = numeric_limits<ll>::min();
        for(int i = 0;i< N;i++){
            ll after_odd = odd_sum[N] - odd_sum[i+1];
            ll before_odd = odd_sum[i];
            ll after_even = even_sum[N] - even_sum[i+1];
            ll before_even = even_sum[i];
            cout << "====" << i << endl;
            // cout << "e:" <<  before_even << " " << after_even << endl;
            // cout << "o:" <<before_odd << " " << after_odd << endl;
            if (i % 2 == 0){
                cout << before_even + after_even << endl;
                cout << before_even + after_odd << endl;
                cout << before_odd + after_even << endl;
                cout << before_odd + after_odd << endl;
                ans = max(ans,before_even + after_even);
                ans = max(ans,before_even + after_odd);
                ans = max(ans,before_odd + after_even);
                ans = max(ans,before_odd + after_odd);
            }else{
                cout << before_even + after_odd << endl;
                cout << before_odd + after_even << endl;
                // ans = max(ans,before_even + after_even);
                ans = max(ans,before_even + after_odd);
                ans = max(ans,before_odd + after_even);
                // ans = max(ans,before_odd + after_odd);
            }
        }
        cout << ans << endl;
    }
    return 0;
}