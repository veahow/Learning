#include "mywidget.h"
#include "ui_mywidget.h"
#include <QFrame>
#include <QLabel>
#include <QPixmap>
#include <QMovie>

MyWidget::MyWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MyWidget)
{
    ui->setupUi(this);

//    QFont font;
//    font.setFamily("华文行楷");
//    font.setPointSize(20);
//    font.setBold(true);
//    font.setItalic(true);
//    ui->label->setFont(font);

//    QString string = tr("标题太长，需要进行省略！");
//    QString str = ui->label->fontMetrics().elidedText(string, Qt::ElideRight, 180);
//    ui->label->setText(str);

//    ui->label->setPixmap(QPixmap("C:/Users/DMT/Desktop/logo.jpg"));

//    QMovie *movie = new QMovie("C:/Users/DMT/Desktop/logo.gif");
//    ui->label->setMovie(movie);
//    movie->start();
}

MyWidget::~MyWidget()
{
    delete ui;
}
