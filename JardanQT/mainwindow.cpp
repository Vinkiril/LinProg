#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "jardan.h"



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
    //открываем скрытые столбцы
    for(int i=0;i<ui->EditColumn->text().toInt();i++)
    ui->tableWidget->setColumnHidden(i,false);
}

void MainWindow::on_ButtonJardan_clicked()
{
    Jardan jard;
    //передам в жардан размеры матрицы
    jard.n=ui->tableWidget->rowCount();
    jard.m=ui->tableWidget->columnCount();
    jard.init();
    //передаем значения таблицы в матрицу для жардана
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            jard.arr[i][j]=ui->tableWidget->item(i,j)->text().toInt();
        }
    }
    //жарданим
    jard.jardArr(ui->tableWidget->currentRow(),ui->tableWidget->currentColumn());

    //выводим
    for(int i=0;i<ui->tableWidget->rowCount();i++){
        for(int j=0;j<ui->tableWidget->columnCount();j++){
            QTableWidgetItem *itm = new QTableWidgetItem(tr("%1").arg(jard.arr[i][j]));
            ui->tableWidget->setItem(i,j,itm);
        }
    }
    //скрваем выыбранный столбец
    ui->tableWidget->setColumnHidden(ui->tableWidget->currentColumn(),true);
}
