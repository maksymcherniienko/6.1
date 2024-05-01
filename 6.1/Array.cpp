#include "Array.h"
using namespace std;
Array::Array(const size_type& n) throw(std::bad_alloc, std::invalid_argument) {
    if (n < minsize)
        throw std::invalid_argument("Array size cannot be less than minsize");

    Size = n;
    Count = 0;
    First = 0;
    elems = new value_type[Size];
    for (size_type i = 0; i < Size; ++i)
        elems[i] = 0;
}

Array::Array(const iterator first, const iterator last) throw(std::bad_alloc, std::invalid_argument) {
    size_type n = last - first + 1;
    if (n < minsize)
        throw std::invalid_argument("Array size cannot be less than minsize");

    Size = n;
    Count = 0;
    First = 0;
    elems = new value_type[Size];
    for (size_type i = 0; i < Size; ++i)
        elems[i] = 0;
    for (size_type i = 0; i < n; ++i)
        elems[i] = *(first + i);
}

Array::Array(const size_type first, const size_type last) throw(std::bad_alloc, std::invalid_argument) {
    size_type n = last - first + 1;
    if (n < minsize)
        throw std::invalid_argument("Array size cannot be less than minsize");

    Size = n;
    Count = 0;
    First = first;
    elems = new value_type[Size];
    for (size_type i = 0; i < Size; ++i)
        elems[i] = 0;
}

Array::Array(const Array& other) throw(std::bad_alloc)
    : Size(other.Size), Count(other.Count), First(other.First), elems(new value_type[other.Size]) {
    for (size_type i = 0; i < Size; ++i)
        elems[i] = other.elems[i];
}

Array::~Array() {
    delete[] elems;
}

Array& Array::operator=(const Array& other) {
    if (this != &other) {
        Array temp(other);
        swap(temp);
    }
    return *this;
}

// реалізація розширеного методу для генерації динамічного масиву
double* Array::generateDynamicArray(int size) {
    srand(time(nullptr));

    double* dynamicArray = new double[size];

    // Заповнюємо масив випадковими числами в діапазоні від -50 до 50
    for (int i = 0; i < size; ++i) {
        dynamicArray[i] = -60 + rand() % 101; // отримуємо випадкове число від -50 до 50
    }

    // Знаходимо пів-суму першого від'ємного числа та 50-го числа
    double sum = 0.0;
    int negativeIndex = -1;
    for (int i = 0; i < size; ++i) {
        sum += dynamicArray[i];
        if (dynamicArray[i] < 0 && negativeIndex == -1) {
            negativeIndex = i;
        }
    }
    if (negativeIndex == -1) {
        // Якщо в масиві немає від'ємних чисел
        delete[] dynamicArray;
        return nullptr;
    }
    double halfSum = sum / 2.0;

    // Розділяємо кожне число на пів-суму
    for (int i = 0; i < size; ++i) {
        dynamicArray[i] /= halfSum;
    }

    // Повертаємо новий динамічний масив
    return dynamicArray;
}

#include "Array.h"
#include <algorithm> // Для функції std::swap


void Array::pop_back() {
    if (Count > 0) {
        --Count; // Зменшити лічильник елементів
    }
}

void Array::swap(Array& other) {
    std::swap(elems, other.elems); // Поміняти вказівники на дані
    std::swap(Size, other.Size);   // Поміняти розміри масивів
    std::swap(Count, other.Count); // Поміняти лічильники елементів
    std::swap(First, other.First); // Поміняти значення індексу першого елемента
}

void Array::assign(const value_type& v) {
    for (size_type i = 0; i < Size; ++i) {
        elems[i] = v; // Присвоїти кожному елементу вказане значення
    }
}

Array::size_type Array::capacity() const {
    return Size;
}

void Array::resize(size_type newsize) throw(std::bad_alloc) {
    if (newsize > capacity()) {
        value_type* data = new value_type[newsize];
        for (size_type i = 0; i < Count; ++i)
            data[i] = elems[i];
        delete[] elems;
        elems = data;
        Size = newsize;
    }
}

void Array::push_back(const value_type& v) {
    if (Count == Size) {
        resize(Size * 2); // Збільшити розмір масиву, якщо він переповнений
    }
    elems[Count++] = v; // Додати елемент у кінець масиву та збільшити лічильник
}

std::ostream& operator<<(std::ostream& out, const Array& a) {
    for (Array::size_type i = 0; i < a.Count; ++i) {
        out << a.elems[i] << " ";
    }
    return out;
}

std::istream& operator>>(std::istream& in, Array& a) {
    for (Array::size_type i = 0; i < a.Count; ++i) {
        in >> a.elems[i];
    }
    return in;
}
