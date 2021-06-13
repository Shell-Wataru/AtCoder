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

int main()
{
    // 整数の入力
    ll N;
    cin >> N;
    vector<ll> counts(N);
    vector<ll> a(N);
    for (size_t i = 0; i < N; i++)
    {
        cin >> a[i];
        counts[a[i]]++;
    }
    sort(a.begin(),a.end());
    ll min_a = a[0];
    ll max_a = a[N-1];
    if (min_a < (max_a+1)/2){
        cout << "Impossible" << endl;
        return 0;
    }
    if (max_a % 2 == 0 && counts[min_a] != 1){
        cout << "Impossible" << endl;
        return 0;
    }
    if (max_a % 2 == 1 && counts[min_a] != 2){
        cout << "Impossible" << endl;
        return 0;
    }
    for(int i = min_a + 1;i <= max_a;i++){
        if (counts[i] < 2){
            cout << "Impossible" << endl;
            return 0;
        }
    }
    cout << "Possible" << endl;
    return 0;
}