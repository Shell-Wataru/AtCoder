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

int solve(int n){
    ll counter = 0;
    ll base;
    for(int i = 0;i< 10;i++){
        if (i == 0){
            base = 1;
        }else{
            base = base * 10;
            base++;
        }

        for(int j = 1;j <= 9;j++){
            if (n >= base * j){
                // cout << base * j << endl;
                counter++;
            }
        }
    }
    return counter;
}

int main()
{
    // 整数の入力
    ll t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        ll n;
        cin >> n;
        cout << solve(n) << endl;
    }
    return 0;
}