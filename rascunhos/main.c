#include <stdio.h>

// Função para interpolação linear entre dois pontos
double interpolate(double x1, double y1, double x2, double y2, double x) {
    // Verifique se x1 e x2 não são iguais para evitar divisão por zero
    if (x1 == x2) {
        return y1;
    }

    // Calcule a proporção entre x e os pontos x1 e x2
    double ratio = (x - x1) / (x2 - x1);

    // Interpole linearmente entre os valores y1 e y2
    double interpolatedValue = y1 + ratio * (y2 - y1);

    return interpolatedValue;
}

int main() {
    double x1 = 2.0;
    double y1 = 5.0;
    double x2 = 5.0;
    double y2 = 10.0;
    double x = 2.0;

    double interpolatedResult = interpolate(x1, y1, x2, y2, x);

    printf("O valor interpolado em x = %.2f é %.2f\n", x, interpolatedResult);

    return 0;
}