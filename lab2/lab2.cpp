#include <iostream>
#include <list>
using namespace std;
#include <algorithm>
#include <string>
#include <sstream>

// Сформировать динамический список. Описать функцию, которая включает в упорядоченный по убыванию список новое значение,
//  введенное с клавиату-ры, таким образом, чтобы не нарушать упорядоченность.
//--------------------------
// Дана строка символов, представляющих собой арифметическое выражение. Порядок операций определен слева направо. 
// Подсчитайте результат данного выражения.


void add_el(list <int> &lst){

    cout<<"enter the new element"<<endl;
    int new_el;
    cin >> new_el;
    lst.push_back(new_el);
    lst.sort();
    lst.reverse();
    cout<< "new lst:"<<endl;
    for(int j : lst){
        cout<< j<< " ";
        
    }
    cout<<endl;
}

int math_str(string &s){
    stringstream ss(s);
    int result, num;
    char op;

    ss >> result;  // Читаем первое число

    while (ss >> op >> num) {  // Читаем поочерёдно оператор и следующее число
        if (op == '+') {
            result += num;
        } else if (op == '-') {
            result -= num;
        } else if (op == '*') {
            result *= num;
        } else if (op == '/') {
            if (num == 0) {
                throw runtime_error("Zero division");
            }
            result /= num;
        } else {
            throw runtime_error("Unknown operator");
        }
    }

    return result;
    }





int main(){
cout << "--------------------------------First task----------------------------"<< endl;
list <int> test_lst = {4, 9, 3, 7, 5};
add_el(test_lst);
cout<<"----------------------------------Second task----------------------------"<<endl;
string s1 = "14 + 2 - 6 / 2";
try {
cout<<"result of operation: 13"<<math_str(s1)<<endl;
}
catch(exception &e) {
    cout<< e.what()<<endl;
}
}