#include "Pagination.h"

Pagination::Pagination(QWidget *parent) : QWidget(parent)
{
    m_iCurrentPage = 1;
    m_iTotalItem = -1;
    m_iTotalPages = -1;
    m_iPageItemSize = -1;
    Init();
}

Pagination::~Pagination()
{
    m_iCurrentPage = 1;
    m_iTotalItem = -1;
    m_iTotalPages = -1;
    m_iPageItemSize = -1;
}

void Pagination::UpdateTotalPage(const int &_PageItemSize, const int &_TotalItem, const int &_TotalPages)
{
    if(_PageItemSize < 0 || _TotalItem < 0)
    {
        return;
    }
    //[0] 初始化 总页数
    m_iTotalPages = _TotalPages;



}

void Pagination::Init()
{
    QWidget *root = new QWidget(this);
}
