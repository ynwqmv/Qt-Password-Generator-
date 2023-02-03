#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->lineEdit->setReadOnly(true);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::generatePass);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::generatePass()
{
    std::string alphanum = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    std::string symbols = "!@#$%^&*/|";
    std::string numbers = "0123456789";
    int length = ui->horizontalSlider->value();

    std::string password = alphanum;
    if (ui->checkBox->isChecked())
    {
        password += symbols;
    }
    if (ui->checkBox_2->isChecked())
    {
       password += numbers;
    }


    std::random_device rd;
    std::mt19937 rng(rd());

    std::uniform_int_distribution<int> uni(0, password.size() - 1);

    std::string result;
    for (int i = 0; i < length; i++) {
        result += password[uni(rng)];
    }

    ui->lineEdit->setText(QString::fromStdString(result));
}

