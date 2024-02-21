#include <iostream>
#include <algorithm>
#define FOR(i, e) for(int i=0 ; i<e ; ++i)
using namespace std;

// 1. vector: List 구현
template <typename T> class List
{
private:
    T* container;
    size_t capacity;
    size_t size;

    void UpdateCapacity(size_t newCapacity)
    {
        T* newContainer = new T[newCapacity];

        for(size_t i = 0; i < size; ++i)
        {
            newContainer[i] = container[i];
        }

        capacity = newCapacity;
        delete[] container;

        container = newContainer;
        cout << "cop: "<< capacity << '\n';
    }

public:
    List() : container(nullptr), capacity(0), size(0) {}
    ~List() { delete[] container; }

    int Size()
    {
        return size;
    }

    void Add(T element)
    {
        if(size >= capacity) UpdateCapacity(capacity == 0 ? 1 : capacity * 2 );
        container[size] = element;
        size++;
    }

    T& operator[](size_t index) 
    {
        return container[index];
    }
};

struct A
{
    int a;
    double b;
};

int main()
{
    List<int> list;

    for(int i=0 ; i<100 ; ++i)
    {
        list.Add(i);
    }


    for(int i=0 ; i<list.Size() ; ++i) cout << list[i] << '\n';

    return 0;
}