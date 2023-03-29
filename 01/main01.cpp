#include <stdio.h>
#include <math.h>


struct Comp { double a; double b; double c; };
struct Result { double x1; double x2; };

void solve(Comp* cp);
double calc_delta(Comp* cp);

int main() {
    // ax ^ 2 + bx + c
    Comp comp;
    comp.a = 1;
    comp.b = 1;
    comp.c = 1;

    solve(&comp);

    return 0;
}

double calc_delta(Comp* cp) {
    return cp->b * cp->b - (4 * cp->a * cp->c);
}

void solve(Comp* cp) {
    Result result;

    if (cp->a == 0) {
        result.x1 = -1 * cp->c / cp->b;
        result.x2 = -1 * cp->c / cp->b;
    }

    double delta = calc_delta(cp);
    if (delta < 0) printf("nie ma rozwi¹zania, delta < 0");
    else if (delta == 0) {
        result.x1 = -1 * cp->b / (2 * cp->a);
        result.x2 = -1 * cp->b / (2 * cp->a);
    }
    else {
        result.x1 = (-cp->b - sqrt(delta)) / (2 * cp->a);
        result.x2 = (-cp->b + sqrt(delta)) / (2 * cp->a);
    }

    printf("Rozwiazania");
    //printf(result.x1, result.x2);
}


