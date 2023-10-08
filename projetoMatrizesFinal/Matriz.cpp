#include "Matriz.h"
#include <QString>

namespace TP2 {

Matriz::Matriz() : quantidadeDeLinhas(0), quantidadeDeColunas(0), ptMatriz(nullptr) {
    // Inicialização do construtor padrão
}

Matriz::Matriz(int linhas, int colunas) : quantidadeDeLinhas(0), quantidadeDeColunas(0), ptMatriz(nullptr) {
    if (linhas <= 0 || colunas <= 0)
        throw std::invalid_argument("Quantidade de linhas ou colunas inválida.");

    try {
        ptMatriz = new int *[linhas];
        for (int l = 0; l < linhas; l++) {
            ptMatriz[l] = new int[colunas];
        }
        quantidadeDeLinhas = linhas;
        quantidadeDeColunas = colunas;
    } catch (std::bad_alloc&) {
        throw std::bad_alloc(); // Rethrow para manter consistência
    }
}

Matriz::~Matriz() {
    if (ptMatriz) {
        for (int l = 0; l < quantidadeDeLinhas; l++) {
            delete[] ptMatriz[l];
        }
        delete[] ptMatriz;
    }
}

int Matriz::getQuantidadeDeLinhas() const {
    return quantidadeDeLinhas;
}

int Matriz::getQuantidadeDeColunas() const {
    return quantidadeDeColunas;
}

int Matriz::getElemento(int linha, int coluna) const {
    if (linha < 0 || linha >= quantidadeDeLinhas || coluna < 0 || coluna >= quantidadeDeColunas) {
        throw std::out_of_range("Acesso inválido a elementos da matriz");
    }
    return ptMatriz[linha][coluna];
}

void Matriz::setElemento(int linha, int coluna, int elemento) {
    ptMatriz[linha][coluna] = elemento;
}

QString Matriz::getMatriz() const {
    QString saida = "";
    for (int i = 0; i < quantidadeDeLinhas; i++) {
        for (int j = 0; j < quantidadeDeColunas; j++) {
            saida += QString::number(getElemento(i, j)) + " ";
        }
        saida += "\n";
    }
    return saida;
}

Matriz Matriz::operator +(const Matriz& mat) const {
    if (this->quantidadeDeLinhas != mat.quantidadeDeLinhas || this->quantidadeDeColunas != mat.quantidadeDeColunas) {
        throw std::invalid_argument("Matrizes de tamanhos diferentes para a operação de soma.");
    }

    Matriz result(quantidadeDeLinhas, quantidadeDeColunas);

    for (int i = 0; i < quantidadeDeLinhas; i++) {
        for (int j = 0; j < quantidadeDeColunas; j++) {
            result.setElemento(i, j, getElemento(i, j) + mat.getElemento(i, j));
        }
    }

    return result;
}

Matriz Matriz::operator -(const Matriz& mat) const {
    if (this->quantidadeDeLinhas != mat.quantidadeDeLinhas || this->quantidadeDeColunas != mat.quantidadeDeColunas) {
        throw std::invalid_argument("Matrizes de tamanhos diferentes para a operação de subtração.");
    }

    Matriz result(quantidadeDeLinhas, quantidadeDeColunas);

    for (int i = 0; i < quantidadeDeLinhas; i++) {
        for (int j = 0; j < quantidadeDeColunas; j++) {
            result.setElemento(i, j, getElemento(i, j) - mat.getElemento(i, j));
        }
    }

    return result;
}

Matriz Matriz::operator *(const Matriz& mat) const {
    if (this->quantidadeDeColunas != mat.quantidadeDeLinhas) {
        throw std::invalid_argument("Quantidade de colunas da matriz da esquerda deve ser igual à quantidade de linhas da matriz da direita.");
    }

    Matriz result(quantidadeDeLinhas, mat.quantidadeDeColunas);

    for (int i = 0; i < quantidadeDeLinhas; i++) {
        for (int j = 0; j < mat.quantidadeDeColunas; j++) {
            int soma = 0;
            for (int k = 0; k < this->quantidadeDeColunas; k++) {
                soma += this->getElemento(i, k) * mat.getElemento(k, j);
            }
            result.setElemento(i, j, soma);
        }
    }

    return result;
}

Matriz Matriz::operator *(int k) const {
    Matriz result(quantidadeDeLinhas, quantidadeDeColunas);

    for (int i = 0; i < quantidadeDeLinhas; i++) {
        for (int j = 0; j < quantidadeDeColunas; j++) {
            result.setElemento(i, j, this->getElemento(i, j) * k);
        }
    }

    return result;
}
/*
Matriz multiplicarMatrizes(const Matriz& A, const Matriz& B) {
    int linhasA = A.getQuantidadeDeLinhas();
    int colunasA = A.getQuantidadeDeColunas();
    int colunasB = B.getQuantidadeDeColunas();

    Matriz result(linhasA, colunasB);

    for (int i = 0; i < linhasA; ++i) {
        for (int j = 0; j < colunasB; ++j) {
            int soma = 0;
            for (int k = 0; k < colunasA; ++k) {
                soma += A.getElemento(i, k) * B.getElemento(k, j);
            }
            result.setElemento(i, j, soma);
        }
    }

    return result;
}
*/
Matriz Matriz::operator^(int exp) const {
    if (exp < 0) {
        throw std::invalid_argument("Expoente não pode ser negativo para a potência de matriz.");
    }


    if (exp == 0) {
        return MatrizIdentidade(quantidadeDeLinhas);
    }

    Matriz result = *this;


    for (int i = 1; i < exp; ++i) {
        result = result * (*this);
    }

    return result;
}


Matriz Matriz::MatrizIdentidade(int tamanho) {
    if (tamanho <= 0) {
        throw std::invalid_argument("Tamanho inválido para a matriz identidade.");
    }

    Matriz identidade(tamanho, tamanho);

    for (int i = 0; i < tamanho; ++i) {
        for (int j = 0; j < tamanho; ++j) {
            identidade.setElemento(i, j, (i == j) ? 1 : 0);
        }
    }

    return identidade;
}


bool Matriz::Identidade() const {

    if (quantidadeDeLinhas != quantidadeDeColunas) {
        return false;
    }


    for (int i = 0; i < quantidadeDeLinhas; i++) {
        for (int j = 0; j < quantidadeDeColunas; j++) {

            if ((i != j && ptMatriz[i][j] != 0) || (i == j && ptMatriz[i][j] != 1)) {
                return false;
            }
        }
    }


    return true;
}

bool Matriz::eTriangularSuperior() {

    if (quantidadeDeLinhas != quantidadeDeColunas) {
        return false;
    }


    for (int i = 0; i < quantidadeDeLinhas; ++i) {
        for (int j = 0; j < i; ++j) {
            if (ptMatriz[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool Matriz::eTriangularInferior() {

    if (quantidadeDeLinhas != quantidadeDeColunas) {
        return false;
    }


    for (int i = 0; i < quantidadeDeLinhas; ++i) {
        for (int j = i + 1; j < quantidadeDeColunas; ++j) {
            if (ptMatriz[i][j] != 0) {
                return false;
            }
        }
    }

    return true;
}

bool Matriz::simetrica() {

    if (quantidadeDeLinhas != quantidadeDeColunas) {
        return false;
    }


    return (*this == this->trasposta());
}

Matriz Matriz::trasposta() const {
    Matriz transposta(quantidadeDeColunas, quantidadeDeLinhas);

    for (int i = 0; i < quantidadeDeLinhas; ++i) {
        for (int j = 0; j < quantidadeDeColunas; ++j) {
            transposta.setElemento(j, i, getElemento(i, j));
        }
    }

    return transposta;
}

bool Matriz::operator==(const Matriz& mat) const {

    if (quantidadeDeLinhas != mat.quantidadeDeLinhas || quantidadeDeColunas != mat.quantidadeDeColunas) {
        return false;
    }


    for (int i = 0; i < quantidadeDeLinhas; ++i) {
        for (int j = 0; j < quantidadeDeColunas; ++j) {
            if (getElemento(i, j) != mat.getElemento(i, j)) {
                return false;
            }
        }
    }

    return true;
}

bool Matriz::dif(const Matriz& mat) const {

    if (quantidadeDeLinhas != mat.quantidadeDeLinhas || quantidadeDeColunas != mat.quantidadeDeColunas) {
        return true;
    }


    for (int i = 0; i < quantidadeDeLinhas; ++i) {
        for (int j = 0; j < quantidadeDeColunas; ++j) {
            if (getElemento(i, j) != mat.getElemento(i, j)) {
                return true;
            }
        }
    }

    return false;
}


Matriz& Matriz::operator=(const Matriz& outra) {
    if (this != &outra) {

        if (ptMatriz) {
            for (int l = 0; l < quantidadeDeLinhas; l++) {
                delete[] ptMatriz[l];
            }
            delete[] ptMatriz;
        }


        quantidadeDeLinhas = outra.quantidadeDeLinhas;
        quantidadeDeColunas = outra.quantidadeDeColunas;
        ptMatriz = new int*[quantidadeDeLinhas];
        for (int i = 0; i < quantidadeDeLinhas; ++i) {
            ptMatriz[i] = new int[quantidadeDeColunas];
            for (int j = 0; j < quantidadeDeColunas; ++j) {
                ptMatriz[i][j] = outra.ptMatriz[i][j];
            }
        }
    }

    return *this;
}

}
