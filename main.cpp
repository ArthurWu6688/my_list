#include <iostream>
#include "list.h"

void test_list1() {
    wyp::list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    lt.push_back(6);

    wyp::list<int>::iterator it = lt.begin();
    while (it != lt.end()) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;

    for (auto e: lt) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

int main() {
    test_list1();

    return 0;
}
