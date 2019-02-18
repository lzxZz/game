#ifndef MOONTREE_FIR_PLAYER_H_
#define MOONTREE_FIR_PLAYER_H_

#include <stdint.h>

namespace moontree{

namespace fir{

   class Player{
      void Repent(); // 申请悔棋
      void Confirm(const uint8_t x, const uint8_t y); //落子
      void Peace();  //申请和棋
      void Remote(Player *other);   //通知远程的玩家自己的操作.
   };


} //namespace fir

} //namespace moontree

#endif //MOONTREE_FIR_PLAYER_H_