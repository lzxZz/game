#ifndef MOONTREE_FIR_UI_H_
#define MOONTREE_FIR_UI_H_

#include <QtWidgets/QWidget>
// namespace Ui {
// class Widget;
// }
namespace moontree {

namespace fir{

class Widget : public QWidget
{
   Q_OBJECT

public:
   explicit Widget(QWidget *parent = nullptr);
   ~Widget(){}

private:
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
