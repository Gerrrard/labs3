#include "Menus.h"

void forCache() {
	ListSequence<Person>* a = new ListSequence<Person>;

	for (int i = 0; i < 10; i++) {
		a->Append(Person(i));
	}
	for (int i = 0; i < 10; i++) {
		cout << a->Get(i) << "\n";
	}

	Cache<Person> C((ListSequence<Person>*)a, 3);
}
int Indexer(Person a) {
	return a.GetID().number;
}
bool inder(Person a) {
	if (a.GetID().number > 5)
		return 1;
	else
		return 0;
}
void forindexes() {
	srand(time(0));
	ListSequence<Person>* a = new ListSequence<Person>;

	for (int i = 0; i < 10; i++) {
		a->Append(Person(rand() % 10));
	}
	for (int i = 0; i < 10; i++) {
		cout << a->Get(i) << "\n";
	}

	Indexes<int, Person> Z((ListSequence<Person>*)a, inder);
	Dictionary<int, Person> K = Z.ReturnIndexed();
	K.Print();
}
void IndexerMenu() {
	srand(time(0));
	cout << "We will index persons\n Do you want to enter data yourself:\n1.Yes\n2.No";
	int u = 0;
	cin >> u;

	if (u == 1) {
		cout << "To make it faster we will generate people only with their numbers\nEnter length please\n";
		int l;
		cin >> l;

		ListSequence<Person>* a = new ListSequence<Person>;
		for (int i = 0; i < l; i++) {
			int t;
			cin >> t;
			a->Append(Person(t));
		}

		for (int i = 0; i < l; i++) {
			cout << a->Get(i) << "\n";
		}

		Indexes<int, Person>Z((ListSequence<Person>*)a, Indexer);
		Dictionary<int, Person> K = Z.ReturnIndexed();
		K.Print();
	}
	else
	{
		cout << "To make it faster we will generate people only with their numbers\nEnter length please\n";
		int l;
		cin >> l;

		ListSequence<Person>* a = new ListSequence<Person>;
		for (int i = 0; i < l; i++) {
			a->Append(Person(rand() % 10));
		}
		for (int i = 0; i < l; i++) {
			cout << a->Get(i) << "\n";
		}
		Indexes<int, Person>Z((ListSequence<Person>*)a, Indexer);
		Dictionary<int, Person> K = Z.ReturnIndexed();
		K.Print();
	}
}
void Vectint() {
	cout << "Enter Length\n";
	int l;
	cin >> l;
	cout << "\nDo you want random generation?\n1.Yes\n2.No\n";
	int temp;
	cin >> temp;

	if (temp == 1) {
		int* t = new int[l];
		for (int i = 0; i < l; i++)
			t[i] = rand() % 10;

		Vector<int> Z(t, l);
		int z = 0;
		Dictionary<int, int> M = Z.Get();
		M.Print();

		while (z != 7)
		{
			cout << "What do you want?\n1.Sum\n2.Min\n3.Mult\n4.Map\n5.Reduce\n6.Where\n7.Exit\n";
			cin >> z;
			switch (z)
			{
			case 1: {
				cout << "We will summ it with a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						h[i] = rand() % 10;

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();

					Vector<int> S = Z + Z1;
					Dictionary<int, int> G = S.Get();
					G.Print();
				}
				else
				{
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<int> Z1(h, l);
					Vector<int> S = Z + Z1;
					Dictionary<int, int> G = S.Get();
					G.Print();
				}
				break;
			}
			case 2: {
				cout << "We will summ it with a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;

				if (y == 1) {
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						h[i] = rand() % 10;

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();

					Vector<int> S = Z - Z1;
					Dictionary<int, int> G = S.Get();
					G.Print();
				}
				else
				{
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();

					Vector<int> S = Z - Z1;
					Dictionary<int, int> G = S.Get();
					G.Print();
				}
				break;
			}
			case 3: {
				cout << "We will mult it on a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						h[i] = rand() % 10;

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();

					int a = Z * Z1;
					cout << a;
				}
				else
				{
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();

					int a = Z * Z1;
					cout << a;
				}
				break;
			}
			case 4: {
				cout << "We will map it\n";
				Vector<int> Z1 = Z.Map(Maper);
				Dictionary<int, int> L = Z1.Get();
				L.Print();
				break;
			}
			case 5: {
				cout << "We will reduce it, cin valut\n";
				int e;
				cin >> e;
				int Z1 = Z.reduce(Reducer, e);
				cout << Z1;
				break;
			}
			case 6: {
				cout << "We will where it\n";
				Vector<int> Z1 = Z.Where(Wherer);
				Dictionary<int, int> L = Z1.Get();
				L.Print();
				break;
			}
			default:
				break;
			}
		}
	}
	if (temp == 2) {
		int* t = new int[l];
		for (int i = 0; i < l; i++)
			cin >> t[i];

		Vector<int> Z(t, l);
		int z = 0;
		Dictionary<int, int> M = Z.Get();
		M.Print();

		while (z != 7)
		{
			cout << "What do you want?\n1.Sum\n2.Min\n3.Mult\n4.Map\n5.Reduce\n6.Where\n7.Exit\n";
			cin >> z;
			switch (z)
			{
			case 1: {
				cout << "We will summ it with a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						h[i] = rand() % 10;

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();

					Vector<int> S = Z + Z1;
					Dictionary<int, int> G = S.Get();
					G.Print();
				}
				else
				{
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<int> Z1(h, l);
					Vector<int> S = Z + Z1;
					Dictionary<int, int> G = S.Get();
					G.Print();
				}
				break;
			}
			case 2: {
				cout << "We will summ it with a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						h[i] = rand() % 10;

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();

					Vector<int> S = Z - Z1;
					Dictionary<int, int> G = S.Get();
					G.Print();
				}
				else
				{
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();

					Vector<int> S = Z - Z1;
					Dictionary<int, int> G = S.Get();
					G.Print();
				}
				break;
			}
			case 3: {
				cout << "We will mult it on a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						h[i] = rand() % 10;

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();
					int a = Z * Z1;
					cout << a;
				}
				else {
					int* h = new int[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<int> Z1(h, l);
					Dictionary<int, int> G1 = Z1.Get();
					G1.Print();
					int a = Z * Z1;
					cout << a;
				}
				break;
			}
			case 4: {
				cout << "We will map it\n";
				Vector<int> Z1 = Z.Map(Maper);
				Dictionary<int, int> L = Z1.Get();
				L.Print();
				break;
			}
			case 5: {
				cout << "We will reduce it, cin valut\n";
				int e;
				cin >> e;
				int Z1 = Z.reduce(Reducer, e);
				cout << Z1;
				break;
			}
			case 6: {
				cout << "We will where it\n";
				Vector<int> Z1 = Z.Where(Wherer);
				Dictionary<int, int> L = Z1.Get();
				L.Print();
				break;
			}
			default:
				break;
			}
		}
	}
}
void Vectdouble() {
	cout << "Enter Length\n";
	int l;
	cin >> l;
	cout << "\nDo you want random generation?\n1.Yes\n2.No\n";
	int temp;
	cin >> temp;
	if (temp == 1) {
		double* t = new double[l];
		for (int i = 0; i < l; i++)
			t[i] = (rand() + 1.1) / 10;

		Vector<double> Z(t, l);
		Dictionary<int, double> Ga = Z.Get();
		Ga.Print();

		int z = 0;
		while (z != 7)
		{
			cout << "What do you want?\n1.Sum\n2.Min\n3.Mult\n4.Map\n5.Reduce\6.Where\n7.Exit\n";
			cin >> z;
			switch (z)
			{
			case 1: {
				cout << "We will summ it with a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						h[i] = (rand() + 1.1) / 10;

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					Vector<double> S = Z + Z1;
					Dictionary<int, double> G = S.Get();
					G.Print();
				}
				else
				{
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					Vector<double> S = Z + Z1;
					Dictionary<int, double> G = S.Get();
					G.Print();
				}
				break;
			}
			case 2: {
				cout << "We will summ it with a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						h[i] = (rand() + 1.1) / 10;

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					Vector<double> S = Z - Z1;
					Dictionary<int, double> G = S.Get();
					G.Print();
				}
				else
				{
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					Vector<double> S = Z - Z1;
					Dictionary<int, double> G = S.Get();
					G.Print();
				}
				break;
			}
			case 3: {
				cout << "We will mult it on a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						h[i] = (rand() + 1.1) / 10;

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					double a = Z * Z1;
					cout << a;
				}
				else
				{
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					double a = Z * Z1;
					cout << a;
				}
				break;
			}
			case 4: {
				cout << "We will map it\n";
				Vector<double> Z1 = Z.Map(Maper);
				Dictionary<int, double> L = Z1.Get();
				L.Print();
				break;
			}
			case 5: {
				cout << "We will reduce it, cin valut\n";
				int e;
				cin >> e;
				double Z1 = Z.reduce(Reducer, e);
				cout << Z1;
				break;
			}
			case 6: {
				cout << "We will where it\n";
				Vector<double> Z1 = Z.Where(Wherer);
				Dictionary<int, double> L = Z1.Get();
				L.Print();
				break;
			}
			default:
				break;
			}
		}
	}
	if (temp == 2) {
		double* t = new double[l];
		for (int i = 0; i < l; i++)
			cin >> t[i];

		Vector<double> Z(t, l);
		Dictionary<int, double> Ga = Z.Get();
		Ga.Print();
		int z = 0;

		while (z != 7)
		{
			cout << "What do you want?\n1.Sum\n2.Min\n3.Mult\n4.Map\n5.Reduce\6.Where\n7.Exit\n";
			cin >> z;
			switch (z)
			{
			case 1: {
				cout << "We will summ it with a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						h[i] = (rand() + 1.1) / 10;

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					Vector<double> S = Z + Z1;
					Dictionary<int, double> G = S.Get();
					G.Print();
				}
				else
				{
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					Vector<double> S = Z + Z1;
					Dictionary<int, double> G = S.Get();
					G.Print();
				}
				break;
			}
			case 2: {
				cout << "We will summ it with a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						h[i] = (rand() + 1.1) / 10;

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					Vector<double> S = Z - Z1;
					Dictionary<int, double> G = S.Get();
					G.Print();
				}
				else
				{
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					Vector<double> S = Z - Z1;
					Dictionary<int, double> G = S.Get();
					G.Print();
				}
				break;
			}
			case 3: {
				cout << "We will mult it on a vector. Do you want random generation?\n1.Yes\n2.No\n";
				int y;
				cin >> y;
				if (y == 1) {
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						h[i] = (rand() + 1.1) / 10;

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					double a = Z * Z1;
					cout << a;
				}
				else
				{
					double* h = new double[l];
					for (int i = 0; i < l; i++)
						cin >> h[i];

					Vector<double> Z1(h, l);
					Dictionary<int, double> G1 = Z1.Get();
					G1.Print();

					double a = Z * Z1;
					cout << a;
				}
				break;
			}
			case 4: {
				cout << "We will map it\n";
				Vector<double> Z1 = Z.Map(Maper);
				Dictionary<int, double> L = Z1.Get();
				L.Print();
				break;
			}
			case 5: {
				cout << "We will reduce it, cin valut\n";
				int e;
				cin >> e;
				double Z1 = Z.reduce(Reducer, e);
				cout << Z1;
				break;
			}
			case 6: {
				cout << "We will where it\n";
				Vector<double> Z1 = Z.Where(Wherer);
				Dictionary<int, double> L = Z1.Get();
				L.Print();
				break;
			}
			default:
				break;
			}
		}
	}
}
void VectorMenu() {
	srand(time(0));
	cout << "What type do you want?\n1.Integer\n2.Double\n";
	int r = 0;
	cin >> r;
	if (r == 1) {
		Vectint();
	}
	else {
		Vectdouble();
	}

}
void CacheMenu() {
	cout << "We will cache persons\nhow many persons do you want to cache?\n";
	int l;
	cin >> l;
	cout << "We will generate only numbers to be faster. Do you want generate them randomly?\n1.Yes\n2.No\n";
	int x;
	cin >> x;

	ListSequence<Person>* a = new ListSequence<Person>;
	if (x == 1) {
		for (int i = 0; i < l; i++) {
			a->Append(Person(rand() % 100));
		}
	}
	else {
		for (int i = 0; i < l; i++) {
			int j;
			cin >> j;
			a->Append(Person(j));
		}
	}
	for (int i = 0; i < l; i++) {
		cout << a->Get(i) << "\n";
	}

	cout << "\nEnter cache length\n";
	int cl;
	cin >> cl;
	Cache<Person> C((ListSequence<Person>*)a, cl);
}
void GrandMenu() {
	int a = 0;
	while (a != 4) {
		cout << "What do you want to see now?\n1.Indexer\n2.Vector\n3.Cache\n4.Exit\n";
		cin >> a;

		switch (a)
		{
		case 1: {
			IndexerMenu();
			break;
		}
		case 2: {
			VectorMenu();
			break;
		}
		case 3: {
			CacheMenu();
			break;
		}
		default:
			break;
		}
	}
}

int Maper(int a) {
	return a + 1;
}
int Reducer(int a, int c) {
	return a + c;
}
bool Wherer(int a) {
	if (a % 3 != 0)
		return 1;
	else
		return 0;

}
double Maper(double a) {
	return a + 1.1;
}
double Reducer(double a, double c) {
	return a + c;
}
bool Wherer(double a) {
	if (a >= 1.5)
		return 1;
	else
		return 0;

}