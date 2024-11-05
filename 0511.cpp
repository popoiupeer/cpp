#include <iostream>
using namespace std;

int main()
{
    int array[9][9];

    for (int i = 0; i < 9; ++i)
    {
        for (int j = 0; j < 9; ++j)
        {
            array[i][j] = 0;
            if (j == 9 / 2 || i == 9 / 2)
            {
                array[i][j] = 1;
            }
            cout << array[i][j];
        }
        cout << endl;
    }
}
