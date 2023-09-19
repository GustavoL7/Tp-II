#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "num_complex.h"
#include <QMainWindow>

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
    void on_btn_verificar_clicked();

    void on_btn_soma_clicked();
    void on_btn_sub_clicked();
    void on_btn_mult_clicked();
    void on_btn_div_clicked();
    void on_btn_igual_clicked();
    void on_btn_dif_clicked();


    void on_btn_creditos_clicked();

    void on_btn_fechar_clicked();

private:
    Ui::MainWindow *ui;
    num_complex *abi, *cdi;
};
#endif // MAINWINDOW_H
