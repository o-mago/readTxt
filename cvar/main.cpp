// ================= Importing dependencies ==================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
// ===========================================================

//================= Input file name (put the file inside the same folder of the main.cpp file) ====================
const std::string fileName = "CVAR.DAT";
//=================================================================================================================

// ================ Union declarations =================
union DataField {
    int i;
    float f;

    operator int() const {
        return i;
    }

    operator float() const {
        return f;
    }
};
// ====================================================

// ================ Class declarations =================
class RegisterFields {
public:
    std::string format;
    const int* sequence;

    RegisterFields(const std::string f, const int* s) {
        this->format = f;
        this->sequence = s;
    }
};



class Bloco1 {
public:
    float alpha;
    float lambda;
    
    Bloco1() {
    }

    Bloco1(float alpha, float lambda) {
        this->alpha = alpha;
        this->lambda = lambda;
    }

    void print() {
        std::cout << "Valores constantes no tempo" << std::endl << "(α: " << this->alpha <<
                "\nλ: " << this->lambda << ")" << std::endl;
    }
};

class Reg1 {
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
    
    Reg1() {
    }
    
    Reg1(int ano, float jan, float fev, float mar,
            float abr, float mai, float jun, float jul, float ago,
            float set, float out, float nov, float dez) {

        this->ano = ano;
        this->jan = jan;
        this->fev = fev;
        this->mar = mar;
        this->abr = abr;
        this->mai = mai;
        this->jun = jun;
        this->jul = jul;
        this->ago = ago;
        this->set = set;
        this->out = out;
        this->nov = nov;
        this->dez = dez;
    }

    void print() {
        std::cout << "[ano: " << this->ano << std::endl <<
                "jan: " << this->jan << std::endl <<
                "fev: " << this->fev << std::endl <<
                "mar: " << this->mar << std::endl <<
                "abr: " << this->abr << std::endl <<
                "mai: " << this->mai << std::endl <<
                "jun: " << this->jun << std::endl <<
                "jul: " << this->jul << std::endl <<
                "ago: " << this->ago << std::endl <<
                "set: " << this->set << std::endl <<
                "out: " << this->out << std::endl <<
                "nov: " << this->nov << std::endl <<
                "dez: " << this->dez << "]" << std::endl;
    }
};

class Reg2 : public Reg1 {
public:
    std::string staticString;
    
    Reg2() {
        this->staticString = "<EMPTY>";
    }
    
    Reg2(std::string staticString, float jan, float fev, float mar,
            float abr, float mai, float jun, float jul, float ago,
            float set, float out, float nov, float dez) {

        this->staticString = staticString;
        this->jan = jan;
        this->fev = fev;
        this->mar = mar;
        this->abr = abr;
        this->mai = mai;
        this->jun = jun;
        this->jul = jul;
        this->ago = ago;
        this->set = set;
        this->out = out;
        this->nov = nov;
        this->dez = dez;
    }
    
    void print() {
        std::cout << "[string: " << this->staticString << std::endl <<
                "jan: " << this->jan << std::endl <<
                "fev: " << this->fev << std::endl <<
                "mar: " << this->mar << std::endl <<
                "abr: " << this->abr << std::endl <<
                "mai: " << this->mai << std::endl <<
                "jun: " << this->jun << std::endl <<
                "jul: " << this->jul << std::endl <<
                "ago: " << this->ago << std::endl <<
                "set: " << this->set << std::endl <<
                "out: " << this->out << std::endl <<
                "nov: " << this->nov << std::endl <<
                "dez: " << this->dez << "]" << std::endl;
    }
};

class Bloco2 {
public:
    std::vector<Reg1> reg1;
    Reg2 reg2;
    Reg2 reg3;
    
    Bloco2() {
    }

    Bloco2(std::vector<Reg1> reg1, Reg2 reg2, Reg2 reg3) {
        this->reg1 = reg1;
        this->reg2 = reg2;
        this->reg3 = reg3;
    }
    
    void setReg1(Reg1 reg1) {
        this->reg1.push_back(reg1);
    }
    
    void setReg2(Reg2 reg2) {
        this->reg2 = reg2;
    }
    
    void setReg3(Reg2 reg3) {
        this->reg3 = reg3;
    }
    
public:
    void print() {
        std::cout << "α variaveis no tempo" << std::endl;
        
        if(this->reg2.staticString != "<EMPTY>") {
            this->reg2.print();
        }
        
        for (std::vector<Reg1>::iterator it = this->reg1.begin(); it != this->reg1.end(); ++it) {
            (*it).print();
        }
        
        if(this->reg3.staticString != "<EMPTY>") {
            this->reg3.print();
        }
                
        std::cout << std::endl;
    }
};

