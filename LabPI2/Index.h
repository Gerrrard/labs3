#pragma once
#include "Dictionary.h"

template<class T, class R>
class Indexes {
private:
	Dictionary<T, R> C;
public:
	Indexes() {};
	Indexes(Sequence<R>* a, T(*indexer)(R)) {
		for (int i = 0; i < a->GetLength(); i++) {
			T index = indexer(a->Get(i));
			C.Add(index, a->Get(i));
		}
	}
	Indexes(Sequence<R>* a, bool (*cmp)(R)) {
		for (int i = 0; i < a->GetLength(); i++) {
			bool index = cmp(a->Get(i));
			C.Add(index, a->Get(i));
		}
	}

	Dictionary<T, R> ReturnIndexed() {
		return C;
	}
};