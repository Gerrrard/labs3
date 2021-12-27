#pragma once
#include "ISet.h"
#include "HashTable.h"

template<class T>
class Set : public ISet<T> {
private:
	HashTable<T> a;
public:
	Set() {}
	Set(T* data, int length) {
		for (int i = 0; i < length; i++)
			a.Append(data[i]);
	}

	Set<T>* Union(ISet<T>* s) {
		Set<T>* Uni = new Set<T>();
		Uni->a = this->a;
		for (int i = 0; i < ((Set<T>*)s)->a.l.size(); i++) {
			for (int j = 0; j < ((Set<T>*)s)->a.l[i].GetLength(); j++) {
				if (a.find(((Set<T>*)s)->a.l[i].Get(j)) == 0)
					Uni->a.Append(((Set<T>*)s)->a.l[i].Get(j));
			}
		}
		return Uni;
	}
	Set<T>* Intersection(ISet<T>* s) {
		Set<T>* Uni = new Set<T>();

		for (int i = 0; i < ((Set<T>*)s)->a.l.size(); i++) {
			for (int j = 0; j < ((Set<T>*)s)->a.l[i].GetLength(); j++) {
				if (a.find(((Set<T>*)s)->a.l[i].Get(j))) {
					Uni->Add(a.l[i].Get(j));
				}
			}
		}
		return Uni;
	}
	Set<T>* Substraction(ISet<T>* s) {
		Set<T>* Uni = new Set<T>();
		Uni->a = this->a;

		for (int i = 0; i < ((Set<T>*)s)->a.l.size(); i++) {
			for (int j = 0; j < ((Set<T>*)s)->a.l[i].GetLength(); j++) {
				if (a.find(((Set<T>*)s)->a.l[i].Get(j)) == 1) {
					Uni->a.remove(((Set<T>*)s)->a.l[i].Get(j));
				}
			}
		}
		return Uni;
	}

	bool IsEqual(ISet<T>* s) {
		if (this->a.l.size() != ((Set<T>*)s)->a.l.size())
			return 0;

		for (int i = 0; i < ((Set<T>*)s)->a.l.size(); i++) {
			if (this->a.l[i].GetLength() != ((Set<T>*)s)->a.l[i].GetLength())
				return 0;

			for (int j = 0; j < ((Set<T>*)s)->a.l[i].GetLength(); j++) {
				if (a.find(((Set<T>*)s)->a.l[i].Get(j)) == 0)
					return 0;
			}
		}
		return 1;
	}
	void Add(T dat) {
		a.Append(dat);
	}
	void Delete(T dat) {
		a.remove(dat);
	}
	bool Contains(T dat) {
		if (a.find(dat) == 1)
			return 1;
		else
			return 0;
	}
	void SetPrint() {
		a.Print();
	}
	int Count() {
		return a.Count();
	}
};