class Bloco3 : public Bloco2 {
    
public:
    void print() {
        std::cout << "λ variaveis no tempo" << std::endl;
        
        if(this->reg2.staticString != "<EMPTY>") {
            this->reg2.print();
        }
        
        for (std::vector<Reg1>::iterator it = this->reg1.begin(); it != this->reg1.end(); ++it) {
            (*it).print();
        }
        
        if(this->reg3.staticString != "<EMPTY>") {
            this->reg3.print();
        }
        
        std::cout << std::endl;
    }
};

// ================= Functions definitions ====================
DataField getData(std::string, RegisterFields);
void printRegisters(Bloco1, Bloco2, Bloco3);
std::string getStringData(std::string text, RegisterFields field);
// ============================================================

// ================= Fields formats and number sequences definitions ======================

// ----------------- Bloco 1 -------------------
const char REGISTROS_OBRIGATORIOS_1 = 2;

// Registro tipo 1
const int ALPHA_SEQ[] = {8, 12};
const RegisterFields ALPHA = RegisterFields("F5.1", ALPHA_SEQ);

const int LAMBDA_SEQ[] = {15, 19};
const RegisterFields LAMBDA = RegisterFields("F5.1", LAMBDA_SEQ);
// ---------------------------------------------

// ---------------- Blocos 2 E 3 --------------------
const char REGISTROS_OBRIGATORIOS_2_3 = 2;

const std::string PERIODO_ESTATICO_INICIAL = "PRE";
const std::string PERIODO_ESTATICO_FINAL = "POS";

const int FIRST_POSITION_SEQ[] = {1, 7};
const RegisterFields FIRST_POSITION = RegisterFields("A7", FIRST_POSITION_SEQ);

const int PERCENTUAL_JAN_SEQ[] = {8, 12};
const RegisterFields PERCENTUAL_JAN = RegisterFields("F5.1", PERCENTUAL_JAN_SEQ);

const int PERCENTUAL_FEV_SEQ[] = {15, 19};
const RegisterFields PERCENTUAL_FEV = RegisterFields("F5.1", PERCENTUAL_FEV_SEQ);

const int PERCENTUAL_MAR_SEQ[] = {22, 26};
const RegisterFields PERCENTUAL_MAR = RegisterFields("F5.1", PERCENTUAL_MAR_SEQ);

const int PERCENTUAL_ABR_SEQ[] = {29, 33};
const RegisterFields PERCENTUAL_ABR = RegisterFields("F5.1", PERCENTUAL_ABR_SEQ);

const int PERCENTUAL_MAI_SEQ[] = {36, 40};
const RegisterFields PERCENTUAL_MAI = RegisterFields("F5.1", PERCENTUAL_MAI_SEQ);

const int PERCENTUAL_JUN_SEQ[] = {43, 47};
const RegisterFields PERCENTUAL_JUN = RegisterFields("F5.1", PERCENTUAL_JUN_SEQ);

const int PERCENTUAL_JUL_SEQ[] = {50, 54};
const RegisterFields PERCENTUAL_JUL = RegisterFields("F5.1", PERCENTUAL_JUL_SEQ);

const int PERCENTUAL_AGO_SEQ[] = {57, 61};
const RegisterFields PERCENTUAL_AGO = RegisterFields("F5.1", PERCENTUAL_AGO_SEQ);

const int PERCENTUAL_SET_SEQ[] = {64, 68};
const RegisterFields PERCENTUAL_SET = RegisterFields("F5.1", PERCENTUAL_SET_SEQ);

const int PERCENTUAL_OUT_SEQ[] = {71, 75};
const RegisterFields PERCENTUAL_OUT = RegisterFields("F5.1", PERCENTUAL_OUT_SEQ);

const int PERCENTUAL_NOV_SEQ[] = {78, 82};
const RegisterFields PERCENTUAL_NOV = RegisterFields("F5.1", PERCENTUAL_NOV_SEQ);

const int PERCENTUAL_DEZ_SEQ[] = {85, 89};
const RegisterFields PERCENTUAL_DEZ = RegisterFields("F5.1", PERCENTUAL_DEZ_SEQ);
// ---------------------------------------------------


