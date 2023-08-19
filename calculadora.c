#include <stdio.h>
#include <stdbool.h>
#include <math.h>

double suma(double a, double b) {
    return a + b;
}

double resta(double a, double b) {
    return a - b;
}

double multiplicacion(double a, double b) {
    return a * b;
}

double division(double a, double b) {
    if (b == 0) {
        printf("Error: División por cero no permitida.\n");
        return -1;  // Un valor indicador de error
    }
    return a / b;
}

double potencia(double base, double exponente) {
    return pow(base, exponente);
}

double raizCuadrada(double a) {
    if (a < 0) {
        printf("Error: No es posible calcular la raíz cuadrada de un número negativo.\n");
        return -1;  // Un valor indicador de error
    }
    return sqrt(a);
}

bool validarOperador(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/' || op == '^' || op == 'r';
}

int main() {
    double num1, num2, resultado;
    char operador;
    char opcion;

    do {
        printf("Introduce la operación (ejemplo: a + b): ");
        if (scanf("%lf %c %lf", &num1, &operador, &num2) != 3 || !validarOperador(operador)) {
            printf("Entrada inválida. Asegúrate de ingresar una operación válida.\n");
            continue;
        }

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
                if (resultado == -1) {
                    continue;
                }
                break;
            case '^':
                resultado = potencia(num1, num2);
                break;
            case 'r':
                resultado = raizCuadrada(num1);
                if (resultado == -1) {
                    continue;
                }
                break;
        }

        printf("Resultado: %.2lf %c %.2lf = %.2lf\n", num1, operador, num2, resultado);

        printf("¿Quieres realizar otra operación? (S/N): ");
        scanf(" %c", &opcion);

    } while (opcion == 'S' || opcion == 's');

    printf("¡Gracias por usar la calculadora! Hasta luego.\n");
    return 0;
}

