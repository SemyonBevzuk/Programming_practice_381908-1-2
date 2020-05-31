#include "Hall.h"


Hall Halls::getHall(int num)
{
    switch (num)
    {
    case 1: return Hall{ 30, 10, 3, 10 };
    case 2: return Hall{ 10, 10, 2, 10 };
    case 3: return Hall{ 20, 20, 3, 20 };
    default:
        break;
    }
}
