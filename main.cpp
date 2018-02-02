#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

bool isOutOfArrayBounds(int i);

int main()
{
    int i, j, random, count = 0, tmp = -1;
    int landmine[121] = {0};
    srand(time(NULL));

    while(count < 10)
    {
        random = rand() * 97 / (RAND_MAX + 1) + 12;
        if((tmp == random) || isOutOfArrayBounds(random)) continue;
        landmine[random] = 9;
        tmp = random;
        count ++;
    }

    for(i = 0; i < 121; i ++)
    {
        if(isOutOfArrayBounds(i))
            landmine[i] = -1;
    }

    for(i = 12; i <= 108; i ++)
    {
        if(isOutOfArrayBounds(i) || landmine[i] == 9) continue;
        count = 0;
        if(landmine[i - 1] == 9) count ++;
        if(landmine[i + 1] == 9) count ++;
        if(landmine[i + 11] == 9) count ++;
        if(landmine[i - 11] == 9) count ++;
        if(landmine[i + 10] == 9) count ++;
        if(landmine[i - 10] == 9) count ++;
        if(landmine[i + 12] == 9) count ++;
        if(landmine[i - 12] == 9) count ++;
        landmine[i] = count;
    }

    for(i = 0; i < 9; i ++)
    {
        for(j = 0; j < 9; j ++)
            cout << landmine[12 + i * 11 + j] << '\t';
        cout << '\n';
    }
    
    return 0;
}


bool isOutOfArrayBounds(int i)
{
    return (i >= 0 && i <= 10) || i == 11 || i == 21 || i == 22 || i == 32 || i == 33 || i == 43 || i == 44 || i == 54 || i == 55 || i == 65 || i == 66 || i == 76 || i == 77 || i == 87 || i == 88 || i == 98 || i == 99 || i == 109 || (i >= 110 && i <= 120);
}
