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
#include <climits>
using namespace std;
using ll = long long;

int solve()
{
    ll H,W,N,sr,sc;
    cin >> H >> W >> N >> sr >> sc;
    string S,T;
    cin >> S >> T;
    ll s_up = 0;
    ll s_down = 0;
    ll t_up = 0;
    ll t_down = 0;
    ll s_left = 0;
    ll s_right = 0;
    ll t_left = 0;
    ll t_right = 0;
    for(int i = 0;i < N;i++){
        if (S[i] == 'L'){
            s_left++;
        }else if (S[i] == 'R'){
            s_right++;
        }else if (S[i] == 'U'){
            s_up++;
        }else if (S[i] == 'D'){
            s_down++;
        }

        if (sr - s_up + t_down <= 0){
            cout << "NO" << endl;
            return 0;
        }else{
            ll up = min(t_up,sr - s_up - 1);
            if (sr + s_down - up > H){
                cout << "NO" << endl;
                return 0;
            }
        }

        if (sc - s_left + t_right <= 0){
            cout << "NO" << endl;
            return 0;
        }else{
            ll left = min(t_left,sc - s_left - 1);
            if (sc + s_right - left > W){
                cout << "NO" << endl;
                return 0;
            }
        }

        if (T[i] == 'L'){
            if (s_right > 0){
                s_right--;
            }else if (sc - t_left > 1){
                    t_left++;
            }
        }else if (T[i] == 'R'){
            if (s_left > 0){
                s_left--;
            }else if (sc + t_right < W){
                t_right++;
            }
        }else if (T[i] == 'U'){
            if (s_down > 0){
                s_down--;
            }else if (sr - t_up > 1){
                t_up++;
            }
        }else if (T[i] == 'D'){
            if (s_up > 0){
                s_up--;
            }else if (sc + t_down < H){
                t_down++;
            }
        }
    }
    cout << "YES" << endl;
    return 0;
}

int main()
{
    // // 整数の入力
    //   ll t;
    //   cin >> t;
    //   for (size_t i = 0; i < t; i++)
    //   {
    solve();
    //   }
    //   cout << flush;
    return 0;
}
