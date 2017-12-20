#ifndef BMPWIDGET_H
#define BMPWIDGET_H

#include <QWidget>
#include <QScopedPointer>
class BmpWidgetPrivate;
class BmpWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(BmpWidget)
public:
    explicit BmpWidget(QWidget *parent = 0);
    ~BmpWidget();
    void setBackgroundPixMapPath(const QString &path);
protected:
    void paintEvent(QPaintEvent *);
private:
    //这玩意就是个指针
    QScopedPointer<BmpWidgetPrivate> m_Private;
};

#endif // BMPWIDGET_H
