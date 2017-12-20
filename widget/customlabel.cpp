#include "customlabel.h"

CustomLabel::CustomLabel(QWidget *parent) :
    QLabel(parent)
{
    this->setText(QObject::tr("is a "));
}
