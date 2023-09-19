#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"

/*resumo do aplicativo
 * Get mostra o valor armazenado pela variavel privada || set pega a variavel privada para modificala
 * sts::string e FromStdString() ajudando na conversao da variavel tipo string, para int
 *
 *
 *
 *
 *
 *
 *
 */


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btn_verificar_clicked()
{
    this->abi = new num_complex();
    this->cdi = new num_complex();

    abi->set(ui->txt_real1->text().toInt(),ui->txt_imag1->text().toInt());
    cdi->set(ui->txt_real2->text().toInt(),ui->txt_imag2->text().toInt());

    ui->lbl_resp->setText(QString::fromStdString(abi->get())+ "|" +QString::fromStdString(cdi->get()));
}


void MainWindow::on_btn_soma_clicked()
{
    // Crie instâncias de num_complex
    num_complex* resultado = new num_complex();

    // armazenando as variaveis de texto, em uma variavel que transforme o texto em string. Para depois jogar no FromStringStd
    abi->set(ui->txt_real1->text().toInt(), ui->txt_imag1->text().toInt());
    cdi->set(ui->txt_real2->text().toInt(), ui->txt_imag2->text().toInt());

    // Use o operador + para somar as duas instâncias e armazenar o resultado em 'resultado'
    *resultado = *abi + *cdi;

    // imprimindo resultado na label
    ui->lbl_resp->setText(QString::fromStdString(resultado->get()));

    // Lembre-se de liberar a memória alocada para 'resultado' quando não for mais necessário
    delete resultado;
}

void MainWindow::on_btn_sub_clicked()
{
    num_complex* resultado = new num_complex();

    // armazenando as variaveis de texto, em uma variavel que transforme o texto em string. Para depois jogar no FromStringStd
    abi->set(ui->txt_real1->text().toInt(), ui->txt_imag1->text().toInt());
    cdi->set(ui->txt_real2->text().toInt(), ui->txt_imag2->text().toInt());

    // Use o operador - para subtrair as duas instâncias e armazenar o resultado em 'resultado'
    *resultado = *abi - *cdi;

    ui->lbl_resp->setText(QString::fromStdString(resultado->get()));

    delete resultado;
}

void MainWindow::on_btn_mult_clicked()
{
    num_complex* resultado = new num_complex();

    // armazenando as variaveis de texto, em uma variavel que transforme o texto em string. Para depois jogar no FromStringStd
    abi->set(ui->txt_real1->text().toInt(), ui->txt_imag1->text().toInt());
    cdi->set(ui->txt_real2->text().toInt(), ui->txt_imag2->text().toInt());

    // Use o operador * para multiplicar as duas instâncias e armazenar o resultado em 'resultado'
    *resultado = *abi * *cdi;

    ui->lbl_resp->setText(QString::fromStdString(resultado->get()));

    delete resultado;
}

void MainWindow::on_btn_div_clicked()
{
    num_complex* resultado = new num_complex();

    // armazenando as variaveis de texto, em uma variavel que transforme o texto em string. Para depois jogar no FromStringStd
    abi->set(ui->txt_real1->text().toInt(), ui->txt_imag1->text().toInt());
    cdi->set(ui->txt_real2->text().toInt(), ui->txt_imag2->text().toInt());

    // Use o operador * para dividir as duas instâncias e armazenar o resultado em 'resultado'
    *resultado = *abi / *cdi;

    ui->lbl_resp->setText(QString::fromStdString(resultado->get()));

    delete resultado;
}

void MainWindow::on_btn_igual_clicked()
{

    // armazenando as variaveis de texto, em uma variavel que transforme o texto em string. Para depois jogar no FromStringStd
    abi->set(ui->txt_real1->text().toInt(), ui->txt_imag1->text().toInt());
    cdi->set(ui->txt_real2->text().toInt(), ui->txt_imag2->text().toInt());


    bool saoIguais = (*abi == *cdi);

    if (saoIguais) {
        ui->lbl_resp->setText("Os números são iguais.");
    } else {
        ui->lbl_resp->setText("Os números são diferentes.");
    }
}

void MainWindow::on_btn_dif_clicked()
{

    // armazenando as variaveis de texto, em uma variavel que transforme o texto em string. Para depois jogar no FromStringStd
    abi->set(ui->txt_real1->text().toInt(), ui->txt_imag1->text().toInt());
    cdi->set(ui->txt_real2->text().toInt(), ui->txt_imag2->text().toInt());

    // Usando o operador != para diferenciar as duas instâncias e armazenar o resultado em 'saoDiferentes'
    bool saoDiferentes = (*abi != *cdi);

    if (saoDiferentes) {
        ui->lbl_resp->setText("Os números são diferentes.");
    } else {
        ui->lbl_resp->setText("Os números são iguais.");
    }
}



void MainWindow::on_btn_fechar_clicked()
{
    QMessageBox::StandardButton resposta = QMessageBox::question(this,"","Deseja realmente fechar o programa?",QMessageBox::Yes|QMessageBox::No);
    if(resposta == QMessageBox::Yes){
        close();
    }
}




void MainWindow::on_btn_creditos_clicked()
{
    QMessageBox::information(this,"Créditos do trabalho","Andre Dias:20212003300140\nGustavo Lucas:20212003300396");
        ui->statusbar->showMessage("Andre Dias/Gustavo Lucas");

}

