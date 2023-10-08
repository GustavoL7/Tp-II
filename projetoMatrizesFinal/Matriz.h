#ifndef MATRIZ_H
#define MATRIZ_H

#include<QString>

namespace TP2 {
    class Matriz
    {
        private:
            int quantidadeDeLinhas;
            int quantidadeDeColunas;
            int **ptMatriz;
        public:
            Matriz();
            Matriz(int linhas, int colunas);
            ~Matriz();
            int getQuantidadeDeLinhas() const;
            int getQuantidadeDeColunas() const;
            int getElemento(int linha, int coluna) const;
            void setElemento(int linha, int coluna, int elemento);
            QString getMatriz() const;
            Matriz operator +(const Matriz& mat) const;
            Matriz operator -(const Matriz& mat) const;
            Matriz operator *(const Matriz& mat) const;
            Matriz operator ^(int exp) const;
            Matriz operator *(int k) const;
            bool operator ==(const Matriz& mat) const;
            Matriz& operator=(const Matriz& outra);
            bool eTriangularSuperior();
            bool eTriangularInferior();
            bool Identidade() const;
            bool simetrica();
            Matriz trasposta() const;
            bool dif(const Matriz& mat) const;
            static Matriz MatrizIdentidade(int tamanho);
    };

}

#endif // MATRIZ_H
