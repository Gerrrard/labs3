#pragma once
template<typename T>
class Item{
public:
	T data;
	Item<T>* next;
	Item<T>* previous;

	Item() {
		next = NULL;
		previous = NULL;
	}
	Item(T value) {
		this->data = value;
	}
};

template<class T>
class LinkedList {
private:
	Item<T>* head;
	Item<T>* tail;
	int length;

	Item<T>* GetNode(int index) {
		if (index == 0) return head;
		if (index == length - 1) return tail;
		Item<T>* temp = head;

		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp;
	}
public:
	LinkedList() {
		head = NULL;
		tail = NULL;
		length = 0;
	}
	LinkedList(T* data, int count) {
		head = NULL;
		tail = NULL;
		length = 0;

		for (int i = 0; i < count; i++) {
			Append(data[i]);
		}
	}

	~LinkedList() {
		head = NULL;
		tail = NULL;
		length = 0;

		delete head;
		delete tail;
	}

	void Append(T value) {
		if (head == NULL) {
			head = new Item<T>; head->data = value; tail = head; length++;
		}
		else
		{
			Item<T>* temp = new Item<T>;
			temp->data = value;

			tail->next = temp;
			tail = temp;
			length++;
		}
	}
	bool Find(T value) {
		Item<T>* temp = head;
		for (int i = 0; i < length; i++) {
			if (value != temp->data)
				temp = temp->next;
			else {
				return 1;
			}
		}
		return 0;
	}
	void Prepend(T value) {
		Item<T>* buf = new Item<T>;
		buf->data = value;
		if (head != NULL) {
			head->previous = buf;
			buf->next = head;
			head = buf;
			length++;
		}
		if (head == NULL) {
			head = buf;
			head->previous = NULL;
			tail = head;
			length++;
		}
	}
	void InsertAt(int index, T value) {
		assert(index >= 0);
		assert(index <= this->GetLength());
		if (index == 0) {
			this->Prepend(value);
		}
		if (index == this->GetLength()) {
			this->Append(value);
		}
		if (index != 0 && index != this->GetLength()) {
			Item<T>* temp = head;
			for (int i = 0; i < index - 1; i++) temp = temp->next;

			Item<T>* buf = new Item<T>;

			buf->data = value;
			buf->next = temp->next;
			temp->next = buf;
			this->length++;
		}
	}
	void Resize(int x) {
		this->length = x;
	}

	T GetFirst() {
		return head->data;
	}
	T Get(int index) const {
		assert(index >= 0);
		assert(index <= this->GetLength());
		Item<T>* temp = head;

		for (int i = 0; i < index; i++) {
			temp = temp->next;
		}
		return temp->data;
	}
	T GetLast() {
		return tail->data;
	}
	int GetLength()const {
		return length;
	}
	void Set(int index, T value) {
		assert(index >= 0);
		assert(index <= this->GetLength());

		Item<T>* buf = head;
		for (int i = 0; i < index; i++)
			buf = buf->next;
		buf->data = value;
	}

	LinkedList<T>* Concat(LinkedList<T>* list) {
		LinkedList<T>* data = new LinkedList<double>;
		for (int i = 0; i < this->GetLength(); i++) {
			data->Append(this->Get(i));
		}

		for (int i = 0; i < list->GetLength(); i++) {
			data->Append(list->Get(i));
		}
		return data;
	}
	LinkedList<T>* GetSubList(int start, int end) {
		assert(start >= 0);
		assert(start < this->GetLength());
		assert(end >= 0);
		assert(end < this->GetLength());
		assert(start <= end);

		LinkedList<T>* data = new LinkedList<T>;
		for (int i = start; i < end; i++)
			data->Append(this->Get(i));
		return data;
	}
	void DeleteKey(int pos) {
		if (pos == 0) {
			Item<T>* temp = this->head->next;
			T value = this->head->data;
			delete this->head;
			this->head = temp;
			length--;
		}
		else if (pos == this->length - 1) {
			Item<T>* temp = GetNode(this->length - 2);
			T value = this->tail->data;
			delete this->tail;
			this->tail = temp;
			length--;
		}
		else {
			Item<T>* current;
			Item<T>* previous;
			current = GetNode(pos);
			previous = GetNode(pos - 1);
			previous->next = current->next;
			delete current;
			length--;
		}
	}
};