#pragma once
using namespace std;

template<class T>
class Sequence {
public:
    Sequence() {};
    Sequence(T* data, int length);
    Sequence(const Sequence& a);

    virtual T GetFirst() = 0;
    virtual T GetLast() = 0;
    virtual T Get(int index) = 0;

    virtual int GetLength() = 0;

    virtual void Append(T item) = 0;
    virtual void Prepend(T item) = 0;
    virtual void InsertAt(T item, int index) = 0;

    virtual void Resize(int newl) = 0;
    virtual void Set(int index, T value) = 0;

    virtual Sequence <T>* Concat(Sequence <T>* list) = 0;
    virtual Sequence<T>* GetSubsequence(int startIndex, int endIndex) = 0;
    ~Sequence() {};
};