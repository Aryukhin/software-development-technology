#include <iostream>
#include <cmath>
#include <ctime>

using namespace std;

// Создать класс- интерфейс пространственной фигуры, который содержит три элемента с модификатором доступа protected. 
// Создать производные классы: усеченная пирамида с ромбическим основанием, прямая призма с квадратным основанием, шаровой слой. 
// Для каждой из фигур предусмотреть вывод ее названия и вычисление площади поверхности. Случайным образом выбрать фигуру и 
// с помощью оператора dynamic_cast произвести конвертацию типа из класса-интерфейса в производный.


class SpatialFigure {
protected:
    double dim1, dim2, dim3;  // Общие размеры фигур
public:
    virtual ~SpatialFigure() {}
    virtual void my_name() const = 0;
    virtual double get_surface_area() const = 0;
    void set_dimensions(double d1, double d2, double d3) {
        dim1 = d1;
        dim2 = d2;
        dim3 = d3;
    }
};

class TruncatedPyramid : public SpatialFigure {
public:
    void my_name() const override {
        cout << "I am a truncated pyramid with a rhombic base" << endl;
    }
    double get_surface_area() const override {
        return 2 * (dim1 * dim2) + 4 * (0.5 * dim1 * dim3);  // Примерная формула
    }
};

class RectangularPrism : public SpatialFigure {
public:
    void my_name() const override {
        cout << "I am a rectangular prism with a square base" << endl;
    }
    double get_surface_area() const override {
        return 2 * (dim1 * dim1 + dim1 * dim2 + dim2 * dim1);
    }
};

class SphericalLayer : public SpatialFigure {
public:
    void my_name() const override {
        cout << "I am a spherical layer" << endl;
    }
    double get_surface_area() const override {
        const double Pi = 3.14159;
        return 2 * Pi * dim1 * dim2;  // dim1 - радиус сферы, dim2 - высота слоя
    }
};

SpatialFigure* GetRandomFigure() {
    switch (rand() % 3) {
        case 0: return new TruncatedPyramid();
        case 1: return new RectangularPrism();
        case 2: return new SphericalLayer();
        default: return nullptr;
    }
}

int main() {
    srand(time(nullptr));
    
    for (int i = 0; i < 4; i++) {
        SpatialFigure* figure = GetRandomFigure();
        figure->my_name();
        
        double d1, d2, d3;
        cout << "Enter dimensions (d1, d2, d3): ";
        cin >> d1 >> d2 >> d3;
        figure->set_dimensions(d1, d2, d3);
        
        cout << "Surface area = " << figure->get_surface_area() << endl;
        
        if (auto* pyramid = dynamic_cast<TruncatedPyramid*>(figure)) {
            cout << "This is a truncated pyramid!" << endl;
        } else if (auto* prism = dynamic_cast<RectangularPrism*>(figure)) {
            cout << "This is a rectangular prism!" << endl;
        } else if (auto* sphere = dynamic_cast<SphericalLayer*>(figure)) {
            cout << "This is a spherical layer!" << endl;
        }
        
        delete figure;
    }
    
    return 0;
}
