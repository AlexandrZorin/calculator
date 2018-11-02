#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFile>

QString addSpaces (QString str);

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    QFile styleF;
    ui->setupUi(this);
    styleF.setFileName(":/stylesheet.qss/qss/stylesheet.qss");
    styleF.open(QFile::ReadOnly);
    QString qssStr = styleF.readAll();
    qApp->setStyleSheet(qssStr);
    connect(ui->zero, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->one, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->two, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->three, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->four, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->five, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->six, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->seven, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->eight, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->nine, SIGNAL(clicked()), this, SLOT(digits()));
    connect(ui->dot, SIGNAL(clicked()), this, SLOT(dot()));
    connect(ui->CE, SIGNAL(clicked()), this, SLOT(ce()));

    if (ui->label->text().length() == 0) {
        ui->label->setText("0");
    }
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::digits() {
    QString newLabel;
    QString label;
    QPushButton *button = dynamic_cast<QPushButton *>(sender());

    if (ui->label->text() == "0") {
        ui->label->setText("");
    }

    label = ui->label->text().replace(".", "").replace(" ", "");

    if (label.length() <= 15) {
        newLabel = ui->label->text() + button->text();
    } else {
        newLabel = ui->label->text();
    }

    if (!(ui->label->text().contains('.'))) {
        newLabel = addSpaces(newLabel);
    }

    ui->label->setText(newLabel);
}

void MainWindow::dot() {
    QString newLabel;

    if (!(ui->label->text().contains('.'))) {
        ui->label->setText(ui->label->text() + '.');
    }
}

void MainWindow::ce() {
    ui->label->setText("0");
}

QString addSpaces(QString str) {
    str.replace(" ", "");

    for (int i = str.size() - 3; i >= 1; i -= 3) {
        str.insert(i, ' ');
    }

    return str;
}
