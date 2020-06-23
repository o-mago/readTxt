// ================= Importing dependencies ==================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// ===========================================================

//================= Input file name (put the file inside the same folder of the main.cpp file) ====================
const std::string fileName = "CURVA.DAT";
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
        for (int i = 0; i < sizeof (this->sequence); i++) {
            this->sequence = s;
        }
    }
};



class Bloco1 {
public:
    int numeroSubsistema;
    float penalidade;

    Bloco1(int numeroSubsistema, float penalidade) {
        this->numeroSubsistema = numeroSubsistema;
        this->penalidade = penalidade;
    }

    void print() {
        std::cout << "Bloco1 (numeroSubsistema: " << this->numeroSubsistema <<
                "\npenalidade: " << this->penalidade << ")" << std::endl;
    }
};

class Reg1Bloco2 {
public:
    int numeroSubsistema;
    
    Reg1Bloco2() {
    }

    Reg1Bloco2(int numeroSubsistema) {
        this->numeroSubsistema = numeroSubsistema;
    }

    void print() {
        std::cout << "(numeroSubsistema: " << this->numeroSubsistema << ")" << std::endl;
    }
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

class Bloco2 {
public:
    Reg1Bloco2 reg1;
    std::vector<Reg2Bloco2> reg2;
    
    Bloco2() {
    }

    Bloco2(Reg1Bloco2 reg1, std::vector<Reg2Bloco2> reg2) {
        this->reg1 = reg1;
        this->reg2 = reg2;
    }
    
    void setReg1(Reg1Bloco2 reg1) {
        this->reg1 = reg1;
    }
    
    void setReg2(Reg2Bloco2 reg2) {
        this->reg2.push_back(reg2);
    }

    void print() {
        std::cout << "Bloco2 ";
        
        this->reg1.print();
        
        for (std::vector<Reg2Bloco2>::iterator it = this->reg2.begin(); it != this->reg2.end(); ++it) {
            (*it).print();
        }
        
        std::cout << std::endl;
    }
};

class Bloco3 {
public:
    int maxIteracoes;
    int iteracaoPenalidade;
    float tolerancia;
    int relatorio;
    
    Bloco3() {
    }

    Bloco3(int maxIteracoes, int iteracaoPenalidade, float tolerancia, int relatorio) {
        this->maxIteracoes = maxIteracoes;
        this->iteracaoPenalidade = iteracaoPenalidade;
        this->tolerancia = tolerancia;
        this->relatorio = relatorio;
    }

