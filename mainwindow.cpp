#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Queue.h"
#include <QString>
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


void MainWindow::on_pushButton_2_clicked()
{
   queue.Print();
}

void MainWindow::on_pushButton_clicked()
{
    queue.push( ui->spinBox->value());

}

void MainWindow::on_pushButton_3_clicked()
{
    queue.pop();
}

void MainWindow::on_pushButton_4_clicked()
{
    qDebug()<<"Queue is empty";
    queue.~Queue();
}

void MainWindow::on_pushButton_5_clicked()
{
    qDebug()<<queue.size();
}
