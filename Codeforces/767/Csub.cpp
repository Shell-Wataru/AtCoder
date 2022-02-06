#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <numeric>
#include <cmath>
#include <unordered_map>
#include <unordered_set>
using namespace std;
using ll = long long;

int main()
{
    // 整数の入力
    ll count = 0;
    ll k = 4;
    for (int i = 0; i < (1ll << k); i++)
    {
        for (int j = 0; j < (1ll << k); j++)
        {
            for (int l = 0; l < (1ll << k); l++)
            {
                for (int m = 0; m < (1ll << k); m++)
                {
                    if ((i & j & l & m) >= (i ^ j ^ l ^ m))
                    {
                        count++;
                    }
                }
            }
        }
    }
    cout << count << "\n";
    cout << flush;
    return 0;
}
