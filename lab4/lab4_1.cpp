#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Параметризованный класс для проверки палиндрома
template <typename T>
class IsPalindrome {
public:
    bool operator()(const T& str) const {
        // Проверяем, равна ли строка её реверсированной версии
        return str == std::string(str.rbegin(), str.rend());
    }
};

int main() {
    std::vector<std::string> words = {"kazak", "shalash", "dom", "madam"};

    // Используем find_if для нахождения первой строки-палиндрома
    auto it = std::find_if(words.begin(), words.end(), IsPalindrome<std::string>());

    if (it != words.end()) {
        std::cout << "Первая строка-перевертыш: " << *it << std::endl;
    } else {
        std::cout << "Нет строк-перевертышей" << std::endl;
    }

    return 0;
}
