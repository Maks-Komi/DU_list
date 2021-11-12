#include<iostream>
#include<string>
using namespace std;

template <typename T>
class MonoDirectList {
public:
	MonoDirectList() {}
	MonoDirectList(T elem) {
		element = elem;
		next = nullptr;
	}
	MonoDirectList(MonoDirectList& L) {
		element = L.element;
		next = L.next;
	}
	~MonoDirectList() {
		if (next != 0) {
			delete next;
		}
	}	
	virtual void addValue(T elem) { // ����� ���������� �������� � ������
		MonoDirectList* current = this;  // ��������� ��������� �� ������� ��������� ������ � *current
		while (current->next != 0) { // ���� � ������
			current = current->next; // ����� ��������� ���������
		}
		current->next = new MonoDirectList(elem); // ������� ����� ��������� ������ � ���� � ���������� ��������� �� ���� � ���� next
	}
	int Count() { // ����� ��������� ����� ������
		int count = 0; // ������������� ��������
		for (MonoDirectList* current = this; current != 0; current = current->next) { // ���������� ��� �������� ������
			count++; // ����������� �������
		}
		return count; // ���������� �������� ��������
	}
	virtual void Show() {  // ����� ������ ������ �� �������
		for (MonoDirectList* current = this; current != 0; current = current->next) { // ���������� ��� �������� ������
			cout << current->element << "->"; // ������� �������� ��������
		}
		cout <<"\n";
	}
protected:
	T element;
	MonoDirectList* next;
};

template <typename T>
class BiDirectList : public MonoDirectList<T> {
public:
	BiDirectList(T elem) : MonoDirectList<T>(elem) {
		previous = nullptr;
	}
	void Add_elem(T elem) {
		BiDirectList* current = this;
		while (current->next != 0) {
			current = (BiDirectList*)current->next;
		}
		current->next = new BiDirectList(elem);
		((BiDirectList*)current->next)->previous = current;
	}
	void Show() {
		cout << "DU-list: " << endl;
		BiDirectList* temp;
		for (BiDirectList* current = this; current != 0; current = (BiDirectList*)current->next) {
			cout << current->element << "->";
			temp = current;
		}
		cout << "\n";
		cout << "DU-list revers: " << endl;
		/*for (BiDirectList* current = temp; current != 0; current = (BiDirectList*)current->previous) {
			cout << "->" << current->previous;
		}*/
		
		cout << endl;
	}
private:
	BiDirectList* previous;
};

template <typename T>
void AddSeqvence(MonoDirectList<T>* K, int num, T elem) {
	for (int i = 0; i < num; i++) {
		K->addValue(elem);
	}
}

int main() {
	double x = 5.234, y = 3.456;
	MonoDirectList<double> b(y);
	BiDirectList<double> a(x);
	cout << "Kolvo elementov: " << a.Count() << endl;
	a.Show();
	a.Add_elem(5);
	cout << "Kolvo elementov: " << a.Count() << endl;
	a.Show();
	a.Add_elem(6);
	cout << "Kolvo elementov: " << a.Count() << endl;
	a.Show();
	a.Add_elem(7);
	cout << "Kolvo elementov: " << a.Count() << endl;
	a.Show();
	a.Add_elem(8);
	cout << "Kolvo elementov: " << a.Count() << endl;
	a.Show();
	a.Add_elem(9);
	cout << "Kolvo elementov: " << a.Count() << endl;
	a.Show();
	AddSeqvence(&b, 7, 1.23);
	AddSeqvence(&a, 9, 2.45);
	cout << "Kolvo elementov: " << b.Count() << endl;
	b.Show();
	cout << "Kolvo elementov: " << a.Count() << endl;
	a.Show();
}