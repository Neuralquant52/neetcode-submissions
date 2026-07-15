struct Node {
    int val = 0;
    Node* tail = nullptr;
    Node* head = nullptr;   
};
class MyLinkedList {
public:
    Node* start = nullptr;
    Node* curr = nullptr;
    int size = 0;
    MyLinkedList() {
        
    }
    
    int get(int index) {
        if (index < 0 || index >= size) return -1;
        Node* iter = start;
        for (int i = 0; i < index; i++) iter = iter->tail;
        return iter->val;
    }
    
    void addAtHead(int val) {
        Node* new_node = new Node;
        new_node->val = val;
        if (size == 0){
            start = new_node;
            curr = new_node;
        } else {
            start->head = new_node;
            new_node->tail = start;
            start = new_node;
        }
        size++;
    }
    
    void addAtTail(int val) {
        Node* new_node = new Node;
        new_node->val = val;
        if (size == 0){
            start = new_node;
            curr = new_node;
        } else {
            curr->tail = new_node;
            new_node->head = curr;
            curr = new_node;
        }
        size++;
    }
        
    void addAtIndex(int index, int val) {
        if (index > size) return;
        if (index <= 0) { addAtHead(val); return; }
        if (index == size) { addAtTail(val); return; }

        Node* iter = start;
        Node* new_node = new Node;
        new_node->val = val;
        
        for (int i=0; i < index - 1; i++) iter = iter->tail;
        Node* next_node = iter->tail;
        new_node->tail = next_node;
        new_node->head = iter;

        if (next_node) next_node->head = new_node;
        iter->tail = new_node;
        size++;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= size) return;
        if (index == 0) {
            Node* temp = start;
            start = start->tail;
            if (start) start->head = nullptr;
            else curr = nullptr;
            delete temp;
        } else {
            Node* iter = start;
            for (int i=0; i < index; i++) iter = iter->tail;
            Node* prev_node = iter->head;
            Node* next_node = iter->tail;
            if (prev_node) prev_node->tail = next_node;
            if (next_node) next_node->head = prev_node;
            if (iter == curr) curr = prev_node;
            delete iter;
        }
        size--;
    }
};