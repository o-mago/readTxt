/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   curva.h
 * Author: Mago
 *
 * Created on July 7, 2020, 3:04 AM
 */

#ifndef CURVA_H
#define CURVA_H


union DataFieldCurva {
    int i;
    float f;

    operator int() const;

    operator float() const;
};

// ================ Class declarations =================
class RegisterFieldsCurva {
public:
    std::string format;
    const int* sequence;

    RegisterFieldsCurva(const std::string f, const int* s);
};



class Bloco1 {
public:
    int numeroSubsistema;
    float penalidade;

    Bloco1(int numeroSubsistema, float penalidade);

    void print();
};

class Reg1Bloco2 {
public:
    int numeroSubsistema;
    
    Reg1Bloco2();

    Reg1Bloco2(int numeroSubsistema);

    void print();
};

class Reg2Bloco2 {
public:
    int ano;
    float jan;
    float fev;
    float mar;
    float abr;
    float mai;
    float jun;
    float jul;
    float ago;
    float set;
    float out;
    float nov;
    float dez;

    Reg2Bloco2(int ano, float jan, float fev, float mar,
            float abr, float mai, float jun, float jul, float ago,
            float set, float out, float nov, float dez);

    void print();
};

class Bloco2 {
public:
    Reg1Bloco2 reg1;
    std::vector<Reg2Bloco2> reg2;
    
    Bloco2();

    Bloco2(Reg1Bloco2 reg1, std::vector<Reg2Bloco2> reg2);
    
    void setReg1(Reg1Bloco2 reg1);
    
    void setReg2(Reg2Bloco2 reg2);

    void print();
};

class Bloco3 {
public:
    int maxIteracoes;
    int iteracaoPenalidade;
    float tolerancia;
    int relatorio;
    
    Bloco3();

    Bloco3(int maxIteracoes, int iteracaoPenalidade, float tolerancia, int relatorio);

    void print();
};

DataFieldCurva getData(std::string, RegisterFieldsCurva);
void printRegisters(std::vector<Bloco1>, std::vector<Bloco2>, Bloco3);
void curva();

#endif /* CURVA_H */

