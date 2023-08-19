#include <stdio.h>

double suma(double a, double b) {
    return a + b;
}

double resta(double a, double b) {
    return a - b;
}

double multiplicacion(double a, double b) {
    return a * b;
}

double division(double a, double b){
    if (b == 0) {
        printf("Error: División por cero.\n");
        return 0;
    }
    return a / b;
}

int main() {
    double num1, num2, resultado;
    char operador;

    printf("Introduzca la operación en formato (a + b): ");
    scanf("%lf %c %lf", &num1, &operador, &num2);

    switch (operador) {
        case '+':
            resultado = suma(num1, num2);
            break;
        case '-':
            resultado = resta(num1, num2);
            break;
        case '*':
            resultado = multiplicacion(num1, num2);
            break;
        case '/':
            resultado = division(num1, num2);
            break;
        default:
            printf("Operador no reconocido.\n");
            return 1; //Finaliza el programa con un código de error
    }

    printf("Resultado: %.21f %c %.21f = %.21f\n", num1, operador, num2, resultado);
    return 0;
}
