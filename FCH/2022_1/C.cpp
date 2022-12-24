#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <stack>
using namespace std;
using ll = long long;

// 3D cross product of OA and OB vectors, (i.e z-component of their "2D" cross product, but remember that it is not defined in "2D").
// Returns a positive value, if OAB makes a counter-clockwise turn,
// negative for clockwise turn, and zero if the points are collinear.
ll cross(pair<ll,ll> &O, pair<ll,ll> &A, pair<ll,ll> &B)
{
	return (A.first - O.first) * (B.second - O.second) - (A.second - O.second) * (B.first - O.first);
}

// Returns a list of points on the convex hull in counter-clockwise order.
// Note: the last point in the returned list is the same as the first one.
vector<pair<ll,ll>> convex_hull(vector<pair<ll,ll>> P)
{
	size_t n = P.size(), k = 0;
	// if (n <= 3) return P;
	vector<pair<ll,ll>> H(2*n);

	// Sort points lexicographically
	sort(P.begin(), P.end());

	// Build lower hull
	for (size_t i = 0; i < n; ++i) {
		while (k >= 2 && cross(H[k-2], H[k-1], P[i]) <= 0) k--;
		H[k++] = P[i];
	}

	// Build upper hull
	for (size_t i = n-1, t = k+1; i > 0; --i) {
		while (k >= t && cross(H[k-2], H[k-1], P[i-1]) <= 0) k--;
		H[k++] = P[i-1];
	}

	H.resize(k-1);
	return H;
}

string solve()
{
    ll N,K,D;
    cin >> N >> K >> D;
    vector<pair<ll,ll>> H(N);
    for(int i = 0;i < N;i++){
        scanf("%lld",&H[i].first);
        scanf("%lld",&H[i].second);
    }
    auto convex = convex_hull(H);
    sort(convex.begin(),convex.end());
    ll M = convex.size();
    vector<ll> DP(M,numeric_limits<ll>::max()/2);
    DP[0] = 0;
    for(int i = 0; i < M;i++){
        // cout << convex[i].first << " " << convex[i].second << endl;
        for(int j = 0;j < i;j++){
            if ( abs(convex[i].first -  convex[j].first) + abs(convex[i].second -  convex[j].second) <= D){
                // cout  << j << "->" << i << endl;
                DP[i] = min(DP[i],
                    DP[j] + max(K,
                    (convex[i].first -  convex[j].first) * (convex[i].first -  convex[j].first) +
                    (convex[i].second -  convex[j].second) * (convex[i].second -  convex[j].second)));
            }
        }
        // cout << DP[i] << endl;
    }
    if (DP[M-1] == numeric_limits<ll>::max()/2){
        return "-1";
    }else{
        return to_string(DP[M-1]);
    }

}

int main()
{
    // 整数の入力
    ll T;
    cin >> T;

    for (int i = 1; i <= T; i++)
    {
        string ans = solve();
        cout << "Case #" << i << ": " << ans << "\n";
    }
    cout << flush;
    return 0;
}