// ================== Parsing file ==================
int main() {
    std::string line;
    int lineCount = 0;
    Bloco1 bloco1;
    Bloco2 bloco2;
    Bloco3 bloco3;
    char block = 1;
    int lastLineBlock = 1;

    std::ifstream file(fileName);

    while (getline(file, line)) {
        lineCount++;
        if(block == 1) {
            if (lineCount <= REGISTROS_OBRIGATORIOS_1) {
                continue;
            }

            if (lineCount == 3) {
                bloco1 = Bloco1(getData(line, ALPHA), getData(line, LAMBDA));
            } else {
                block = 2;
                lastLineBlock = lineCount - 1;
            }
        } else {
            if (lineCount <= lastLineBlock + REGISTROS_OBRIGATORIOS_2_3) {
                continue;
            }

            std::string firstPosition = getStringData(line, FIRST_POSITION);
            firstPosition.erase(std::remove(firstPosition.begin(),firstPosition.end(),' '), firstPosition.end());
            
            if (firstPosition == PERIODO_ESTATICO_INICIAL) {
                Reg2 reg = Reg2(firstPosition,
                        getData(line, PERCENTUAL_JAN),
                        getData(line, PERCENTUAL_FEV),
                        getData(line, PERCENTUAL_MAR),
                        getData(line, PERCENTUAL_ABR),
                        getData(line, PERCENTUAL_MAI),
                        getData(line, PERCENTUAL_JUN),
                        getData(line, PERCENTUAL_JUL),
                        getData(line, PERCENTUAL_AGO),
                        getData(line, PERCENTUAL_SET),
                        getData(line, PERCENTUAL_OUT),
                        getData(line, PERCENTUAL_NOV),
                        getData(line, PERCENTUAL_DEZ));
                if(block == 2) {
                    bloco2.setReg2(reg);
                } else {
                    bloco3.setReg2(reg);
                }
            } else if (firstPosition == PERIODO_ESTATICO_FINAL) {
                Reg2 reg = Reg2(firstPosition,
                        getData(line, PERCENTUAL_JAN),
                        getData(line, PERCENTUAL_FEV),
                        getData(line, PERCENTUAL_MAR),
                        getData(line, PERCENTUAL_ABR),
                        getData(line, PERCENTUAL_MAI),
                        getData(line, PERCENTUAL_JUN),
                        getData(line, PERCENTUAL_JUL),
                        getData(line, PERCENTUAL_AGO),
                        getData(line, PERCENTUAL_SET),
                        getData(line, PERCENTUAL_OUT),
                        getData(line, PERCENTUAL_NOV),
                        getData(line, PERCENTUAL_DEZ));

                if(block == 2) {
                    bloco2.setReg3(reg);
                } else {
                    bloco3.setReg3(reg);
                }
                block = 3;
                lastLineBlock = lineCount;
            } else if(line.at(0) == ' ') {
                int ano = std::stoi(firstPosition);
                Reg1 reg = Reg1(ano,
                        getData(line, PERCENTUAL_JAN),
                        getData(line, PERCENTUAL_FEV),
                        getData(line, PERCENTUAL_MAR),
                        getData(line, PERCENTUAL_ABR),
                        getData(line, PERCENTUAL_MAI),
                        getData(line, PERCENTUAL_JUN),
                        getData(line, PERCENTUAL_JUL),
                        getData(line, PERCENTUAL_AGO),
                        getData(line, PERCENTUAL_SET),
                        getData(line, PERCENTUAL_OUT),
                        getData(line, PERCENTUAL_NOV),
                        getData(line, PERCENTUAL_DEZ));

                if(block == 2) {
                    bloco2.setReg1(reg);
                } else {
                    bloco3.setReg1(reg);
                }
            } else if(block == 2) {
                block = 3;
                lastLineBlock = lineCount - 1; 
            }
        }
    }

    printRegisters(bloco1, bloco2, bloco3);

    file.close();
}

// ======================= Printing parsed data =========================
void printRegisters(Bloco1 bloco1, Bloco2 bloco2, Bloco3 bloco3) {
    bloco1.print();

    std::cout << std::endl;

    bloco2.print();

    std::cout << std::endl;
    
    bloco3.print();

    std::cout << std::endl;
}

// ===================== Handling data formats ========================

std::string getStringData(std::string text, RegisterFields field) {
    std::string extract = "";
    try {
        text.at(field.sequence[1]-1);
        extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
    } catch (const std::exception& e) {
        extract = "empty";
    }
    return extract;
}

DataField getData(std::string text, RegisterFields field) {
    DataField data;
    switch (field.format.at(0)) {
        case 'I':
        {
            try {
                text.at(field.sequence[1]-1);
                std::string extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
                data.i = std::stoi(extract);
            }
            catch (const std::exception& e) {
                data.i = -1;
            }
            break;
        }
        case 'F':
        {
            /*const int decimalNumber = (field.format.at(3) - '0');
            const int integerNumber = (field.format.at(1) - '0') - decimalNumber;
            const int start = field.sequence[0] - 1;
            const std::string integerSlice = text.substr(start, integerNumber);
            const std::string decimalSlice = text.substr(start + integerNumber, decimalNumber);
            data.f = stof(integerSlice + "." + decimalSlice);*/
            try {
                text.at(field.sequence[1]-1);
                std::string extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
                data.f = std::stof(extract);
            }
            catch (const std::exception& e) {
                std::cout << "entrou nesse trem" << std::endl;
                data.f = -1.0;
            }
            break;
        }
    }
    return data;
}
// ====================================================================