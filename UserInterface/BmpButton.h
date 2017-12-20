#ifndef BMPBUTTON_H
#define BMPBUTTON_H

#include <QWidget>
#include <QScopedPointer>
class BmpButtonPrivate;
class BmpButton : public QWidget
{
    Q_DISABLE_COPY(BmpButton)
    Q_OBJECT
public:
    enum buttonStatus{
        B_Normal = 0,
        B_Press,
        B_check
    };
    explicit BmpButton(QWidget *parent = 0);
    ~BmpButton();

    void setNormalPixmap(const QString &path);
    void setPressPixmap(const QString &path);
    void setCheckPixmap(const QString &path);

signals:
    void bmpButtomPress();
    void bmpButtonRelease();
public slots:

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);
    virtual void normalPaint(QPainter& painter);
    virtual void pressPaint(QPainter& painter);
    virtual void checkPaint(QPainter& painter);
private:
    QScopedPointer<BmpButtonPrivate> m_Private;
};

#endif // BMPBUTTON_H
