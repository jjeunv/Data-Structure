#include <iostream>
#include <vector>
using namespace std;

class Node {
public:
	int value;
	Node* parent;
	vector<Node*> childList;
	Node(Node* p, int v) {
		parent = p;
		value = v;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> nodeList;
	Tree() {
		root = new Node(nullptr, 1);
		nodeList.push_back(root);
	}
	Node* findNode(int x) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (x == nodeList[i]->value) {
				return nodeList[i];
			}
		}
		return nullptr;
	}
	void insertNode(int x, int y) {
		Node* parentNode = findNode(x);
		Node* curNode = findNode(y);
		if (parentNode == nullptr || curNode != nullptr) {
			cout << -1 << endl;
			return;
		}
		Node* newNode = new Node(parentNode, y);
		parentNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	int printDepth(int x) {
		int depth = 0;
		Node* curNode = findNode(x);
		if (curNode == nullptr) {
			return -1;
		}
		while (curNode != root) {
			curNode = curNode->parent;
			depth++;
		}
		return depth;
	}
};

int main() {
	int N, M;
	Tree tree = Tree();
	cin >> N >> M;
	int x, y;
	while (N--) {
		cin >> x >> y;
		tree.insertNode(x, y);
	}
	while (M--) {
		cin >> x >> y;
		int a = tree.printDepth(x);
		int b = tree.printDepth(y);
		if (a == -1 || b == -1) {
			cout << -1 << endl;
		}
		else cout << a + b << endl;
	}
}