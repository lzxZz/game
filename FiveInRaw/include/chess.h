#ifndef MOONTREE_FIR_CHESS_H_
#define MOONTREE_FIR_CHESS_H_

namespace moontree{

namespace fir{
   
   // 表示棋盘上点的状态
   enum class ChessPointType :int {
      kWhite = 1,  
      kBlack = 2,
      kNone =0      //表示当前位置没有棋
   };

   constexpr int BoardSize = 15;  //定义棋盘大小为15*15的标准尺寸
   // 棋盘结构体
   class ChessBoard{

   public:
      ChessBoard(){
         for (int i = 0; i < BoardSize; i++){
            for (int j = 0; j < BoardSize; j++){
               points[i][j] = ChessPointType::kNone;
            }
         }
      }
      ChessPointType points[BoardSize][BoardSize];
   };

} // namespace fir

} //namespace moontree

#endif //MOONTREE_FIR_CHESS_H_