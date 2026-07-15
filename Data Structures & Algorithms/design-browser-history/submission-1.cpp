struct Node{
    string last_search;
    Node* last = nullptr;
    Node* next = nullptr;
};


class BrowserHistory {
public:
    Node* base = new Node;
    int size = 0;
    int current_step = 0;

    BrowserHistory(string homepage) {
        base->last_search = homepage;
    }
    
    void visit(string url) {
        Node* new_node = new Node; // create new node
        new_node->last_search = url; // new node url
        new_node->next = nullptr;

        new_node->last = base;
        base->next = new_node;
        base = base->next;
        current_step++;
        size++;
        std::cerr << "visit made" << endl;
    }
    
    string back(int steps) {
        if ((current_step - steps) <= 0){
            while(base->last != nullptr){
                base = base->last;
                current_step--;
            }
        } else {
            for(int i{0}; i < steps; i++) {
                base = base->last;
                current_step--;
            }
        }
        std::cerr << "backing made" << endl;
        return base->last_search;
    }

    string forward(int steps) {
        if ((current_step + steps) >= size){
            while(base->next != nullptr){
                base = base->next;
                current_step++;
            }
        } else{
            for (int i{0}; i < steps; i++) {
                base = base->next;
                current_step++;
            }
        }
        std::cerr << "forward made" << endl;
        return base->last_search;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */