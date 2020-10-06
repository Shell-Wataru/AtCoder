#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <iterator> // std::rbegin, std::rend

using namespace std;
using ll = long long;

int solve()
{
    ll a,b,c;
    vector<ll> dishes(3);
    cin >> dishes[0] >> dishes[1] >> dishes[2];
    sort(dishes.begin(),dishes.end(),greater<ll>());
    ll count = 0;
    for(int i = 0; i< 3;i++){
        if(dishes[i] > 0){
            dishes[i]--;
            count++;
        }
    }

    if (dishes[0] > 0 && dishes[1] > 0){
        dishes[0]--;
        dishes[1]--;
        count++;
    }

    if (dishes[0] > 0 && dishes[2] > 0){
        dishes[0]--;
        dishes[2]--;
        count++;
    }

    if (dishes[1] > 0 && dishes[2] > 0){
        dishes[1]--;
        dishes[2]--;
        count++;
    }

    if (dishes[0] > 0 && dishes[1] > 0 && dishes[2] > 0){
        count++;
    }

    cout << count << endl;
    return 0;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (size_t i = 0; i < t; i++)
    {
        solve();
    }
    return 0;
}