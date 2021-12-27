#pragma once

template<typename T>
class ISet {
public:
    virtual ISet<T>* Union(ISet<T>* set) = 0;
    virtual ISet<T>* Intersection(ISet<T>* set) = 0;
    virtual ISet<T>* Substraction(ISet<T>* set) = 0;

    virtual bool IsEqual(ISet<T>*) = 0;
    virtual void Add(T) = 0;
    virtual void Delete(T) = 0;
    virtual bool Contains(T) = 0;
};