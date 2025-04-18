#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>
# include <exception>

template <typename T>
class Array {
private:
	unsigned int	_size;
	T	*_array;
public:
	Array(void);
	Array(unsigned int len);
	Array(const Array<T>& array);
	Array<T>& operator=(const Array& array);
	~Array();
	unsigned int	size(void) const;
	T&	operator[](unsigned int i);
	const T&	operator[](unsigned int i) const;
};

#include "Array.tpp"

#endif
