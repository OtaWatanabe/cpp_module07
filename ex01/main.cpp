#include "iter.hpp"
#include <iostream>
#include <string>

void	printNum(int i) {
	std::cout << "number " << i << std::endl;
}

template <typename T>
T	printValue(T value) {
	std::cout << "value: " << value << std::endl;
	return value;
}

int	main() {
	int x[] = {0, 1, 3, 8};

	iter(x, 4, printNum);

	std::string s[] = {"Hello", "World", "template", "!"};

	iter(s, 4, printValue<std::string>);
}
