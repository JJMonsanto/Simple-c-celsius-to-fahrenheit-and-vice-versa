#include <stdio.h>

void celsiusToFahrenheit(void);
void fahrenheitToCelsius(void);

int main(void) {
    celsiusToFahrenheit();
    fahrenheitToCelsius();
    return 0;
}

void celsiusToFahrenheit(void) {
    double celsius, fahrenheit;

    printf("Enter celsius temperature to be converted: ");
    scanf("%lf", &celsius);

    fahrenheit = 32.0 + (celsius * (180.0 / 100.0));

    printf("Fahrenheit: %.2f\n\n", fahrenheit);
}

void fahrenheitToCelsius(void) {
    double celsius, fahrenheit;

    printf("Enter fahrenheit temperature to be converted: ");
    scanf("%lf", &fahrenheit);

    celsius = (fahrenheit - 32.0) * (100.0 / 180.0);

    printf("Celsius: %.2f\n\n", celsius);
}
