#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <iomanip>
#include <cmath>
#include <set>
#include <numeric>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using ll = long long;
namespace mp = boost::multiprecision;

int main()
{
    // 整数の入力
    string S;
    string T;
    cin >> S >> T;
    string s;
    string t;
    for (int i = 0; i < S.size(); i++)
    {
        if (S[i] != T[i])
        {
            s.push_back(S[i]);
            t.push_back(T[i]);
        }
    }
    vector<bool> contain(26, false);
    bool has_duplicate = false;
    for (int i = 0; i < S.size(); i++)
    {
        if (contain[S[i] - 'a'])
        {
            has_duplicate = true;
            break;
        }
        else
        {
            contain[S[i] - 'a'] = true;
        }
    }
    if (s.size() > 6)
    {
        cout << "NO" << endl;
    }
    else if (s.size() == 0)
    {
        if (has_duplicate)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        ll N = s.size();
        for (int i = 0; i < N; i++)
        {
            for (int j = i + 1; j < N; j++)
            {
                swap(s[i], s[j]);
                if (s == t)
                {
                    cout << "YES" << endl;
                    return 0;
                }
                for (int k = 0; k < N; k++)
                {
                    for (int l = k + 1; l < N; l++)
                    {
                        swap(s[k], s[l]);
                        if (s == t && has_duplicate)
                        {
                            cout << "YES" << endl;
                            return 0;
                        }
                        for (int m = 0; m < N; m++)
                        {
                            for (int n = m + 1; n < N; n++)
                            {
                                swap(s[m], s[n]);
                                if (s == t)
                                {
                                    // cout << i << j << k << l << m << n << endl;
                                    cout << "YES" << endl;
                                    return 0;
                                }
                                swap(s[m], s[n]);
                            }
                        }
                        swap(s[k], s[l]);
                    }
                }
                swap(s[i], s[j]);
            }
        }
        cout << "NO" << endl;
    }
    return 0;
}