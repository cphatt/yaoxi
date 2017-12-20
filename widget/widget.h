#ifndef WIDGET_H
#define WIDGET_H

#include "widget_global.h"
#include "customlabel.h"
class WIDGETSHARED_EXPORT Widget : public QWidget
{

public:
    Widget(QWidget *parent =0);
    CustomLabel *label;
};

#endif // WIDGET_H
