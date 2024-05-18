#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
/*
//Блок 1 задание 2
std::string modifyIP(std::string IP) {
    std::string modAds = "";
    for (char c : IP) {
        if (c == '.') {
            modAds += "[.]";
        }
        else {
            modAds += c;
        }
    }
    return modAds;
}

int main() {
    setlocale(LC_ALL, "rus");
    std::string IP;
    std::cout << "Введите IPv4 адрес: ";
    std::getline(std::cin, IP);

    std::string modIP = modifyIP(IP);

    std::cout << "Измененный адрес: " << modIP << std::endl;

    return 0;
}
*/
// Блок 2 задание 1
/*
bool isPalindrome(std::string str) {
    // Удаляем все пробелы из строки
    str.erase(std::remove(str.begin(), str.end(), ' '), str.end());

    // Преобразуем все символы в нижний регистр
    transform(str.begin(), str.end(), str.begin(), ::tolower);

    // Проверяем, является ли строка палиндромом
    int left = 0;
    int right = str.length() - 1;
    while (left < right) {
        if (str[left] != str[right]) {
            return false;
        }
        left++;
        right--;
    }
    return true;
}

int main() {
    setlocale(LC_ALL, "rus");
    std::string input;
    std::cout << "Введите строку: ";
    std::getline(std::cin, input);

    if (isPalindrome(input)) {
        std::cout << "Строка является палиндромом." << std::endl;
    }
    else {
        std::cout << "Строка не является палиндромом." << std::endl;
    }

    return 0;
}

*/

 //Блок 3
int maxScore(std::vector<std::string> words, std::vector<char> letters, std::vector<int> score) {
    int maxPrice = 0;
    std::string Word = "";
    for (const std::string& word : words) {
        int price = 0;
        std::vector<char> remainingLetters = letters;
        
        for (char letter : word) {
            auto it = std::find(remainingLetters.begin(), remainingLetters.end(), letter);
            if (it != remainingLetters.end()) {
                price += score[letter - 97];
                remainingLetters.erase(it);
            } else {
                price = 0;
                break;
            }
        }

        if (price > maxPrice) {
            maxPrice = price;
            Word = word;
        }
    }
    std::cout << Word << std::endl;
    return maxPrice;
}

int main() {
    setlocale(LC_ALL, "rus");
    std::vector<std::string> words = { "aple", "banana", "orange", "lime" };
    std::vector<char> letters = { 'p', 'p', 'l', 'e', 'n', 'g','r', 'g', 'l' ,'i' ,'m','a','n'};
    std::vector<int> score = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                              11, 12, 13, 14, 15, 16, 17, 18, 19, 20,
                              21, 22, 23, 24, 25, 26};

    int maxPrice = maxScore(words, letters, score);
    std::cout << "Максимальный счёт: " << maxPrice << std::endl;

    return 0;
}