//
// Created by 93539 on 2023/6/28.
//

#ifndef LIST106_REVERSE_ITERATOR_H
#define LIST106_REVERSE_ITERATOR_H

namespace wyp {
    template<class Iterator, class Ref, class Ptr>
    class _reverse_iterator {
        typedef _reverse_iterator<Iterator, Ref, Ptr> Self;
    public:
        _reverse_iterator(Iterator it)
                : _it(it) {

        }

        Self &operator++() {
            --_it;
            return *this;
        }

        Self &operator--() {
            ++_it;
            return *this;
        }

        bool operator!=(const Self &s) const {
            return _it != s._it;
        }

        Ref operator*() {
            Iterator tmp = _it;
            return *(--_it);
        }

        Ptr operator->() {
            return &(*_it);
        }

    private:
        Iterator _it;
    };

} // wyp

#endif //LIST106_REVERSE_ITERATOR_H
