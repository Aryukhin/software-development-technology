#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool is_power_of_three(int num) {
    int b = num;
    if (num < 1) return false;
    while (num % 3 == 0) {
        num /= 3;
    }
    if (num == 1){
        cout<< b<<endl;
    }
    return num == 1;
}

int main() {
    std::vector<int> numbers = {1, 3, 9, 27, 4, 6, 81, 10, 243};
    int count = 0;

    std::for_each(numbers.begin(), numbers.end(), [&count](int num) {
        if (num < 1) return false;
        while (num % 3 == 0) {
            num /= 3;
        }
        if (num == 1){
            count++;
        }
        // if (is_power_of_three(num)) {
        //     count++;
        // }
    });

    std::cout << "Count of ^3: " << count << std::endl;
    return 0;
}