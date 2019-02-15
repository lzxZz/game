

# moontree游戏大厅

使用QT进行编写
三栏式布局:左侧10%-20%为游戏列表,上部分作为常玩游戏,下面的是所有游戏列表,中间作为游戏大厅,监测选定游戏的桌子列表.右侧为个人信息页和好友列表.

## 编译

游戏大厅为该仓库下的GamePlatform项目,使用QT编写.
编译输入下列指令:
```shell
> cd GamePlatform
> qmake
> make
```
运行
```shell
> ./out/platform
```
清理临时文件
```shell
> make clean
```
但是生成的`Makefile`和`.qmake.stash`不会清理.
