#ifndef TEXTWIDGET_H
#define TEXTWIDGET_H

#include <QWidget>
#include <QScopedPointer>
//声明一个私有类
class TextWidgetPrivate;
class TextWidget : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(TextWidget)
public:
    explicit TextWidget(QWidget *parent = 0);
    ~TextWidget();
    void setText(const QString &text);
//    void setLanguageType(const TextWidget::Type type);
    void setAlignmentFlag(const int flags);
    void setFontPointSize(const int pointSize);

signals:

public slots:

protected:
    void paintEvent(QPaintEvent *event);
    QScopedPointer<TextWidgetPrivate> m_Private;
};


#endif // TEXTWIDGET_H
