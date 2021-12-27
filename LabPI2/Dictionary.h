#pragma once
#include "IDictionary.h"
#include <vector>
#include <cassert>
#include "LinkedList.h"
#include "Person.h"

template<class T, class R>
class Pair {
public:
	T key;
	R value;

	Pair() {};
	Pair(T key, R value) {
		this->key = key;
		this->value = value;
	}

	bool operator==(Pair pair) {
		return key == pair.key && value == pair.value;
	}
	bool operator!=(Pair pair) {
		return key != pair.key || value != pair.value;
	}
	bool operator>(Pair pair) {
		return key > pair.key;
	}
	bool operator<(Pair pair) {
		return key < pair.key;
	}
	bool operator>=(Pair pair) {
		return key >= pair.key;
	}
	bool operator<=(Pair pair) {
		return key <= pair.key;
	}

	friend ostream& operator<<(ostream& out, const Pair& pair) {
		out << "key: ";
		out << pair.key;
		out << "; ";
		out << "value: ";
		out << pair.value;
		return out;
	}
};

template<class T, class R>
class Dictionary : public IDictionary<T, R> {
private:
	int Hashfunction(int elem) {
		if (elem % 2 == 0)
			return 0;
		if (elem % 2 != 0)
			return 1;
	}
	int Hashfunction(double elem) {
		if (elem > 10)
			return 1;
		else
			return 0;
	}
	int Hashfunction(char elem) {
		if (elem == 'a')
			return 1;
		else
			return 0;
	}
	int Hashfunction(Person elem) {
		if (elem.GetBirthDate() > 10)
			return 1;
		else
			return 0;
	}

	void Append(Pair<T, R> a) {
		int z = Hashfunction(a.key);
		if (z > data.size()) {
			R* temp = new R[1];
			temp[0] = a.value;
			LinkedList<R> n(temp, 1);

			T* temp1 = new T[1];
			temp1[0] = a.key;
			LinkedList<T> n1(temp1, 1);

			while (z > data.size()) {
				data.push_back(LinkedList<R>());
				keys.push_back(LinkedList<T>());
			}

			data.push_back(n);
			keys.push_back(n1);
		}
		else
			if (z == data.size()) {
				R* temp = new R[1];
				temp[0] = a.value;
				LinkedList<R> n(temp, 1);

				T* temp1 = new T[1];
				temp1[0] = a.key;
				LinkedList<T> n1(temp1, 1);

				data.push_back(n);
				keys.push_back(n1);
			}
			else
				if (z < data.size()) {
					data[z].Append(a.value);
					keys[z].Append(a.key);
				}
	}
public:
	vector<LinkedList<T>> keys;
	vector<LinkedList<R>> data;

	Dictionary() {}
	Dictionary(Pair<T, R>* a, int length) {
		for (int i = 0; i < length; i++) {
			Append(a[i]);
		}
	}
	Dictionary(Dictionary<T, R>& a) {
		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.data[i].GetLength(); j++) {
				Add(a.keys[i].Get(j), a.data[i].Get(j));
			}
		}
	}
	Dictionary(const Dictionary<T, R>& a) {
		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.data[i].GetLength(); j++) {
				Add(a.keys[i].Get(j), a.data[i].Get(j));
			}
		}
	}

	~Dictionary() {
		keys.clear();
		data.clear();
	}

	void Add(T key, R value) {
		Pair<T, R> a(key, value);
		Append(a);
	}
	size_t Count() {
		size_t x = 0;
		for (int i = 0; i < data.size(); i++) {
			if (data[i].GetLength() != 0) {
				x += data[i].GetLength();
			}
		}
		return x;
	}
	void Remove(T key) {
		assert(ContainsKey(key) != 0);
		int i = Hashfunction(key);

		for (int j = 0; j < keys[i].GetLength(); j++) {
			if (key == keys[i].Get(j)) {
				keys[i].DeleteKey(j);
				data[i].DeleteKey(j);
				return;
			}
		}
	}
	bool ContainsKey(T key) {
		int x = Hashfunction(key);
		if (x >= keys.size() || keys[x].GetLength() == 0) {
			return 0;
		}
		for (int i = 0; i < keys[x].GetLength(); i++) {
			if (keys[x].Get(i) == key)
				return 1;
		}
		return 0;
	}
	R GetVal(T key) {
		assert(ContainsKey(key) != 0);
		for (int i = 0; i < keys.size(); i++) {
			for (int j = 0; j < keys[i].GetLength(); j++) {
				if (keys[i].Get(j) == key) return data[i].Get(j);
			}
		}
	}
	void Print() {
		for (int i = 0; i < keys.size(); i++) {
			if (keys[i].GetLength() != 0)
				cout << "Hashcode = " << i << "\n";

			for (int j = 0; j < keys[i].GetLength(); j++) {
				cout << "Key " << keys[i].Get(j) << " ";
				cout << "Data " << data[i].Get(j) << "\n";
			}
		}
	}
};