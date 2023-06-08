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

    template<class T, class Ref, class Ptr>
    struct _list_iterator {
        typedef list_node<T> node;
        typedef _list_iterator<T, Ref, Ptr> self;
        node *_p_node;

        _list_iterator(node *pn)
                : _p_node(pn) {

        }

        Ref operator*() {
            return _p_node->_data;
        }

        self &operator++() {
            _p_node = _p_node->_next;
            return *this;
        }

        self operator++(int) {
            self tmp(*this);
            _p_node = _p_node->_next;
            return tmp;
        }

        self &operator--() {
            _p_node = _p_node->_prev;
            return *this;
        }

        self operator--(int) {
            self tmp(*this);
            _p_node = _p_node->_prev;
            return tmp;
        }

        Ptr operator->() {
            return &_p_node->_data;
        }

        bool operator!=(const self &it) const {
            return _p_node != it._p_node;
        }

        bool operator==(const self &it) const {
            return _p_node == it._p_node;
        }
    };

#if 0
    const迭代器普通写法
    template<class T>
    struct _list_const_iterator {
        typedef list_node<T> const_node;
        const_node *p_const_node;

        _list_const_iterator(const_node *pcn)
                : p_const_node(pcn) {

        }

        const T &operator*() {
            return p_const_node->_data;
        }

        _list_const_iterator<T> &operator++() {
            p_const_node = p_const_node->_next;
            return *this;
        }

        _list_const_iterator<T> &operator--(){
            p_const_node = p_const_node->_prev;
            return *this;
        }

        bool operator!=(const _list_const_iterator<T> lt) {
            return p_const_node != lt.p_const_node;
        }
    };

#endif

    template<class T>
    class list {
        typedef list_node<T> node;
    public:
        typedef _list_iterator<T, T &, T *> iterator;
        typedef _list_iterator<T, const T &, const T *> const_iterator;

        iterator begin() {
            return iterator(_head->_next);
        }

        iterator end() {
            return iterator(_head);
        }

        const_iterator begin() const {
            return const_iterator(_head->_next);
        }

        const_iterator end() const {
            return const_iterator(_head);
        }

        void push_back(const T val) {
//            node *new_node = new node(T());
//            new_node->_data = val;
//            node *tail = _head->_prev;
//
//            new_node->_next = _head;
//            new_node->_prev = tail;
//            tail->_next = new_node;
//            _head->_prev = new_node;

            insert(end(), val);
        }

        void push_front(const T val) {
            insert(begin(), val);
        }

        void pop_front() {
            erase(begin());
        }

        void pop_back() {
            erase(--end());
        }

        iterator insert(iterator pos, const T &val) {
            node *new_node = new node(val);
            node *cur = pos._p_node;
            node *prev = cur->_prev;

            new_node->_next = cur;
            new_node->_prev = prev;
            prev->_next = new_node;
            cur->_prev = new_node;

            ++_size;

            return iterator(new_node);
        }

        iterator erase(iterator pos) {
            assert(pos != end());

            node *prev = pos._p_node->_prev;
            node *next = pos._p_node->_next;

            prev->_next = next;
            next->_prev = prev;

            delete pos._p_node;

            --_size;

            return iterator(next);
        }

        void clear() {
            iterator it = begin();
            while (it != end()) {
                it = erase(it);
            }
        }

        size_t size() const {
            return _size;
        }

        bool empty() const {
            return _head->_next == _head;
        }

#if 0
        深拷贝传统写法
        list() {
            empty_initialize();
        }

        list(const list<T> &lt) {
            empty_initialize();

            for (const auto &e: lt) {
                push_back(e);
            }
        }

        list<T> &operator=(const list<T> &lt) {
            if (this != &lt) {
                clear();
                for (const auto &e: lt) {
                    push_back(e);
                }
            }
            return *this;
        }

#endif

        void empty_initialize() {
            _head = new node(T());
            _head->_next = _head;
            _head->_prev = _head;
        }

        void swap(list<T> &lt) {
            std::swap(_head, lt._head);
            std::swap(_size, lt._size);
        }

        template<class InputIterator>
        list(InputIterator first, InputIterator last) {
            empty_initialize();
            while (first != last) {
                push_back(*first);
                ++first;
            }
        }

        list() {
            empty_initialize();
        }

        list(const list<T> &lt) {
            empty_initialize();
            list<T> tmp(lt.begin(), lt.end());
            swap(tmp);
        }

        list<T> &operator=(list<T> lt) {
            swap(lt);
            return *this;
        }

        ~list() {
            clear();
            delete _head;
            _head = nullptr;
        }

    private:
        node *_head;
        size_t _size;
    };

}


#endif //LIST106_LIST_H
