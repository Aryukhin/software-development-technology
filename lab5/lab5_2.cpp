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
    return num == 1;
}




class PowerOfThreeCounter {
private:
    int count;
public:
    PowerOfThreeCounter() : count(0) {}

    void operator()(int num) {
        if (is_power_of_three(num)) {
            count++;
            cout<<num<<endl;
        }
    }

    int get_count() const { return count; }
};

int main() {
    std::vector<int> numbers = {1, 3, 9, 27, 4, 6, 81, 10, 243};
    PowerOfThreeCounter counter;
    std::for_each(numbers.begin(), numbers.end(), ref(counter));

    std::cout << "Count of ^3: " << counter.get_count() << std::endl;
    return 0;
}