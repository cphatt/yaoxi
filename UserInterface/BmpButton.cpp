#include "BmpButton.h"
#include <QPixmap>
#include <QPainter>
#include <QFile>
#include <QDebug>
class BmpButtonPrivate{
    Q_DISABLE_COPY(BmpButtonPrivate)
public:
    BmpButtonPrivate(BmpButton* parent);
    ~BmpButtonPrivate();

    QScopedPointer<QPixmap> m_NormalPixmap;
    QScopedPointer<QPixmap> m_CheckPixmap;
    QScopedPointer<QPixmap> m_PressPixmap;

    BmpButton::buttonStatus m_Status;
private:
    BmpButton * m_Parent;
};

BmpButton::BmpButton(QWidget *parent) :
    QWidget(parent)
  ,m_Private(new BmpButtonPrivate(this))
{
}
BmpButton::~BmpButton(){

}

void BmpButton::mousePressEvent(QMouseEvent *event){
    m_Private->m_Status = B_Press;\
    update();
    emit bmpButtomPress();
    QWidget::mousePressEvent(event);
}

void BmpButton::mouseReleaseEvent(QMouseEvent *event){
    //先就这样子做着，有问题再看
    m_Private->m_Status = B_Normal;
    update();
    emit bmpButtonRelease();
    QWidget::mouseReleaseEvent(event);
}

void BmpButton::paintEvent(QPaintEvent *event){
    //在这里显示图片
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing, true);
    if(m_Private->m_Status == B_check){
        checkPaint(painter);
    }else if(m_Private->m_Status == B_Press){
        pressPaint(painter);
    }else{
        normalPaint(painter);
    }

    QWidget::paintEvent(event);
}
void BmpButton::normalPaint(QPainter &painter){
    if(!m_Private->m_NormalPixmap.isNull()){
        painter.drawPixmap(QRect((width() - m_Private->m_NormalPixmap->width()  ) / 2,
                                 (height() - m_Private->m_NormalPixmap->height() ) / 2,
                                 m_Private->m_NormalPixmap->width() ,
                                 m_Private->m_NormalPixmap->height()),
                           *m_Private->m_NormalPixmap);
    }
}
void BmpButton::checkPaint(QPainter &painter){

}
void BmpButton::pressPaint(QPainter &painter){
    if(!m_Private->m_PressPixmap.isNull()){
        painter.drawPixmap(QRect((width() - m_Private->m_PressPixmap->width()  ) / 2,
                                 (height() - m_Private->m_PressPixmap->height() ) / 2,
                                 m_Private->m_PressPixmap->width() ,
                                 m_Private->m_PressPixmap->height()),
                           *m_Private->m_PressPixmap);
    }
}
void BmpButton::setNormalPixmap(const QString &path){
    //判断有没有这文件

    if(QFile(path + QString(".png")).exists()){
        m_Private->m_NormalPixmap.reset(new QPixmap(path + QString(".png")));
        qDebug() << path;
    }else{
        m_Private->m_NormalPixmap.reset(NULL);
    }
    if(isVisible()){
       update();
    }
}
void BmpButton::setCheckPixmap(const QString &path){
    //判断有没有这文件

    if(QFile(path + QString(".png")).exists()){
        m_Private->m_CheckPixmap.reset(new QPixmap(path + QString(".png")));
        qDebug() << path;
    }else{
        m_Private->m_CheckPixmap.reset(NULL);
    }
    if(isVisible()){
       update();
    }
}
void BmpButton::setPressPixmap(const QString &path){
    //判断有没有这文件

    if(QFile(path + QString(".png")).exists()){
        m_Private->m_PressPixmap.reset(new QPixmap(path + QString(".png")));
        qDebug() << path;
    }else{
        m_Private->m_PressPixmap.reset(NULL);
    }
    if(isVisible()){
       update();
    }
}

BmpButtonPrivate::BmpButtonPrivate(BmpButton *parent):
    m_Parent(parent)
  ,m_Status(BmpButton::B_Normal)
{

}
BmpButtonPrivate::~BmpButtonPrivate(){

}
