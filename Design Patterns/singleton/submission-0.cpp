class Singleton {
private:
    
    std::string value;
    Singleton() {}

public:

    static Singleton *getInstance() {
        static Singleton Instance;
        return &Instance;
    }

    string getValue() {
        return value;
    }

    void setValue(string &value) {
        this->value = value;
    }
};
