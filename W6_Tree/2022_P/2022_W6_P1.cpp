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
		}
		else {
			Node* newNode = new Node(parentNode, y);
			parentNode->childList.push_back(newNode);
			nodeList.push_back(newNode);
		}
	}
	void deleteNode(int x) {
		Node* deleteNode = findNode(x);
		if (deleteNode == nullptr) {
			cout << -1 << endl;
		}
		else {
			for (int i = 0; i < deleteNode->childList.size(); i++) {
				deleteNode->parent->childList.push_back(deleteNode->childList[i]);
				deleteNode->childList[i]->parent = deleteNode->parent;
			}
			for (int i = 0; i < deleteNode->parent->childList.size(); i++) {
				if (deleteNode == deleteNode->parent->childList[i]) {
					deleteNode->parent->childList.erase(deleteNode->parent->childList.begin() + i);
				}
			}
			for (int i = 0; i < nodeList.size(); i++) {
				if (deleteNode == nodeList[i]) {
					nodeList.erase(nodeList.begin() + i);
				}
			}
			delete deleteNode;
		}
	}
	void printParent(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr|| curNode -> parent == nullptr) {
			cout << -1 << endl;
		}
		else {
			cout << curNode->parent->value << endl;
		}
	}
	void printChild(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr || curNode->childList.empty()) {
			cout << -1 << endl;
		}
		else {
			for (int i = 0; i < curNode->childList.size(); i++) {
				cout << curNode->childList[i]->value << " ";
			}
			cout << endl;
		}
	}
	void maxChild(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr || curNode->childList.empty()) {
			cout << -1 << endl;
		}
		else {
			int maxnum = 0;
			for (int i = 0; i < curNode->childList.size(); i++) {
				if (curNode->childList[i]->value > maxnum) {
					maxnum = curNode->childList[i]->value;
				}
			}
			cout << maxnum << endl;
		}
	}
};

int main() {
	int T;
	cin >> T;
	string str;
	Tree tree = Tree();
	while (T--) {
		int x, y;
		cin >> str;
		if (str == "insert") {
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		else if (str == "delete") {
			cin >> x;
			tree.deleteNode(x);
		}
		else if (str == "parent") {
			cin >> x;
			tree.printParent(x);
		}
		else if (str == "child") {
			cin >> x;
			tree.printChild(x);
		}
		else if (str == "maxChild") {
			cin >> x;
			tree.maxChild(x);
		}
	}
}