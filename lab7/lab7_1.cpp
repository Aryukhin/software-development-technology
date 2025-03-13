#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <numeric>
#include <iostream>

int main() {
    std::srand(static_cast<unsigned int>(std::time(0)));

    int size = 23;
    int firstValue = 12;
    std::vector<int> vec(size);

    std::iota(vec.begin(), vec.end(), firstValue);

    for (int i = 0; i < vec.size(); ++i) {
        int j = i + rand() % (vec.size() - i);
        std::swap(vec[i], vec[j]);
    }

    std::sort(vec.begin(), vec.end(), [](int a, int b) {
        if (a % 3 == 0 && b % 3 != 0) return true;
        if (a % 3 != 0 && b % 3 == 0) return false;
        return a < b;
    });

    for (const auto& v : vec) {
        std::cout << v << " ";
    }
    std::cout << std::endl;

    return 0;
}
