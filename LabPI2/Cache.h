#pragma once
#include "Dictionary.h"

template<class R>
class Cache {
private:
	Dictionary <R, int> C;
	int length;

	void Add(R data) {
		if (C.ContainsKey(data) == 0) {
			if (length > C.Count()) {
				C.Add(data, 1);
			}
			else {
				RemoveSmallestRequest();
				C.Add(data, 1);
			}
		}
		else {
			int q = C.GetVal(data);
			C.Remove(data);
			C.Add(data, q + 1);
		}
	}
	void RemoveSmallestRequest() {
		int x = SmallestRequest();
		R smreq = DataofRequest(x);
		C.Remove(smreq);
	}
	R DataofRequest(int request) {
		for (int i = 0; i < C.keys.size(); i++)
			for (int j = 0; j < C.keys[i].GetLength(); j++)
				if (C.data[i].Get(j) == request)
					return C.keys[i].Get(j);
	};
	int Numberofrequests(R dat) {
		for (int i = 0; i < C.keys.size(); i++)
			for (int j = 0; j < C.keys[i].GetLength(); j++) {
				if (C.keys[i].Get(j) == dat)
					return C.data[i].Get(j);
			}
		return 0;
	}
	int SmallestRequest() {
		int m = 0;
		while (C.data[m].GetLength() == 0 && m != C.data.size()) {
			m++;
		}

		int min = C.data[m].Get(0);
		for (int i = m; i < C.data.size(); i++)
			for (int j = 0; j < C.data[i].GetLength(); j++) {
				if (C.data[i].Get(j) < min)
					min = C.data[i].Get(j);
			}
		return min;
	}
	void Print() {
		for (int i = 0; i < C.keys.size(); i++) {
			for (int j = 0; j < C.keys[i].GetLength(); j++) {
				cout << "Data " << C.keys[i].Get(j) << " ";
				cout << "Requests " << C.data[i].Get(j) << "\n";
			}
		}
	}
public:
	Cache() {};
	Cache(Sequence<R>* a, int l) {
		length = l;
		int q;

		cout << "What should we do?\n1.Get\n0.Exit\n";
		cin >> q;

		while (q != 0) {
			switch (q)
			{
			case 1: {
				cout << "What data do you want to get?\n";
				int k;
				cin >> k;
				Add(a->Get(k));
				Print();
				break;
			}
			default:
				break;
			}
			cout << "What should we do?\n1.Get\n0.Exit\n";
			cin >> q;
		}
		C.Print();
	}

	Dictionary <int, R> ReturnCache() {
		return C;
	}

	~Cache() {
		C.data.clear();
		C.data.clear();
	}
};