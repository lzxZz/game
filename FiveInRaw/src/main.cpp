#include "include/ui.h"
#include <QtWidgets/QApplication>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

#include "include/game.h"

using moontree::fir::Widget;

    
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    moontree::fir::Game game;
    QWidget widget;
    game.Start();
    Widget w;
    w.SetGame(&game);
    QHBoxLayout hlay;
    hlay.addStretch(1);
    hlay.addWidget(&w,1,Qt::AlignCenter);
    hlay.addStretch(1);

    widget.setLayout(&hlay);



    widget.setWindowTitle("MoonTree 五子棋");
    widget.setWindowState(Qt::WindowFullScreen);

    widget.show();

    
    

    

    return a.exec();
}
