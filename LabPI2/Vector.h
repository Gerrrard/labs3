#pragma once
#include "Dictionary.h"

template<class R>
class Vector {
private:
	Dictionary<int, R> a;
	int Maxindex() {
		int m = 0;
		for (int i = 0; i < a.keys.size(); i++)
			for (int j = 0; j < a.keys[i].GetLength(); j++)
				if (m < a.keys[i].Get(j))
					m = a.keys[i].Get(j);
		return m;
	}
public:
	Vector() {}
	Vector(R* vector, int length) {
		for (int i = 0; i < length; i++) {
			if (vector[i] != 0) {
				a.Add(i, vector[i]);
			}
		}
	}

	Dictionary<int, R> Get() {
		return a;
	}

	R norm() {
		R sum = 0;
		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.data[i].GetLength(); j++) {
				sum = sum + a.data[i].Get(j) * a.data[i].Get(j);
			}
		}
		return (sqrt(sum));
	}
	Vector operator + (Vector b) {
		R* a1 = new R[Maxindex()];
		for (int i = 0; i < Maxindex(); i++)
			a1[i] = 0;

		R* b1 = new R[b.Maxindex()];
		for (int i = 0; i < b.Maxindex(); i++)
			b1[i] = 0;

		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.keys[i].GetLength(); j++) {
				a1[a.keys[i].Get(j)] = a.data[i].Get(j);
			}
		}

		for (int i = 0; i < b.a.data.size(); i++) {
			for (int j = 0; j < b.a.keys[i].GetLength(); j++) {
				b1[b.a.keys[i].Get(j)] = b.a.data[i].Get(j);
			}
		}

		int l = Maxindex();
		int l1 = b.Maxindex();
		int m;

		R* rez;
		if (l >= l1) {
			rez = new R[l];
			m = l;
			for (int i = 0; i <= l; i++) {
				if (i <= l1)
					rez[i] = a1[i] + b1[i];
				else {
					rez[i] = a1[i];
				}
			}
		}
		else {
			rez = new R[l1];
			m = l1;
			for (int i = 0; i <= l1; i++) {
				if (i <= l)
					rez[i] = a1[i] + b1[i];
				else {
					rez[i] = b1[i];
				}
			}
		}
		Vector<R> z(rez, m + 1);
		return z;
	}
	Vector operator - (Vector b) {
		R* a1 = new R[Maxindex()];
		for (int i = 0; i < Maxindex(); i++)
			a1[i] = 0;

		R* b1 = new R[b.Maxindex()];
		for (int i = 0; i < b.Maxindex(); i++)
			b1[i] = 0;

		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.keys[i].GetLength(); j++) {
				a1[a.keys[i].Get(j)] = a.data[i].Get(j);
			}
		}

		for (int i = 0; i < b.a.data.size(); i++) {
			for (int j = 0; j < b.a.keys[i].GetLength(); j++) {
				b1[b.a.keys[i].Get(j)] = b.a.data[i].Get(j);
			}
		}

		int l = Maxindex();
		int l1 = b.Maxindex();
		int m;

		R* rez;
		if (l >= l1) {
			rez = new R[l];
			m = l;
			for (int i = 0; i <= l; i++) {
				if (i <= l1)
					rez[i] = a1[i] - b1[i];
				else {
					rez[i] = a1[i];
				}
			}
		}
		else {
			rez = new R[l1];
			m = l1;
			for (int i = 0; i <= l1; i++) {
				if (i <= l)
					rez[i] = a1[i] - b1[i];
				else {
					rez[i] = -b1[i];
				}
			}
		}
		Vector<R> z(rez, m + 1);
		return z;
	}
	R operator * (Vector b) {
		R* a1 = new R[Maxindex()];
		for (int i = 0; i < Maxindex(); i++)
			a1[i] = 0;

		R* b1 = new R[b.Maxindex()];
		for (int i = 0; i < b.Maxindex(); i++)
			b1[i] = 0;

		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.keys[i].GetLength(); j++) {
				a1[a.keys[i].Get(j)] = a.data[i].Get(j);
			}
		}

		for (int i = 0; i < b.a.data.size(); i++) {
			for (int j = 0; j < b.a.keys[i].GetLength(); j++) {
				b1[b.a.keys[i].Get(j)] = b.a.data[i].Get(j);
			}
		}

		int l = Maxindex();
		int l1 = b.Maxindex();
		int m;
		R rez = 0;
		if (l >= l1) {
			m = l;
			for (int i = 0; i <= l1; i++) {
				rez = rez + a1[i] * b1[i];
			}
		}
		else {
			for (int i = 0; i <= l; i++) {
				rez = rez + a1[i] * b1[i];
			}
		}
		return rez;
	}
	Vector Map(R(*(mapper))(R)) {
		Vector<R>z;

		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.data[i].GetLength(); j++) {
				cout << a.data[i].Get(j) << mapper(a.data[i].Get(j)) << "\n";
				z.a.Add(a.keys[i].Get(j), mapper(a.data[i].Get(j)));
			}
		}
		return z;
	}
	R reduce(R(*reducer)(R, R), R c) {
		R res = c;
		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.data[i].GetLength(); j++) {
				res = res + a.data[i].Get(j);
			}
		}
		return res;
	}
	Vector Where(bool(*(wherer))(R)) {
		int l = 0;
		Vector<R> z;

		for (int i = 0; i < a.data.size(); i++) {
			for (int j = 0; j < a.data[i].GetLength(); j++) {
				if (wherer(a.data[i].Get(j)))
				{
					z.a.Add(a.keys[i].Get(j), a.data[i].Get(j));
				}
			}
		}
		return z;
	}
};