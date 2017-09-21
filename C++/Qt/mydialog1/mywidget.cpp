#include "mywidget.h"
#include "ui_mywidget.h"
#include <QDialog>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

//    QDialog dialog(this);
//    dialog.show();

//    QDialog *dialog = new QDialog(this);
//    dialog->show();

//    QDialog dialog(this);
//    dialog.exec();

//    QDialog *dialog = new QDialog(this);
//    dialog->setModal(true);
//    dialog->show();

//    connect(ui->showChildButton, &QPushButton::clicked,
//            this, &MyWidget::showChildDialog);

}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_showChildButton_clicked()
{
    QDialog *dialog = new QDialog(this);
    dialog->show();
}
