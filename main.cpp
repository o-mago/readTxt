#include <iostream>
#include <fstream>
#include <string>
#include <vector>

const std::string fileName = "CURVA.DAT";

union DataField
{
	int i;
	float f;
	operator int() const { return i; }
	operator float() const { return f; }
};

class RegisterFields {
public:
	std::string format;
	const int* sequence;

	RegisterFields(const std::string f, const int* s) {
		this->format = f;
		for (int i = 0; i < sizeof(this->sequence); i++) {
			this->sequence = s;
		}
	}
};

DataField getData(std::string, RegisterFields);

class Reg1Bloco1 {
public:
	int numeroSubsistema;
	float penalidade;

	Reg1Bloco1(int numeroSubsistema, float penalidade) {
		this->numeroSubsistema = numeroSubsistema;
		this->penalidade = penalidade;
	}

	void print() {
		std::cout << "Reg1Bloco1 (numeroSubsistema: " << this->numeroSubsistema <<
			"\npenalidade: " << this->penalidade << ")\n";
	}
};

class Reg1Bloco2 {
public:
	int numeroSubsistema;

	Reg1Bloco2(int numeroSubsistema) {
		this->numeroSubsistema = numeroSubsistema;
	}

	void print() {
		std::cout << "Reg1Bloco2 (numeroSubsistema: " << this->numeroSubsistema << ")\n";
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
		std::cout << "Reg2Bloco2 (ano: " << this->ano <<
			"\njan: " << this->jan <<
			"\nfev: " << this->fev <<
			"\nmar: " << this->mar <<
			"\nabr: " << this->abr <<
			"\nmai: " << this->mai <<
			"\njun: " << this->jun <<
			"\njul: " << this->jul <<
			"\nago: " << this->ago <<
			"\nset: " << this->set <<
			"\nout: " << this->out <<
			"\nnov: " << this->nov <<
			"\ndez: " << this->dez << ")\n";
	}
};

class Reg1Bloco3 {
public:
	int maxIteracoes;

	Reg1Bloco3(int maxIteracoes) {
		this->maxIteracoes = maxIteracoes;
	}

	void print() {
		std::cout << "Reg1Bloco3 (maxIteracoes: " << this->maxIteracoes << ")\n";
	}
};

class Reg2Bloco3 {
public:
	int iteracaoPenalidade;

	Reg2Bloco3(int iteracaoPenalidade) {
		this->iteracaoPenalidade = iteracaoPenalidade;
	}

	void print() {
		std::cout << "Reg2Bloco3 (iteracaoPenalidade: " << this->iteracaoPenalidade << ")\n";
	}
};

class Reg3Bloco3 {
public:
	float tolerancia;

	Reg3Bloco3(float tolerancia) {
		this->tolerancia = tolerancia;
	}

	void print() {
		std::cout << "Reg3Bloco3 (tolerancia: " << this->tolerancia << ")\n";
	}
};

class Reg4Bloco3 {
public:
	int relatorio;

	Reg4Bloco3(int relatorio) {
		this->relatorio = relatorio;
	}

	void print() {
		std::cout << "Reg4Bloco3 (relatorio: " << this->relatorio << ")\n";
	}
};

void printRegisters(std::vector<Reg1Bloco1>, std::vector<Reg1Bloco2>, std::vector<Reg2Bloco2>, std::vector<Reg1Bloco3>, std::vector<Reg2Bloco3>, std::vector<Reg3Bloco3>, std::vector<Reg4Bloco3>);

// ================= Bloco 1 ===================
const char REGISTROS_OBRIGATORIOS_1 = 4;

// Registro tipo 1
const int NUMERO_SUBSISTEMA_1_SEQ[] = { 2, 4 };
const RegisterFields NUMERO_SUBSISTEMA_1 = RegisterFields("I3", NUMERO_SUBSISTEMA_1_SEQ);

const int PENALIDADE_1_SEQ[] = { 12, 18 };
const RegisterFields PENALIDADE_1 = RegisterFields("F7.2", PENALIDADE_1_SEQ);

const int LIMITADOR_BLOCO_1 = 999;

// ================= Bloco 2 ===================
const char REGISTROS_OBRIGATORIOS_2 = 3;

// Registro tipo 1
const int NUMERO_SUBSISTEMA_2_SEQ[] = { 2, 4 };
const RegisterFields NUMERO_SUBSISTEMA_2 = RegisterFields("I3", NUMERO_SUBSISTEMA_2_SEQ);

