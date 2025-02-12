#include <iostream>
#include <vector>



template <class T>
void replace_value(std::vector <T>& arr, T new_value, T old_value){
    for (T& element : arr){
        if (element == old_value){
            element = new_value;
        }
    }
}

template <class T>
void printarr(std::vector <T>&arr){
    for (T& element : arr){
        std::cout << element << " ";
    }
    std::cout << std::endl;
}


double div_value(double a, double b){
    if (b == 0){
        throw std::runtime_error("zero div");
    }            
    return a / b; 
}



int main(){
    std::cout << "--------------First part------------------------"<<std::endl;
    std::vector<int> intArr = {1, 2, 3, 4, 5};
    std::cout<<"old int vector is:"<< std::endl;
    printarr(intArr);
    replace_value(intArr, 0, 5);
    std::cout << "new int vector is:"<< std::endl;
    printarr(intArr);

    std::vector<double> doubleArr = {1.5, 2.3, 3.8, 4.2, 5.7};
    std::cout<<"old double vector is:"<< std::endl;
    printarr(doubleArr);
    replace_value(doubleArr, 0.0, 5.7);
    std::cout << "new double vector is:"<< std::endl;
    printarr(doubleArr);

    std::vector<std::string> stringArr = {"one", "two", "three", "four", "five"};
    std::cout<<"old str vector is:"<< std::endl;
    printarr(stringArr);
    replace_value(stringArr, std::string("zero"), std::string("five"));
    std::cout << "new str vector is:"<< std::endl;
    printarr(stringArr);


    std::cout<< "--------------Second part------------------------" << std::endl;
    try {
        double res = div_value(3.0, 2.0);
        std::cout<< "res: " << res << std::endl; 
    }
    catch (std::runtime_error& e) {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
    try {
        double res = div_value(3.0, 0);
        std::cout<< "res: " << res << std::endl; 
    }
    catch (std::runtime_error& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
