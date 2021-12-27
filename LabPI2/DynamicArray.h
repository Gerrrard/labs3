#pragma once
#include <cassert>

template <class T>
class DynamicArray
{
    T* data;
    int length;
    int reservedlength;
public:
    DynamicArray() {
        data = new T[0];
        length = 0;
        reservedlength = 0;
    }
    DynamicArray(int l, T* get)
    {
        length = l;
        this->reservedlength = l;
        data = new T[length];

        for (int i = 0; i < length; i++) data[i] = get[i];
    }
    DynamicArray(int l) {
        length = l;
        reservedlength = l;
        data = new T[l];
    }
    DynamicArray(const DynamicArray<T>& obj)
    {
        length = obj.length;
        reservedlength = obj.reservedlength;
        data = new T[obj.length];

        for (int i = 0; i < obj.length; i++)
        {
            data[i] = obj.data[i];
        }
    }
    T Get(int index)
    {
        assert(index >= 0);
        assert(index < length);
        return data[index];
    }
    int GetLen()
    {
        return length;
    }
    int GetReservedL() {
        return reservedlength;
    }
    void Set(int index, T value)
    {
        assert(index >= 0);
        assert(index < length);

        data[index] = value;
    }
    void Resize(int NewSize) {
        assert(NewSize > 0);
        T* ndat = new T[NewSize];
        int temp = 0;

        if (NewSize >= reservedlength) {
            for (int i = 0; i < length; i++) ndat[i] = data[i];
            delete data;
            data = ndat;
            reservedlength = NewSize;
        }

        if (NewSize < reservedlength) {
            for (int i = 0; i < NewSize; i++) ndat[i] = data[i];
            delete data;
            data = ndat;
            reservedlength = NewSize;
        }

    }
    void Relen(int newlen) {
        assert(newlen > 0);
        length = newlen;
    }

    void InsertAt(int index, T value) {
        assert(index >= 0);
        assert(index <= this->GetLen());

        this->Resize(this->GetLen() + 1);
        this->Relen(this->GetLen() + 1);
        for (int i = this->GetLen() - 1; i > index; i--) {
            this->Set(i, this->Get(i - 1));
        }
        this->Set(index, value);
    }
};