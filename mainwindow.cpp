#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

#include <QTableView>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , tableView(new QTableView(this))
{
    setCentralWidget(tableView);
    Dialog *myModel = new Dialog(this);
    tableView->setModel(myModel);

    //transfer changes to the model to the window title
    connect(myModel, &Dialog::editCompleted,
            this, &MainWindow::showWindowTitle);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showWindowTitle(const QString &title)
{
    setWindowTitle(title);
}


