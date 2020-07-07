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
    float* a;

    operator int() const {
        return i;
    }

    operator float() const {
        return f;
    }
    
    operator float*() const {
        return a;
    }
};
// ====================================================

// ================ Class declarations =================
class RegisterFields {
public:
    std::string format;
    const int* sequence;
    int* spacement;
    
    RegisterFields(const std::string format, const int* sequence) {
        this->format = format;
        this->sequence = sequence;
        int newArray[2] = {-1, -1};
        this->spacement = newArray;
        
    }
    
    RegisterFields(const std::string format, const int* sequence, int* spacement) {
        this->format = format;
        this->sequence = sequence;
        this->spacement = spacement;
    }
};



class Bloco1 {
private:
    int numeroSubsistema;
    float penalidade;
public:
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
private:
    int numeroSubsistema;
public:
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
private:
    int ano;
    float* meses; 
public:
    Reg2Bloco2(int ano, float* meses) {
        this->ano = ano;
        this->meses = meses;
    }

    void print() {
        std::cout << "[ano: " << this->ano << std::endl <<
                "jan: " << this->meses[0] << std::endl <<
                "fev: " << this->meses[1] << std::endl <<
                "mar: " << this->meses[2] << std::endl <<
                "abr: " << this->meses[3] << std::endl <<
                "mai: " << this->meses[4] << std::endl <<
                "jun: " << this->meses[5] << std::endl <<
                "jul: " << this->meses[6] << std::endl <<
                "ago: " << this->meses[7] << std::endl <<
                "set: " << this->meses[8] << std::endl <<
                "out: " << this->meses[9] << std::endl <<
                "nov: " << this->meses[10] << std::endl <<
                "dez: " << this->meses[11] << "]" << std::endl;
    }
};

class Bloco2 {
private:
    Reg1Bloco2 reg1;
    std::vector<Reg2Bloco2> reg2;
public:
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
private:
    int maxIteracoes;
    int iteracaoPenalidade;
    float tolerancia;
    int relatorio;
    
public:
    Bloco3() {
    }

    Bloco3(int maxIteracoes, int iteracaoPenalidade, float tolerancia, int relatorio) {
        this->maxIteracoes = maxIteracoes;
        this->iteracaoPenalidade = iteracaoPenalidade;
        this->tolerancia = tolerancia;
        this->relatorio = relatorio;
    }
    
    void setMaxIteracoes(int maxIteracoes) {
        this->maxIteracoes = maxIteracoes;
    }
    
    void setIteracaoPenalidade(int iteracaoPenalidade) {
        this->maxIteracoes = maxIteracoes;
    }
    
    void setTolerancia(float tolerancia) {
        this->maxIteracoes = maxIteracoes;
    }
    
    void setRelatorio(int relatiorip) {
        this->maxIteracoes = maxIteracoes;
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

const int PERCENTUAL_MONTH_2_SEQ[] = {7, 77};
int SPACEMENT[] = {12, 1};
const RegisterFields PERCENTUAL_MONTH_2 = RegisterFields("F5.1", PERCENTUAL_MONTH_2_SEQ, SPACEMENT);

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
                    Reg2Bloco2 reg = Reg2Bloco2(ano, getData(line, PERCENTUAL_MONTH_2));
                    
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
                    bloco3.setMaxIteracoes(getData(line, MAX_ITERACOES_3));
                    break;
                }
                if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 2) {
                    bloco3.setIteracaoPenalidade(getData(line, ITERACAO_PENALIDADE_3));
                    break;
                }
                if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 3) {
                    bloco3.setTolerancia(getData(line, TOLERANCIA_3));
                    break;
                }
                if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 4) {
                    bloco3.setRelatorio(getData(line, RELATORIO_3));
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
            if(field.spacement[0] == -1 && field.spacement[1] == -1) {
                float months[field.spacement[0]];
                int start = field.sequence[0] - 1;
                const int numberChar = (field.format.at(1) - '0');
                int space = field.spacement[1];
                
                for(int i = 0; i < field.spacement[0]; i++) {
                    std::string extract = std::string(&text[start + i*(numberChar + space)], &text[start + (i+1)*(numberChar+space)]);
                    months[i] =  std::stof(extract);
                }
                data.a = months;
            }
            std::string extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
            data.f = std::stof(extract);
            break;
        }
    }
    return data;
}
// ====================================================================