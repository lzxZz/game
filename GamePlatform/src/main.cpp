#include "include/widget.h"
#include <QtWidgets/QApplication>

#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

void click(){
    qDebug("click");
}

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    // w.setWindowState(Qt::WindowState::WindowMaximized);


    QHBoxLayout basic_layout;       //最底层的布局,使用HBox,实现三栏式
    
    QVBoxLayout game_list_layout;   // 左侧游戏列表布局,使用VBox
    QVBoxLayout room_list_layout;   // TODO 中间游戏房间列表布局,临时使用
    QVBoxLayout friend_list_layout; // 个人信息及好友列表布局,使用VBOX垂直排列

    basic_layout.addLayout(&game_list_layout);
    basic_layout.addLayout(&room_list_layout, 1);   // 游戏房间布局最大伸缩
    basic_layout.addLayout(&friend_list_layout);

    QLabel label_friend;
    QLabel label_game;
    QLabel label;
    label_game.setMinimumWidth(200);
    label_friend.setMinimumWidth(200);

    room_list_layout.addWidget(&label,1);
    game_list_layout.addWidget(&label_game,1);
    friend_list_layout.addWidget(&label_friend,1);

    label_game.setText("游戏列表");
    label_game.setStyleSheet("background-color:blue;");

    label.setText("游戏房间列表");
    label.setStyleSheet("background-color : red;");
    
    label_friend.setText("个人信息\n及好友列表");
    label_friend.setStyleSheet("background-color:gold;");

    


    w.setLayout(&basic_layout);


    w.show();

    return a.exec();
}
