#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QMessageBox>
#include <Matriz.h>
#include <QInputDialog>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_CriarMatrizA_clicked();

    void on_pushButton_CriarMatrizB_clicked();

    void on_btn_Soma_clicked();
    void on_btn_Sub_clicked();
    void on_btn_Multi_clicked();
    void on_btn_MultiK_clicked();
    void on_btn_dif_clicked();
    void on_btn_Simetrica_clicked();
    void on_btn_Sup_clicked();
    void on_btn_Inf_clicked();
    void on_btn_Igual_clicked();
    void on_btn_trans_clicked();
    void on_btn_Id_clicked();
    void on_btn_potencia_clicked();
    void on_btn_potencia_2_clicked();
    void on_btn_trans_2_clicked();
    void on_btn_Id_2_clicked();
    void on_btn_Sup_2_clicked();
    void on_btn_Inf_2_clicked();
    void on_btn_Simetrica_2_clicked();
    void on_btn_MultiK_2_clicked();


    void showError(const QString &error) {
        QMessageBox::critical(this, "Erro", error);
    }

private:
    Ui::MainWindow *ui;
    TP2::Matriz *a, *b;
};
#endif // MAINWINDOW_H
