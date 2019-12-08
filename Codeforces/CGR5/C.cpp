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
    vector<ll> position = {0,0,0};
};

class Node
{
    public:
    Point p;
    Node *left = nullptr;
    Node *right = nullptr;
    int axis = -1; //!< dimension's axis
};

//zero indexed and vector
class KDTree
{
private:
	/** @brief k-d tree node.
		*/
	Node *buildRecursive(typename vector<Point>::iterator start_itr, typename vector<Point>::iterator end_itr, ll depth)
	{
		ll npoints = end_itr - start_itr;
		if (npoints <= 0)
			return nullptr;

		const int axis = depth % (*start_itr).position.size();
		const int mid = npoints / 2;

		std::nth_element(start_itr, start_itr + mid, end_itr, [&](Point &lhs, Point &rhs) {
			return lhs.position[axis] < rhs.position[axis];
		});

		Node *node = new Node();
		node->axis = axis;
		node->p = *(start_itr + mid);
        // cout << "axis:" << axis <<"depth" << depth << "index:"<< node->p.index  << endl;
        // print(node->p.position);
		node->left = buildRecursive(start_itr, start_itr + mid, depth + 1);
		node->right = buildRecursive(start_itr + mid + 1, end_itr, depth + 1);
		return node;
	}

public:
	vector<Point> data;
	Node *root = nullptr;
	KDTree(vector<Point> &_data) : data(_data)
	{
		root = buildRecursive(data.begin(), data.end(), 0);
	}

	void search(vector<ll> &order)
	{
		if (root != nullptr)
		{
		    search(root,order);
		}
	}
	void search(Node *node,vector<ll> &order)
	{
		// cout << (node->p.position)[0] << " " << (node->p.position)[1] << " " << (node->p.position)[2] << endl;
		if (node->left != nullptr)
		{
			search(node->left,order);
		}
        order.push_back(node->p.index);
		if (node->right != nullptr)
		{
			search(node->right,order);
		}
	}
};


int main()
{
    ll N;
    cin >> N;
    vector<Point> points;
    for(int i = 0;i<N;i++){
        Point p;
        p.index = i+1;
        cin >> p.position[0] >> p.position[1] >> p.position[2];
        points.push_back(p);
    }
    KDTree kdt(points);
    vector<ll> order;
    kdt.search(order);
    // print(order);
    for(int i = 0;i<N/2;i++){
        cout << order[2*i] << " " << order[2*i+1] << endl;
    }
    // 整数の入力
    return 0;
}
