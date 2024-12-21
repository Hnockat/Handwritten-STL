class List {
public:
    class Node {
	public:
		Node* next;
		int value = -1;
		Node(int value,Node* next) {
			this->next = next;
			this->value = value;
		}
	};
	void addFinst(int value) {
		head = new Node(value, head);
	}
	void echa_for() {
		Node* node = this->head;
		while(node != NULL) {
			cout << node->value<<endl;
			node = node->next;
		}
	}
	int get(int IT) {
		Node* node = findNode(IT);
		if (node == NULL) {
			throw NULL;
		}
		return node->value;

	}
	void addList(int value) {
		Node* end = Listfind();
		if (end == NULL) {
			addFinst(value);
			return;
		}
		end->next = new Node(value, NULL);
	}
	~List() { //释放资源
		this->freeList();
	}
private:
	Node* head = NULL;
	void freeList() {
		Node* node = head;
		while (node != NULL) {
			Node* temp = node;
			node = node->next;
			delete temp;
		}
		head = NULL;
	}
	Node* Listfind() {
		if (head == NULL) {
			return NULL;
		}
		Node* p;
		for (p = head; p->next != NULL;p = p->next) {
		}
		return p;
	}
	Node* findNode(int itor) {
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
