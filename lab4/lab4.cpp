#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// Функциональный объект для проверки палиндрома
class IsPalindrome {
public:
    bool operator()(const std::string& str) const {
        // Проверяем, равна ли строка её реверсированной версии
        return str == std::string(str.rbegin(), str.rend());
    }
};

int main() {
    std::vector<std::string> words = {"kazak", "shalash", "dom", "madam"};

    auto it = std::find_if(words.begin(), words.end(), IsPalindrome());

    if (it != words.end()) {
        std::cout << "Первая строка-перевертыш: " << *it << std::endl;
    } else {
        std::cout << "Нет строк-перевертышей" << std::endl;
    }

    return 0;
}