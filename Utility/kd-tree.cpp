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

class Point
{
public:
	ll index = -1;
	vector<ll> position;

	ll distance(Point &q)
	{
		ll dist = 0;
		for (size_t i = 0; i < position.size(); i++)
		{
			ll d = position[i] - q.position[i];
			dist += d * d;
		}
		return dist;
	}
};

//zero indexed and vector
class KDTree
{
private:
	/** @brief k-d tree node.
		*/
	struct Node
	{
		Point p;
		Node *left = nullptr;
		Node *right = nullptr;
		int depth = -1;
		int axis = -1; //!< dimension's axis
	};

	Node *buildRecursive(typename vector<Point>::iterator start_itr, typename vector<Point>::iterator end_itr, ll depth)
	{
		ll npoints = end_itr - start_itr;
		if (npoints <= 0)
			return nullptr;

		const int axis = depth % (*start_itr).position.size();
		const int mid = (npoints - 1) / 2;

		std::nth_element(start_itr, start_itr + mid, end_itr, [&](Point &lhs, Point &rhs) {
			return lhs.position[axis] < rhs.position[axis];
		});

		Node *node = new Node();
		node->axis = axis;
		node->depth = depth;
		node->p = *(start_itr + mid);
		node->left = buildRecursive(start_itr, start_itr + mid, depth + 1);
		node->right = buildRecursive(start_itr + mid + 1, end_itr, depth + 1);
		return node;
	}

public:
	vector<Point> data;
	Node *root = nullptr;
	KDTree(vector<Point> &_data) : data(_data)
	{
		// cout << data[0][1] << endl;
		root = buildRecursive(data.begin(), data.end(), 0);
	}

	Point *nnSearch(Point &query)
	{
		Node *nearestNode = new Node();

		ll minDistance = (1LL << 62) - 1;
		nnSearchRecursive(query, root, nearestNode, &minDistance);
		return &nearestNode->p;
	}
	void nnSearchRecursive(Point &query, Node *node, Node *nearestNode, ll *minDistance)
	{
		if (node == nullptr)
		{
			return;
		}
		// cout << "search" << node->point[0] << node->point[1] << endl;

		ll current_node_distance = query.distance(node->p);
		if (current_node_distance < *minDistance)
		{
			*minDistance = current_node_distance;
			*nearestNode = *node;
		}
		const int axis = node->axis;
		const int containsInLeft = query.position[axis] < node->p.position[axis];

		if (containsInLeft)
		{
			nnSearchRecursive(query, node->left, nearestNode, minDistance);
		}
		else
		{
			nnSearchRecursive(query, node->right, nearestNode, minDistance);
		}

		const double other_side_minimum = fabs(query.position[axis] - node->p.position[axis]);
		if (other_side_minimum < *minDistance)
		{
			if (containsInLeft)
			{
				nnSearchRecursive(query, node->right, nearestNode, minDistance);
			}
			else
			{
				nnSearchRecursive(query, node->left, nearestNode, minDistance);
			}
		}
	}

	void show()
	{
		if (root != nullptr)
		{
			show(root);
		}
	}
	void show(Node *node)
	{
		cout << "depth:" << node->depth << " position:" << node->p.position[0] << " " << node->p.position[1] << endl;
		if (node->left != nullptr)
		{
			show(node->left);
		}
		if (node->right != nullptr)
		{
			show(node->right);
		}
	}
};

int main()
{
	vector<Point> data;
	for (int i = 0; i < 16; i++)
	{
		Point p;
		p.index = i;
		p.position = vector<ll>{i % 16, 2 * i % 16};
		data.push_back(p);
	}
	KDTree kdt(data);

	kdt.show();
	cout << "--------------------" << endl;
	// vector<ll> &nearest = *kdt.nnSearch(data[0]);
	// cout << da[0] << " " << d[1] << endl;
	// cout << nearest[0] << " " << nearest[1] << endl;

	for (auto d : data)
	{
		Point &nearest = *kdt.nnSearch(d);
		cout << d.position[0] << " " << d.position[1] << endl;
		cout << nearest.position[0] << " " << nearest.position[1] << endl;
	}
}
