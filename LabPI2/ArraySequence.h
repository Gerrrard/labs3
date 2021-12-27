#pragma once
#include "Sequence.h"
#include "DynamicArray.h"

template<class T>
class ArraySequence : public Sequence<T> {
private:
	DynamicArray<T>* data;
public:
	ArraySequence<T>() {
		data = new DynamicArray<T>;
	}
	ArraySequence<T>(T* entdata, int length) {
		data = new DynamicArray<T>(length);
		for (int i = 0; i < length; i++)
			data->Set(i, entdata[i]);
	}
	ArraySequence<T>(ArraySequence<T>& copy) {
		data = new DynamicArray<T>;
		data->Relen(copy.GetLength());
		data->Resize(copy.data->GetReservedL());

		for (int i = 0; i < copy.GetLength(); i++)
			data->Set(i, copy.Get(i));
	}
	ArraySequence<T>(int i) {
		data = new DynamicArray<T>(i);
	}

	T GetFirst() {
		return data->Get(0);
	}
	T GetLast() {
		return data->Get(data->GetLen() - 1);
	}
	T Get(int index) {
		assert(index >= 0);
		assert(index <= this->data->GetLen());
		return data->Get(index);
	}

	int GetLength() {
		return data->GetLen();
	}
	void Append(T value) {
		if (this->data->GetReservedL() - this->data->GetLen() == 0) {
			this->data->Resize(this->data->GetReservedL() + 2000);
		}
		this->data->Relen(this->data->GetLen() + 1);
		this->data->Set(this->data->GetLen() - 1, value);
	}
	void Prepend(T value) {
		if (this->data->GetReservedL() - this->data->GetLen() == 0) {
			this->data->Resize(this->data->GetReservedL() + 2000);
		}
		DynamicArray<T>* temp = new DynamicArray<T>(this->data->GetLen() + 1);
		temp->Set(0, value);

		for (int i = 1; i < temp->GetLen(); i++)
			temp->Set(i, this->data->Get(i - 1));

		data->Relen(data->GetLen() + 1);
		for (int i = 0; i < temp->GetLen(); i++)
			this->data->Set(i, temp->Get(i));
	}
	void Resize(int newl) {
		assert(newl >= 0);
		data->Resize(newl);
		data->Relen(newl);
	}
	void Set(int index, T value) {
		assert(index >= 0);
		assert(index <= this->GetLength());
		data->Set(index, value);
	}
	void InsertAt(T item, int index) {
		assert(index >= 0);
		assert(index <= this->GetLength());

		data->InsertAt(index, item);
	}
	ArraySequence<T>* Concat(Sequence<T>* dats) {
		ArraySequence<T>* dat = new ArraySequence<T>;
		for (int i = 0; i < this->GetLength(); i++) {
			dat->Append(this->Get(i));
		}

		for (int i = 0; i < dats->GetLength(); i++) {
			dat->Append(dats->Get(i));
			cout << "\n" << dat->GetLast() << "\n";
		}
		return dat;
	}
	ArraySequence<T>* GetSubsequence(int startIndex, int endIndex) {
		ArraySequence<T>* temp = new ArraySequence<T>;
		cout << "\n" << this->GetLength() << "\n";

		for (int i = startIndex; i <= endIndex; i++)
			temp->Append(this->Get(i));

		return temp;
	}
};