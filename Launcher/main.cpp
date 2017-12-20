
#include <QApplication>
#include <MainWidget/MainWidget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();
    MainWidget mainWindow;
    Q_UNUSED(mainWindow);
    return a.exec();
}
