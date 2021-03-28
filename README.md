# 西洋棋遊戲

## 類別表(Model)

---
> ### abstract class `Piece`: 棋子的抽象類別

- properties
  - char `color`: 棋子顏色
  - char `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過

- constructor / destructor
  - `Piece()`
  - `~Piece()`

- methods
  - getters / setters
    - char `getColor()`
    - char `getName()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkIsAlive()`
    - bool `checkHasMoved()`
    - void `setIsAlive()`
    - void `setHasMoved()`


---
> ### interface `MoveInterface`: 定義棋子的移動方式
- methods
  - `move()`
  - `capture()`




---
> ### class `Pawn` entends `Piece` implements `MoveInterface`: 兵 繼承 棋子
- properties
  - char `color`: 棋子顏色
  - char `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過
  

- constructor / destructor
  - `Pawn()`
  - `~Pawn()`

- method
  - getters / setters
    - char `getColor()`
    - char `getName()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkIsAlive()`
    - bool `checkHasMoved()`
    - void `setIsAlive()`
    - void `setHasMoved()`
  - `move()`
  - `capture()`


---
> ### class `Queen` extends `Piece` implements `MoveInterface`: 皇后 繼承 棋子
- properties
  - char `color`: 棋子顏色
  - char `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過
  

- constructor / destructor
  - `Queen()`
  - `~Queen()`
  
- method
  - getters / setters
    - char `getColor()`
    - char `getName()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkIsAlive()`
    - bool `checkHasMoved()`
    - void `setIsAlive()`
    - void `setHasMoved()`
  - `move()`
  - `capture()`

---
> ### class `King` extends `Piece` implements `MoveInterface`: 國王 繼承 棋子
- properties
  - char `color`: 棋子顏色
  - char `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過
  

- constructor / destructor
  - `King()`
  - `~King()`

- method
  - getters / setters
    - char `getColor()`
    - char `getName()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkIsAlive()`
    - bool `checkHasMoved()`
    - void `setIsAlive()`
    - void `setHasMoved()`
  - `move()`
  - `capture()`

---
> ### class `Bishop` extends `Piece` implements `MoveInterface`: 主教 繼承 棋子
- properties
  - char `color`: 棋子顏色
  - char `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過
  

- constructor / destructor
  - `Bishop()`
  - `~Bishop()`

- method
  - getters / setters
    - char `getColor()`
    - char `getName()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkIsAlive()`
    - bool `checkHasMoved()`
    - void `setIsAlive()`
    - void `setHasMoved()`
  - `move()`
  - `capture()`

---
> ### class `Castle` extends `Piece` implements `MoveInterface`: 城堡 繼承 棋子
- properties
  - char `color`: 棋子顏色
  - char `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過
  

- constructor / destructor
  - `Castle()`
  - `~Castle()`

- method
  - getters / setters
    - char `getColor()`
    - char `getName()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkIsAlive()`
    - bool `checkHasMoved()`
    - void `setIsAlive()`
    - void `setHasMoved()`
  - `move()`
  - `capture()`

---
> ### class `Knight` extends `Piece` implements `MoveInterface`: 騎士 繼承 棋子
- properties
  - char `color`: 棋子顏色
  - char `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過
  

- constructor / destructor
  - `Knight()`
  - `~Knight()`

- method
  - getters / setters
    - char `getColor()`
    - char `getName()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkIsAlive()`
    - bool `checkHasMoved()`
    - void `setIsAlive()`
    - void `setHasMoved()`
  - `move()`
  - `capture()`

---
> ### class `Cell`:

- properties
  - Piece* `currentPiece`: 目前在格子上的棋子
  - int `x`: 棋盤上的 X 位置
  - int `y`: 棋盤上的 Y 位置

- constructor / destructor
  - `Cell(int, int)`
  - `~Cell()`

- methods
  - getters / setters
    - Piece* `getCurrentPiece()`
    - void `setCurrentPiece(piece*)`
  - pair<char, int> `getCoordinate()`: 取得西洋棋的標準座標，例如 d5, h3, a6

---
> ### class `Board`:

- properties
  - const int `BOARD_SIZE` = 8
  - Cell `board[BOARD_SIZE][BOARD_SIZE]`: 棋盤

- methods


---
> ### abstract class `Player`: 玩家 的抽象類別
- properties
  
- methods
---
> ### class `HumanPlayer`: 真實玩家

- properties

- methods

---
> ### class `Game`:

- properties

- methods

