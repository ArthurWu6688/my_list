#include <iostream>
#include <cassert>
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

void test_list2() {
    wyp::list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);

    lt.push_front(1);
    lt.push_front(2);
    lt.push_front(3);
    lt.push_front(4);
    lt.push_front(5);

    lt.pop_back();
    lt.pop_front();

    for (auto e: lt) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_list3() {
    wyp::list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    for (auto e: lt) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    wyp::list<int> lt1(lt);
    for (auto e: lt1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    lt1.clear();
    lt1 = lt;
    for (auto e: lt1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

void test_list4() {
    wyp::list<int> lt;
    lt.push_back(1);
    lt.push_back(2);
    lt.push_back(3);
    lt.push_back(4);
    lt.push_back(5);
    for (auto e: lt) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    wyp::list<int> lt1(lt);
    for (auto e: lt1) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    wyp::list<int> lt2;
    lt2 = lt;
    for (auto e: lt2) {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    std::cout << lt.size() << std::endl;
    std::cout << lt1.size() << std::endl;
    std::cout << lt2.size() << std::endl;
}

int main() {
    test_list4();

    return 0;
}
