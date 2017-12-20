
#include <QApplication>
#include <TextWidget.h>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    return a.exec();
}
//(.rodata._ZTV10TextWidget[_ZTV10TextWidget]+0x1d0):-1: error: undefined reference to `non-virtual thunk to TextWidget::~TextWidget()'
