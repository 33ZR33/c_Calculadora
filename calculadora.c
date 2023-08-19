#include <stdio.h>
#include <stdbool.h>

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
        printf("Error: División por cero no permitido.\n");
        return -1;
    }
    return a / b;
}


bool validarOperador(char op) {
    return op == '+' || op == '-' || op == '*' || op == '/';
}

int main() {
    double num1, num2, resultado;
    char operador;
    char opcion;

    do {
        printf("Introduzca la operación en formato (a + b): ");
        if (scanf("%lf %c %lf", &num1, &operador, &num2) != 3 || !validarOperador(operador)) {
            printf("Entrada inválida. Asegúrate de ingresar una operación válida.\n");
            continue; // Vuelve al inicio del bucle
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
                    return 1;
                }
                break;
        }

        printf("Resultado: %.21f %c %.21f = %.21f\n", num1, operador, num2, resultado);
        //Preguntar al usuario si quiere realizar otra operación
        printf("¿Quieres realizar otra operación? (S/N): ");
        scanf(" %c", &opcion); //El espacio antes de %c elimina cualquier whitespace pendiente
    } while (opcion == 'S' || opcion == 's');
    
    printf("¡Hasta luego!.\n");
    return 0;
}
