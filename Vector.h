#pragma once
template <typename T>
class Vector
{

    T* tab;
    int capacity;
    int ilosc_el;

public:

    Vector()
    {
        tab = new T[1];
        capacity = 1;
        ilosc_el = 0;
    }

    ~Vector()
    {
        delete[] tab;
    }

    void push(T data)
    {
        if (ilosc_el == capacity) {
            T* nowa_tab = new T[2 * capacity];

            for (int i = 0; i < capacity; i++) {
                nowa_tab[i] = tab[i];
            }

            delete[] tab;
            capacity *= 2;
            tab = nowa_tab;
        }

        tab[ilosc_el] = data;
        ilosc_el++;
    }

    void push(T data, int index)
    {

        if (index == capacity)
            push(data);
        else
            tab[index] = data;
    }

    T get(int index)
    {
        if (index < ilosc_el)
            return tab[index];
    }

    T* begin()
    {
        return tab;
    }

    T* end()
    {
        return tab+ilosc_el;
    }
    void pop()
    {
        ilosc_el--;
    }

    void erase(int index)
    {
        for (int i = index; i < (ilosc_el - 1); i++)
        {
            tab[i] = tab[i + 1];
        }
        ilosc_el--;
    }

    int size()
    {
        return ilosc_el;
    }

}; 
