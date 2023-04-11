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
	Node* findNode(int v) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (v == nodeList[i]->value) {
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
	void deleteNode(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr) {
			cout << -1 << endl;
			return;
		}
		for (int i = 0; i < curNode->childList.size(); i++) {
			curNode->parent->childList.push_back(curNode->childList[i]);
			curNode->childList[i]->parent = curNode->parent;
		}
		for (int i = 0; i < curNode->parent->childList.size(); i++) {
			if (curNode == curNode->parent->childList[i]) {
				curNode->parent->childList.erase(curNode->parent->childList.begin() + i);
				break;
			}
		}
		for (int i = 0; i < nodeList.size(); i++) {
			if (curNode == nodeList[i]) {
				nodeList.erase(nodeList.begin() + i);
				break;
			}
		}
		delete curNode;
	}
	void printParent(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr) {
			cout << -1 << endl;
			return;
		}
		cout << curNode->parent->value << endl;
	}
	void printChild(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr || curNode->childList.empty()) {
			cout << -1 << endl;
			return;
		}
		for (int i = 0; i < curNode->childList.size(); i++) {
			cout << curNode->childList[i]->value << " ";
		}
		cout << endl;
	}
	void min_maxChild(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr || curNode->childList.size() < 2) {
			cout << -1 << endl;
			return;
		}
		int max = 0;
		int min = 10001;
		for (int i = 0; i < curNode->childList.size(); i++) {
			if (curNode->childList[i]->value > max) {
				max = curNode->childList[i]->value;
			}
		}
		for (int i = 0; i < curNode->childList.size(); i++) {
			if (curNode->childList[i]->value < min) {
				min = curNode->childList[i]->value;
			}
		}
		cout << max - min << endl;
	}
};

int main() {
	int T;
	string str;
	Tree tree = Tree();
	cin >> T;
	int x, y;
	while (T--) {
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
		else if (str == "min_maxChild") {
			cin >> x;
			tree.min_maxChild(x);
		}
	}
}