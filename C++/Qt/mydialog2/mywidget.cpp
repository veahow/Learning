#include "mywidget.h"
#include "ui_mywidget.h"
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QInputDialog>
#include <QMessageBox>
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

void MyWidget::on_pushButton_2_clicked()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, this);
    if(ok) ui->pushButton_2->setFont(font);
    else qDebug() << tr("没有选择字体！");

}

void MyWidget::on_pushButton_6_clicked()
{
    bool ok;
    QString string = QInputDialog::getText(this, tr("输入字符串对话框"),
                                           tr("请输入用户名:"),
                                           QLineEdit::Normal,
                                           tr("admin"), &ok);
    if(ok) qDebug() << "string:" << string;

    int value1 = QInputDialog::getInt(this, tr("输入整数对话框"),
                                      tr("请输入-1000到1000之间的数值"),
                                      100, -1000, 1000, 10, &ok);
    if(ok) qDebug() << "value1:" << value1;

    double value2 = QInputDialog::getDouble(this, tr("输入浮点数对话框"),
                                            tr("请输入-1000到1000之间的数值"),
                                            0.00, -1000, 1000, 2, &ok);
    if(ok) qDebug() << "value2:" << value2;

    QStringList items;
    items << tr("条目1") << tr("条目2");
    QString item = QInputDialog::getItem(this, tr("输入条目对话框"),
                                         tr("请选择或输入一个条目"),
                                         items, 0, true, &ok);
    if(ok) qDebug() << "item:" << item;
}

void MyWidget::on_pushButton_3_clicked()
{
    int ret1 = QMessageBox::question(this, tr("问题对话框"),
                                     tr("你了解Qt吗？"),
                                     QMessageBox::Yes,
                                     QMessageBox::No);
    if(ret1 == QMessageBox::Yes) qDebug() << tr("问题！");

    int ret2 = QMessageBox::information(this, tr("提示对话框"),
                                        tr("这是Qt书籍！"),
                                        QMessageBox::Ok);
    if(ret2 == QMessageBox::Ok) qDebug() << tr("提示！");

    int ret3 = QMessageBox::warning(this, tr("警告对话框"),
                                     tr("不能提前结束！"),
                                     QMessageBox::Abort);
    if(ret3 == QMessageBox::Abort) qDebug() << tr("警告！");

    int ret4 = QMessageBox::critical(this, tr("严重错误对话框"),
                                      tr("发现一个严重错误！现在要求关闭所有文件"),
                                      QMessageBox::YesAll);
    if(ret4 == QMessageBox::YesAll) qDebug() << tr("错误");

    QMessageBox::about(this, tr("关于对话框"),
                       tr("Qt Creator"));
}
