// ================= Importing dependencies ==================
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
// ===========================================================

//================= Input file name (put the file inside the same folder of the main.cpp file) ====================
const std::string fileName = "PENALID.DAT";
//=================================================================================================================

// ================ Union declarations =================
union DataFieldPenalid {
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
class RegisterFieldsPenalid {
public:
    std::string format;
    const int* sequence;

    RegisterFieldsPenalid(const std::string f, const int* s) {
        this->format = f;
        for (int i = 0; i < sizeof (this->sequence); i++) {
            this->sequence = s;
        }
    }
};

class Bloco {
public:
    std::string pchave;
    float penalid1;
    float penalid2;
    int sis;
    int pat;

    Bloco(std::string pchave, float penalid1, float penalid2, int sis, int pat) {
        this->pchave = pchave;
        this->penalid1 = penalid1;
        this->penalid2 = penalid2;
        this->sis = sis;
        this->pat = pat;
    }

    void print() {
        std::cout << "(PCHAVE: " << this->pchave << std::endl <<
                "penalid1: " << this->penalid1 << std::endl <<
                "penalid2: " << this->penalid2 << std::endl <<
                "sis: " << this->sis << std::endl <<
                "pat: " << this->pat << ")" << std::endl;
    }
};

// ================= Functions definitions ====================
DataFieldPenalid getData(std::string, RegisterFieldsPenalid);
void printRegisters(std::vector<Bloco>);
std::string getStringData(std::string text, RegisterFieldsPenalid field);
// ============================================================

// ================= Fields formats and number sequences definitions ======================

// ----------------- Bloco -------------------
const char REGISTROS_OBRIGATORIOS = 2;

const int PCHAVE_SEQ[] = {2, 7};
const RegisterFieldsPenalid PCHAVE = RegisterFieldsPenalid("A6", PCHAVE_SEQ);

const int PENALID_1_SEQ[] = {15, 22};
const RegisterFieldsPenalid PENALID_1 = RegisterFieldsPenalid("F8.0", PENALID_1_SEQ);

const int PENALID_2_SEQ[] = {25, 32};
const RegisterFieldsPenalid PENALID_2 = RegisterFieldsPenalid("F8.0", PENALID_2_SEQ);

const int SIS_SEQ[] = {37, 39};
const RegisterFieldsPenalid SIS = RegisterFieldsPenalid("I3", SIS_SEQ);

const int PAT_SEQ[] = {43, 44};
const RegisterFieldsPenalid PAT = RegisterFieldsPenalid("I2", PAT_SEQ);
// ---------------------------------------------

// ================== Parsing file ==================
void penalid() {
    std::string line;
    int lineCount = 1;
    std::vector <Bloco> bloco;

    std::ifstream file(fileName);

    while (getline(file, line)) {
        if (lineCount > REGISTROS_OBRIGATORIOS) {
            std::string pchave = getStringData(line, PCHAVE);
            float penalid1 = getData(line, PENALID_1);
            float penalid2 = getData(line, PENALID_2);
            int sis = getData(line, SIS);
            int pat = getData(line, PAT);
            Bloco reg = Bloco(pchave, penalid1, penalid2, sis, pat);
            bloco.push_back(reg);
        }

        lineCount++;
    }

    printRegisters(bloco);

    file.close();
}

// ======================= Printing parsed data =========================
void printRegisters(std::vector<Bloco> bloco) {
    for (std::vector<Bloco>::iterator it = bloco.begin(); it != bloco.end(); ++it) {
        (*it).print();
    }

    std::cout << std::endl;
}

// ===================== Handling data formats ========================
std::string getStringData(std::string text, RegisterFieldsPenalid field) {
    std::string extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
    return extract;
}

DataFieldPenalid getData(std::string text, RegisterFieldsPenalid field) {
    DataFieldPenalid data;
    switch (field.format.at(0)) {
        case 'I':
        {
            std::string extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
            try {
                data.i = std::stoi(extract);
            } catch (const std::exception& e) {
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
            std::string extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
            try {
                data.f = std::stof(extract);
            } catch (const std::exception& e) {
                data.f = -1.0;
            }
            break;
        }
    }
    return data;
}
// ====================================================================