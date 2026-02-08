#include "calculator.h"

bool ReadNumber(Number& result) {
    std::string input;

    if (!(std::cin >> input)) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }

    try {
        result = std::stod(input);
    } catch (const std::invalid_argument&) {
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    } catch (const std::out_of_range&) {
        std::cerr << "Error: Number out of range" << std::endl;
        return false;
    }

    return true;
}

bool RunCalculatorCycle() {
    Number currentValue = 0;
    Number memory = 0;
    bool memorySet = false;
    bool isInf = false;  // Флаг для отслеживания состояния деления на 0

    // Инициализация текущего значения
    if (!ReadNumber(currentValue)) {
        return false;
    }

    while (true) {
        std::string command;

        if (!(std::cin >> command)) {
            break;
        }

        if (command == "q") {
            return true; 
        }

        if (isInf) {
            if (command == "=") {
                std::cout << "inf" << std::endl; // Выводим inf
            } else if (command == ":") {
                Number number;
                if (!ReadNumber(number)) {
                    return false;
                }
                currentValue = number; // Устанавливаем новое значение
                isInf = false; 
            }
            continue;
        }

        if (command == "+") {
            Number number;
            if (!ReadNumber(number)) {
                return false;
            }
            currentValue += number;

        } else if (command == "-") {
            Number number;
            if (!ReadNumber(number)) {
                return false;
            }
            currentValue -= number;

        } else if (command == "*") {
            Number number;
            if (!ReadNumber(number)) {
                return false;
            }
            currentValue *= number;

        } else if (command == "/") {
            Number number;
            if (!ReadNumber(number)) {
                return false;
            }
            if (number == 0) {
                isInf = true; 
                continue; 
            }
            currentValue /= number;

        } else if (command == "**") {
            Number number;
            if (!ReadNumber(number)) {
                return false;
            }
            currentValue = std::pow(currentValue, number);

        } else if (command == "=") {
            std::cout << currentValue << std::endl; // Выводим текущее значение

        } else if (command == ":") {
            Number number;
            if (!ReadNumber(number)) {
                return false;
            }
            currentValue = number; // Устанавливаем новое значение

        } else if (command == "c") {
            currentValue = 0; // Сброс текущего значения

        } else if (command == "s") {
            memory = currentValue; 
            memorySet = true; 

        } else if (command == "l") {
            if (!memorySet) {
                std::cerr << "Error: Memory is empty" << std::endl; 
            } else {
                currentValue = memory; 
            }

        } else {
            std::cerr << "Error: Unknown token " << command << std::endl;
            return false;
        }
    }

    return true; // Успешное выполнение
}
