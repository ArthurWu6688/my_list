//
// Created by 93539 on 2023/5/31.
//

#ifndef LIST106_LIST_H
#define LIST106_LIST_H

namespace wyp {
    template<class T>
    struct list_node {
        list_node *_next;
        list_node *_prev;
        T _data;

        list_node(const T &x)
                : _next(nullptr), _prev(nullptr), _data(x) {

        }
    };

    template<class T>
    struct _list_iterator {
        typedef list_node<T> node;
        node *_p_node;

        _list_iterator(node *pn)
                : _p_node(pn) {

        }

        T &operator*() {
            return _p_node->_data;
        }

        _list_iterator<T> operator++() {
            _p_node = _p_node->_next;
            return *this;
        }

        bool operator!=(const _list_iterator<T> &it) {
            return _p_node != it._p_node;
        }
    };

    template<class T>
    class list {
        typedef list_node<T> node;
    public:
        typedef _list_iterator<T> iterator;

        iterator begin() {
            return iterator(_head->_next);
        }

        iterator end() {
            return iterator(_head);
        }

        list() {
            _head = new node(T());
            _head->_next = _head;
            _head->_prev = _head;
        }

        void push_back(T val) {
            node *new_node = new node(T());
            new_node->_data = val;
            node *tail = _head->_prev;

            new_node->_next = _head;
            new_node->_prev = tail;
            tail->_next = new_node;
            _head->_prev = new_node;
        }

    private:
        node *_head;
    };

}


#endif //LIST106_LIST_H
