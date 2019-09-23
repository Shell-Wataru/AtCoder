#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
#include <cmath>

using namespace std;
using ll = long long;


//   bool isTaikaku(int x, int y)
//   {
//     int x4 = x % 4, y4 = y % 4;
//     return ((x4 == 0 || x4 == 3) && (y4 == 0 || y4 == 3)) ||
//            ((x4 == 1 || x4 == 2) && (y4 == 1 || y4 == 2));
//   }

// vector<vector<ll>> calc(int N)
// {
//   vector<vector<ll>> r(N,vector<ll>(N,0));
//   for(int y = 0; y<N;y++)
//     for(int x =  0; x < N;x++) {
//       int i = x + y * N;
//       if (isTaikaku(x, y))
//         r[y][x] = i;
//       else
//         r[N-1-y][N-1-x] = i;
//     }

//   return r;
// }

int main()
{
    int N;
    cin >> N;
    ll total = 0;
    vector<vector<ll>> magic(N,vector<ll>(N,0));
    for(int i = 0;i < N*N;i++){
        ll row = i/N;
        ll column = i%N;
        if(i/N % 4 == 0 || i/N % 4 == 2){
            column = i%N;
        }else{
            column = N - i % N - 1;
        }
        total ^= i;
        magic[row][column] = i;
    }
    // cout << "row" << endl;
    // for(int i = 0;i<N;i++){
    //     ll a = 0;
    //     for(int j = 0; j< N;j++){
    //         a ^= magic[i][j];
    //     }
    //     cout << a << endl;
    // }
    cout << "column" << endl;
    for(int i = 0;i<N;i++){
        ll a = 0;
        for(int j = 0; j< N;j++){
            a ^= magic[j][i];
        }
        cout << a << endl;
    }
    for (int i = 0;i<N;i++){
        for(int j = 0;j<N;j++){
            if(j == 0){
                cout << magic[i][j];
            }else{
                cout << " " <<magic[i][j];
            }
        }
        if (i != N - 1){
            cout << "\n";
        }
    }
    cout << endl;
    cout << (8^9^14) << endl;
    cout << (10^11^12) << endl;
    cout << (15^8^11) << endl;
    cout << (9^10^13) << endl;
    cout << total << endl;
    return 0;
}
