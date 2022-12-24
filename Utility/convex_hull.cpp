// Implementation of Andrew's monotone chain 2D convex hull algorithm.
// Asymptotic complexity: O(n log n).
// Practical performance: 0.5-1.0 seconds for n=1000000 on a 1GHz machine.
#include <iostream>
#include <algorithm>
#include <vector>
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

int main(){
    vector<pair<ll,ll>> P ={
        {0,0},
		{0,1},
        {0,2},
        {2,2},
        {2,0},
        {1,1},
    };
    for(auto p:convex_hull(P)){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}