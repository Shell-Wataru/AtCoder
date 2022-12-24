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
#include <atcoder/mincostflow>
using namespace std;
using ll = long long;
using namespace atcoder;

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

int solve()
{
    ll N;
    cin >>  N;
    vector<pair<ll,ll>>  points(N);
    map<pair<ll,ll>,ll> mapping;
    for(int i = 0;i < N;i++){
        ll x,y;
        cin >> x >> y;
        mapping[{x,y}] = i;
        points[i] = {x,y};
    }
    auto convex = convex_hull(points);
    vector<double> answers(N,0);
    ll M = convex.size();
    if (M == 2){
        for(auto p:convex){
            answers[mapping[p]] = 0.5;
        }
    }else{
        for(int i = 0;i < M;i++){
            pair<ll,ll> ab = {convex[(i+1)%M].first-convex[i].first,convex[(i+1)%M].second-convex[i].second};
            pair<ll,ll> bc = {convex[i].first-convex[(M+i-1)%M].first,convex[i].second-convex[(M+i-1)%M].second};
            double a = atan2(ab.second,-ab.first);
            double b = atan2(bc.second,-bc.first);
            double angle = min(abs(a-b),M_PI*2- abs(a-b));
            // cout << angle/(M_PI*2) << endl;
            answers[mapping[convex[i]]] = angle/(M_PI*2);
        }
    }
    cout << fixed << setprecision(12);
    for(int i = 0;i < N;i++){
        cout << answers[i] << "\n";
    }
    cout << flush;
    return 0;
}

int main()
{
    // ll T;
    // cin >> T;
    // for (int i = 0; i < T; i++)
    // {
    solve();
    // }
    cout << flush;
    return 0;
}
