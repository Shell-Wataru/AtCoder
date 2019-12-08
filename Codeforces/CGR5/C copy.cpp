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
ll BASE_NUM = 1000000007;

#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <deque>
#include <cmath>
#include <map>
#include <queue>
using namespace std;
using ll = long long;

void print(vector<ll> &data){
    for (auto a: data){
        cout << "," << a;
    }
    cout << endl;
}

class Point{
public:
    ll index = -1;
    tuple<ll,ll,ll> position;
};

class Node
{
    public:
    Point p;
    Node *left = nullptr;
    Node *right = nullptr;
    int axis = -1; //!< dimension's axis
};


int main()
{
    ll N;
    cin >> N;
    vector<Point> points;
    for(int i = 0;i<N;i++){
        Point p;
        p.index = i+1;
        cin >> get<0>(p.position) >> get<1>(p.position) >> get<2>(p.position);
        points.push_back(p);
    }
	sort(points.begin(),points.end(),[](Point &lp,Point &rp){
		return greater<tuple<ll,ll,ll>>()(lp.position,rp.position);
	});
    // print(order);
	for(int i = 0;i<N;i++){
        cout << get<0>(points[i].position) << get<1>(points[i].position) << get<2>(points[i].position) << endl;
    }
    for(int i = 0;i<N/2;i++){
        cout << points[2*i].index << " " << points[2*i+1].index << endl;
    }
    // 整数の入力
    return 0;
}
