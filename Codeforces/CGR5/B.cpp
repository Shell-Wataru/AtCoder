#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <iomanip>
#include <cmath>
#include <map>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;

int main()
{
    ll N;
    map<ll, ll> enter_data;
    vector<ll> exit_data;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        enter_data[a] = i;
    }

    for (int i = 0; i < N; i++)
    {
        ll a;
        cin >> a;
        exit_data.push_back(a);
    }
    reverse(exit_data.begin(),exit_data.end());
    ll first_enter = N;
    ll counter = 0;
    for (int i = 0; i < N; i++)
    {
        ll current_car_enter = enter_data[exit_data[i]];
        if (current_car_enter < first_enter){
            first_enter = current_car_enter;
        }else{
            counter++;
        }
    }


    cout << counter << endl;
    return 0;
}