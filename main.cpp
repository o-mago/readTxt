// ================= Importing dependencies ==================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "curva.h"
#include "penalid.h"
// ===========================================================

#define FILE 1 //0 - CURVA.DAT; 1 - PENALID.DAT

int main() {
    if(FILE == 0) {
        curva();
    } else if(FILE == 1) {
        penalid();
    }
}
// ====================================================================