// Registro tipo 2
const int ANO_2_SEQ[] = { 1, 4 };
const RegisterFields ANO_2 = RegisterFields("I4", ANO_2_SEQ);

const int PERCENTUAL_JAN_2_SEQ[] = { 7, 11 };
const RegisterFields PERCENTUAL_JAN_2 = RegisterFields("F5.1", PERCENTUAL_JAN_2_SEQ);

const int PERCENTUAL_FEV_2_SEQ[] = { 13, 17 };
const RegisterFields PERCENTUAL_FEV_2 = RegisterFields("F5.1", PERCENTUAL_FEV_2_SEQ);

const int PERCENTUAL_MAR_2_SEQ[] = { 19, 23 };
const RegisterFields PERCENTUAL_MAR_2 = RegisterFields("F5.1", PERCENTUAL_MAR_2_SEQ);

const int PERCENTUAL_ABR_2_SEQ[] = { 25, 29 };
const RegisterFields PERCENTUAL_ABR_2 = RegisterFields("F5.1", PERCENTUAL_ABR_2_SEQ);

const int PERCENTUAL_MAI_2_SEQ[] = { 31, 35 };
const RegisterFields PERCENTUAL_MAI_2 = RegisterFields("F5.1", PERCENTUAL_MAI_2_SEQ);

const int PERCENTUAL_JUN_2_SEQ[] = { 37, 41 };
const RegisterFields PERCENTUAL_JUN_2 = RegisterFields("F5.1", PERCENTUAL_JUN_2_SEQ);

const int PERCENTUAL_JUL_2_SEQ[] = { 43, 47 };
const RegisterFields PERCENTUAL_JUL_2 = RegisterFields("F5.1", PERCENTUAL_JUL_2_SEQ);

const int PERCENTUAL_AGO_2_SEQ[] = { 49, 53 };
const RegisterFields PERCENTUAL_AGO_2 = RegisterFields("F5.1", PERCENTUAL_AGO_2_SEQ);

const int PERCENTUAL_SET_2_SEQ[] = { 55, 59 };
const RegisterFields PERCENTUAL_SET_2 = RegisterFields("F5.1", PERCENTUAL_SET_2_SEQ);

const int PERCENTUAL_OUT_2_SEQ[] = { 61, 65 };
const RegisterFields PERCENTUAL_OUT_2 = RegisterFields("F5.1", PERCENTUAL_OUT_2_SEQ);

const int PERCENTUAL_NOV_2_SEQ[] = { 67, 71 };
const RegisterFields PERCENTUAL_NOV_2 = RegisterFields("F5.1", PERCENTUAL_NOV_2_SEQ);

const int PERCENTUAL_DEZ_2_SEQ[] = { 73, 77 };
const RegisterFields PERCENTUAL_DEZ_2 = RegisterFields("F5.1", PERCENTUAL_DEZ_2_SEQ);

const int LIMITADOR_BLOCO_2 = 9999;

// ================= Bloco 3 ===================
const char REGISTROS_OBRIGATORIOS_3 = 1;

// Registro tipo 1
const int MAX_ITERACOES_3_SEQ[] = { 32, 34 };
const RegisterFields MAX_ITERACOES_3 = RegisterFields("I3", MAX_ITERACOES_3_SEQ);

// Registro tipo 2
const int ITERACAO_PENALIDADE_3_SEQ[] = { 32, 34 };
const RegisterFields ITERACAO_PENALIDADE_3 = RegisterFields("I3", ITERACAO_PENALIDADE_3_SEQ);

// Registro tipo 3
const int TOLERANCIA_3_SEQ[] = { 30, 34 };
const RegisterFields TOLERANCIA_3 = RegisterFields("F5.0", TOLERANCIA_3_SEQ);

// Registro tipo 4
const int RELATORIO_3_SEQ[] = { 34, 34 };
const RegisterFields RELATORIO_3 = RegisterFields("I1", RELATORIO_3_SEQ);

