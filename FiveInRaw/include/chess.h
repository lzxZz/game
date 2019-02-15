#ifndef MOONTREE_FIR_CHESS_H_
#define MOONTREE_FIR_CHESS_H_

namespace moontree{

namespace fir{
   
   // 表示棋盘上点的状态
   enum class ChessPointType{
      kWhite,  
      kBlack,
      kNone       //表示当前位置没有棋
   };

   constexpr int BoardSize = 15;  //定义棋盘大小为15*15的标准尺寸
   // 棋盘结构体
   struct ChessBoard{
      ChessPointType points[BoardSize][BoardSize];
   };

} // namespace fir

} //namespace moontree

#endif //MOONTREE_FIR_CHESS_H_