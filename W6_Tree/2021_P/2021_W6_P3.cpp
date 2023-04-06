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
		if (parentNode == nullptr) {
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
	void printNode(int x) {
		Node* curNode = findNode(x);
		if (curNode == nullptr || curNode -> parent == nullptr) {
			cout << -1 << endl;
		}
		else {
			cout << curNode->parent->value << endl;
		}
	}
};

int main() {
	int N;
	cin >> N;
	string str;
	Tree tree = Tree();
	int x, y;
	while (N--) {
		cin >> str;
		if (str == "insert") {
			cin >> x >> y;
			tree.insertNode(x, y);
		}
		else if (str == "delete") {
			cin >> x;
			tree.deleteNode(x);
		}
		else if (str == "print") {
			cin >> x;
			tree.printNode(x);
		}
	}
}