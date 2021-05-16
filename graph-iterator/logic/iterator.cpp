#include <algorithm>
#include <iostream>

#include "iterator.h"

bool Iterator::isEnd() {
	return std::all_of(
		std::begin(this->visited),
		std::end(this->visited),
		[](bool i) {
			return i;
		}
	);
}

void Iterator::iterate() {

	reset();
	std::cout << currentKey();

	while ( !isEnd() ) {
		next();
		std::cout << currentKey();
	}
}