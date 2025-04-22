#include "Array.hpp"

template <typename T>
Array<T>::Array(void) : _size(0), _array(new T[0]) {
	std::cout << "Array: default constructor called" << std::endl;
	if (_array == NULL) std::cerr << "Memory allocation failed" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int len) : _size(len), _array(new T[len]) {
	std::cout << "Array: initialization constructor called" << std::endl;
	if (_array == NULL) {
		_size = 0;
		std::cerr << "Memory allocation failed" << std::endl;
	}
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Array: destructor called" << std::endl;
	delete [] _array;
}

template <typename T>
Array<T>::Array(const Array<T>& array) : _size(array.size()) , _array(new T[_size]) {
	std::cout << "Array: copy constructor called" << std::endl;
	if (_array == NULL) {
		_size = 0;
		std::cerr << "Memory allocation failed" << std::endl;
		return ;
	}
	for (unsigned int i = 0; i < _size; ++i) {
		_array[i] = array[i];
	}
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& array) {
	std::cout << "Array: copy assignement operator called" << std::endl;
	if (this != &array) {
		_size = array.size();
		delete [] _array;
		_array = new T[_size];
		if (_array == NULL) {
			_size = 0;
			std::cerr << "Memory allocation failed" << std::endl;
			return *this;
		}
		for (unsigned int i = 0; i < _size; ++i) {
			_array[i] = array[i];
		}
	}
	return *this;
}

template <typename T>
unsigned int	Array<T>::size(void) const {
	return _size;
}

template <typename T>
T&	Array<T>::operator[](unsigned int i) {
	if (_size <= i) {
		throw(std::out_of_range("Index out of range"));
	}
	return _array[i];
}

template <typename T>
const T&	Array<T>::operator[](unsigned int i) const {
	if (_size <= i) {
		throw(std::out_of_range("Index out of range"));
	}
	return _array[i];
}
