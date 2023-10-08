#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QInputDialog>
#include <QMessageBox>
#include <QDebug>
#include <exception>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete a;
    delete b;
    delete ui;
}


void MainWindow::on_pushButton_CriarMatrizA_clicked()
{
    try {
        int la, ca;
        la = ui->lineEdit_LinA->text().toInt();
        ca = ui->lineEdit_ColA->text().toInt();

        a = new TP2::Matriz(la,ca);

        if (la <= 0 || ca <= 0) {
            throw std::invalid_argument("Argumento inválido");
        }
        // Input Dialog
        int lin, col;
        QString aux;
        for(lin=0; lin < a->getQuantidadeDeLinhas(); lin++){
            for(col=0; col < a->getQuantidadeDeColunas(); col++){
                aux = "Matriz A["+QString::number(lin)+"]["+QString::number(col)+"]:";
                int valor = QInputDialog::getInt(this,"Matriz", aux);
                a->setElemento(lin, col, valor);               
            }
        }
        ui->textEdit_Resultado->setText(a->getMatriz());
    } catch (std::bad_alloc &) {
        throw QString ("Memoria insuficiente.");
    }
    catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }catch (const std::invalid_argument &ex) {
        QMessageBox::critical(this,"Erro", " Argumento inválido.");
    }
}

void MainWindow::on_pushButton_CriarMatrizB_clicked()
{


      try {
        int lb, cb;

        lb = ui->lineEdit_LinB->text().toInt();
        cb = ui->lineEdit_ColB->text().toInt();

        b = new TP2::Matriz(lb,cb);
        if (lb <= 0 || cb <= 0) {
            throw std::invalid_argument("Argumento inválido");
        }
        QString aux;
        for(int lin=0; lin < b->getQuantidadeDeLinhas(); lin++){
            for(int col=0; col < b->getQuantidadeDeColunas(); col++){
                aux = "Matriz B["+QString::number(lin)+"]["+QString::number(col)+"]:";
                int valor = QInputDialog::getInt(this,"Matriz", aux);
                b->setElemento(lin, col, valor);
            }
        }
        ui->textEdit_Resultado->setText(b->getMatriz());

    } catch (std::bad_alloc &) {
        throw QString ("Memoria insuficiente.");
    }
    catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }catch (const std::invalid_argument &ex) {
        QMessageBox::critical(this,"Erro", " Argumento inválido.");
    }

}

void MainWindow::on_btn_Soma_clicked()
{

    try{
        TP2::Matriz *c = new TP2::Matriz(a->getQuantidadeDeLinhas(), a->getQuantidadeDeColunas());
        *c = *a + *b;

        ui->textEdit_Resultado->setText("MatrizA\n" + a->getMatriz()+"MatrizB\n"+b->getMatriz()+ "Resultado\n" +c->getMatriz());


    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }

}

void MainWindow::on_btn_Sub_clicked()
{

    try{
        TP2::Matriz *c = new TP2::Matriz(a->getQuantidadeDeLinhas(), a->getQuantidadeDeColunas());
        *c = *a - *b;

        ui->textEdit_Resultado->setText("MatrizA\n" + a->getMatriz()+"MatrizB\n"+b->getMatriz()+ "Resultado\n" +c->getMatriz());

    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }

}

void MainWindow::on_btn_Multi_clicked()
{

    try{
        TP2::Matriz *c = new TP2::Matriz(a->getQuantidadeDeLinhas(), a->getQuantidadeDeColunas());
        *c = *a * *b;

        ui->textEdit_Resultado->setText("MatrizA\n" + a->getMatriz()+"MatrizB\n"+b->getMatriz()+ "Resultado\n" +c->getMatriz());

    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }

}

