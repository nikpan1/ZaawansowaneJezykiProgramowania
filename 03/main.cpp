#include <iostream>
#include <random>

void init(char* str, int size);
size_t n_strlen(const char* str);
char* n_strcpy(char* destination, const char* source);
char* n_strncpy(char* destination, const char* source, size_t num);
char* n_strcat(char* destination, const char* source);
int   n_strcmp(const char* str1, const char* str2);
char* n_strchr(char* str, int character);
char* n_strrchr(char* str, int character);
char* n_strstr(char* str1, const char* str2);


int main() {
	size_t size = 5;
	char* str1 = (char*)malloc(size * sizeof(char));
	char* str2 = (char*)malloc(size * sizeof(char));	
	init(str1, 10);
	init(str2, 10);
	
	printf("str1 = %s, size = %d\n", str1, strlen(str1));
	printf("str2 = %s, size = %d\n", str2, strlen(str2));
	
	n_strcpy(str2, str1);
	printf("n_strcpy:\nstr1 = %s, size = %d\n", str1, strlen(str1));
	printf("str2 = %s, size = %d\n", str2, strlen(str2));
	

	init(str2, 10);
	printf("n_strncpy 6:\nstr2 = %s, size = %d\n", str2, strlen(str2));
	n_strncpy(str2, str1, 6);
	printf("str2 = %s, size = %d\n", str2, strlen(str2));
	
	n_strcat(str2, str1);
	printf("n_strcat:\nstr1 = %s, size = %d\n", str1, strlen(str1));
	printf("str2 = %s, size = %d\n", str2, strlen(str2));
	
	printf("n_strcmp:\n str1 != str2 := %d\n", n_strcmp(str1, str2));
	init(str1, 10);
	init(str2, 10);
	n_strcpy(str1, str2);	
	printf("str1 == str2 := %d\n", n_strcmp(str1, str2));


	printf("n_strchr 4th\nstr=%s\nn=%c\n", str1, *(n_strchr(str1, str1[3])));
	printf("n_strrchr 6th\nstr=%s\nn=%c\n", str1, *(n_strrchr(str1, str1[5])));
	strncpy(str1, str2, 3);

	printf("n_strstr\nstr1=%s\nstr2=%s\n", str1, str2);
	auto ptr = n_strstr(str1, (str2 + 3));
	
	if (ptr != nullptr)
		printf("strfound=%s\n", *ptr);
	else
		printf("strfound=none\n");

	return 0;
}

// random string generator
void init(char* str, int size) {
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(101, 131);
	
	for (int i = 0; i < size - 1; i++) {
		str[i] = char(dist(rng));
	}

	str[size - 1] = '\0';
}

// returns length of string
size_t n_strlen(const char* str) {
	//char* pivot = const_cast<char*>(str);
	int result = 0;
	while (*(str + result) != '\0') result++;
	return result;
}

// copies the content to another string
char* n_strcpy(char* destination, const char* source) {
	if (n_strlen(destination) < n_strlen(source)) return nullptr;
	for (int i = 0; i < n_strlen(source); i++) 
		*(destination + i) = *(source + i);
	
	return destination;
}

// copies the first num characters of source to destination
char* n_strncpy(char* destination, const char* source, size_t num) {
	if (n_strlen(destination) < num 
	  	  || n_strlen(source) < num) return nullptr;
	for (int i = 0; i < num; i++) 
		*(destination + i) = *(source + i);
	
	return destination;
}

// concatenate strings
char* n_strcat(char* destination, const char* source) {
	size_t old_size = n_strlen(destination);
	realloc(destination, n_strlen(source) * sizeof(char));
	for (int i = 0; i < n_strlen(source); i++) 
		*(destination + old_size + i) = *(source + i);

	return destination;
}

// compare strings
int n_strcmp(const char* str1, const char* str2) {
	if (n_strlen(str1) != n_strlen(str2)) return 0;
	
	while (*str1 != '\0')
	{
		if (*str1 != *str2) return 0;
		str1++; str2++;
	}

	return 1;
}

// searches a character in a string
char* n_strchr(char* str, int character) {
	for (auto ptr = str; ptr <= str + n_strlen(str); ptr++)
		if (*ptr == char(character))
			return ptr;

	return nullptr;
}

// last occurance of a char
char* n_strrchr(char* str, int character) {
	for (int i = n_strlen(str) - 1; i != 0; i--)
		if (str[i] == char(character)) return str + i;
	return nullptr;
}

//  returns a pointer to the first occurrence of str2 in str1
char* n_strstr(char* str1, const char* str2) {
	int pivot;
	for (int i = 0; i < n_strlen(str1); i++) {
		if (*(str1 + i) == *str2) {
			int k = n_strlen(str2) - 1;
			for (; k > i; k --) {
				printf("%c-%c ", *(str1 + i + k), *(str2 + k));
				if (*(str1 + i + k) != *(str2 + k)) break;
			}
			std::cout << k;
			if (k == 1) return str1 + i;
		}
	}

	return nullptr;
}



