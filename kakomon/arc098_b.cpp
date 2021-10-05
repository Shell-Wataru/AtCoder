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
    ll N;
    cin >> N;
    vector<ll> last_occured(20,-1);
    vector<ll> last_last_occured(20,-1);
    ll total = 0;
    for(int i = 0;i < N;i++){
        ll a;
        cin >> a;
        ll width = numeric_limits<ll>::max();
        for(int j = 0;j < 20;j++){
            if(a & 1<<j){
                last_last_occured[j] = last_occured[j];
                last_occured[j] = i;
                width = min(width, i - last_last_occured[j]);
            }else{
                width = min(width, i - last_last_occured[j]);
            }
        }
        // cout << i << ":" << width << endl;
        total += width;
    }
    cout << total << endl;
    return 0;
}