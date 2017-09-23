#include "mywidget.h"
#include "ui_mywidget.h"
#include <QColorDialog>
#include <QDebug>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);
}

MyWidget::~MyWidget()
{
    delete ui;
}

void MyWidget::on_pushButton_clicked()
{
//    QColor color = QColorDialog::getColor(Qt::red, this, tr("颜色对话框"),
//                                          QColorDialog::ShowAlphaChannel);
//    qDebug() << "color:" << color;

    QColorDialog dialog(Qt::red, this);
    dialog.setOption(QColorDialog::ShowAlphaChannel);
    dialog.exec();
    QColor color = dialog.currentColor();
    qDebug() << "color:" << color;
}
