#ifndef MAX_HPP
# define MAX_HPP

template<typename T>
T max(T a, T b) {
	if (b < a) return a;
	return b;
}

#endif
