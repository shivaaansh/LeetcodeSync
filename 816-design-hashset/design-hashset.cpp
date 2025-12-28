struct Node {
    int val;
    Node* next;
    Node(int v) : val(v), next(NULL) {}
};

class MyHashSet {
public:
    static const int SIZE = 1000;
    Node* arr[SIZE];

    MyHashSet() {
        for (int i = 0; i < SIZE; i++)
            arr[i] = NULL;
    }

    void add(int key) {
        int hash = key % SIZE;
        Node* it = arr[hash];

        // check duplicate
        while (it) {
            if (it->val == key) return;
            it = it->next;
        }

        // insert at head
        Node* node = new Node(key);
        node->next = arr[hash];
        arr[hash] = node;
    }

    void remove(int key) {
        int hash = key % SIZE;
        Node* it = arr[hash];
        Node* prev = NULL;

        while (it) {
            if (it->val == key) {
                if (prev) prev->next = it->next;
                else arr[hash] = it->next;
                delete it;
                return;
            }
            prev = it;
            it = it->next;
        }
    }

    bool contains(int key) {
        int hash = key % SIZE;
        Node* it = arr[hash];
        while (it) {
            if (it->val == key) return true;
            it = it->next;
        }
        return false;
    }
};
