#include <iostream>

double calculate_delta(double a, double b, double c);

int main() {
	// ax^2 + bx + c = 0
	double a(0), b(0), c(0);
	double solution(0);
	std::cin >> a >> b >> c;
	// alternative:
	// scanf("%lf",&a);

	double delta;
	delta = calculate_delta(a, b, c);
	delta = sqrt(delta);

	if (delta == 0) {
		solution = (-1) * b / (2 * a);
		printf("x1=%lf\nx2=%lf", solution, solution);
	}
	else if (delta > 0) {
		solution = ((-1) * b + delta) / (2 * a);
		printf("x1=%lf\n", solution);

		solution = ((-1) * b - delta) / (2 * a);
		printf("x1=%lf\n", solution);
	}
	else printf("Function doesn't have a solution");

	return 1;
}


double calculate_delta(double a, double b, double c) {
	return b * b - 4 * a * c;
}


