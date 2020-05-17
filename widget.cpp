#include "widget.h"
#include "./ui_widget.h"

#include "src/Cat_Animation/ProgressArc.h"
#include "src/Cat_Animation/Marquee.h"

#include "src/Cat_Button/Pagination.h"
#include "src/Cat_Button/SwitchButton.h"

#include "src/Cat_InputGroup/IpInputGroup.h"

#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QSlider>
#include <QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    marquee = nullptr;
    ui->setupUi(this);
    TextProgressArc();
    TextMarquee();
    TextSwitchButton();
    TextIpInputGroup();
    ui->stackedWidget->setCurrentIndex(0);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::TextProgressArc()
{
    QVBoxLayout *vboxlayout = new QVBoxLayout(ui->PaginationWidget);
    QSlider *TestSlider;
    TestSlider = new QSlider(this);
    TestSlider->setObjectName(QString::fromUtf8("TestSlider"));
    //TestSlider->setGeometry(QRect(110, 270, 160, 16));
    TestSlider->setMaximum(100);
    TestSlider->setOrientation(Qt::Horizontal);
    ProgressArc *TestArcWidget = new ProgressArc(ui->PaginationWidget);
    TestArcWidget->setGeometry(0,0,200,200);
    TestArcWidget->setMinimumWidth(40);
    TestArcWidget->setMinimumHeight(40);
    TestArcWidget->SetBorderWidth(5);
    TestArcWidget->SetLineWidth(20);
    TestArcWidget->SetLineColor(QColor(Qt::white));
    TestArcWidget->SetBorderColor(QColor(Qt::white));
    TestArcWidget->SetBgColor(QColor(Qt::gray));
    TestArcWidget->SetValue(0);
    TestArcWidget->SetCortoon(true);
    vboxlayout->addWidget(TestArcWidget);
    vboxlayout->addWidget(TestSlider);
    connect(TestSlider, SIGNAL(valueChanged(int)), TestArcWidget, SLOT(Update_Value(int)));
}

void Widget::TextMarquee()
{
    QVBoxLayout *vboxlayout = new QVBoxLayout(ui->MarqueeWidget);

    QSpacerItem* vSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem* vSpacer2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);

    marquee = new Marquee(ui->MarqueeWidget);
    vboxlayout->addItem(vSpacer1);
    vboxlayout->addWidget(marquee);
    vboxlayout->addItem(vSpacer2);
    marquee->setGeometry(100,100, 600, 50);
    marquee->AddText("nokia nokia nokia nokia nokia nokia nokia nokia nokia nokia nokia nokia");
    QFont font;
    font.setFamily("Microsoft YaHei");
    font.setBold(true);
    font.setPointSize(50);
    marquee->setFont(font);
    marquee->SetSpeed(Marquee::Quick);
    marquee->Start(0);
    marquee->Stop();
}

void Widget::TextSwitchButton()
{
    QGridLayout *gridlayout = new QGridLayout(ui->SwitchButtonWidget);
    SwitchButton *m_pBinButton0;
    m_pBinButton0 = new SwitchButton(ui->SwitchButtonWidget);
    m_pBinButton0->SetButtonStyle(SwitchButton::Slide_InCircle);
    m_pBinButton0->resize(QSize(50, 20));
    //m_pBinButton0->setGeometry(0,5,50, 20);
    m_pBinButton0->setMaximumSize(QSize(50, 20));
    m_pBinButton0->SetBlockInterval(2);
    m_pBinButton0->SetAnimation(true);
    m_pBinButton0->SetDisable(true);
    m_pBinButton0->SetDisable(false);
    gridlayout->addWidget(m_pBinButton0, 0, 0);

    SwitchButton *m_pBinButton1;
    m_pBinButton1 = new SwitchButton(ui->SwitchButtonWidget);
    m_pBinButton1->SetButtonStyle(SwitchButton::Slide_Roundrect);
    m_pBinButton1->resize(QSize(50, 20));
    //m_pBinButton1->setGeometry(60,5,50, 20);
    m_pBinButton1->setMaximumSize(QSize(50, 20));
    m_pBinButton1->SetBlockInterval(1);
    m_pBinButton1->SetRectRadius(3);
    m_pBinButton1->SetAnimation(true);
    gridlayout->addWidget(m_pBinButton1, 0, 1);

    SwitchButton *m_pBinButton2;
    m_pBinButton2 = new SwitchButton(ui->SwitchButtonWidget);
    m_pBinButton2->SetButtonStyle(SwitchButton::Slide_OutCIrcle);
    m_pBinButton2->resize(QSize(50, 20));
    //m_pBinButton2->setGeometry(0,30,50, 20);
    m_pBinButton2->setMaximumSize(QSize(50, 20));
    m_pBinButton2->SetBlockInterval(1);
    m_pBinButton2->SetRectRadius(3);
    m_pBinButton2->SetAnimation(true);
    gridlayout->addWidget(m_pBinButton2, 1, 0);

    SwitchButton *m_pBinButton4;
    m_pBinButton4 = new SwitchButton(ui->SwitchButtonWidget);
    m_pBinButton4->SetButtonStyle(SwitchButton::Circle);
    m_pBinButton4->resize(QSize(60,80));
    //m_pBinButton4->setGeometry(60,30,50, 50);
    m_pBinButton4->setMaximumSize(QSize(60, 80));
    m_pBinButton4->SetBlockInterval(1);
    m_pBinButton4->SetRectRadius(3);
    m_pBinButton4->SetAnimation(true);
    gridlayout->addWidget(m_pBinButton4, 1, 1);
}


void Widget::TextIpInputGroup()
{
    QVBoxLayout *vboxlayout = new QVBoxLayout(ui->IpInputGroupWidget);

    QSpacerItem* vSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    QSpacerItem* vSpacer2 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Expanding);
    IpInputGroup *iplabeledit = new IpInputGroup(ui->IpInputGroupWidget);
    iplabeledit->SetBorderRadius(15);
    QColor color1;
    color1.setNamedColor("#FFFFFF");
    iplabeledit->SetBackGroundColor(color1);
    QColor color2;
    color2.setNamedColor("#BEBEBE");
    iplabeledit->SetBorderColor(color2);
    //iplabeledit->setGeometry(10,10, 200, 30);
    iplabeledit->setMaximumSize(QSize(200, 30));
    iplabeledit->SetIp("192.168.3.175");

    QColor textcolor;
    textcolor.setNamedColor("black");
    iplabeledit->SetTextColor(textcolor);
    vboxlayout->addItem(vSpacer1);
    vboxlayout->addWidget(iplabeledit);
    vboxlayout->addItem(vSpacer2);


    iplabeledit->Clear();

}


void Widget::on_up_clicked()
{
    int nCont = ui->stackedWidget->count();
    int nIndex = ui->stackedWidget->currentIndex();
    --nIndex;

    if(nIndex < 0)
    {
        nIndex = nCont;
    }

    ui->stackedWidget->setCurrentIndex(nIndex);

    if(ui->stackedWidget->currentWidget() == ui->MarqueeWidget)
    {
        marquee->Start();
    } else {
        marquee->Stop();
    }
}

void Widget::on_down_clicked()
{
    int nCont = ui->stackedWidget->count();
    int nIndex = ui->stackedWidget->currentIndex();
    ++nIndex;

    if(nIndex > nCont)
    {
        nIndex = 0;
    }

    ui->stackedWidget->setCurrentIndex(nIndex);

    if(ui->stackedWidget->currentWidget() == ui->MarqueeWidget)
    {
        marquee->Start();
    } else {
        marquee->Stop();
    }
}
