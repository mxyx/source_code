
//二叉树系列
//先序，中序，后序打印二叉树
//非递归

#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;

struct TreeNode
{
	TreeNode* left;
	TreeNode* right;
	int val;
	TreeNode() : val(0), left(nullptr), right(nullptr){}
	TreeNode(int v) : val(v), left(nullptr), right(nullptr){}
};

//************************************
// Method:    PrintBSTOrderPre
// FullName:  PrintBSTOrderPre
// Access:    public 
// Returns:   void
// Qualifier:
// Parameter: const TreeNode * root
//************************************
void PrintBSTOrderPre(TreeNode* root)
{
	if (root == nullptr)
		return;
	stack<TreeNode*> s;
	s.push(root);
	while (!s.empty())
	{
		TreeNode* tmp = s.top();
		s.pop();
		cout << tmp->val << " ";
		if (tmp->right)
			s.push(tmp->right);
		if (tmp->left)
			s.push(tmp->left);
	}
	cout << endl;
}

void PrintBSTOrderMiddle(TreeNode* root)
{
	if (root == nullptr)
		return;
	stack<TreeNode*> s;
	while (!s.empty() || root)
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}
		TreeNode* tmp = s.top();
		s.pop();
		cout << tmp->val << " ";
		root = tmp->right;
	}
	cout << endl;
}

void PrintBSTOrderPost(TreeNode* root)
{
	if (!root)
		return;
	stack<TreeNode*> s;
	TreeNode* pre = nullptr;
	while (!s.empty() || root)
	{
		while (root)
		{
			s.push(root);
			root = root->left;
		}
		TreeNode* tmp = s.top();
		if (tmp->right && tmp->right != pre)
			root = tmp->right;
		else
		{
			cout << tmp->val << " ";
			pre = tmp;
			s.pop();
		}
	}
	cout << endl;
}

//递归
void PrintBSTOrderPreRecursive(TreeNode* root)
{
	if (!root)
		return;
	cout << root->val << " ";
	PrintBSTOrderPreRecursive(root->left);
	PrintBSTOrderPreRecursive(root->right);
}

void PrintBSTOrderMidRecursive(TreeNode* root)
{
	if (!root)
		return;
	PrintBSTOrderMidRecursive(root->left);
	cout << root->val << " ";
	PrintBSTOrderMidRecursive(root->right);
}

void PrintBSTOrderPostRecursive(TreeNode* root)
{
	if (!root)
		return;
	PrintBSTOrderPostRecursive(root->left);
	PrintBSTOrderPostRecursive(root->right);
	cout << root->val << " ";
}

TreeNode* CreateBST()
{
	int in;
	cin >> in;
	if (in == -1)
		return nullptr;
	TreeNode* root = new TreeNode(in);
	root->left = CreateBST();
	root->right = CreateBST();
	return root;
}

void DeleteTree(TreeNode* root)
{
	if (!root)
		return;
	DeleteTree(root->left);
	DeleteTree(root->right);
	delete(root);
}

int main()
{
	TreeNode* root = CreateBST(); // 1 2 4 -1 -1  5 -1 -1 3 -1 -1
	//pre
	PrintBSTOrderPre(root);
	PrintBSTOrderPreRecursive(root);
	cout << endl;

	//mid
	PrintBSTOrderMiddle(root);
	PrintBSTOrderMidRecursive(root);
	cout << endl;

	//post
	PrintBSTOrderPost(root);
	PrintBSTOrderPostRecursive(root);
	cout << endl;

	DeleteTree(root);
	system("pause");
	return 0;
}