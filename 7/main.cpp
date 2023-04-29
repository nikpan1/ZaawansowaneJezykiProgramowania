#include <iostream>

class dynamic_string {
public:
	dynamic_string(char *input_string, uint16_t);
	~dynamic_string();
public:
	void add_in_index(uint16_t index, char adder);
	void remove_index(uint16_t index);
	void append(char appended);
public:
	char *container;
	uint16_t size;
};

dynamic_string::dynamic_string(char *input_string, uint16_t size){
	container = (char*)malloc(size);
	size--;
	while (size - 1 > 0) {
		container[size] = input_string[size];
		size--;
	}
}

dynamic_string::~dynamic_string() {
	free(container);
}

void dynamic_string::add_in_index(uint16_t index, char adder) {
	realloc(container, size + 1);
	uint16_t i = size;
	while (--i != index) container[i] = container[i - 1];
	container[index] = adder;
	size--;
}

void dynamic_string::remove_index(uint16_t index) {
	while (index) container[index] = container[index - 1];
	realloc(container, size - 1);
	size--;
}

void dynamic_string::append(char appended) {
	realloc(container, size + 1);
	size++;
	container[size - 1] = appended;
}


int main(int argc, char** argv) {
	char* a = (char*)malloc(3);
	a[0] = 'a'; a[1] = 'b'; a[2] = 'c';
	dynamic_string str(a, 3);
	std::cout << a << str.container;

}


