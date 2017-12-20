#include "MainWidget.h"
#include "../UserInterface/TextWidget.h"
#include "../UserInterface/BmpWidget.h"
#include "../UserInterface/BmpButton.h"
#include <QDebug>
class MainWidgetPrivate{
//    Q_OBJECT
    Q_DISABLE_COPY(MainWidgetPrivate)
public:
    MainWidgetPrivate(MainWidget *parent);
    ~MainWidgetPrivate();

    void initialize();
    void connectAllSlots();
    BmpWidget *bmp = NULL;
    BmpButton *carplay = NULL;
    BmpButton *carlife = NULL;

private:
    MainWidget *m_Parent;
};

MainWidget::MainWidget(QWidget *parent) :
    QWidget(parent)
  ,m_Private(new MainWidgetPrivate(this))
{
    setFixedSize(1280,720);
    setVisible(true);
}
MainWidget::~MainWidget(){

}

void MainWidget::onButtonRelease(){
    if(sender() == m_Private->carlife){
        qDebug() << "carlife";
    }else if(sender() == m_Private->carplay){
        qDebug() << "carplay";
    }
}

MainWidgetPrivate::MainWidgetPrivate(MainWidget *parent)
    :m_Parent(parent)
{
    initialize();
    connectAllSlots();
}
MainWidgetPrivate::~MainWidgetPrivate(){

}
void MainWidgetPrivate::initialize(){
    bmp = new BmpWidget(m_Parent);
    bmp->setBackgroundPixMapPath(QString(":/Images/Resources/Images/LinkWidgetBackground"));
    bmp->setGeometry(0,0,1280,720);
    bmp->setVisible(true);

    carlife = new BmpButton(m_Parent);
    carlife->setNormalPixmap(":/Images/Resources/Images/LinkWidgetCarlifeBtnNormal");
    carlife->setGeometry(300,300,160,160);
    carlife->setVisible(true);

    carplay = new BmpButton(m_Parent);
    carplay->setNormalPixmap(":/Images/Resources/Images/LinkWidgetCarplayBtnNormal");
    carplay->setGeometry(800,300,160,160);
    carplay->setVisible(true);

}
void MainWidgetPrivate::connectAllSlots(){
    Qt::ConnectionType type = static_cast<Qt::ConnectionType>(Qt::AutoConnection | Qt::UniqueConnection);
    //不能直接用ｃｏｎｎｅｃｔ
    QObject::connect(carlife, SIGNAL(bmpButtonRelease()), m_Parent, SLOT(onButtonRelease()),type);
    QObject::connect(carplay, SIGNAL(bmpButtonRelease()), m_Parent, SLOT(onButtonRelease()),type);
}
