class Person {
private:
    string lastName;
    int age;
    bool married;

public:
    Person(string lastName, int age, bool married) 
        : lastName(lastName), age(age), married(married) {}

    string getLastName() {
        return lastName;
    }

    int getAge() {
        return age;
    }

    bool isMarried() {
        return married;
    }
};

class PersonFilter {
public:
    virtual ~PersonFilter() {}
    virtual bool apply(Person& person) = 0;
};

class AdultFilter : public PersonFilter {
    bool apply(Person& person) override {
        if (int age = person.getAge() ; age >= 18) return true;
        else return false;
    }
    // Implement Adult filter
};

class SeniorFilter : public PersonFilter {
    bool apply(Person& person) override {
        if (int age = person.getAge(); age >= 65) return true;
        else return false;
    }
    // Implement Senior filter
};

class MarriedFilter : public PersonFilter {
    bool apply(Person& person) override {
        if (bool married = person.isMarried(); married) return true;
        else return false;
    }
    // Implement Married filter
};

class PeopleCounter {
private:
    PersonFilter* filter;

public:
    void setFilter(PersonFilter& filter) {
        this->filter = &filter;
    }

    int count(vector<Person>& people) {
        int count = 0;
        for (Person i : people){
            if (filter->apply(i)) count++;
        }
        return count;
        // Implement method here
    }
};
