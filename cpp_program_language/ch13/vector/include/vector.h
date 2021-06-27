//
// Created by gang cheng on 2021/6/3.
//

#ifndef SIMPLE_VECTOR_VECTOR_H
#define SIMPLE_VECTOR_VECTOR_H

#include <memory>

template<class T, class A = std::allocator<T>>
class vector {
private:
    T *elem;
    T *space;
    T *last;
    A alloc;

public:
    using size_type = unsigned int;

    explicit vector(size_type n, const T &val = T(), const A &a = A())
            : alloc{a} {
        elem = alloc.allocate(n);
        space = last = elem + n;
        for (T *p = elem; p != last; ++p)
            alloc.construct(p, val);
    }
//    vector(const vector& a);
//    vector& operator=(const vector& a);
//
//    vector(vector&& a);
//    vector& operator=(vector&& a);

//    ~vector();

    size_type size() const { return space - elem; }

    size_type capacity() const { return last - elem; }
//    void reserve(size_type n);
//
//    void resize(size_type n, const T& = {});
//    void push_back(const T&);
};

#endif //SIMPLE_VECTOR_VECTOR_H
