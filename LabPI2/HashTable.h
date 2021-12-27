#pragma once
#include "LinkedList.h"

template<class T> class HashTable {
private:
	int Hashfunction(T elem) {
		return elem + 1;
	}
public:
	vector<LinkedList<T>> l;

	HashTable() {}
	HashTable(T* a, int length) {
		for (int i = 0; i < length; i++) {
			Append(a[i]);
		}
	}
	HashTable(const HashTable<T>& a) {
		l = a.l;
	}
	void Append(T a) {
		int z = Hashfunction(a);
		if (z > l.size()) {
			T* temp1 = new T[1];
			temp1[0] = a;
			LinkedList<T> n1(temp1, 1);

			while (z > l.size()) {
				l.push_back(LinkedList<T>());
			};

			l.push_back(n1);
		}
		else
			if (z == l.size()) {
				T* temp1 = new T[1];
				temp1[0] = a;
				LinkedList<T> n1(temp1, 1);
				l.push_back(n1);
			}
			else
				if (z < l.size()) {
					l[z].Append(a);
				}
	}
	void remove(T data) {
		assert(find(data) != 0);
		int z = Hashfunction(data);

		for (int i = 0; i < l[z].GetLength(); i++)
			if (l[z].Get(i) == data)
				l[z].DeleteKey(i);
	}
	bool find(T data) {
		int z = Hashfunction(data);
		if (z <= l.size())
			return l[z].Find(data);
		else
			return 0;
	}
	void Print() {
		for (int i = 0; i < l.size(); i++)
			for (int j = 0; j < l[i].GetLength(); j++)
				cout << "Key " << i << " Data " << l[i].Get(j) << "\n";
	}
	int Count() {
		int y = 0;
		for (int i = 0; i < l.size(); i++) {
			for (int j = 0; j < l[i].GetLength(); j++) {
				y++;
			}
		}
		return y;
	}
};