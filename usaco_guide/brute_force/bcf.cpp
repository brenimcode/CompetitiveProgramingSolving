#include <iostream>
using namespace std;

int main()
{
    int x, y, m;
    cin >> x >> y >> m;
    int max = 0;
    for (int i = 0; i * x <= m; i++)
    {
        for (int j = 0; i * x + j * y <= m; j++)
        {
            if (i * x + j * y > max)
            {
                max = i * x + j * y;
            }
        }
    }

    cout << max << endl;
    return 0;
}