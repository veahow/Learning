#include "mywidget.h"
#include "ui_mywidget.h"
#include <QColorDialog>
#include <QFileDialog>
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

void MyWidget::on_pushButton_5_clicked()
{
//    QString fileName = QFileDialog::getOpenFileName(this, tr("文件对话框"),
//                                                    "C://Users/dmt/Desktop",
//                                                    tr("图片文件(*png *jpg);;文本文件(*txt)"));
//    qDebug() << "fileName:" << fileName;

    QStringList fileNames = QFileDialog::getOpenFileNames(this, tr("文件对话框"),
                                                          "C://Users/dmt/Desktop", tr("图片文件(*png *jpg)"));
    qDebug() << "fileNames:" << fileNames;
}
