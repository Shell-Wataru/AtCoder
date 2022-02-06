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

ll best_score(vector<string> &current, vector<vector<ll>> &B, vector<vector<ll>> &C, bool chokudai)
{
    bool changed = false;
    ll score;
    if (chokudai)
    {
        score = numeric_limits<ll>::min();
    }
    else
    {
        score = numeric_limits<ll>::max();
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (current[i][j] == '.')
            {
                changed = true;
                if (chokudai)
                {
                    current[i][j] = 'o';
                    score = max(score, best_score(current, B, C, !chokudai));
                    current[i][j] = '.';
                }
                else
                {
                    current[i][j] = 'x';
                    score = min(score, best_score(current, B, C, !chokudai));
                    current[i][j] = '.';
                }
            }
        }
    }
    if (!changed)
    {
        score = 0;
        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (current[i][j] == current[i+1][j]){
                    score += B[i][j];
                }
            }
        }
        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                if (current[i][j] == current[i][j+1]){
                    score += C[i][j];
                }
            }
        }
    }
    return score;
}

int main()
{
    // 整数の入力
    vector<vector<ll>> B(2, vector<ll>(3));
    vector<vector<ll>> C(3, vector<ll>(2));
    ll total = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> B[i][j];
            total += B[i][j];
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> C[i][j];
            total += C[i][j];
        }
    }
    vector<string> current = {
        "...",
        "...",
        "..."
    };
    // cout << "!!" << endl;
    ll chokudai = best_score(current,B,C,true);
    ll chokuko = total - chokudai;
    cout << chokudai << endl;
    cout << chokuko << endl;
    return 0;
}