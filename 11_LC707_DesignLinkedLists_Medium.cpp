class MyLinkedList {
public:
    struct Node {
        int val;
        Node* next;
        Node(int x) {
            val = x;
            next = nullptr;
        }
    };

    Node* head;

    MyLinkedList() {
        head = nullptr;
    }

    int get(int index) {
        Node* curr = head;
        int i = 0;

        while (curr != nullptr) {
            if (i == index)
                return curr->val;

            curr = curr->next;
            i++;
        }

        return -1;
    }

    void addAtHead(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    void addAtTail(int val) {
        Node* newNode = new Node(val);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* curr = head;
        while (curr->next != nullptr) {
            curr = curr->next;
        }

        curr->next = newNode;
    }

    void addAtIndex(int index, int val) {
        if (index == 0) {
            addAtHead(val);
            return;
        }

        Node* curr = head;
        int i = 0;

        while (curr != nullptr && i < index - 1) {
            curr = curr->next;
            i++;
        }

        if (curr == nullptr)
            return;

        Node* newNode = new Node(val);
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void deleteAtIndex(int index) {
        if (head == nullptr)
            return;

        if (index == 0) {
            head = head->next;
            return;
        }

        Node* curr = head;
        int i = 0;

        while (curr->next != nullptr && i < index - 1) {
            curr = curr->next;
            i++;
        }

        if (curr->next == nullptr)
            return;

        curr->next = curr->next->next;
    }
};
