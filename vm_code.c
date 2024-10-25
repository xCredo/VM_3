#include <stdio.h>

double f(double x, double y) {
    return x + y;
}

void runge_kutta(double x0, double y0, double h, double x_max) {
    double x = x0;
    double y = y0;
    
    printf("x\t  y\n");
    printf("%0.4f\t  %0.4f\n", x, y);

    while (x < x_max) {
        double k1 = h * f(x, y);
        double k2 = h * f(x + h / 2, y + k1 / 2);
        double k3 = h * f(x + h / 2, y + k2 / 2);
        double k4 = h * f(x + h, y + k3);
        
        y = y + (k1 + 2*k2 + 2*k3 + k4) / 6;
        x = x + h;
        
        printf("%0.4f\t  %0.4f\n", x, y);
    }
}

int main() {
    double x0 = 0.0;
    double y0 = 1.0;
    double h = 0.1; 
    double x_max = 10.0;

    runge_kutta(x0, y0, h, x_max);

    return 0;
}
