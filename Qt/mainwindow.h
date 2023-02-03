#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


#include <ctime>
#include <cstdlib>
#include <string>
#include <random>
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
    void generatePass();
private:
    Ui::MainWindow *ui;
};





#endif // MAINWINDOW_H