void MainWindow::on_btn_MultiK_clicked() {
    try {
        int k = QInputDialog::getInt(this, "Constante", "Digite a constante k:");

        TP2::Matriz *c = new TP2::Matriz( a->getQuantidadeDeLinhas(), a->getQuantidadeDeColunas());
        *c = *a * k;

        QString resultadoStr = "Matriz A" + a->getMatriz() + "\n" + QString::number(k) + " * A\n" + c->getMatriz();
        ui->textEdit_Resultado->setText(resultadoStr);

        delete c;
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_MultiK_2_clicked() {
    try {
        int k = QInputDialog::getInt(this, "Constante", "Digite a constante k:");

        TP2::Matriz *c = new TP2::Matriz( b->getQuantidadeDeLinhas(), b->getQuantidadeDeColunas());
        *c = *b * k;

        QString resultadoStr = "Matriz A" + b->getMatriz() + "\n" + QString::number(k) + " * B\n" + c->getMatriz();
        ui->textEdit_Resultado->setText(resultadoStr);

        delete c;
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_dif_clicked() {
    try {
        bool diferentes = a->dif(*b);

        ui->textEdit_Resultado->setText("MatrizA\n" + a->getMatriz() + "MatrizB\n" + b->getMatriz() + "\nDiferentes: " + (diferentes ? "Sim": "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_Simetrica_clicked() {
    try {
        bool simetrica = a->simetrica();

        ui->textEdit_Resultado->setText("MatrizA\n"+ a->getMatriz() + "\nSimétrica: " + (simetrica ? "Sim" : "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_Simetrica_2_clicked() {
    try {
        bool simetrica = b->simetrica();

        ui->textEdit_Resultado->setText("MatrizA\n"+ b->getMatriz() + "\nSimétrica: " + (simetrica ? "Sim" : "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_Sup_clicked() {
    try {
        bool triangularSuperior = a->eTriangularSuperior();

        ui->textEdit_Resultado->setText("MatrizA\n" + a->getMatriz() + "\nTriangular Superior: " + (triangularSuperior ? "Sim" : "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_Sup_2_clicked() {
    try {
        bool triangularSuperior = b->eTriangularSuperior();

        ui->textEdit_Resultado->setText("MatrizB\n" + b->getMatriz() + "\nTriangular Superior: " + (triangularSuperior ? "Sim" : "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_Inf_clicked() {
    try {
        bool triangularInferior = a->eTriangularInferior();

        ui->textEdit_Resultado->setText("MatrizA\n"+a->getMatriz() + "\nTriangular Inferior: " + (triangularInferior ? "Sim" : "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_Inf_2_clicked() {
    try {
        bool triangularInferior = b->eTriangularInferior();

        ui->textEdit_Resultado->setText("MatrizB\n"+b->getMatriz() + "\nTriangular Inferior: " + (triangularInferior ? "Sim" : "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_Igual_clicked() {
    try {
        bool igual = (*a == *b);

        ui->textEdit_Resultado->setText("MatrizA\n" + a->getMatriz() + "MatrizB\n" + b->getMatriz() + "\nIguais: " + (igual ? "Sim" : "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_trans_clicked() {

    ui->textEdit_Resultado->clear();
    try {
        TP2::Matriz transposta = a->trasposta();

        ui->textEdit_Resultado->setText("MatrizA\n"+a->getMatriz() + "\nTransposta de A:\n" + transposta.getMatriz());
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_trans_2_clicked() {

    ui->textEdit_Resultado->clear();
    try {
        TP2::Matriz transposta = b->trasposta();

        ui->textEdit_Resultado->setText("MatrizB\n"+b->getMatriz() + "\nTransposta de B:\n" + transposta.getMatriz());
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}


void MainWindow::on_btn_Id_clicked() {
    try {
        bool identidade = a->Identidade();

        ui->textEdit_Resultado->setText("MatrizA\n"+a->getMatriz() + "\nIdentidade: " + (identidade ? "Sim" : "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_Id_2_clicked() {
    try {
        bool identidade = b->Identidade();

        ui->textEdit_Resultado->setText("MatrizB\n"+b->getMatriz() + "\nIdentidade: " + (identidade ? "Sim" : "Não"));
    } catch (QString msg) {
        QMessageBox::information(this, "ERRO", msg);
    }
}

void MainWindow::on_btn_potencia_clicked() {
    try {
        int exp = QInputDialog::getInt(this, "Expoente", "Digite o expoente:");

        qDebug() << "Antes da potenciação";
        if (exp < 0) {
            throw std::invalid_argument("Expoente deve ser não negativo");
        }

        TP2::Matriz *potencia = new TP2::Matriz(a->getQuantidadeDeLinhas(), a->getQuantidadeDeColunas());
        *potencia = (*a) ^ exp;

        qDebug() << "Após a potenciação";

        ui->textEdit_Resultado->setText("MatrizA\n"+a->getMatriz() + "\nA^" + QString::number(exp) + ":\n" + potencia->getMatriz());

        delete potencia;

        qDebug() << "Antes de deletar potencia";

    } catch (const std::exception& e) {
        qDebug() << "Exceção: " << e.what();
        QMessageBox::information(this, "ERRO", "Erro ao calcular a potência da matriz.");
    } catch (const std::invalid_argument &ex) {
        showError("Erro: " + QString(ex.what()));
    }
    qDebug() << "Após deletar potencia";
}

void MainWindow::on_btn_potencia_2_clicked() {
    try {
        int exp = QInputDialog::getInt(this, "Expoente", "Digite o expoente:");

        if (exp < 0) {
            throw std::invalid_argument("Expoente deve ser não negativo");
        }

        TP2::Matriz *potencia = new TP2::Matriz(b->getQuantidadeDeLinhas(), a->getQuantidadeDeColunas());
        *potencia = (*b) ^ exp;


        ui->textEdit_Resultado->setText("MatrizA\n"+b->getMatriz() + "\nA^" + QString::number(exp) + ":\n" + potencia->getMatriz());

        delete potencia;


    } catch (const std::exception& e) {
        QMessageBox::information(this, "ERRO", "Erro ao calcular a potência da matriz.");
    } catch (const std::invalid_argument &ex) {
        showError("Erro: " + QString(ex.what()));
    }
}






