#pragma once
#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <stdexcept>

class Array {
public:
    // типи
    typedef unsigned int UINT;
    typedef double value_type;
    typedef double* iterator;
    typedef const double* const_iterator;
    typedef double& reference;
    typedef const double& const_reference;
    typedef std::size_t size_type;

private:
    static const size_type minsize = 10; // мінімальний розмір масиву
    size_type Size; // виділено пам’яті для елементів
    size_type Count; // кількість елементів в масиві
    size_type First; // значення індексу першого елемента в масиві
    value_type* elems; // вказівник на дані

public:
    // конструктори/копіювання/деструктор
    Array(const size_type& n = minsize) throw(std::bad_alloc, std::invalid_argument);
    Array(const Array&) throw(std::bad_alloc);
    Array(const iterator first, const iterator last) throw(std::bad_alloc, std::invalid_argument);
    Array(const size_type first, const size_type last) throw(std::bad_alloc, std::invalid_argument);
    ~Array();
    Array& operator=(const Array&);

    // методи-модифікатори
    void push_back(const value_type& v); // добавити елемент в кінець
    void pop_back(); // видалити останній елемент – реалізувати самостійно
    void clear() { Count = 0; } // очистити масив
    void swap(Array& other); // поміняти з другим масивом
    void assign(const value_type& v); // заповнити масив – реалізувати самостійно

    void resize(size_type newsize) throw(std::bad_alloc);
    size_type capacity() const;
    static double* generateDynamicArray(int size);

    // дружні функції вводу/виводу
    friend std::ostream& operator<<(std::ostream& out, const Array& a);
    friend std::istream& operator>>(std::istream& in, Array& a);
};
