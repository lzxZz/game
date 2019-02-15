#include "include/ui.h"

#include <QtGui/QPainter>

const int kBoardMargin = 30; // 棋盘边缘空隙
const int kRadius = 15;      // 棋子半径
const int kMarkSize = 6;     // 落子标记边长
const int kBlockSize = 40;   // 格子的大小
const int kPosDelta = 20;    // 鼠标点击的模糊距离上限
int kBoardSizeNum = 15;

namespace moontree
{
namespace fir
{

Widget::Widget(QWidget *parent) 
   : QWidget(parent)
{
   this->setFixedSize(kBoardMargin * 2 + kBlockSize * kBoardSizeNum, kBoardMargin * 2 + kBlockSize * kBoardSizeNum);
}

void Widget::paintEvent(QPaintEvent *event){
   QPainter painter(this);
    // 绘制棋盘
    painter.setRenderHint(QPainter::Antialiasing, true); // 抗锯齿
//    QPen pen; // 调整线条宽度
//    pen.setWidth(2);
//    painter.setPen(pen);
    for (int i = 0; i < kBoardSizeNum + 1; i++)
    {
        painter.drawLine(kBoardMargin + kBlockSize * i, kBoardMargin, kBoardMargin + kBlockSize * i, size().height() - kBoardMargin);
        painter.drawLine(kBoardMargin, kBoardMargin + kBlockSize * i, size().width() - kBoardMargin, kBoardMargin + kBlockSize * i);
    }

}


} // namespace fir
} // namespace moontree
