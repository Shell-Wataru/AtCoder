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
    ll N;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        vector<ll> tiles;
        ll n;
        cin >> n;
        for(int j= 0;j<n;j++){
            ll a;
            cin >> a;
            tiles.push_back(a);
        }
        sort(tiles.begin(),tiles.end(),greater<ll>());
        ll square = 0;
        for(int j =0;j<n;j++){
            if (tiles[j] >= j + 1){
                square = j+1;
            }else{
                break;
            }
        }
        cout << square  << endl;
    }
    return 0;
}