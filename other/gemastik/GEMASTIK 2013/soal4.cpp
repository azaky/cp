#include <iostream>
#include <stdio.h>
using namespace std;
class Animal {
	private:
		int order; // urutan kedatangan
		int id; //id binatang
		int jenis; // 0: anjing; 1: kucing
	public:
		Animal() { id = 0; order = 0; jenis = -1; }
		Animal(int n, int ord, int j) { id = n; order = ord; jenis = j; } 
		Animal(const Animal& a) { id = a.id; order = a.order; jenis = a.jenis; }
		void setOrder(int ord) { order = ord; }
		int getOrder() { return order; }
		void setId(int i) { id = i; }
		int getId() { return id; }
		void setJenis(int j) { jenis = j; }
		int getJenis() { return jenis; }
		bool isOlderThan(Animal a) { return (this->order < a.getOrder()); }
};
class Queue {
public:
	Queue();
	Queue(int, int);
	Queue(const Queue&);
	~Queue();
	Queue& operator=(const Queue&);
	int IsEmpty() const;
	int IsFull() const;
	void Add (const Animal&); 
	void Del (Animal&);
	void PrintQueue();
private:
	int size;             
	int head;            
	int tail; 
	Animal *data;
	const int IdxUndefined;
};	
Queue::Queue():IdxUndefined(-999) {
	size = 100;
	data = new Animal[size];
	head = IdxUndefined;
	tail = IdxUndefined;
}
Queue::Queue(int s, int idx):size(s),IdxUndefined(idx) {
	data = new Animal[s];
	head = idx;
	tail = idx;
}
Queue::Queue(const Queue& q):IdxUndefined(q.IdxUndefined) {
	size = q.size;
	head = q.head;
	tail = q.tail;
	data = new Animal[q.size];
	if (!q.IsEmpty()) {
		int i = q.head;
		while (i != q.tail) {
			data[i] = q.data[i];
			if (i == size-1) {
				i = 0;
			} else {
				i++;
			}
		} data[i] = q.data[i];
	}
} 
Queue::~Queue() {
	delete [] data;
	size = 0;
}
Queue& Queue::operator=(const Queue& q) {
	delete [] data;
	size = q.size;
	head = q.head;
	tail = q.tail;
	data = new Animal[q.size];
	if (!q.IsEmpty()) {
		int i = q.head;
		while (i != q.tail) {
			data[i] = q.data[i];
			if (i == size-1) {
				i = 0;
			} else {
				i++;
			}
		}
		data[i] = q.data[i];
	}
	return *this;
}
int Queue::IsEmpty() const {
	return ((head == IdxUndefined) && (tail == IdxUndefined));
}
int Queue::IsFull() const {
	return (((size + tail - head) % size) + 1) == size;
}
void Queue::Add (const Animal& A) {
	if (IsEmpty()) {
		head = 0;
		tail = 0;
	} else {
		if (tail == size-1) {
			tail = 0;
		} else {
			tail++;
		}
	}
	printf("[%d %d]\n",head,tail);
	for (int i = head; i <= tail; ++i) printf("%d %d %d\n",data[tail].getOrder(),data[tail].getId(),data[tail].getJenis());
	data[tail] = A;
}
void Queue::Del (Animal& A) {
	A = data[head];
	if (head == tail) {
		head = IdxUndefined;
		tail = IdxUndefined;
	} else {
		if (head == size-1) {
			head = 0;
		} else {
			head++;
		}
	}
}
void Queue::PrintQueue() {
	
}

int main () {
	int n,i;
	Queue QAnjing, QKucing;
	cin >> n;
	int _id,_order, _jenis;
	for (i=0; i<=n; i++) {
		cin >> _id >> _order >> _jenis;;
		Animal A(_id, _order, _jenis);
		if (_jenis == 0) 
			QAnjing.Add(A);
		else
			QKucing.Add(A);
	}
	int type;
	cin >> type;
	Animal B;
	while (type != -1) {
		if (type == 0) 
			QAnjing.Del(B);
		else
			QKucing.Del(B);
		cin >> type;
	}
	QAnjing.PrintQueue();
	QKucing.PrintQueue();
	return 0;
}
