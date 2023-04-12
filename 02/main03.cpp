#include <iostream>

int main() {
	for (int i = 33; i < 127; i++) std::cout << i << ": " << char(i) << std::endl;
	
	float sum = 0.0f;
	for (int i = 0; i < 1000000; i++) sum++;
	
	std::cout << "sum = " << sum << std::endl;
	return 0;
}