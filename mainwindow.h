#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QRegularExpression>
#include <QtQml/QJSEngine>
#include <QtQml/QJSValue>
#include <memory>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    QString ScreenTemporalMemory;
    ~MainWindow();

private slots:

    //Setup
    //-----------------------------------
    void SetUpSignalsAndSlots();
    //-----------------------------------

    //All Clear function
    //-----------------------------------
    void AcButtonClicked();
    //-----------------------------------

    //Numeric Buttons
    //-----------------------------------
    void NUM0Clicked();

    void NUM1Clicked();

    void NUM2Clicked();

    void NUM3Clicked();

    void NUM4Clicked();

    void NUM5Clicked();

    void NUM6Clicked();

    void NUM7Clicked();

    void NUM8Clicked();

    void NUM9Clicked();
    //-----------------------------------


    //Operations Buttons
    //-----------------------------------
    void AdditionButtonClicked();

    void SubtractionButtonClicked();

    void ProductButtonClicked();

    void DivisionButtonClicked();

    void ResultButtonClicked();
    //-----------------------------------

    //Error Detection & System Functions
    //-----------------------------------
    void InputProcessor();

    void SyntaxErrorCheck();

    void EnableAllButtons();

    void EnableOperations();

    void DisableAllButtons();

    void DisableOperations();
    //-----------------------------------

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
