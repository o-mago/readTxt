/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   penalid.h
 * Author: Mago
 *
 * Created on July 7, 2020, 3:04 AM
 */

#ifndef PENALID_H
#define PENALID_H

union DataFieldPenalid {
    int i;
    float f;
    std::string* s;

    operator int() const;

    operator float() const;
    
    operator std::string() const;
};

// ================ Class declarations =================
class RegisterFieldsPenalid {
public:
    std::string format;
    const int* sequence;

    RegisterFieldsPenalid(const std::string f, const int* s);
};

class Bloco {
public:
    std::string pchave;
    float penalid1;
    float penalid2;
    int sis;
    int pat;

    Bloco(std::string pchave, float penalid1, float penalid2, int sis, int pat);

    void print();
};

// ================= Functions definitions ====================
DataFieldPenalid getData(std::string, RegisterFieldsPenalid);
void printRegisters(std::vector<Bloco>);
std::string getStringData(std::string text, RegisterFieldsPenalid field);
void penalid();
// ============================================================

#endif /* PENALID_H */