    void print() {
        std::cout << "Bloco4 (maxIteracoes: " << this->maxIteracoes << std::endl <<
                "iteracaoPenalidade: " << this->iteracaoPenalidade << std::endl <<
                "tolerancia: " << this->tolerancia << std::endl <<
                "relatorio: " << this->relatorio << ")" << std::endl;
    }
};

// ================= Functions definitions ====================
DataField getData(std::string, RegisterFields);
void printRegisters(std::vector<Bloco1>, std::vector<Bloco2>, Bloco3);
// ============================================================

// ================= Fields formats and number sequences definitions ======================

// ----------------- Bloco 1 -------------------
const char REGISTROS_OBRIGATORIOS_1 = 4;

// Registro tipo 1
const int NUMERO_SUBSISTEMA_1_SEQ[] = {2, 4};
const RegisterFields NUMERO_SUBSISTEMA_1 = RegisterFields("I3", NUMERO_SUBSISTEMA_1_SEQ);

const int PENALIDADE_1_SEQ[] = {12, 18};
const RegisterFields PENALIDADE_1 = RegisterFields("F7.2", PENALIDADE_1_SEQ);

const int LIMITADOR_BLOCO_1 = 999;
// ---------------------------------------------

// ---------------- Bloco 2 --------------------
const char REGISTROS_OBRIGATORIOS_2 = 3;

// Registro tipo 1
const int NUMERO_SUBSISTEMA_2_SEQ[] = {2, 4};
const RegisterFields NUMERO_SUBSISTEMA_2 = RegisterFields("I3", NUMERO_SUBSISTEMA_2_SEQ);

// Registro tipo 2
const int ANO_2_SEQ[] = {1, 4};
const RegisterFields ANO_2 = RegisterFields("I4", ANO_2_SEQ);

const int PERCENTUAL_JAN_2_SEQ[] = {7, 11};
const RegisterFields PERCENTUAL_JAN_2 = RegisterFields("F5.1", PERCENTUAL_JAN_2_SEQ);

const int PERCENTUAL_FEV_2_SEQ[] = {13, 17};
const RegisterFields PERCENTUAL_FEV_2 = RegisterFields("F5.1", PERCENTUAL_FEV_2_SEQ);

const int PERCENTUAL_MAR_2_SEQ[] = {19, 23};
const RegisterFields PERCENTUAL_MAR_2 = RegisterFields("F5.1", PERCENTUAL_MAR_2_SEQ);

const int PERCENTUAL_ABR_2_SEQ[] = {25, 29};
const RegisterFields PERCENTUAL_ABR_2 = RegisterFields("F5.1", PERCENTUAL_ABR_2_SEQ);

const int PERCENTUAL_MAI_2_SEQ[] = {31, 35};
const RegisterFields PERCENTUAL_MAI_2 = RegisterFields("F5.1", PERCENTUAL_MAI_2_SEQ);

const int PERCENTUAL_JUN_2_SEQ[] = {37, 41};
const RegisterFields PERCENTUAL_JUN_2 = RegisterFields("F5.1", PERCENTUAL_JUN_2_SEQ);

const int PERCENTUAL_JUL_2_SEQ[] = {43, 47};
const RegisterFields PERCENTUAL_JUL_2 = RegisterFields("F5.1", PERCENTUAL_JUL_2_SEQ);

const int PERCENTUAL_AGO_2_SEQ[] = {49, 53};
const RegisterFields PERCENTUAL_AGO_2 = RegisterFields("F5.1", PERCENTUAL_AGO_2_SEQ);

const int PERCENTUAL_SET_2_SEQ[] = {55, 59};
const RegisterFields PERCENTUAL_SET_2 = RegisterFields("F5.1", PERCENTUAL_SET_2_SEQ);

const int PERCENTUAL_OUT_2_SEQ[] = {61, 65};
const RegisterFields PERCENTUAL_OUT_2 = RegisterFields("F5.1", PERCENTUAL_OUT_2_SEQ);

const int PERCENTUAL_NOV_2_SEQ[] = {67, 71};
const RegisterFields PERCENTUAL_NOV_2 = RegisterFields("F5.1", PERCENTUAL_NOV_2_SEQ);

const int PERCENTUAL_DEZ_2_SEQ[] = {73, 77};
const RegisterFields PERCENTUAL_DEZ_2 = RegisterFields("F5.1", PERCENTUAL_DEZ_2_SEQ);

const int LIMITADOR_BLOCO_2 = 9999;
// ---------------------------------------------------

// ------------------- Bloco 3 -----------------------
const char REGISTROS_OBRIGATORIOS_3 = 1;

// Registro tipo 1
const int MAX_ITERACOES_3_SEQ[] = {32, 34};
const RegisterFields MAX_ITERACOES_3 = RegisterFields("I3", MAX_ITERACOES_3_SEQ);

// Registro tipo 2
const int ITERACAO_PENALIDADE_3_SEQ[] = {32, 34};
const RegisterFields ITERACAO_PENALIDADE_3 = RegisterFields("I3", ITERACAO_PENALIDADE_3_SEQ);

// Registro tipo 3
const int TOLERANCIA_3_SEQ[] = {30, 34};
const RegisterFields TOLERANCIA_3 = RegisterFields("F5.0", TOLERANCIA_3_SEQ);

// Registro tipo 4
const int RELATORIO_3_SEQ[] = {34, 34};
const RegisterFields RELATORIO_3 = RegisterFields("I1", RELATORIO_3_SEQ);
// ---------------------------------------------------


// ================== Parsing file ==================
int main() {
    std::string line;
    int lineCount = 1;
    std::vector <Bloco1> bloco1;
    std::vector <Bloco2> bloco2;
    Bloco3 bloco3;
    char regType = 1;
    char lastLineBlock = 1;

    std::ifstream file(fileName);

    while (getline(file, line)) {
        switch (regType) {
            case 1:
            {
                if (lineCount <= REGISTROS_OBRIGATORIOS_1) {
                    break;
                }

                int numeroSubsistema = getData(line, NUMERO_SUBSISTEMA_1);

                if (numeroSubsistema != LIMITADOR_BLOCO_1) {
                    float penalidade = getData(line, PENALIDADE_1);
                    Bloco1 reg = Bloco1(numeroSubsistema, penalidade);
                    bloco1.push_back(reg);
                } else {
                    regType = 2;
                    lastLineBlock = lineCount;
                }
                break;
            }
            case 2:
            {
                if (lineCount <= lastLineBlock + REGISTROS_OBRIGATORIOS_2) {
                    break;
                }

                std::string subsystem = std::string(&line[0], &line[1]);
                if (subsystem == " ") {
                    Reg1Bloco2 reg = Reg1Bloco2(getData(line, NUMERO_SUBSISTEMA_1));
                    
                    Bloco2 newBloco2;
                    bloco2.push_back(newBloco2);
                    
                    bloco2[bloco2.size()-1].setReg1(reg);         
                    break;
                }

                int ano = getData(line, ANO_2);

                if (ano != LIMITADOR_BLOCO_2) {
                    Reg2Bloco2 reg = Reg2Bloco2(ano,
                            getData(line, PERCENTUAL_JAN_2),
                            getData(line, PERCENTUAL_FEV_2),
                            getData(line, PERCENTUAL_MAR_2),
                            getData(line, PERCENTUAL_ABR_2),
                            getData(line, PERCENTUAL_MAI_2),
                            getData(line, PERCENTUAL_JUN_2),
                            getData(line, PERCENTUAL_JUL_2),
                            getData(line, PERCENTUAL_AGO_2),
                            getData(line, PERCENTUAL_SET_2),
                            getData(line, PERCENTUAL_OUT_2),
                            getData(line, PERCENTUAL_NOV_2),
                            getData(line, PERCENTUAL_DEZ_2));
                    
                    bloco2[bloco2.size()-1].setReg2(reg);               
                } else {
                    regType = 3;
                    lastLineBlock = lineCount;
                }

                break;
            }
            case 3:
            {
                if (lineCount <= lastLineBlock + REGISTROS_OBRIGATORIOS_3) {
                    break;
                }
                if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 1) {
                    bloco3.maxIteracoes = getData(line, MAX_ITERACOES_3);
                    break;
                }
                if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 2) {
                    bloco3.iteracaoPenalidade = getData(line, ITERACAO_PENALIDADE_3);
                    break;
                }
                if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 3) {
                    bloco3.tolerancia = getData(line, TOLERANCIA_3);
                    break;
                }
                if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 4) {
                    bloco3.relatorio = getData(line, RELATORIO_3);
                    break;
                }
                break;
            }
        }

        lineCount++;
    }

    printRegisters(bloco1, bloco2, bloco3);

    file.close();
}

// ======================= Printing parsed data =========================
void printRegisters(std::vector<Bloco1> bloco1, std::vector<Bloco2> bloco2, Bloco3 bloco3) {
    for (std::vector<Bloco1>::iterator it = bloco1.begin(); it != bloco1.end(); ++it) {
        (*it).print();
    }

    std::cout << std::endl;

    for (std::vector<Bloco2>::iterator it = bloco2.begin(); it != bloco2.end(); ++it) {
        (*it).print();
    }

    std::cout << std::endl;
    
    bloco3.print();

    std::cout << std::endl;
}

// ===================== Handling data formats ========================
DataField getData(std::string text, RegisterFields field) {
    DataField data;
    switch (field.format.at(0)) {
        case 'I':
        {
            std::string extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
            data.i = std::stoi(extract);
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
            std::string extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
            data.f = std::stof(extract);
            break;
        }
    }
    return data;
}
// ====================================================================