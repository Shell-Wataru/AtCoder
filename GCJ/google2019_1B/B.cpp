#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
using ll = long long;
string result(vector<ll> Rs){
    ll A[6][6] = {
        {4,-4,-2,0,0,1},
        {-48,48,4,0,0,-2},
        {-16,-24,48,0,0,-4},
        {64,-64,-32,40,0,-4},
        {-64,64,32,-40,40,-16},
        {96,-16,-48,0,-40,24}
    };

    string result = "";

    for (int i= 0;i< 6;i++){
        ll total = 0;
        for (int j= 0;j< 6;j++){
            total += A[i][j] * Rs[j];
        }
        if (i != 0){
            result.append(" ");
        }
        cerr <<  total << endl;
        result.append(to_string(total/40));
    }

    return result;
}
int main()
{
    // 整数の入力
    ll T,W;
    cin >> T >> W;
    cerr << T << " " << W << endl;
    for (int i = 1; i <= T; i++)
    {
        ll iday_ring;
        vector<ll> Rs;
        for (int i = 1;i<= W;i++){
            cout << i << endl;
            cin >> iday_ring;
            cerr << i <<"day:get" << iday_ring << endl;
            Rs.push_back(iday_ring);
        }

        string r = result(Rs);
        cerr << r << endl;
        cout << r << endl;
        ll res;
        cin >> res;
    }

    return 0;
}