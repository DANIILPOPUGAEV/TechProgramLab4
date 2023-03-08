// TechProgramLab4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Point // описание класса
{
private: // закрытые переменные 
    int x;
    int y;
public:
    void set_x(int a) { x = a; } // функции доступа к переменным
    int get_x() { return x; }

    void set_y(int b) { y = b; }
    int get_y() { return y; }

    Point(){} // пустой конструктор 
    ~Point(){} // пустой деструктор

    friend double Square(Point point[4]); // дружественная функция
};
class Watch // Класс часов
{
public:
    string name;
    string country;
    int prise;
    Watch(){}
    ~Watch(){}
};


void FuncOne();
void FuncTwo();
double DlinaStoroni(int x2, int x1, int y1, int y2); //объявление расчёта длины стороны
double Gipotenuza(double a, double b); //объявление расчёта гипотенузы

int main()
{
    setlocale(LC_ALL, "Russian");
    bool tf = true;
    char op;
    while (tf)
    {
        system("CLS");
        cout << "Выберете номер операции:\n";
        cout << "1.Работа с классом point\n";
        cout << "2.Индивидуальное задание\n";
        cout << "3.Завершить работу\n";
        cin >> op;
        switch (op)
        {
            case '1': FuncOne(); break;
            case '2': FuncTwo(); break;
            case '3': tf = false; break;
            default: break;
        }
    }
}

void FuncOne()
{
    Point *point;
    point = new Point[4]; //Динамическое выделение памяти для массива
    int i;
    int a;
    int b;
    for (i = 0; i < 4; i++)
    {
        system("CLS");
        cout << "Введите значение x и у для " << i+1 << " точки\n";
        cin >> a; 
        cin >> b;
        point[i].set_x(a);
        point[i].set_y(b);
    }
    system("CLS");
    cout << "x   y\n";
    for (i = 0; i < 4; i++)
    cout << point[i].get_x() << "   " << point[i].get_y() << "\n";
    double Storona1 = DlinaStoroni(point[0].get_x(), point[1].get_x(), point[0].get_y(), point[1].get_y());
    cout <<"Длина перовой стороны = "<< Storona1 << "\n";
    double Storona2 = DlinaStoroni(point[1].get_x(), point[2].get_x(), point[1].get_y(), point[2].get_y());
    cout << "Длина второй стороны = " << Storona2 << "\n";
    double gipotenuza = Gipotenuza(Storona1, Storona2);
    cout << "Гипотенуза треугольника равна " << gipotenuza << "\n";
    double square = Square(point);
    cout << "Площадь прямоугольника равна " << square << "\n";
    delete[] point; //очищение памяти
    system("pause");
}
double DlinaStoroni(int x2, int x1, int y1, int y2)
{
    double Dlina = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    return Dlina;
}
double Gipotenuza(double a, double b)
{
    double gipotenuza = sqrt(a * a + b * b);
    return gipotenuza;
}
double Square(Point point[4])
{
    double square = DlinaStoroni(point[0].x, point[1].x, point[0].y, point[1].y)
        * DlinaStoroni(point[1].x, point[2].x, point[1].y, point[2].y);
    return square;
}
void FuncTwo()
{
    system("CLS");
    Watch watch[6];
    int i;
    watch[0].name = "Rolex"; watch[0].country = "Швейцария"; watch[0].prise = 740000;
    watch[1].name = "Omega"; watch[1].country = "Швейцария"; watch[1].prise = 680000;
    watch[2].name = "Audermars"; watch[2].country = "Швейцария"; watch[2].prise = 14840000;
    watch[3].name = "Cartier"; watch[3].country = "Франция"; watch[3].prise = 650000;
    watch[4].name = "Chopard"; watch[4].country = "Швейцария"; watch[4].prise = 17220000;
    watch[5].name = "Hallucination "; watch[5].country = "Англия"; watch[5].prise = 330000000;
    for (int i = 0; i < 6; i++)
        cout << setiosflags(ios::left)
        << setw(15) << watch[i].name;
    cout << endl;
    for (int i = 0; i < 6; i++)
        cout << setiosflags(ios::left)
        << setw(15) << watch[i].country;
    cout << endl;
    for (int i = 0; i < 6; i++)
        cout << setiosflags(ios::left)
        << setw(15) << watch[i].prise;
    cout << endl;
    int max = 1;
    int j = 0;
    for (int i = 0; i < 6; i++)
    {
        if (watch[i].prise > max)
        {
            max = watch[i].prise;
            j = i;
        }
    }
    cout << "Самый дорогой экземпляр: " << watch[j].name <<"\n";
    system("Pause");
}


// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
// 6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.