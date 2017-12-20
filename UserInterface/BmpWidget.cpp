#include "BmpWidget.h"
#include <QPainter>
#include <QPixmap>
#include <QFile>
#include <QDebug>
class BmpWidgetPrivate{
    Q_DISABLE_COPY(BmpWidgetPrivate)
public:
    BmpWidgetPrivate(BmpWidget *parent);
    ~BmpWidgetPrivate();
    //这个玩意应该是个pixmap
    QScopedPointer<QPixmap> m_BackgroundPixmap;
private:
    BmpWidget *m_Parent = NULL;
};

BmpWidget::BmpWidget(QWidget *parent) :
    QWidget(parent)
  ,m_Private(new BmpWidgetPrivate(this))
{
}
BmpWidget::~BmpWidget(){

}

void BmpWidget::paintEvent(QPaintEvent *event){
    QPainter painter(this);
    if(!m_Private->m_BackgroundPixmap.isNull()){
        painter.drawPixmap(QRect((width() - m_Private->m_BackgroundPixmap->width()  ) / 2,
                                 (height() - m_Private->m_BackgroundPixmap->height() ) / 2,
                                 m_Private->m_BackgroundPixmap->width() ,
                                 m_Private->m_BackgroundPixmap->height()),
                           *m_Private->m_BackgroundPixmap);
    }
}

void BmpWidget::setBackgroundPixMapPath(const QString &path){
    //在这里替换掉ｐｉｘｍａｐ
    //文件是否存在
    if(QFile(path + QString(".png")).exists()){
        m_Private->m_BackgroundPixmap.reset(new QPixmap(path + QString(".png")));
    }else{
        if(!m_Private->m_BackgroundPixmap.isNull())
            m_Private->m_BackgroundPixmap.reset(NULL);
    }
    if(isVisible())
        update();
    //这里少了一个关于ｔｉｍｅ的东西，先不急着用
}
BmpWidgetPrivate::BmpWidgetPrivate(BmpWidget *parent)
    :m_Parent(parent)
    ,m_BackgroundPixmap(NULL)
{
}
BmpWidgetPrivate::~BmpWidgetPrivate(){

}
