#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
#include <iostream>
#include <iomanip>
using namespace std;
using ll = long long;

// template <typename T>
// struct V : vector<T>
// {
//     using vector<T>::vector;
// };
// V()->V<int>;
// V(size_t)->V<int>;
// template <typename T>
// V(size_t, T) -> V<T>;
// template <typename T>
// vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
// template <typename... Ts>
// auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
// template <typename T>
// ostream &operator<<(ostream &os, const vector<T> &v)
// {
//     for (auto &e : v)
//         os << e << ' ';
//     return os;
// }
// struct fast_ios
// {
//     fast_ios()
//     {
//         cin.tie(nullptr);
//         ios::sync_with_stdio(false);
//         cout << fixed << setprecision(20);
//     };
// } fast_ios_;

class DoubleWordLadder
{
public:
    vector<string> transform(string A, string B)
    {
        ll N = A.size();
        vector<ll> changes;
        for (int i = 0; i < N; i++)
        {
            if (A[i] != B[i])
            {
                changes.push_back(i);
            }
        }
        if (changes.size() == 0)
        {
            return {A};
        }
        else
        {
            if (changes.size() == 1)
            {
                if (A[0] == B[0])
                {
                    changes.push_back(0);
                }
                else
                {
                    changes.push_back(1);
                }
            }
            vector<string> ans = {A};
            for (auto c : changes)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (j != A[c] - 'a' && j != B[c] - 'a')
                    {
                        A[c] = 'a' + j;
                        break;
                    }
                }
                ans.push_back(A);
            }
            // cout << "!" << endl;
            for (auto c : changes)
            {
                A[c] = B[c];
                ans.push_back(A);
            }
            return ans;
        }
    }
};

// int main()
// {
//     DoubleWordLadder m;
//     cout << m.transform(
//           "aa",
// "ba"

//                 )
//          << endl;
//     return 0;
// }