#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QScopedPointer>
class MainWidgetPrivate;
class MainWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(MainWidget)

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();
signals:

public slots:

protected slots:
    void onButtonRelease();
private:
    QScopedPointer<MainWidgetPrivate> m_Private;
};

#endif // MAINWIDGET_H
