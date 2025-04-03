#include <iostream>
#include <string>

class List {
    private:
        int memberCount;
        std::string *  member;
    public:
        List ();
        ~ List ();
        void getMember(std::string member);
        void addMember(std::string member);
};

void List::getMember(std::string member) {
    std::cout << member << std::endl;
}

int main() {
    std::cout << "Welcome To my To Do List" << std::endl;
    return 0;
}