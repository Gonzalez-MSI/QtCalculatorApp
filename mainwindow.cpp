#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
    SetUpSignalsAndSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetUpSignalsAndSlots(){

    connect(ui->AcButton, SIGNAL(clicked()), this, SLOT(AcButtonClicked()));

    connect(ui->Number0Button, SIGNAL(clicked()), this, SLOT(NUM0Clicked()));
    connect(ui->Number1Button, SIGNAL(clicked()), this, SLOT(NUM1Clicked()));
    connect(ui->Number2Button, SIGNAL(clicked()), this, SLOT(NUM2Clicked()));
    connect(ui->Number3Button, SIGNAL(clicked()), this, SLOT(NUM3Clicked()));
    connect(ui->Number4Button, SIGNAL(clicked()), this, SLOT(NUM4Clicked()));
    connect(ui->Number5Button, SIGNAL(clicked()), this, SLOT(NUM5Clicked()));
    connect(ui->Number6Button, SIGNAL(clicked()), this, SLOT(NUM6Clicked()));
    connect(ui->Number7Button, SIGNAL(clicked()), this, SLOT(NUM7Clicked()));
    connect(ui->Number8Button, SIGNAL(clicked()), this, SLOT(NUM8Clicked()));
    connect(ui->Number9Button, SIGNAL(clicked()), this, SLOT(NUM9Clicked()));

    connect(ui->AdditionButton, SIGNAL(clicked()), this, SLOT(AdditionButtonClicked()));
    connect(ui->SubtractButton, SIGNAL(clicked()), this, SLOT(SubtractionButtonClicked()));
    connect(ui->ProductButton,  SIGNAL(clicked()), this, SLOT(ProductButtonClicked()));
    connect(ui->DivisionButton, SIGNAL(clicked()), this, SLOT(DivisionButtonClicked()));

    connect(ui->ResultButton, SIGNAL(clicked()), this, SLOT(ResultButtonClicked()));
}

void MainWindow::InputProcessor(){

    QJSEngine *MathEngine = new QJSEngine;
    QJSValue *RawResult = new QJSValue(MathEngine->evaluate(ScreenTemporalMemory));
    QString *ProcessedResult = new QString(QString::number(RawResult->toNumber()));

    ScreenTemporalMemory = *ProcessedResult;
    ui->ScreenlineEdit->clear();
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);

    delete RawResult;
    delete ProcessedResult;
    delete MathEngine;
}

void MainWindow::AcButtonClicked(){

    EnableAllButtons();
    ui->ScreenlineEdit->clear();
    ScreenTemporalMemory.clear();
}

