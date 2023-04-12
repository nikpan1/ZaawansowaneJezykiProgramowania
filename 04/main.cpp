#include <iostream>


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
	result.content = (double**)malloc(sizeof(double) * result.rows * result.columns);


}

