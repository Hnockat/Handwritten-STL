#include <iostream>
using namespace std;
class List {
public:
    class Node { //内部实现类
	public:
		Node* next = NULL;
		int value = 0;
		Node(int value,Node* next) {
			this->next = next;
			this->value = value;
		}
	};
	void addFinst(int value) { //头插入
		head = new Node(value, head);
	}
	void echa_for() { //遍历输出器
		Node* node = this->head;
		while(node != NULL) {
			cout << node->value<<endl;
			node = node->next;
		}
	}
	int get(int IT) {//通过索引找到元素
		Node* node = findNode(IT);
		if (node == NULL) {
			throw NULL;
		}
		return node->value;

	}
	void addList(int value) { //线性插入
		Node* end = Listfind();
		if (end == NULL) {
			addFinst(value);
			return;
		}
		end->next = new Node(value, NULL);
	}
	bool remove(int IT) { //删除指定索引 从 0 开始
		if (head == NULL) {
			return false;
		}
		if (IT == 0) {
			Node* nextNode = head->next;
			delete head;
			head = nextNode;
			return true;
		}
		Node* finds = findNode(IT - 1);
		if (finds == NULL) {
			return false;
		}
		if (finds->next == NULL) {
			return false;
		}
		Node* aimNode = finds->next;
		finds->next = aimNode->next;
		delete aimNode;
		return true;	
	}

	~List() { //释放资源
		this->freeList();
	}
private:
	Node* head = NULL;
	void freeList() { //释放内存
		Node* node = head;
		while (node != NULL) {
			Node* temp = node;
			node = node->next;
			delete temp;
		}
		head = NULL;
	}
	Node* Listfind() { //查找尾节点
		if (head == NULL) {
			return NULL;
		}
		Node* p;
		for (p = head; p->next != NULL;p = p->next) {
		}
		return p;
	}
	Node* findNode(int itor) { //查找指定索引节点
		Node* p = head;
		if (p == NULL) {
			return NULL;
		}
		int i = 0;
		for (; p != NULL; p = p->next,i++) {
			if (i == itor) {
				return p;
			}
		}
		return NULL;
	}
};