void MainWindow::NUM0Clicked(){

    EnableOperations();
    ScreenTemporalMemory.append(QString::number(0));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::NUM1Clicked(){

    EnableOperations();
    ScreenTemporalMemory.append(QString::number(1));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::NUM2Clicked(){

    EnableOperations();
    ScreenTemporalMemory.append(QString::number(2));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::NUM3Clicked(){

    EnableOperations();
    ScreenTemporalMemory.append(QString::number(3));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::NUM4Clicked(){

    ScreenTemporalMemory.append(QString::number(4));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::NUM5Clicked(){

    EnableOperations();
    ScreenTemporalMemory.append(QString::number(5));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::NUM6Clicked(){

    EnableOperations();
    ScreenTemporalMemory.append(QString::number(6));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::NUM7Clicked(){

    EnableOperations();
    ScreenTemporalMemory.append(QString::number(7));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::NUM8Clicked(){

    EnableOperations();
    ScreenTemporalMemory.append(QString::number(8));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::NUM9Clicked(){

    EnableOperations();
    ScreenTemporalMemory.append(QString::number(9));
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
}

void MainWindow::AdditionButtonClicked(){

    ScreenTemporalMemory.append("+");
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
    DisableOperations();
}

void MainWindow::SubtractionButtonClicked(){

    ScreenTemporalMemory.append("-");
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
    DisableOperations();
}

void MainWindow::ProductButtonClicked(){

    ScreenTemporalMemory.append("*");
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
    DisableOperations();
}

void MainWindow::DivisionButtonClicked(){

    ScreenTemporalMemory.append("/");
    ui->ScreenlineEdit->setText(ScreenTemporalMemory);
    DisableOperations();
}

void MainWindow::ResultButtonClicked(){

    SyntaxErrorCheck();

    InputProcessor();
}

void MainWindow::SyntaxErrorCheck(){

    if(ScreenTemporalMemory.endsWith("+") || ScreenTemporalMemory.startsWith("+")){

        DisableAllButtons();
        ScreenTemporalMemory.clear();
        ScreenTemporalMemory = "Syntax ERROR - [AC]:Cancel";
        ui->ScreenlineEdit->setText(ScreenTemporalMemory);
    }

    if(ScreenTemporalMemory.endsWith("-") || ScreenTemporalMemory.startsWith("-")){

        DisableAllButtons();
        ScreenTemporalMemory.clear();
        ScreenTemporalMemory = "Syntax ERROR - [AC]:Cancel";
        ui->ScreenlineEdit->setText(ScreenTemporalMemory);
    }

    if(ScreenTemporalMemory.endsWith("*") || ScreenTemporalMemory.startsWith("*")){

        DisableAllButtons();
        ScreenTemporalMemory.clear();
        ScreenTemporalMemory = "Syntax ERROR - [AC]:Cancel";
        ui->ScreenlineEdit->setText(ScreenTemporalMemory);
    }

    if(ScreenTemporalMemory.endsWith("/") || ScreenTemporalMemory.startsWith("/")){

        DisableAllButtons();
        ScreenTemporalMemory.clear();
        ScreenTemporalMemory = "Syntax ERROR - [AC]:Cancel";
        ui->ScreenlineEdit->setText(ScreenTemporalMemory);
    }
}

void MainWindow::DisableAllButtons(){

    //Disable Numbers
    //-------------------------------------
    ui->Number0Button->setEnabled(false);
    ui->Number1Button->setEnabled(false);
    ui->Number2Button->setEnabled(false);
    ui->Number3Button->setEnabled(false);
    ui->Number4Button->setEnabled(false);
    ui->Number5Button->setEnabled(false);
    ui->Number6Button->setEnabled(false);
    ui->Number7Button->setEnabled(false);
    ui->Number8Button->setEnabled(false);
    ui->Number9Button->setEnabled(false);
    //-------------------------------------

    //Disable Operations
    //-------------------------------------
    ui->AdditionButton->setEnabled(false);
    ui->SubtractButton->setEnabled(false);
    ui->ProductButton->setEnabled(false);
    ui->DivisionButton->setEnabled(false);
    ui->BackspaceButton->setEnabled(false);
    ui->DotButton->setEnabled(false);
    ui->ResultButton->setEnabled(false);
    //-------------------------------------
}

void MainWindow::DisableOperations(){

    //Disable Operations
    ui->AdditionButton->setEnabled(false);
    ui->SubtractButton->setEnabled(false);
    ui->ProductButton->setEnabled(false);
    ui->DivisionButton->setEnabled(false);
    ui->BackspaceButton->setEnabled(false);
    ui->DotButton->setEnabled(false);
}

void MainWindow::EnableAllButtons(){

    //Enable Numbers
    //------------------------------------
    ui->Number0Button->setEnabled(true);
    ui->Number1Button->setEnabled(true);
    ui->Number2Button->setEnabled(true);
    ui->Number3Button->setEnabled(true);
    ui->Number4Button->setEnabled(true);
    ui->Number5Button->setEnabled(true);
    ui->Number6Button->setEnabled(true);
    ui->Number7Button->setEnabled(true);
    ui->Number8Button->setEnabled(true);
    ui->Number9Button->setEnabled(true);
    //------------------------------------

    //Enable Operations
    //------------------------------------
    ui->AdditionButton->setEnabled(true);
    ui->SubtractButton->setEnabled(true);
    ui->ProductButton->setEnabled(true);
    ui->DivisionButton->setEnabled(true);
    ui->ResultButton->setEnabled(true);
    ui->BackspaceButton->setEnabled(true);
    ui->DotButton->setEnabled(true);
    //------------------------------------
}

void MainWindow::EnableOperations(){

    //Enable Operations
    //------------------------------------
    ui->AdditionButton->setEnabled(true);
    ui->SubtractButton->setEnabled(true);
    ui->ProductButton->setEnabled(true);
    ui->DivisionButton->setEnabled(true);
    ui->ResultButton->setEnabled(true);
    ui->BackspaceButton->setEnabled(true);
    ui->DotButton->setEnabled(true);
    //------------------------------------
}
