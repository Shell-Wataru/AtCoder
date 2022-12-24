#include <string>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <numeric>
#include <bitset>
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

class IntersectionArea
{
public:
    vector <int> addOne(vector <int> X1, vector <int> Y1, vector <int> X2, vector <int> Y2, long long A)
    {
        ll N = X1.size();
        vector<int> intersection = {0,0,1000000,1000000};
        for(int i = 0;i < N;i++){
            intersection[0] = max(intersection[0],X1[i]);
            intersection[1] = max(intersection[1],Y1[i]);
            intersection[2] = min(intersection[2],X2[i]);
            intersection[3] = min(intersection[3],Y2[i]);
        }
        // cout << intersection << endl;
        for(int i = intersection[0]+1;i <=intersection[2];i++){
            ll x = i - intersection[0];
            if (A % x == 0 && A/x <= intersection[3]- intersection[1]){
                return {intersection[0],intersection[1],i,(int)(intersection[1]+ A/x)};
            }
        }
        return vector<int>(0);
    }

};

// int main()
// {
//     IntersectionArea m;
//     auto v =  m.addOne(
//         {0, 2, 2, 2},
// {2, 2, 0, 2},
// {5, 7, 5, 5},
// {5, 5, 5, 7},
// 4);
//     // cout << v<< endl;

//     return 0;
// }
