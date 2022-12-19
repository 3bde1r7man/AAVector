#pragma once
#include <iostream>
#include <string>
#include <iterator>
#include <algorithm>


using namespace std;

template<class T>
class AAVector
{
private:
	int Size, Capacity;
	T* Data;
public:
	// Constructors and Big 4 
	AAVector(int n = 2);		// Initialize by specific capacity
	// No content is added, size = 0
	// Assign a default size value
	AAVector(T*, int  n);		// Initialize by n items from array 
	AAVector(const AAVector&);	// Initialize with a copy
	virtual ~AAVector();		// Delete allocated memory
	AAVector& operator=(const AAVector& v);  // Copy assignment  
	AAVector& operator=(const AAVector&& v) noexcept; // Move assignment 

	// Access operations 
	T& operator[](int); // Access item by reference 
	// Throw an exception if out of range 

	// Modifying operations 
	void push_back(T); // Add item to end of vec & return # of items 
	// Increase capacity of needed
	T pop_back();   // Remove and return last element in vec 
	void erase(const T*);       // Remove item at iterator
	// Throw exception if invalid iter 
	void erase(T*, T*);// Remove items between 
	// iterator 1 <= iterator 2 otherwise do nothing
	// Throw exception if any iterator outside range
	void clear();    // Delete all vector content
	void insert(T* , T);    // Insert item at iterator 
	// Throw exception if invalid 

	// Iterators 		// Supports *, + and ++ operations at least
	// Can use: typedef T* iterator 
	// Or u can use std::iterator so you can 
	// apply STL algorithms on XYVector
	T* begin();	// Return an iterator (T*) 
	T* end();	// Return an iterator (T*) 

	// Comparison operations 
	bool operator==(const AAVector<T>&); // Return true if ==  
	bool operator< (const AAVector<T>&); // Compares item by item
	// Return true if first different item in this is < in other

	// Capacity operations 
	int size() const;		// Return current size of vec
	int capacity() const;	// Return size of current allocated array  
	void resize(const size_t);			// Relocate to bigger space
	bool empty();			// Return true if size is 0

	// Friends 
	friend ostream& operator<<(ostream& out, AAVector<T> other);
};

