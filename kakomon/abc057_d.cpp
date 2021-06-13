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

ll combination(ll n,ll m){
    ll ans = 1;
    for(int i = 1;i <= m;i++){
        ans *= n + 1 - i;
        ans /= i;
    }
    return ans;
}
int main()
{
    // 整数の入力
    ll N, A, B;
    cin >> N >> A >> B;

    vector<ll> numbers(N);
    map<ll,ll> number_count;
    for(int i = 0;i < N;i++){
        cin >> numbers[i];
        number_count[numbers[i]]++;
    }
    sort(numbers.rbegin(),numbers.rend());
    ll total = 0;
    for(int i = 0;i < A;i++){
        total += numbers[i];
    }
    cout << fixed << setprecision(12) << 1.0 * total/A << endl;
    ll used  = 0;
    for(int i = 0;i < A;i++){
        if ( (i == 0 || numbers[i] !=  numbers[i-1]) && numbers[i] != numbers[A-1]){
            used += number_count[numbers[i]];
        }
    }

    if (used == 0){
        ll ans = 0;
        for(int i = A;i <= B;i++){
            ans += combination(number_count[numbers[A-1]],i);
        }
        cout << ans << endl;
    }else{
        ll ans = combination(number_count[numbers[A-1]],A - used);
        cout << ans << endl;
    }
    return 0;
}