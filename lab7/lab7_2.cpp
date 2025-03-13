#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>

int main() {

    std::srand(std::time(0)); 

    std::vector<int> arr(1000);
    for (int i = 0; i < 1000; ++i) {
        arr[i] = rand() % 10 + 1;
    }

    std::cout << "Array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    int max_count = 1;  
    std::vector<int> longest_sequence;

    for (int i = 0; i < arr.size(); ++i) {
        auto it = std::search_n(arr.begin() + i, arr.end(), 2, arr[i]);
        if (it != arr.end()) {
            size_t length = std::distance(it, std::find_if(it, arr.end(), [value = arr[i]](int val) { return val != value; }));
            if (length > max_count) {
                max_count = (int)length;
                
                longest_sequence.clear();
                for (int j = 0; j < length; ++j) {
                    longest_sequence.push_back(*(it + j));
                }
            }
        }
    }

    // Выводим результат
    std::cout << "The most length of same num: " << max_count << std::endl;
    std::cout << "The longest sequence: ";
    for (int num : longest_sequence) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
