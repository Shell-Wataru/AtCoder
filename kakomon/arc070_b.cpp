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
using ll = int;

int main()
{
    ll N, K;
    cin >> N >> K;
    vector<ll> A(N);
    for (int i = 0; i < N; i++)
    {
        cin >> A[i];
    }
    vector<vector<ll>> from_left(N + 1, vector<ll>(K + 1, 0));
    vector<vector<ll>> from_right(N + 1, vector<ll>(K + 1, 0));
    from_left[0][0] = 1;
    from_right[N][0] = 1;
    for (int i = 0; i < N; i++)
    {
        from_left[i + 1] = from_left[i];
        for (int j = 0; j <= K; j++)
        {
            from_left[i + 1][min(j + A[i], K)] |= from_left[i][j];
        }
    }
    for (int i = N - 1; i >= 0; i--)
    {
        from_right[i] = from_right[i + 1];
        for (int j = 0; j <= K; j++)
        {
            from_right[i][min(j + A[i], K)] |= from_right[i + 1][j];
        }
    }

    ll ans = 0;
    for (int i = 0; i < N; i++)
    {
        vector<ll> counts(K+2,0);
        for(int j = 0;j <= K;j++){
            counts[j+1] += counts[j] + from_right[i+1][j];
        }
        bool must_use_found = false;
        for(int j = 0;j < K;j++){
            if (from_left[i][j] > 0 && counts[K-j] - counts[max(K-j-A[i],0)] > 0 ){
                must_use_found = true;
                break;
            }
        }

        if (!must_use_found){
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
