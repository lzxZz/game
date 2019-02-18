#include "include/ui.h"

#include <QtGui/QPainter>

#include <iostream>
using namespace std;

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
      for (int i = 0; i < kBoardSizeNum + 1; i++){
         painter.drawLine(kBoardMargin + kBlockSize * i, kBoardMargin, kBoardMargin + kBlockSize * i, size().height() - kBoardMargin);
         painter.drawLine(kBoardMargin, kBoardMargin + kBlockSize * i, size().width() - kBoardMargin, kBoardMargin + kBlockSize * i);
      }

      QBrush white_bursh;
      QBrush black_brush;
      white_bursh.setStyle(Qt::SolidPattern);
      white_bursh.setColor(Qt::white);
      black_brush.setStyle(Qt::SolidPattern);
      black_brush.setColor(Qt::black);
      // painter.drawEllipse(0,0,15,15);
      for (int i = 0; i < BoardSize; i++){
         for (int j = 0; j < BoardSize; j++){
            
            switch (game_->board_.points[i][j]){
               case ChessPointType::kWhite:{
                  cout << "W" << i << "\t" << j << endl;
                  painter.setBrush(white_bursh);
                  int x,y,w,h;
                  x = kBoardMargin + kBlockSize * i - kRadius;
                  y = kBoardMargin + kBlockSize * j - kRadius;
                  w = h = 30;
                  painter.drawEllipse(x,y,w,h);
                  continue;
               }
               case ChessPointType::kBlack:{
                  cout << "B" << i << "\t" << j << endl;
                  painter.setBrush(black_brush);
                  int x,y,w,h;
                  x = kBoardMargin + kBlockSize * i - kRadius;
                  y = kBoardMargin + kBlockSize * j - kRadius;
                  w = h = 30;
                  painter.drawEllipse(x,y,w,h);
                  continue;
               }
               case ChessPointType::kNone:{

               }
            }
     
         }
      }
      
      // painter.drawEllipse(kBoardMargin + kBlockSize * j - kRadius, 
      //                      kBoardMargin + kBlockSize * i - kRadius, 
      //                      kRadius * 2, 
      //                      kRadius * 2);
   }

} // namespace fir
} // namespace moontree