int main() {
	std::string line;
	int lineCount = 1;
	std::vector <Reg1Bloco1> reg1Bloco1;
	std::vector <Reg1Bloco2> reg1Bloco2;
	std::vector <Reg2Bloco2> reg2Bloco2;
	std::vector <Reg1Bloco3> reg1Bloco3;
	std::vector <Reg2Bloco3> reg2Bloco3;
	std::vector <Reg3Bloco3> reg3Bloco3;
	std::vector <Reg4Bloco3> reg4Bloco3;
	char regType = 1;
	char lastLineBlock = 1;

	std::ifstream file(fileName);

	while (getline(file, line)) {
		switch (regType) {
		case 1: {
			if (lineCount <= REGISTROS_OBRIGATORIOS_1) {
				break;
			}

			int numeroSubsistema = getData(line, NUMERO_SUBSISTEMA_1);

			if (numeroSubsistema != LIMITADOR_BLOCO_1) {
				float penalidade = getData(line, PENALIDADE_1);
				Reg1Bloco1 reg = Reg1Bloco1(numeroSubsistema, penalidade);
				reg1Bloco1.insert(reg1Bloco1.end(), reg);
			}
			else {
				regType = 2;
				lastLineBlock = lineCount;
			}
			break;
		}
		case 2: {
			if (lineCount <= lastLineBlock + REGISTROS_OBRIGATORIOS_2) {
				break;
			}

			std::string subsystem = std::string(&line[0], &line[1]);
			if (subsystem == " ") {
				Reg1Bloco2 reg = Reg1Bloco2(getData(line, NUMERO_SUBSISTEMA_1));
				reg1Bloco2.insert(reg1Bloco2.end(), reg);
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
				reg2Bloco2.insert(reg2Bloco2.end(), reg);
			}
			else {
				regType = 3;
				lastLineBlock = lineCount;
			}

			break;
		}
		case 3: {
			if (lineCount <= lastLineBlock + REGISTROS_OBRIGATORIOS_3) {
				break;
			}
			if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 1) {
				Reg1Bloco3 reg = Reg1Bloco3(getData(line, MAX_ITERACOES_3));
				reg1Bloco3.insert(reg1Bloco3.end(), reg);
				break;
			}
			if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 2) {
				Reg2Bloco3 reg = Reg2Bloco3(getData(line, ITERACAO_PENALIDADE_3));
				reg2Bloco3.insert(reg2Bloco3.end(), reg);
				break;
			}
			if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 3) {
				Reg3Bloco3 reg = Reg3Bloco3(getData(line, TOLERANCIA_3));
				reg3Bloco3.insert(reg3Bloco3.end(), reg);
				break;
			}
			if (lineCount == lastLineBlock + REGISTROS_OBRIGATORIOS_3 + 4) {
				Reg4Bloco3 reg = Reg4Bloco3(getData(line, RELATORIO_3));
				reg4Bloco3.insert(reg4Bloco3.end(), reg);
				break;
			}
			break;
		}
		}

		lineCount++;
	}

	printRegisters(reg1Bloco1, reg1Bloco2, reg2Bloco2, reg1Bloco3, reg2Bloco3, reg3Bloco3, reg4Bloco3);

	file.close();
}

void printRegisters(std::vector<Reg1Bloco1> reg1, std::vector<Reg1Bloco2> reg2, std::vector<Reg2Bloco2> reg3, std::vector<Reg1Bloco3> reg4, std::vector<Reg2Bloco3> reg5, std::vector<Reg3Bloco3> reg6, std::vector<Reg4Bloco3> reg7) {
	for (std::vector<Reg1Bloco1>::iterator it = reg1.begin(); it != reg1.end(); ++it) {
		(*it).print();
	}

	std::cout << std::endl;

	for (std::vector<Reg1Bloco2>::iterator it = reg2.begin(); it != reg2.end(); ++it) {
		(*it).print();
	}

	std::cout << std::endl;

	for (std::vector<Reg2Bloco2>::iterator it = reg3.begin(); it != reg3.end(); ++it) {
		(*it).print();
	}

	std::cout << std::endl;

	for (std::vector<Reg1Bloco3>::iterator it = reg4.begin(); it != reg4.end(); ++it) {
		(*it).print();
	}

	std::cout << std::endl;

	for (std::vector<Reg2Bloco3>::iterator it = reg5.begin(); it != reg5.end(); ++it) {
		(*it).print();
	}

	std::cout << std::endl;

	for (std::vector<Reg3Bloco3>::iterator it = reg6.begin(); it != reg6.end(); ++it) {
		(*it).print();
	}

	std::cout << std::endl;

	for (std::vector<Reg4Bloco3>::iterator it = reg7.begin(); it != reg7.end(); ++it) {
		(*it).print();
	}
}

DataField getData(std::string text, RegisterFields field) {
	DataField data;
	switch (field.format.at(0)) {
	case 'I': {
		std::string extract = std::string(&text[field.sequence[0] - 1], &text[field.sequence[1]]);
		data.i = std::stoi(extract);
		break;
	}
	case 'F': {
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