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

bool is_win_muki(vector<string> &B, pair<ll, ll> muki)
{
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            ll w_counts = 0;
            ll b_counts = 0;
            for (int k = 0; k < 5; k++)
            {
                ll row = i + muki.first * k;
                ll col = j + muki.second * k;
                if (row < 19 && col < 19)
                {
                    if (B[row][col] == 'o')
                    {
                        w_counts++;
                    }
                    else if (B[row][col] == 'x')
                    {
                        b_counts++;
                    }
                }
            }
            // if (w_counts > 0 || b_counts > 0){
            //     cout << w_counts << " " << b_counts << endl;
            // }
            if (w_counts == 5 || b_counts == 5)
            {
                // cout << "win" << endl;
                return true;
            }
        }
    }
    return false;
}

bool is_win(vector<string> &B)
{
    return is_win_muki(B, {1, 0}) || is_win_muki(B, {1, 1}) || is_win_muki(B, {0, 1}) || is_win_muki(B, {1, - 1});
}

int main()
{
    // 整数の入力
    vector<string> B;
    ll b_counts, w_counts;
    b_counts = 0;
    w_counts = 0;
    string row;
    for (int i = 0; i < 19; i++)
    {
        cin >> row;
        B.push_back(row);
    }
    for (int i = 0; i < 19; i++)
    {
        for (int j = 0; j < 19; j++)
        {
            if (B[i][j] == 'o')
            {
                b_counts++;
            }
            else if (B[i][j] == 'x')
            {
                w_counts++;
            }
        }
    }

    if (b_counts != w_counts && b_counts != w_counts + 1)
    {
        cout << "NO" << endl;
    }
    else if (!is_win(B))
    {
        cout << "YES" << endl;
    }
    else
    {
        for (int i = 0; i < 19; i++)
        {
            for (int j = 0; j < 19; j++)
            {
                if (b_counts == w_counts)
                {
                    if (B[i][j] == 'x')
                    {
                        B[i][j] = '.';
                        if (!is_win(B))
                        {
                            cout << "YES" << endl;
                            return 0;
                        }
                        B[i][j] = 'x';
                    }
                }
                else
                {
                    if (B[i][j] == 'o')
                    {
                        B[i][j] = '.';
                        if (!is_win(B))
                        {
                            cout << "YES" << endl;
                            return 0;
                        }
                        B[i][j] = 'o';
                    }
                }
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}