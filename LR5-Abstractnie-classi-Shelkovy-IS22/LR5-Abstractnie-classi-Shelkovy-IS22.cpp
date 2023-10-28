#include <iostream>
#include <string.h>
#include <string>
#include <cmath>

using namespace std;

double getPI()
{
    return 3.141592653589793;
}

class Triangle
{
public:
    virtual void Read() = 0;
    virtual void Print() const = 0;

    virtual double GetSquare() const = 0;
    virtual double GetPerimeter() const = 0;
private:
    double sideA;
    double sideB;
    double angleAB;
};

class RightTriangle : public Triangle
{
public:
    double GetSquare() const override
    {
        return firstCathetus * secondCathetus * 0.5;
    }

    double GetPerimeter() const override
    {
        return firstCathetus + secondCathetus + GetHypotenuse();
    }

    double GetHypotenuse() const
    {
        return sqrt(firstCathetus * firstCathetus + secondCathetus * secondCathetus);
    }

    double GetAngleFirstWithHypotenuse() const
    {
        return atan(secondCathetus / firstCathetus) * 180 / getPI();
    }

    double GetAngleSecondWithHypotenuse() const
    {
        return atan(firstCathetus / secondCathetus) * 180 / getPI();
    }

    void Read() override
    {
        cin >> firstCathetus;
        cin >> secondCathetus;
    }

    void Print() const override
    {
        cout << "RightTriangle sides: ";
        cout << firstCathetus << ", " << secondCathetus << ", " << GetHypotenuse() << " ";
        cout << "angles: " << GetAngleFirstWithHypotenuse() << ", " << GetAngleSecondWithHypotenuse() << ", 90 ";
        cout << "Perimeter=" << GetPerimeter() << " " << "Square=" << GetSquare() << endl;
    }
private:
    double firstCathetus = 1;
    double secondCathetus = 1;
};

class IsoscelesTriangle : public Triangle
{
public:
    void Read() override
    {
        cin >> edge;
        cin >> baseAngle;
    }

    void Print() const override
    {
        cout << "IsoscelesTriangle sides: ";
        cout << edge << ", " << edge << ", " << GetBase() << " ";
        cout << "angles: " << (180 - baseAngle) / 2 << ", " << (180 - baseAngle) / 2 << ", " << baseAngle << " ";
        cout << "Perimeter=" << GetPerimeter() << " " << "Square=" << GetSquare() << endl;
    }

    double GetBase() const
    {
        return 2 * edge * sin((baseAngle / 2) * getPI() / 180);
    }

    double GetPerimeter() const override
    {
        return edge * 2 + GetBase();
    }

    double GetSquare() const override
    {
        double b = GetBase();
        return b * sqrt(4 * edge * edge - b * b) / 4;
    }

private:
    double edge = 1;
    double baseAngle = 60;
};

class EquilateralTriangle : Triangle
{
public:
    void Read() override
    {
        cin >> edge;
    }

    void Print() const override
    {
        cout << "EquilateralTriangle sides: ";
        cout << edge << ", " << edge << ", " << edge << " ";
        cout << "angles: " << 60 << ", " << 60 << ", " << 60 << " ";
        cout << "Perimeter=" << GetPerimeter() << " " << "Square=" << GetSquare() << endl;
    }

    double GetPerimeter() const override
    {
        return edge + edge + edge;
    }

    double GetSquare() const override
    {
        return sqrt(edge * edge * edge * edge * 3 / 16);
    }
private:
    double edge = 1;
};

int main()
{
    RightTriangle rT;
    IsoscelesTriangle iT;
    EquilateralTriangle eT;

    rT.Read();
    iT.Read();
    eT.Read();

    rT.Print();
    iT.Print();
    eT.Print();

    int op;
    while (true)
    {
        cin >> op;
        if (op == 0) break;
        else if (op == 1)
        {
            rT.Read();
            rT.Print();
        }
        else if (op == 2)
        {
            iT.Read();
            iT.Print();
        }
        else if (op == 3)
        {
            eT.Read();
            eT.Print();
        }
    }
}
