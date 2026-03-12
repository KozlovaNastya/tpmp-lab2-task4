#include <stdbool.h>
#include "person.h"

bool FirstBiggerSecond(Date a, Date b) {
    if (a.year > b.year) return true;
    if (a.year < b.year) return false;
    
    if (a.month > b.month) return true;
    if (a.month < b.month) return false;
    
    if (a.day > b.day) return true;
    return false;
}
