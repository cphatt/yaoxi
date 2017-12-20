#ifndef CUSTOMLABEL_H
#define CUSTOMLABEL_H

#include <QtGui/QLabel>
#include "widget_global.h"
class WIDGETSHARED_EXPORT CustomLabel : public QLabel
{
    Q_OBJECT
public:
    explicit CustomLabel(QWidget *parent = 0);

signals:

public slots:

};

#endif // CUSTOMLABEL_H
