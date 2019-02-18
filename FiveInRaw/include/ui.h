#ifndef MOONTREE_FIR_UI_H_
#define MOONTREE_FIR_UI_H_

#include <QtWidgets/QWidget>

#include <include/game.h>
namespace moontree {

namespace fir{

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent = nullptr);
   ~Widget(){}
   void SetGame(Game *game){
      game_ = game;
   }
private:
   Game *game_;      //UI对应的游戏
   void Refersh();   // 刷新界面上的棋盘和棋子
   // 绘制
    void paintEvent(QPaintEvent *event);
    // 监听鼠标移动情况，方便落子
   //  void mouseMoveEvent(QMouseEvent *event);
   //  // 实际落子
   //  void mouseReleaseEvent(QMouseEvent *event);

    
};
} //namespace fir
} //namespace moontree
#endif // MOONTREE_FIR_UI_H_
