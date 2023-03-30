#pragma once
#include <iostream>
#include <list>
#include <memory>
using namespace std;

class Counter
{
public:
    Counter()
        : m_counter(0) {};

    Counter(const Counter&) = delete;
    Counter& operator=(const Counter&) = delete;

    ~Counter() {}

    void reset()
    {
        m_counter = 0;
    }

    unsigned int get()
    {
        return m_counter;
    }

    void operator++()
    {
        m_counter++;
    }

    void operator++(int)
    {
        m_counter++;
    }

    void operator--()
    {
        m_counter--;
    }
    void operator--(int)
    {
        m_counter--;
    }

    friend ostream& operator<<(ostream& os,
        const Counter& counter)
    {
        os << "Wartosc licznika: " << counter.m_counter << "\n";
        return os;
    }

private:
    unsigned int m_counter{};
};


template <typename T>

class Shared_ptr
{
public:
    explicit Shared_ptr(T* ptr = nullptr)
    {
        m_ptr = ptr;
        m_counter = new Counter();
        (*m_counter)++;
    }

    Shared_ptr(Shared_ptr<T>& sp)
    {
        m_ptr = sp.m_ptr;
        m_counter = sp.m_counter;
        (*m_counter)++;
    }

    unsigned int use_count()
    {
        return m_counter->get();
    }

    T* get()
    {
        return m_ptr;
    }

    T& operator*()
    {
        return *m_ptr;
    }

    T* operator->()
    {
        return m_ptr;
    }

    ~Shared_ptr()
    {
        (*m_counter)--;
        if (m_counter->get() == 0)
        {
            delete m_counter;
            delete m_ptr;
        }
    }

    friend ostream& operator<<(ostream& os,
        Shared_ptr<T>& wsk)
    {
        os << "Adres : " << wsk.get() << endl;
        os << *(wsk.m_counter) << endl;
        return os;
    }

private:
    Counter* m_counter;

    T* m_ptr;
};