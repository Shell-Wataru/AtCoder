#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <map>
using namespace std;
using ll = long long;
string result(vector<ll> Rs){
    ll results[6];
    ll base52 = (1LL<<52);
    ll base42 = (1LL<<42);
    ll base35 = (1LL<<35);
    ll base21 = (1LL<<21);
    ll base14 = (1LL<<14);
    ll base10 = (1LL<<10);
    ll base8 = (1LL<<8);
    ll base7 = (1LL<<7);

    results[3] = Rs[0]/base52;
    results[4] = (Rs[0] % base52)/base42;
    results[5] = (Rs[0] % base42)/base35;

    results[0] = (Rs[1])/base42;
    results[1] = (Rs[1] % base42)/base21;
    results[2] = ((Rs[1] - base10 * results[3] - base8 * results[4] - base7 * results[5]) % base21)/base14;

    string result = "";

    for (int i= 0;i< 6;i++){
        if (i != 0){
            result.append(" ");
        }
        cerr <<  results[i] << endl;
        result.append(to_string(results[i]));
    }

    return result;

}
int main()
{
    // 整数の入力
    ll T,W;
    ll qs[6] = {210,42,1,1,1,1};

    cin >> T >> W;
    cerr << T << " " << W << endl;

    for (int i = 1; i <= T; i++)
    {
        ll iday_ring;
        vector<ll> Rs;
        for (int i = 1;i<= W;i++){
            cout << qs[i-1] << endl;
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