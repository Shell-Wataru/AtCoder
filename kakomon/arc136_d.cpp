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
#include <set>
using namespace std;
using ll = long long;

template <typename T>
struct V : vector<T>
{
    using vector<T>::vector;
};
V()->V<int>;
V(size_t)->V<int>;
template <typename T>
V(size_t, T) -> V<T>;
template <typename T>
vector<T> make_vec(size_t n, T a) { return vector<T>(n, a); }
template <typename... Ts>
auto make_vec(size_t n, Ts... ts) { return vector<decltype(make_vec(ts...))>(n, make_vec(ts...)); }
template <typename T>
ostream &operator<<(ostream &os, const vector<T> &v)
{
    for (auto &e : v)
        os << e << ' ';
    return os;
}

ll solve()
{
    ll N;
    cin >> N;
    vector<string> A(N);
    for(int i = 0;i < N;i++){
        cin >> A[i];
        A[i] = ("000000" + A[i]).substr(A[i].size(),6);
    }
    auto sum =  make_vec(10,10,10,10,10,10,0);
    for(auto a:A){
        ll i = a[0] - '0';
        ll j = a[1] - '0';
        ll k = a[2] - '0';
        ll l = a[3] - '0';
        ll m = a[4] - '0';
        ll n = a[5] - '0';
        sum[i][j][k][l][m][n] += 1;
    }
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < 10;k++){
                for(int l = 0;l < 10;l++){
                    for(int m = 0;m < 10;m++){
                        for(int n = 0;n < 9;n++){
                            sum[i][j][k][l][m][n+1] += sum[i][j][k][l][m][n];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < 10;k++){
                for(int l = 0;l < 10;l++){
                    for(int m = 0;m < 10;m++){
                        for(int n = 0;n < 9;n++){
                            sum[j][k][l][m][n+1][i] += sum[j][k][l][m][n][i];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < 10;k++){
                for(int l = 0;l < 10;l++){
                    for(int m = 0;m < 10;m++){
                        for(int n = 0;n < 9;n++){
                            sum[k][l][m][n+1][i][j] += sum[k][l][m][n][i][j];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < 10;k++){
                for(int l = 0;l < 10;l++){
                    for(int m = 0;m < 10;m++){
                        for(int n = 0;n < 9;n++){
                            sum[l][m][n+1][i][j][k] += sum[l][m][n][i][j][k];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < 10;k++){
                for(int l = 0;l < 10;l++){
                    for(int m = 0;m < 10;m++){
                        for(int n = 0;n < 9;n++){
                            sum[m][n+1][i][j][k][l] += sum[m][n][i][j][k][l];
                        }
                    }
                }
            }
        }
    }
    for(int i = 0;i < 10;i++){
        for(int j = 0;j < 10;j++){
            for(int k = 0;k < 10;k++){
                for(int l = 0;l < 10;l++){
                    for(int m = 0;m < 10;m++){
                        for(int n = 0;n < 9;n++){
                            sum[n+1][i][j][k][l][m] += sum[n][i][j][k][l][m];
                        }
                    }
                }
            }
        }
    }
    ll ans = 0;
    for(auto a:A){
        ll i = a[0] - '0';
        ll j = a[1] - '0';
        ll k = a[2] - '0';
        ll l = a[3] - '0';
        ll m = a[4] - '0';
        ll n = a[5] - '0';
        ll target_i = 9 - i;
        ll target_j = 9 - j;
        ll target_k = 9 - k;
        ll target_l = 9 - l;
        ll target_m = 9 - m;
        ll target_n = 9 - n;
        ans += sum[target_i][target_j][target_k][target_l][target_m][target_n];
        if (i <= target_i && j <= target_j && k <= target_k && l <= target_l && m <= target_m && n <= target_n){
            ans--;
        }
    }
    cout << ans/2 << endl;
    return 0;
}

int main()
{
    // ll N;
    // cin >> N;
    // for(int i = 1; i <= N;i++){
    solve();
    // }
    cout << flush;
    return 0;
}
