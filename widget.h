#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Marquee;

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

public:
    void TextProgressArc( void );
    void TextMarquee( void );
    void TextSwitchButton( void );
    void TextIpInputGroup( void );


private slots:
    void on_up_clicked();

    void on_down_clicked();

private:
    Ui::Widget *ui;
    Marquee *marquee;
};
#endif // WIDGET_H
