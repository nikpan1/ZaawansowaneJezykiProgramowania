#include <iostream>


size_t strlen(const char* str);
char* strcpy(char* destination, const char* source);
char* strncpy(char* destination, const char* source, size_t num);
char* strcat(char* destination, const char* source);
int strcmp(const char* str1, const char* str2);
char* strchr(char* str, int character);
char* strrchr(char* str, int character);
char* strstr(char* str1, const char* str2);


int main() {
	std::cout << "test!";
	return 0;
}

// returns length of string
size_t strlen(const char* str) {
	size_t result = 0;
	while (str[result] == '\0') result++;
	return result;
}

// copies the content to another string
char* strcpy(char* destination, const char* source) {
	if (strlen(destination) < strlen(source)) return nullptr;
	for (int i = 0; i < strlen(source); i++) destination[i] = source[i];
	
	return destination;
}

// copies the first num characters of source to destination
char* strncpy(char* destination, const char* source, size_t num) {
	if (strlen(destination) < num ) return nullptr;
	for (int i = 0; i < num; i++) destination[i] = source[i];
	
	return destination;
}

// concatenate strings
char* strcat(char* destination, const char* source) {
	size_t old_size = strlen(destination);
	realloc(destination, strlen(source) * sizeof(char));
	for (int i = 0; i < strlen(source); i++) 
		destination[old_size + i] = source[i];

	return destination;
}

// compare strings
int strcmp(const char* str1, const char* str2) {
	if (strlen(str1) != strlen(str2)) return 0;
	for(int i = 0; i < strlen(str1); i ++)
		if (str1[i] != str2[i]) return 0;
	return 1;
}

// searches a character in a string
char* strchr(char* str, int character) {
	for (auto ptr = str; ptr <= str + strlen(str); ptr++)
		if (*ptr == char(character))
			return ptr;

	return nullptr;
}

// last occurance of a char
char* strrchr(char* str, int character) {
	NULL;
}

//  returns a pointer to the first occurrence of str2 in str1
char* strstr(char* str1, const char* str2) {
	NULL;
}



