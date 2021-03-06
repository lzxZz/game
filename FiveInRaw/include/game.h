#ifndef MOONTREE_FIR_GAME_H_
#define MOONTREE_FIR_GAME_H_

#include "include/chess.h"
#include "include/player.h"
namespace moontree{

namespace fir{
   
   // 对局状态
   enum class GameState{
      kNoRun,     //刚初始化,还未运行
      kRunning,   //运行中
      kDraw,      //平局
      kOver,      //结束
      kSuspend,   //暂停
   };

   class Widget;
   /**
    * 
    *    游戏类, 在一次对局中作为被动方,
    *    接收通知才行动.通知来源于两个玩家.
    * 
   **/
   class Game{
   friend class Widget;
   public:
      Game() = default;
      void Start()        // 开始游戏
      {
         qDebug("set point");
         board_.points[8][8] = ChessPointType::kBlack;
         board_.points[7][8] = ChessPointType::kWhite;
         board_.points[0][0] = ChessPointType::kBlack;
         qDebug("Set ok");
      }
      void Act(void *act); // 被调用,然后执行动作
      ~Game(){
         qDebug("~Game");
      }
   private:
      GameState state_;
      ChessBoard board_;
      Player local_player_;      // 本地玩家
      Player remote_player_;     // 远程玩家
   };

} //namespace fir

} //namespace moontree


#endif //MOONTREE_FIR_GAME_H_