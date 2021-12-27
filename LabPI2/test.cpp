#pragma once
#include <iostream>
#include "../Lab2lib/ArraySequence.h"
#include "../Lab2lib/ListSequence.h"
#include "../Lab2lib/LinkedList.h"
#include <vector>
#include <cassert>
#include "../Lab2lib/Dictionary.h"
#include "../Lab2lib/Cache.h"
#include "../Lab2lib/Vector.h"
#include "../Lab2lib/Index.h"
#include "../Lab2lib/Set.h"
using namespace std;


void VectorTest() {
	int* m = new int[6];
	m[0] = 1;
	m[1] = 0;
	m[2] = 0;
	m[3] = 0;
	m[4] = 0;
	m[5] = 1;
	int* n = new int[6];
	n[5] = 1;
	n[4] = 0;
	n[3] = 1;
	n[2] = 0;
	n[1] = 0;
	n[0] = 1;
	Vector<int> a(m, 6);

	Vector<int> b(n, 6);

	Dictionary<int, int> L;
	L = a.Get();
	Dictionary<int, int> N;

	Vector<int> c;
	c = a - b;
	N = c.Get();
	int x = a * b;
	cout << x;

	cout << "\n";
}
void Cache_Test() {
	ListSequence<int>* a = new ListSequence<int>;
	for (int i = 0; i < 10; i++) {
		a->Append(i * 10 + rand() % 10);
		cout << a->Get(i) << " ";
	}
	cout << "\n";
	Cache<int> Cach((ListSequence<int>*)a, 5);

	Dictionary<int, int> t;
	t = Cach.ReturnCache();
	cout << "\n========================================\n";
	t.Print();
	cout << "\n";

}
void Hash_DictionaryTest() {
	int* m = new int[6];
	m[0] = 1;
	m[1] = 2;
	m[2] = 3;
	m[3] = 4;
	m[4] = 5;
	m[5] = 16;
	int* n = new int[6];
	n[5] = 0;
	n[4] = 9;
	n[3] = 8;
	n[2] = 11;
	n[1] = 12;
	n[0] = 13;
	Dictionary<int, int> A;
	for (int i = 0; i < 6; i++) {
		A.Add(m[i], n[i]);
	}
	A.Print();
	cout << "\n";
}
int indexer(int x) {
	return x + 1;
}
bool indexer_cmp(int x) {
	if (x > 45)
		return 1;
	else
		return 0;
}
void Indexes_Test() {
	ListSequence<int>* a = new ListSequence<int>;
	for (int i = 0; i < 10; i++) {
		a->Append(i * 10 + rand() % 10);
		cout << a->Get(i) << " ";
	}
	cout << "\n\n";
	Dictionary<int, int> t;
	Indexes<int, int> g((ListSequence<int>*)a, indexer_cmp);
	t = g.ReturnIndexed();
	t.Print();
	cout << "\n";
}
void Set_Test() {
	int* m = new int[6];
	m[0] = 0;
	m[1] = 9;
	m[2] = 3;
	m[3] = 4;
	m[4] = 5;
	m[5] = 16;
	int* n = new int[6];
	n[5] = 0;
	n[4] = 9;
	n[3] = 8;
	n[2] = 11;
	n[1] = 12;
	n[0] = 13;

	Set<int> T(m, 6);
	T.SetPrint();
	cout << "==========\n";

	Set<int> B(n, 6);
	B.SetPrint();

	Set<int>* C = new Set<int>((Set<int>) * T.Intersection(&((Set<int>)B)));
	cout << "==========\n";
	C->SetPrint();
}

int main() {
	VectorTest();
	cout << endl << endl;
	Cache_Test();
	cout << endl << endl;
	Hash_DictionaryTest();
	cout << endl << endl;
	Indexes_Test();
	cout << endl << endl;
	Set_Test();
	cout << endl << endl;
	return 0;
}