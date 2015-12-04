#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ButtonJardan->setVisible(false);
    ui->tableWidget->setVisible(false);

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_ButtonCreate_clicked()
{
    //изменяем число столбцов в таблице значением из Edit
    ui->tableWidget->setColumnCount(ui->EditColumn->text().toInt());
    //изменяем число строк в таблице значением из Edit
    ui->tableWidget->setRowCount(ui->EditRow->text().toInt());

    //показываем таблицу и кнопку для расчетов
    ui->tableWidget->setVisible(true);
    ui->ButtonJardan->setVisible(true);
}
