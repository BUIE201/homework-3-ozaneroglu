#include <iostream>
#include "vector"

using namespace std;

struct Node
{
	int i;
	Node* pLeft;
	Node* pRight;

	Node(int iIn) : i(iIn), pLeft(nullptr), pRight(nullptr) {}
};

void InsertToTree(Node*& pRoot, Node* pNew)

{
	if (!pRoot)
	{
		pRoot = pNew;
		return;
	}

	if (pNew->i <= pRoot->i)
		InsertToTree(pRoot->pLeft, pNew);
	else
		InsertToTree(pRoot->pRight, pNew);
}

void DeleteNodeWithTwoChildren(Node*& q, Node*& p)
{
	if (p->pRight)
	{
		DeleteNodeWithTwoChildren(q, p->pRight);
		return;
	}

	p->i = q->i;
	q = p;
	p = p->pLeft;
}

void DeleteNodeFromTree(Node*& pRoot, int i)
{
	if (!pRoot)
		return;

	if (pRoot->i < i)
	{
		DeleteNodeFromTree(pRoot->pRight, i);
		return;
	}

	if (pRoot->i > i)
	{
		DeleteNodeFromTree(pRoot->pLeft, i);
		return;
	}

	Node* q = pRoot;
	if (!q->pRight)
		pRoot = q->pLeft;
	else if (!q->pLeft)
		pRoot = q->pRight;
	else
		DeleteNodeWithTwoChildren(q, q->pLeft);

	delete q;
}

void PrintTree(Node* pRoot, int Level)
{
	if (!pRoot)
		return;

	PrintTree(pRoot->pRight, Level + 1);

	for (int i = 0; i < Level; i++)
		cout << "  ";
	cout << pRoot->i << endl;

	PrintTree(pRoot->pLeft, Level + 1);
}

void Insert(Node*& pRoot, Node* pNewNode)
{
	if (!pRoot)
		pRoot = pNewNode;
	else
	{
		if (pNewNode->i < pRoot->i)
			Insert(pRoot->pLeft, pNewNode);
		else
			Insert(pRoot->pRight, pNewNode);
	}
}


void determinebranches(Node*& pRoot, vector<int> branch, vector <vector<int>> allbranches) {
	if (!pRoot)
		return;
	branch.push_back(pRoot->i);
	if (!(pRoot->pRight) && !(pRoot->pLeft)) { // if there is no child nodes branch can be added to allbranch vector
		allbranches.push_back(branch);
	}
	if ((pRoot->pRight) || (pRoot->pLeft)) {// even if there is one child node algortihm contiunes 
		determinebranches(pRoot->pLeft, branch, allbranches);
		determinebranches(pRoot->pRight, branch, allbranches);
	}

}
void sumofbranches(vector<int>branch, vector <vector<int>> allbranches) {
	int maxsum = 0;
	int branchsum = 0;
	int branchnumber = 0;
	for (int i = 0; i < allbranches.size(); i++) {
		for (int j = 0; j < branch.size(); j++) {// sum of branch 
			branchsum = +branch[j];
		}
		if (branchsum >= maxsum) {//finding the maximum
			maxsum = branchsum;
			branchnumber = i;
		}
	}

	cout << " Branch with the largest sum is";
	for (auto a : allbranches[branchnumber]) {
		cout << a;
	}
	cout << " sum =" << maxsum;

}

void main()
{
	int i;

	Node* pRoot = nullptr;
	while (true)
	{
		cin >> i;
		if (i == 99)
			break;

		Node* p = new Node(i);
		InsertToTree(pRoot, p);// this algorithm will deal with sorted tree structure so insert function remains same.
	}
	vector <vector<int>> allbranches;
	vector <int> branch;
	PrintTree(pRoot, 1);
	determinebranches(pRoot, branch, allbranches);
	sumofbranches(branch, allbranches);



}
