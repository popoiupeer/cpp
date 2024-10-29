#include <iostream>
#include <math.h>

using namespace std;


int main() {
    setlocale(LC_ALL, "RUSSIAN");
    double x, y;
    for (int i = 1; i < 6; ++i)
    {
        switch (i)
        {
        case 1:
            x = -1.5; y = 0.1;
            break;
        case 2:
            x = -2.5; y = 0;
            break;
        case 3:
            x = -0.5; y = 0.5;
            break;
        case 4:
            x = -1.5; y = 0.5;
            break;
        case 5:
            x = 0.5;  y = 1.1;
            break;
        default:
            cout << "введите правильные значения " << endl;
            break;

        }
        
        

        if ((x*x + y*y <= 1) && (x*x >= 0) || (y >= -0.5 * x - 1) && (y <= 0.5 * x + 1) && (x < 0))
            cout << "Входит" << endl;
        else
            cout << "Не входит" << endl;

    }
}
