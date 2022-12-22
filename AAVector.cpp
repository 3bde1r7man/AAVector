#include "AAVector.h"

template<class T>
AAVector<T>::AAVector(int n)
{
	Capacity = n;
	Size = 0;
	Data = new T[Capacity];
}

template<class T>
AAVector<T>::AAVector(T item, int n)
{
	Capacity = n;
	Size = n;
	Data = new T[Capacity];
	for (int i = 0; i < Capacity; i++)
	{
		Data[i] = item;
	}
}

template<class T>
AAVector<T>::AAVector(iterator item, int n)
{
	Capacity = n;
	Size = n;
	Data = new T[Capacity];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = item[i];
	}
}

template<class T>
AAVector<T>::AAVector(const AAVector<T>& v)
{
	if (this != &v) {
		delete[] Data;
		Capacity = v.Capacity;
		Size = v.Size;
		Data = v.Data;
	}
}

template<class T>
AAVector<T>::~AAVector()
{
	delete[] Data;
}

template<class T>
AAVector<T>& AAVector<T>::operator=(const AAVector<T>& v)
{
	if (this != &v) {
		delete[] Data;
		Capacity = v.Capacity;
		Size = v.Size;
		Data = v.Data;
	}
	return *this;
}

template<class T>
AAVector<T>& AAVector<T>::operator=(const AAVector<T>&& v) noexcept
{
	if (this != &v) {
		delete[] Data;
		Capacity = v.Capacity;
		Size = v.Size;
		Data = v.Data;
	}
	return *this;
}

template<class T>
T& AAVector<T>::operator[](int index)
{
	if (index > Size - 1) {
		cout << "An error has occured, index out of range." << endl;
		exit(0);
	}
	return Data[index];
}

template<class T>
void AAVector<T>::push_back(T thing)
{
	if (Size < Capacity) {
		Data[Size++] = thing;
	}
	else {
		T* newdata = new T[Capacity * 2];
		Capacity *= 2;

		for (int i = 0; i < Size; i++) {
			newdata[i] = Data[i];
		}
		delete[] Data;
		Data = newdata;
		newdata = nullptr;
		Data[Size++] = thing;
	}
}

template<class T>
T AAVector<T>::pop_back()
{
	Size--;
	T* newdata = new T[Capacity];
	for (int i = 0; i < Size; i++) {
		newdata[i] = Data[i];
	}
	delete[] Data;
	Data = newdata;
	newdata = nullptr;

	return Data[Size-1];
}

template<class T>
void AAVector<T>::erase(const iterator it)
{
	if (it >= &Data[0] && it <= &Data[Size - 1]) {

		T* newdata = new T[Capacity];
		for (int i = 0; i < Size; i++) {
			if (&Data[i] <  it) {
				newdata[i] = Data[i];
			}
			else if(&Data[i] >= it)
			{
				newdata[i] = Data[i + 1];
			}
		}
		Size--;
		delete[] Data;
		Data = newdata;
		newdata = nullptr;
	}
	else
	{
		cout << "out of range itreator\n";
	}
	
}

template<class T>
void AAVector<T>::erase(iterator it1, iterator it2)
{
	auto start = min(it1, it2);
	auto end = max(it1, it2);
	T* newdata = new T[Capacity];
	if (start >= &Data[0] && end <= &Data[Size - 1]) {
		for (int i = 0; i < Size; i++) {
			if (&Data[i] >= start && &Data[i] <= end) {
				newdata[i] = Data[i + (end - start)];
			}
			else if (&Data[i] > end)
			{
				newdata[i] = Data[i + (end - start)];
			}
			else
			{
				newdata[i] = Data[i];
			}
		}

		Size -= (end - start);
		delete[] Data;
		Data = newdata;
		newdata = nullptr;
	}
	else
	{
		cout << "out of range itreator\n";
	}
	
	
}

template<class T>
void AAVector<T>::clear()
{
	Size = 0;
	Capacity = 2;
	T* newdata = new T[Capacity];
	delete[] Data;
	Data = newdata;
	newdata = nullptr;

}

template<class T>
void AAVector<T>::insert(iterator it, T item)
{
	if (it >= &Data[0] && it <= &Data[Size - 1]) {
		if (Size >= Capacity) {
			Capacity *= 2;
		}
		T* newdata = new T[Capacity];
		for (int i = 0; i < Size+1; i++)
		{
			if (&Data[i] < it) {
				newdata[i] = Data[i];
			}
			else if (&Data[i] == it)
			{
				newdata[i] = item;
			}
			else
			{
				newdata[i] = Data[i - 1];
			}
		}
		delete[] Data;
		Data = newdata;
		newdata = nullptr;
		Size++;
		
	}
	else
	{
		cout << "out of range itreator\n";
	}
}

template<class T>
T* AAVector<T>::begin()
{
	return &Data[0];
}

template<class T>
T* AAVector<T>::end()
{
	return &Data[Size];
}


template<class T>
bool AAVector<T>::operator==(const AAVector<T>& other)
{
	for (int i = 0; i < Size; i++)
	{
		if (Data[i] != other.Data[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
bool AAVector<T>::operator<(const AAVector<T>& other)
{
	for (int i = 0; i < Size; i++)
	{
		if (Data[i] > other.Data[i]) {
			return false;
		}
	}
	return true;
}

template<class T>
int AAVector<T>::size() const
{
	return Size;
}

template<class T>
int AAVector<T>::capacity() const
{
	return Capacity;
}

template<class T>
void AAVector<T>::resize(const size_t size)
{
	T* newdata = new T[Capacity];
	Size = size;
	for (int i = 0; i < size ; i++) {
		newdata[i] = Data[i];
	}
	delete[] Data;
	Data = newdata;
	newdata = nullptr;
}

template<class T>
bool AAVector<T>::empty()
{
	if (Size == 0) {
		return true;
	}
	return false;
}

template<class C>
ostream& operator<<(ostream& out, AAVector<C>& other)
{
	for (int i = 0; i < other.Size; i++)
	{
		out << other.Data[i] << ' ';
	}
	return out;
}





