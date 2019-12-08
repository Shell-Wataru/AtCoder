#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;
ll BASE_NUM = 1000000007;



int main()
{
    // 整数の入力
    ll N,M;
    cin >> N >> M;
    vector<ll> yoko_furenzoku;
    vector<ll> yoko_renzoku;
    yoko_furenzoku.push_back(2);
    yoko_renzoku.push_back(0);

    ll max_nm = max(N,M);
    ll min_nm = min(N,M);

    for(int i = 1;i<max_nm;i++){
        yoko_renzoku.push_back(yoko_furenzoku[i-1]);
        yoko_furenzoku.push_back((yoko_renzoku[i-1] + yoko_furenzoku[i-1]) % BASE_NUM);
    }

    // cout << (yoko_renzoku[max_nm-1] + yoko_furenzoku[max_nm-1]) << endl;
    // cout << (yoko_renzoku[min_nm-1] + yoko_furenzoku[min_nm-1]) << endl;
    ll max_pattern = (yoko_renzoku[max_nm-1] + yoko_furenzoku[max_nm-1]) % BASE_NUM;
    ll min_pattern = (yoko_renzoku[min_nm-1] + yoko_furenzoku[min_nm-1]) % BASE_NUM;
    cout << (max_pattern + min_pattern + BASE_NUM - 2) % BASE_NUM << endl;
    return 0;
}
