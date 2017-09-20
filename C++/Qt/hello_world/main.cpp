#include <QApplication>
#include <QDialog>
#include <QLabel>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QDialog wd;
    QLabel label(&wd);
    label.setText("Hello World!");
    wd.show();
    return app.exec();
}
