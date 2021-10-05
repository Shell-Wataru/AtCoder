#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <iostream>
#include <bitset>
using namespace std;
using ll = long long;

class MarriageAndCirclingChallenge
{
public:
    int N;
    ll threshold;
    ll state;
    ll solve(int _N, int _threshold, int _state)
    {
        N = _N;
        threshold = _threshold;
        state = _state;
        vector<bitset<600>> toG(N);
        vector<bitset<600>> fromG(N);
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                if (rnd() < threshold)
                {
                    // cout << "<-" << endl;
                    toG[i].set(j);
                    fromG[j].set(i);
                }
                else
                {
                    // cout << "->" << endl;
                    fromG[i].set(j);
                    toG[j].set(i);
                }
            }
        }
        ll ans = 0;
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                ans += (toG[i] & fromG[j]).count() * (fromG[i] & toG[j]).count();
            }
        }
        return ans / 2;
        // return 0;
    }

    int rnd()
    {
        state = (state * 1103515245ll + 12345ll) % (1ll << 31);
        return state % 100;
    }
};

// int main()
// {
//     MarriageAndCirclingChallenge m;
//     // int ans = m.solve(10, 0, 12345);
//     int ans = m.solve(5, 50, 47);
//     // int ans = m.solve(600, 47, 1234567);
//     cout << ans << endl;
//     return 0;
// }
