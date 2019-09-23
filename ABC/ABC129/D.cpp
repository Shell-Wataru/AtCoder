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
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    ll H,W;
    cin >> H >> W;
    vector<string> data;
    vector<vector<ll>> migi;
    vector<vector<ll>> hidari;
    vector<vector<ll>> ue;
    vector<vector<ll>> shita;

    for(int i = 0;i<H;i++){
        string s;
        cin >> s;
        data.push_back(s);
    }

    for(int i = 0;i<H;i++){
        ll left  = -1;
        vector<ll> migi_row;
        for(int j = 0;j<W;j++){
            if(data[i][j] == '#'){
                left = j;
            }
            migi_row.push_back(left);
        }
        migi.push_back(migi_row);
    }

    for(int i = 0;i<H;i++){
        ll right  = W;
        vector<ll> hidari_row;
        for(int j = W - 1;j>=0;j--){
            if(data[i][j] == '#'){
                right = j;
            }
            hidari_row.push_back(right);
        }
        reverse(hidari_row.begin(),hidari_row.end());
        hidari.push_back(hidari_row);
    }

    for(int i = 0;i<H;i++){
        vector<ll> ue_row;
        ue.push_back(ue_row);
    }
    for(int j = 0;j<W;j++){
        ll up = -1;
        for(int i = 0;i<H;i++){
            if(data[i][j] == '#'){
                up = i;
            }
            ue[i].push_back(up);
        }
    }

    for(int i = 0;i<H;i++){
        vector<ll> shita_row;
        shita.push_back(shita_row);
    }
    for(int j = 0;j<W;j++){
        ll down = H;
        for(int i = H -1;i>=0;i--){
            if(data[i][j] == '#'){
                down = i;
            }
            shita[i].push_back(down);
        }
    }

    ll max_s = 0;
//     cout << "ue" << endl;
//     for(int i = 0;i<H;i++){
//         for(int j = 0;j<W;j++){
//             cout << ue[i][j];
//         }
//         cout << endl;
//     }
// cout << "shita" << endl;
//     for(int i = 0;i<H;i++){
//         for(int j = 0;j<W;j++){
//             cout << shita[i][j];
//         }
//         cout << endl;
//     }
//     cout << "migi" << endl;
//     for(int i = 0;i<H;i++){
//         for(int j = 0;j<W;j++){
//             cout << migi[i][j];
//         }
//         cout << endl;
//     }
//     cout << "hidari" << endl;
//     for(int i = 0;i<H;i++){
//         for(int j = 0;j<W;j++){
//             cout << hidari[i][j];
//         }
//         cout << endl;
//     }

// cout << "score" << endl;
    for(int i = 0;i<H;i++){
        for(int j = 0;j<W;j++){
            // cout << shita[i][j];
            ll hikatteru = (shita[i][j] - ue[i][j] - 1) + (- migi[i][j] + hidari[i][j] - 1) - 1;
            max_s = max(max_s,hikatteru);
            // cout << hikatteru << ",";
        }
        // cout << endl;
    }

    cout << max_s << endl;
    return 0;

}