#pragma once
template <class T>
class TQueue
{
private:
	int Head, Tail, MaxSize, CurSize;
	T* arr;
public:
	TQueue(int _size = 64);
	~TQueue();
	TQueue(const TQueue<T>& q);
	TQueue<T>& operator=(const TQueue<T>& q);
	bool Empty()const;
	bool Full()const;
	void Push(T a);
	T Pop();
	T TFront();
	T TBack();
	int GetSize();
	int GetMaxSize();
	int GetHead();
};



template <class T>
TQueue<T>::TQueue(int _size) {
	MaxSize = _size;
	arr = new T[MaxSize];
	Head = 0;
	Tail = -1;
	CurSize = 0;
}

template <class T>
TQueue<T>::~TQueue() {
	delete[]arr;
}

template <class T>
TQueue<T>::TQueue(const TQueue<T>& q) {
	MaxSize = q.MaxSize;
	Head = q.Head;
	Tail = q.Tail;
	CurSize = q.CurSize;
	arr = new T[MaxSize];
	if (Head <= Tail)
	{
		for (int i = Head; i <= Tail; i++)
		{
			arr[i] = q.arr[i];
		}
	}
	else
	{
		for (int i = Head; i < MaxSize; i++)
		{
			arr[i] = q.arr[i];
		}
		for (int i = 0; i <= Tail; i++)
		{
			arr[i] = q.arr[i];
		}
	}
}

template <class T>
int TQueue<T>::GetSize() {
	return CurSize;
}

template <class T>
int TQueue<T>::GetHead() {
	return Head;
}

template <class T>
int TQueue<T>::GetMaxSize() {
	return MaxSize;
}
template <class T>
TQueue<T>& TQueue<T>::operator=(const TQueue<T>& q)
{
	if (this != &q)
	{
		if (MaxSize != q.MaxSize)
		{
			MaxSize = q.MaxSize;
			delete[]arr;
			arr = new T[MaxSize];
		}
		Head = q.Head;
		Tail = q.Tail;
		CurSize = q.CurSize;
		if (Head <= Tail)
		{
			for (int i = Head; i <= Tail; i++)
			{
				arr[i] = q.arr[i];
			}
		}
		else
		{
			for (int i = Head; i < MaxSize; i++)
			{
				arr[i] = q.arr[i];
			}
			for (int i = 0; i <= Tail; i++)
			{
				arr[i] = q.arr[i];
			}
		}
	}
	return *this;
}

template <class T>
bool TQueue<T>::Empty()const {
	return (!CurSize);
}

template <class T>
bool TQueue<T>::Full()const {
	return(CurSize == MaxSize);
}

template <class T>
void TQueue<T>::Push(T a) {
	if (Full())
	{
		char e[] = "Stack is Full";
		throw e;
	}
	else
	{
		if (Tail != MaxSize - 1)
		{
			arr[++Tail] = a;
		}
		else
		{
			arr[Tail = 0] = a;
		}
		CurSize++;
	}
}

template <class T>
T TQueue<T>::Pop() {
	if (Empty())
	{
		char e[] = "Stack is Full";
		throw e;
	}
	else
	{
		CurSize--;
		if (Head != MaxSize - 1)
		{
			return arr[Head++];
		}
		else
		{
			int pos = Head;
			Head = 0;
			return arr[pos];
		}
	}
}

template <class T>
T TQueue<T>::TFront() {
	if (Empty())
	{
		char e[] = "Stack is Full";
		throw e;
	}
	else
	{
		return arr[Head];
	}
}

template <class T>
T TQueue<T>::TBack() {
	if (Empty())
	{
		char e[] = "Stack is Full";
		throw e;
	}
	else
	{
		return arr[Tail];
	}
}