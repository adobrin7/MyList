#include <iostream>
using namespace std;

template <typename T>
class List
{
public:
	List();
	~List();

	void push_front(T data);
	void pop_front();

	void insert(T value, int index);
	void removeAt(int index);

	void push_back(T data);
	void pop_back();

	int GetSize() { return size; }
	void clear();
	
	T& operator[](const int index);

private:

	template <typename T>
	class Node
	{
	public:
		Node* pNext;
		T data;

		Node(T data = T(), Node* pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}

	};

	int size;
	Node<T>* head;
};

template <typename T>
List<T>::List()
{
	size = 0;
	head = nullptr;
}

template <typename T>
List<T>::~List() { clear(); }

template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
}

template<typename T>
void List<T>::pop_front()
{
	Node<T>* temp = head;
	head = head->pNext;

	delete temp;
	size--;
}

template<typename T>
void List<T>::insert(T value, int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		previous->pNext = new Node<T>(value, previous->pNext);
		size++;
	}
}

template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T>* previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T>* toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;

		delete toDelete;
		size--;
	}
}

template<typename T>
void List<T>::clear()
{
	while (size)
	{
		pop_front();
	}
}

template<typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr) { head = new Node<T>(data); }
	else
	{
		Node<T>* current = this->head;

		while (current->pNext != nullptr) { current = current->pNext; }
		current->pNext = new Node<T>(data);
	}
	size++;
}

template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}

template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->pNext;
		counter++;
	}
}

int main()
{
	List<int> lst;
	lst.push_front(3);
	lst.push_front(2);
	lst.push_front(1);

	lst.push_back(5);
	lst.push_back(7);
	lst.push_back(8);

	lst.insert(4, 3);
	lst.insert(6, 4);

	lst.push_back(77);

	for (int i = 0; i < lst.GetSize(); i++) { cout << lst[i] << endl; }
}