# moontree游戏大厅

使用QT进行编写
三栏式布局:左侧10%-20%为游戏列表,上部分作为常玩游戏,下面的是所有游戏列表,中间作为游戏大厅,监测选定游戏的桌子列表.右侧为个人信息页和好友列表.

# 游戏项目
## 1. 五子棋
五子棋作为一款经典,简单的游戏,优先制作.


规则简单,任意一方有五个连成一条线的五个棋子即判定为胜利.

### 通信规则

通信方: 对弈双方(*后文分别称之为AB*)和服务端(*后文称之为S*).

处理方式:
1. A在游戏大厅中进入任意棋桌(即对局房间),开始等待,直到A主动退出.  
   此时A主动与服务器建立联接,申请占用该棋桌T.占用完成之后,禁止其他用户的申请.  
   此时A保留占用的棋桌ID,服务端记录占用棋桌的用户ID.
1. B进入棋桌T,开始对局.  
   此时B申请进入T,只允许一个用户进入.(*暂不考虑观战系统,观战使用另外一种方式*).
   此时AB之间,AS,BS之间相互都建立联系  
   A,B,S都启动一个棋谱,来记录双方的下棋情况.
1. A,B对局中.  
   通信规则如下:  
      1. 双方每一次操作都向对方及服务器发送一个数据包,来更新远端的棋谱.
      1. 间隔性的对棋谱进行压缩加密,来验证三个棋谱是否一致,以此来防止作弊. 

   通信协议如下:
      ```
      [源用户ID] [目标用户ID]
      [桌ID] [对局ID]
      [消息种类] 
      [棋种类] [棋位置] / [校验码]
      ```
      示例如下
      ```
      000001 000002
      001 01
      1
      0 8,8
      ```
      其中第四行的第一个数字,0表示黑棋,1表示白棋.后面表示新下的棋的坐标.  
      第三行中表示消息种类,0表示校验信息,1表示新下棋.
