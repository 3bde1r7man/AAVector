/*****************************************************************//**
 * \file   AAVector.cpp
 * \brief  the function file
 * 
 * \author Ahmed Hanfy & Abdelrhman Mostafa
 * \date   December 2022
 *********************************************************************/

#include "AAVector.h"

/**
 * Initialize vector with Size n.
 * 
 * \param n
 */
template<class T>
AAVector<T>::AAVector(int n)
{
	Capacity = n;
	Size = 0;
	Data = new T[Capacity];
}


/**
 * Initialize vector with Size n & fill it with item
 * 
 * \param item
 * \param n
 */
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

/**
 * Initialize vector with Size n form another array
 * 
 * \param item
 * \param n
 */
template<class T>
AAVector<T>::AAVector(T* item, int n)
{
	Capacity = n;
	Size = n;
	Data = new T[Capacity];
	for (int i = 0; i < Size; i++)
	{
		Data[i] = item[i];
	}
}


/**
 * Initialize with a copy
 * 
 * \param v
 */
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

/**
 * Delete allocated memory
 * 
 */
template<class T>
AAVector<T>::~AAVector()
{
	delete[] Data;
}

/**
 * Copy assignment  
 * 
 * \param v
 * \return 
 */
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

/**
 * Move assignment
 * 
 * \param v
 * \return 
 */
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

/**
 * 
 * 
 * \param index
 * \return the Date at specific index
 */
template<class T>
T& AAVector<T>::operator[](int index)
{
	if (index > Size - 1) {
		cout << "An error has occured, index out of range." << endl;
		exit(0);
	}
	return Data[index];
}

/**
 * add 1 item to the vector
 * 
 * \param thing
 */
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

/**
 * Remove and return last element in vec 
 * 
 * \return 
 */
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

/**
 * Remove item at iterator
 * 
 * \param it
 */
template<class T>
void AAVector<T>::erase(const T* it)
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

/**
 * Remove items between 2 iterators
 * 
 * \param it1
 * \param it2
 */
template<class T>
void AAVector<T>::erase(T* it1, T* it2)
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

/**
 * clear the vector
 * 
 */
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

/**
 * Insert item at iterator 
 * 
 * \param it
 * \param item
 */
template<class T>
void AAVector<T>::insert(T* it, T item)
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

/**
 * 
 * 
 * \return iterator 
 */
template<class T>
T* AAVector<T>::begin()
{
	return &Data[0];
}

/**
 *
 *
 * \return iterator
 */
template<class T>
T* AAVector<T>::end()
{
	return &Data[Size];
}


/**
 * Return true if ==  
 * 
 * \param other
 * \return 
 */
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

/**
 * Return true if first different item in this is < in other
 * 
 * \param other
 * \return 
 */
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

/**
 * 
 * 
 * \return Size
 */
template<class T>
int AAVector<T>::size() const
{
	return Size;
}

/**
 * .
 * 
 * \return Capacity
 */
template<class T>
int AAVector<T>::capacity() const
{
	return Capacity;
}

/**
 * resize the vector
 * 
 * \param size
 */
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

/**
 * check if empty
 * 
 * \return 
 */
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





