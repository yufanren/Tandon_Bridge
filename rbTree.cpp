#include <iostream>
#include <queue>
#include <ctime>

using namespace std;

enum color_t { BLACK, RED };

template<class T>
class RBTree;

template <class T>
T& max(T& left, T& right) {
	if (left > right)
		return left;
	else
		return right;
}

template <class T>
T max(const T& left, const T& right) {
	if (left > right)
		return left;
	else
		return right;
}

template<class T>
class RBNode {
	RBNode<T>* parent, * left, * right;
	T data;
	color_t color;
public:
	friend class RBTree<T>;

	RBNode(const T& newdata = T(), RBNode<T>* newParent = nullptr, RBNode<T>* newleft = nullptr,
		RBNode<T>* newright = nullptr) : data(newdata), parent(newParent), left(newleft), right(newright),
		color(RED) {}

	void printInOrder() const {
		if (left != nullptr)
			left->printInOrder();
		cout << data << "\t" << color << endl;
		if (right != nullptr)
			right->printInOrder();
	}

	void printPostOrder() const {
		if (left != nullptr)
			left->printPostOrder();
		if (right != nullptr)
			right->printPostOrder();
		cout << data << "\t" << color << endl;
	}

	int size()const {
		int leftSize = 0;
		int rightSize = 0;
		if (left != nullptr)
			leftSize = left->size();
		if (right != nullptr)
			rightSize = right->size();
		return 1 + leftSize + rightSize;
	}

	int depth() const {
		int parentDepth = -1;
		if (parent != nullptr)
			parentDepth = parent->depth();
		return 1 + parentDepth;
	}

	RBNode<T>* getSibling() {
		if (parent == nullptr)
			return nullptr;
		if (this == parent->left)
			return parent->right;
		else
			return parent->left;
	}

	RBNode<T>* getUncle() {
		if (parent == nullptr)
			return nullptr;
		return parent->getSibling();
	}
};

template<class T>
class RBTree {
	RBNode<T>* root;
	int size;
	RBNode<T>* recursiveCopy(RBNode<T>* toCopy);
	void singleRightRotate(RBNode<T>*& point);
	void doubleRightRotate(RBNode<T>*& point);
	void singleLeftRotate(RBNode<T>*& point);
	void doubleLeftRotate(RBNode<T>*& point);
	void removeTree(RBNode<T>* point);
	void insertHelper(const T& toInsert, RBNode<T>*& point);
	void balanceTree(RBNode<T>* point);
	void insertCase1(RBNode<T>* point);
	void insertCase2(RBNode<T>* point);
	void insertCase3(RBNode<T>* point);
	void insertCase4(RBNode<T>* point);
public:
	RBTree() : size(0), root(nullptr) {}

	RBTree(const RBTree<T>& rhs) : root(nullptr) {
		clear();
		*this = rhs;
	}

	~RBTree() { clear(); }

	RBTree& operator =(const RBTree<T>& rhs);

	bool isInTree(const T& toFind) { return find(toFind) != nullptr; }

	bool isEmpty() const { return root == nullptr; }

	int getSize() const { return size; }

	void insert(const T&);

	void insert(const T&, RBNode<T>*& point);

	RBNode<T>* find(const T& toFind) const;

	void clear();

	void printInOrder()const { root->printInOrder(); }
	void printPostOrder()const { root->printPostOrder(); }
	void printLevelOrder()const;
};

template <class T>
void RBTree<T>::doubleLeftRotate(RBNode<T>*& point) {
	singleRightRotate(point->left);
	singleLeftRotate(point);
}

template <class T>
void RBTree<T>::doubleRightRotate(RBNode<T>*& point) {
	singleLeftRotate(point->left);
	singleRightRotate(point);
}

template <class T>
void RBTree<T>::singleLeftRotate(RBNode<T>*& point) {
	RBNode<T>* parent = point;
	RBNode<T>* child = point->right;
	child->parent = parent->parent;
	parent->parent = child;
	parent->right = child->left;
	child->left = parent;
	if (parent->right != nullptr)
		parent->right->parent = parent;
	if (child->parent == nullptr)
		root = child;
	else if (child->parent->left = parent)
		child->parent->left = child;
	else
		child->parent->right = child;
}

template <class T>
void RBTree<T>::singleRightRotate(RBNode<T>*& point) {
	RBNode<T>* parent = point;
	RBNode<T>* child = point->left;
	child->parent = parent->parent;
	parent->parent = child;
	parent->left = child->right;
	child->right = parent;
	if (parent->left != nullptr)
		parent->left->parent = parent;
	if (child->parent == nullptr)
		root = child;
	else if (child->parent->left = parent)
		child->parent->left = child;
	else
		child->parent->right = child;
}

