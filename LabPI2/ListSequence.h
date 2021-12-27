#pragma once
#include "Sequence.h"
#include "LinkedList.h"

template<class T>
class ListSequence : public Sequence<T>{
private:
	LinkedList<T>* list;
public:
	ListSequence() {
		list = new LinkedList<T>;
	}
	ListSequence(T* data, int x) {
		list = new LinkedList<T>;
		for (int i = 0; i < x; i++) {
			list->Append(data[i]);
		}
	}
	ListSequence(int x) {
		list = new LinkedList<T>(x);
	}
	ListSequence(ListSequence<T>& copy) {
		list = new LinkedList<T>;
		for (int i = 0; i < copy.GetLength(); i++) {
			list->Append(copy.Get(i));
		}
	}

	T GetFirst() {
		return list->GetFirst();
	}
	T GetLast() {
		return list->GetLast();
	}
	T Get(int x) {
		assert(x <= this->GetLength());
		return list->Get(x);
	}
	int GetLength() {
		return list->GetLength();
	}

	void Resize(int x) {
		list->Resize(x);
	}
	void Set(int index, T value) {
		assert(index <= this->GetLength());
		list->Set(index, value);
	}
	void Append(T value) {
		list->Append(value);
	}
	void Prepend(T value) {
		list->Prepend(value);
	}
	void InsertAt(T value, int count) {
		list->InsertAt(count, value);
	}

	ListSequence<T>* GetSubsequence(int startIndex, int endIndex) {
		assert(startIndex >= 0);
		assert(startIndex < this->GetLength());
		assert(endIndex >= 0);
		assert(endIndex <= this->GetLength());

		ListSequence<T>* temp = new ListSequence<T>;
		for (int i = startIndex; i < endIndex; i++) {
			temp->Append(this->Get(i));
		}
		return temp;
	}
	ListSequence<T>* Concat(Sequence<T>* data) {
		ListSequence<T>* res = new ListSequence<T>;
		for (int i = 0; i < this->GetLength(); i++) {
			res->Append(this->Get(i));
		}
		for (int i = 0; i < data->GetLength(); i++) {
			res->Append(data->Get(i));
		}

		return res;
	}
	void Remove(int i) {
		list.DeleteKey(i);
	}
};