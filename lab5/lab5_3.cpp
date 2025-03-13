#include <iostream>
#include <vector>
#include <algorithm>

template <int Base>
class PowerCounter {
private:
    int count;
public:
    PowerCounter() : count(0) {}

    void operator()(int num) {
        if (is_power_of_base(num, Base)) {
            count++;
        }
    }

    int get_count() const { return count; }

    static bool is_power_of_base(int num, int base) {
        if (num < 1) return false;
        while (num % base == 0) {
            num /= base;
        }
        return num == 1;
    }
};

int main() {
    std::vector<int> numbers = {1, 3, 9, 27, 4, 6, 81, 10, 243};
    int base = 3;
    int lambda_count = 0;

    // PowerCounter<3> counter = std::for_each(numbers.begin(), numbers.end(), PowerCounter<3>());

    std::for_each(numbers.begin(), numbers.end(), [&](int num) {
        if (PowerCounter<3>::is_power_of_base(num, base)) {
            lambda_count++;
        }
    });

    std::cout << "Count ^3: " << lambda_count << std::endl;

    return 0;
}
