// В этом файле только функция main и #include-директивы.
#include "calculator.h"

int main() {
    if (!RunCalculatorCycle()) {
        return 1; // Ошибка выполнения
    }
    return 0; // Успешное выполнение
}