template <class T>
void RBTree<T>::insert(const T& toInsert, RBNode<T>*& point) {
	insertHelper(toInsert, point);
	balanceTree(point);
	root = point;
	while (root->parent != nullptr) {
		root = root->parent;
	}
}

template <class T>
void RBTree<T>::balanceTree(RBNode<T>* point) {
	if (point->parent == nullptr)
		insertCase1(point);
	else if (point->parent->color == BLACK)
		insertCase2(point);
	else if (point->getUncle() != nullptr && point->getUncle()->color == RED)
		insertCase3(point);
	else
		insertCase4(point);
}

template <class T>
void RBTree<T>::insertCase4(RBNode<T>* point) {
	RBNode<T>* p = point->parent;
	RBNode<T>* g = p->parent;
	if (g->left == p) {
		if (p->right == point)
			doubleRightRotate(g);
		else
			singleRightRotate(g);
	}
	else {
		if (p->left == point)
			doubleLeftRotate(g);
		else
			singleLeftRotate(g);
	}
	p->color = BLACK;
	g->color = RED;
}

template <class T>
void RBTree<T>::insertCase3(RBNode<T>* point) {
	point->parent->color = BLACK;
	point->getUncle()->color = BLACK;
	point->parent->parent->color = RED;
	balanceTree(point->parent->parent);
}

template <class T>
void RBTree<T>::insertCase2(RBNode<T>* point) {
	return;
}

template <class T>
void RBTree<T>::insertCase1(RBNode<T>* point) {
	point->color = BLACK;
}

template <class T>
void RBTree<T>::insertHelper(const T& toInsert, RBNode<T>*& point) {
	if (point == nullptr)
		point = new RBNode<T>(toInsert);
	else if (toInsert < point->data) {
		insertHelper(toInsert, point->left);
		point->left->parent = point;
	}
	else {
		insertHelper(toInsert, point->right);
		point->right->parent = point;
	}
}

template <class T>
void RBTree<T>::insert(const T& toInsert) {
	insert(toInsert, root);
}

template <class T>
RBNode<T>* RBTree<T>::find(const T& toFind) const {
	RBNode<T>* target = root;
	while (target != nullptr) {
		if (toFind < target->data)
			target = target->left;
		else if (toFind > target->data)
			target = target->right;
		else
			return target;
	}
	return nullptr;
}

template <class T>
void RBTree<T>::clear() {
	if (!isEmpty())
		removeTree(root);
	root = nullptr;
}

template <class T>
void RBTree<T>::removeTree(RBNode<T>* point) {
	if (point->parent != nullptr) {
		if (point->parent->left == point)
			point->parent->left = nullptr;
		else
			point->parent->right = nullptr;
	}
	if (point->left != nullptr)
		removeTree(point->left);
	if (point->right != nullptr)
		removeTree(point->right);
	delete point;
}

template <class T>
RBNode<T>* RBTree<T>::recursiveCopy(RBNode<T>* toCopy) {
	if (toCopy == nullptr)
		return nullptr;
	RBTree<T>* temp = new RBTree<T>(toCopy->data, nullptr, recursiveCopy(toCopy->left), recursiveCopy(toCopy->right));
	if (temp->left != nullptr)
		temp->left->parent = temp;
	if (temp->right != nullptr)
		temp->right->parent = temp;
	return temp;
}

template <class T>
RBTree<T>& RBTree<T>::operator =(const RBTree<T>& rhs) {
	if (this == &rhs)
		return *this;
	clear();
	root = recursiveCopy(rhs.root);
	return *this;
}

template <class T>
void RBTree<T>::printLevelOrder() const {
	queue<RBNode<T>*> q;
	q.push(root);
	while (!q.empty()) {
		RBNode<T>* front = q.front();
		cout << front->data << "\t" << front->color << endl;
		if (front->left != nullptr)
			q.push(front->left);
		if (front->right)
			q.push(front->right);
		q.pop();
	}
}

int main() {
	//RBNode<int>* one = new RBNode<int>(1);

	RBTree<int> b;
	//b.insert(0);
	//b.insert(1);


	srand((unsigned int)time(NULL));
	for (int i = 0; i < 10; i++) {
		int val = rand() % 1000;
		b.insert(i);
	}
	cout << "finished inserting" << endl;
	b.printLevelOrder();
}


