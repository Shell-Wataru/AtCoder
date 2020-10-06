#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>
#include <numeric>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

ll BASE_NUM = 1000000007;

int main()
{
    // 整数の入力
    ll a, b, c;
    cin >> a >> b >> c;
    ll N = a + b + c;
    vector<ll> numbers(N);
    iota(numbers.begin(), numbers.end(), 1);
    ll counter = 0;
    do
    {
        // for(auto n:numbers){
        //     cout << n ;
        // }
        // cout << endl;
        vector<vector<ll>> D(3, vector<ll>(3, -1));
        for (int i = 0; i < a; i++)
        {
            D[0][i] = numbers[i];
        }
        for (int i = 0; i < b; i++)
        {
            D[1][i] = numbers[a + i];
        }

        for (int i = 0; i < c; i++)
        {
            D[2][i] = numbers[a + b + i];
        }

        ll is_ok = true;
        //たて
        for (int i = 0; i < 3; i++)
        {
            ll max_v = 0;
            for (int j = 0; j < 3; j++)
            {
                if (D[i][j] > max_v || D[i][j] == -1)
                {
                    max_v = max(D[i][j], max_v);
                }
                else
                {
                    is_ok = false;
                }
            }
        }
        //よこ
        for (int i = 0; i < 3; i++)
        {
            ll max_v = 0;
            for (int j = 0; j < 3; j++)
            {
                if (D[j][i] > max_v || D[j][i] == -1)
                {
                    max_v = max(D[j][i], max_v);
                }
                else
                {
                    is_ok = false;
                }
            }
        }
        if (is_ok)
        {
            counter++;
        }
    }while (next_permutation(numbers.begin(), numbers.end()));
    cout << counter << endl;
    return 0;
}