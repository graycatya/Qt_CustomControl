#pragma once


#include <QWidget>

#ifdef quc
#if (QT_VERSION < QT_VERSION_CHECK(5,7,0))
#include <QtDesigner/QDesignerExportWidget>
#else
#include <QtUiPlugin/QDesignerExportWidget>
#endif
class QDESIGNER_WIDGET_EXPORT Pagination : public QWidget
#else
class Pagination : public QWidget
#endif
{
    Q_OBJECT
public:
    explicit Pagination(QWidget *parent = nullptr);
    ~Pagination();

public:
    void UpdateTotalPage(const int &_PageItemSize, const int &_TotalItem, \
                         const int &_TotalPages = -1);

private:
    void Init( void );

private:
    int m_iCurrentPage;     // 当前页
    int m_iPageItemSize;    // 每页Item数量
    int m_iTotalPages;   // 总页数
    int m_iTotalItem;       // 总项目数量

    //QWidget *m_pRootWidget;

};

