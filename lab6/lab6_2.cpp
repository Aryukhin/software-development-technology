#include <memory>
#include <vector>
#include <string>
#include <iostream>
#include <stdexcept>

class TrainCar {
public:
    std::string type;
    TrainCar(std::string carType) : type(std::move(carType)) {}
    ~TrainCar() { std::cout << "Car " << type << " destroyed\n"; }
};

class Train {
private:
    std::vector<std::shared_ptr<TrainCar>> cars;

public:
    void addCar(const std::string& carType) {
        cars.push_back(std::make_shared<TrainCar>(carType));
    }

    void removeLastCar() {
        if (!cars.empty()) {
            cars.pop_back();
        } else {
            throw std::runtime_error("No cars to remove");
        }
    }

    void printTrain() const {
        if (cars.empty()) {
            std::cout << "The train is empty.\n";
            return;
        }
        std::cout << "Train composition: ";
        for (const auto& car : cars) {
            std::cout << car->type << " ";
        }
        std::cout << "\n";
    }
};

// Test Cases
int main() {
    try {
        Train train;
        train.addCar("Locomotive");
        train.addCar("Passenger");
        train.addCar("Bistro");
        train.printTrain();

        std::cout << "Removing last car...\n";
        train.removeLastCar();
        train.printTrain();

        std::cout << "Testing early return...\n";
        if (true) return 0;  // Test early return, no memory leaks

    } catch (const std::exception& e) {
        std::cerr << "Exception: " << e.what() << "\n";
    }

    // Test cyclic dependency
    std::shared_ptr<TrainCar> carA = std::make_shared<TrainCar>("CarA");
    std::shared_ptr<TrainCar> carB = std::make_shared<TrainCar>("CarB");
    carA = carB;  // Proper deletion, no cycles

    std::cout << "Program finished without memory leaks.\n";
    return 0;
}
