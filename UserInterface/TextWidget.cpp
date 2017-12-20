#include "TextWidget.h"
#include <QPainter>

//自定义需要注意的几点
class TextWidgetPrivate{
    Q_DISABLE_COPY(TextWidgetPrivate)
public:
    explicit TextWidgetPrivate(TextWidget* parent);
    ~TextWidgetPrivate();
    QString m_Text;
    QFont m_Font;
    int flags;
    int m_Flags = Qt::AlignCenter;

private:
    TextWidget *m_Parent = NULL;
};
//指明父类，当界面一层一层往下面做的时候
TextWidgetPrivate::TextWidgetPrivate(TextWidget *parent)
    :m_Parent(parent)
{
}
TextWidgetPrivate::~TextWidgetPrivate(){

}
//初始化的时候要在自己的界面
TextWidget::TextWidget(QWidget *parent) :
    QWidget(parent)
  ,m_Private(new TextWidgetPrivate(this))
{
}

TextWidget::~TextWidget(){

}

//这个就牛逼了
void TextWidget::paintEvent(QPaintEvent *event){
    //zhunbei xiezi
    QPainter painter(this);
    if(!m_Private->m_Text.isEmpty()){
       painter.setPen(QPen(Qt::black));
       painter.setFont(m_Private->m_Font);
        //这是啥意思
       QFontMetrics fontMetrics(m_Private->m_Font);
       QString text = fontMetrics.elidedText(m_Private->m_Text ,Qt::ElideRight, width());
       painter.drawText(rect(), Qt::AlignCenter, text);
    }
    QWidget::paintEvent(event);
}
void TextWidget::setText(const QString &text){
    m_Private->m_Text = text;
    update();
}
void TextWidget::setFontPointSize(const int pointSize){
    m_Private->m_Font.setPointSize(pointSize);
    update();
}
