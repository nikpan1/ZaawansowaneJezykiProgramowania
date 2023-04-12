#include <iostream>
#include <stdlib.h>

struct matrix {
	double** content;
	size_t columns;
	size_t rows;
};

void print_mtx(matrix* mtx);
matrix multiply_mtx(matrix* mtx1, matrix* mtx2);


int main() {
	matrix mtx;

	std::cout << "column size=";
	std::cin >> mtx.columns;
	std::cout << "row size=";
	std::cin >> mtx.rows;
	
	mtx.content = (double**)malloc(sizeof(double) 
		* mtx.columns * mtx.rows);
	
	double* ptr = (double*)mtx.content;
	int counter = 0;
	while (counter < mtx.rows * mtx.columns) {
		std::cin >> *(ptr + ++counter);
	}
	print_mtx(&mtx);
	
	matrix mtx2;

	std::cout << "column size=";
	std::cin >> mtx2.columns;
	std::cout << "row size=";
	std::cin >> mtx2.rows;
	
	mtx2.content = (double**)malloc(sizeof(double) 
		* mtx2.columns * mtx2.rows);
	
	double* ptr2 = (double*)mtx2.content;
	int counter2 = 0;
	while (counter2 < mtx2.rows * mtx2.columns) {
		std::cin >> *(ptr2 + ++counter2);
	}
	print_mtx(&mtx2);
	

	auto result = multiply_mtx(&mtx, &mtx2);
	print_mtx(&result);

	return 1;
}

void print_mtx(matrix* mtx) {
	std::cout << "mtx:\n";
	for (int j = 0; j < mtx->columns; j++)
	{
		for (int i = 0; i < mtx->rows; i++) {
			std::cout << *((double*)(mtx->content) 
				+ mtx->rows * j + i + 1) << " ";
		}
		std::cout << "\n";
	}
}

matrix multiply_mtx(matrix* mtx1, matrix* mtx2) {
	if (mtx1->columns != mtx2->rows) {
		std::cout << "wrong mtx dimnesions ";
	}
	matrix result;
	result.columns = mtx1->rows;
	result.rows = mtx2->columns;
	result.content = (double**)calloc(result.rows * result.columns, sizeof(double));

	double* ptr = (double*)result.content;

	for (int i = 0; i < mtx1->rows; i++) {
		for (int j = 0; j < mtx2->columns; j++) {
			for (int k = 0; k < mtx2->rows; k++) {
				*((double*)(result.content) + i * result.rows + j + 1) += *((double*)(mtx1->content) + i * mtx1->rows + k + 1) *
					*((double*)(mtx2->content) + k * mtx2->rows + j + 1);
			}
		}
	}

	return result;
}
