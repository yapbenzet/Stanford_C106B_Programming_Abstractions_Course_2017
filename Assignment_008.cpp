/*Problem 1
See Word Editor Project.
*/

/*Problem 2
a) The height of a tree is the NUMBER OF EDGES from the ROOT to the DEEPEST LEAF - 3
b) In Order Traversal - Left, Parent, Right
   Pre Order Traversal - Parent, Left, Right
   Post Order Traversal - Left, Right, Parent
*/

#include <iostream>
#include <vector>
using namespace std;

struct nodeT {
	int value;
	nodeT * left;
	nodeT * right;
	nodeT(int val) : value(val), left(nullptr), right(nullptr) {}
};

template <typename T>
class BinaryT {
public:
	nodeT * root;

	BinaryT() { 
		root = nullptr;
	}

	~BinaryT() {
		emptyTree(root);
	}

	void emptyTree(nodeT * start) {
		if (start != nullptr)
		{
			nodeT * runner = start;
			nodeT * toDelete = start;
			emptyTree (runner->left);
			emptyTree(runner->right);
			delete toDelete;
		}
	}

	void print(nodeT * start) {
		if (start != nullptr)
		{
			nodeT * runner = start;
			cout << runner->value << " ";
			print(runner->left);
			print(runner->right);
		}
	}

	void insert(T insertValue) 
	{
		nodeT * insertNode = new nodeT(insertValue);

		if (root == nullptr)
		{
			root = insertNode;
		}
		else
		{
			nodeT * runner = root;
			nodeT * trailer = runner;

			while (true)
			{
				if ( insertValue <= runner -> value )
				{
					if ( runner -> left == nullptr )
					{
						runner -> left = insertNode;
						break;
					}
					runner = runner->left;
				}
				else
				{
					if ( runner -> right == nullptr )
					{
						runner -> right = insertNode;
						break;
					}
					runner = runner->right;
				}
			}
		}
	}
};


/*Problem 3: Tree Equal
Write a function that takes two binary trees and returns a boolean value which indicates whether or not the two trees are equal (same structure and values)
*/
bool TreeEqual( nodeT * selfRoot, nodeT * otherRoot )
{
	if ( ! ( selfRoot != nullptr && otherRoot != nullptr ) && ( selfRoot == nullptr && otherRoot == nullptr ) )
		return false;

	if ( selfRoot -> value != otherRoot -> value )
		return false;

		TreeEqual(selfRoot -> left , otherRoot -> left );
		TreeEqual(selfRoot -> right , otherRoot -> right );
	
	return true;
}


/*Problem 4: Trim Leaves
Write a function that will take a binary tree and remove all its leaves
*/
void TrimLeaves(nodeT * & tree)
{
	nodeT * runner = tree;
	
	//a Leaf has both child nodes empty
	if (runner->left == nullptr && runner->right == nullptr)
	{
		delete runner;
	}
	else {
		if (runner->left != nullptr)
			TrimLeaves(runner->left);
		if (runner->right != nullptr)
			TrimLeaves(runner->right);
	}
}


/*Problem 5: Balanced Trees
Write a fuction to return the height of a binary tree
*/
int TreeHeight(nodeT * root)
{
	vector<int> v;
	if (root != nullptr)
	{
		if (root->left != nullptr)
			 v.push_back (1 + TreeHeight(root->left) );

		if (root->right != nullptr)
			v.push_back ( 1 + TreeHeight(root->right) );
	}

	int max = 0;
	for (int i = 0; i < v.size(); ++i)
	{
		if (max < v[i])
			max = v[i];
	}
	return max;
}

/*Problem 5: Balanced Trees
Write a fuction to determine if a tree is balanced (bool)
*/
bool isBalancedTree(nodeT * root)
{

	return true;
}


int main() {
	BinaryT<int> * b = new BinaryT<int>();
	for (int i = 5; i < 6; ++i)
		b->insert(i);
	for (int i = 4; i >= 0; --i)
		b->insert(i);

	b->print(b->root);
	cout << endl;

	cout << TreeHeight(b->root) << endl;
	
	return 0;
}
