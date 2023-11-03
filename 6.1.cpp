#include <iostream>
#include <vector>
#include <cstdlib>

// Функція для створення масиву та заповнення його випадковими значеннями в заданому діапазоні
std::vector<int> createArray(int size, int minValue, int maxValue) {
    std::vector<int> array;
    for (int i = 0; i < size; i++) {
        array.push_back(rand() % (maxValue - minValue + 1) + minValue);
    }
    return array;
}

// Функція для обчислення кількості та суми додатніх елементів, крім кратних 5
std::pair<int, int> calculateCountAndSum(const std::vector<int>& array) {
    int count = 0;
    int totalSum = 0;

    for (int element : array) {
        if (element > 0 && element % 5 != 0) {
            count++;
            totalSum += element;
        }
    }

    return std::make_pair(count, totalSum);
}

// Функція для заміни нулями додатніх елементів, крім кратних 5
void replaceWithZeros(std::vector<int>& array) {
    for (int& element : array) {
        if (element > 0 && element % 5 != 0) {
            element = 0;
        }
    }
}

int main() {
    srand(static_cast<unsigned>(time(nullptr)));

    int size = 20;
    int minValue = -20;
    int maxValue = 50;

    // Створення масиву та виведення його на екран
    std::vector<int> myArray = createArray(size, minValue, maxValue);
    std::cout << "Початковий масив:" << std::endl;
    for (int element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    // Обчислення кількості та суми, а також заміна елементів
    std::pair<int, int> result = calculateCountAndSum(myArray);
    replaceWithZeros(myArray);

    // Виведення результатів
    std::cout << "Кількість додатніх некратних 5 елементів: " << result.first << std::endl;
    std::cout << "Сума додатніх некратних 5 елементів: " << result.second << std::endl;
    std::cout << "Модифікований масив:" << std::endl;
    for (int element : myArray) {
        std::cout << element << " ";
    }
    std::cout << std::endl;

    return 0;
}
