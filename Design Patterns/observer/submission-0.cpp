class Observer {
public:
    virtual void notify(string& itemName) = 0;
};

class Customer : public Observer {
private:
    string name;
    int notifications;

public:
    Customer(string& name) : name(name), notifications(0) {}

    void notify(string& itemName) override {
        notifications += 1;
    }

    int countNotifications() {
        return notifications;
    }
};

class OnlineStoreItem {
private:
    string itemName;
    int stock;
    std::vector<Observer*> observers;
public:
    OnlineStoreItem(string& itemName, int stock) : itemName(itemName), stock(stock) {}

    void subscribe(Observer* observer) {
        observers.push_back(observer);
    }

    void unsubscribe(Observer* observer) {
        for (int i{0}; i < observers.size(); i++){
            if (observers[i] == observer){
                observers.erase(observers.begin() + i);
            }
        }
    }

    void updateStock(int newStock) {
        if (stock == 0 && newStock > 0){
            for (auto x : observers){
                x->notify(itemName);
            }
        }
        this->stock = newStock;
    }
};
