# 西洋棋遊戲 Chess # Not done yet

## 類別表(Model)

---
> ### abstract class `Piece`: 棋子的抽象類別

- properties
  - char `color`: 棋子顏色
  - ID `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過

- constructor / destructor
  - `Piece()`
  - `~Piece()`

- methods
  - getters / setters
    - char `getColor()`
    - ID `getPieceID()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkAlive()`
    - bool `checkMoved()`
    - void `setAlive()`
    - void `setMoved()`
  - bool `isTargetCaptruable()`
  - bool `isMoveValid()`
  - void `move()`


---
> ### class `Pawn` entends `Piece`: 兵 繼承 棋子
- properties
  - char `color`: 棋子顏色
  - ID `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過
  

- constructor / destructor
  - `Pawn()`
  - `~Pawn()`

- method
  - getters / setters
    - char `getColor()`
    - ID `getPieceID()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkAlive()`
    - bool `checkMoved()`
    - void `setAlive()`
    - void `setMoved()`
  - bool `isTargetCaptruable()`
  - bool `isMoveValid()`
  - void `move()`


---
> ### class `Queen` extends `Piece`: 皇后 繼承 棋子
- properties
  - char `color`: 棋子顏色
  - ID `pieceID`: 棋子代號
  - bool `isAlive`: 棋子還有沒有死
  - bool `hasMoved`: 棋子有沒有移動過
  

- constructor / destructor
  - `Queen()`
  - `~Queen()`
  
- method
  - getters / setters
    - char `getColor()`
    - ID `getPieceID()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkAlive()`
    - bool `checkMoved()`
    - void `setAlive()`
    - void `setMoved()`
  - bool `isTargetCaptruable()`
  - bool `isMoveValid()`
  - void `move()`

---
> ### class `King` extends `Piece`: 國王 繼承 棋子
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
      - ID `getPieceID()`
      - void `setColor(char)`
      - void `setName(char)`
      - bool `checkAlive()`
      - bool `checkMoved()`
      - void `setAlive()`
      - void `setMoved()`
  - bool `isTargetCaptruable()`
  - bool `isMoveValid()`
  - void `move()`

---
> ### class `Bishop` extends `Piece`: 主教 繼承 棋子
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
    - ID `getPieceID()`
    - void `setColor(char)`
    - void `setName(char)`
    - bool `checkAlive()`
    - bool `checkMoved()`
    - void `setAlive()`
    - void `setMoved()`
  - bool `isTargetCaptruable()`
  - bool `isMoveValid()`
  - void `move()`

---
> ### class `Castle` extends `Piece`: 城堡 繼承 棋子
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
      - ID `getPieceID()`
      - void `setColor(char)`
      - void `setName(char)`
      - bool `checkAlive()`
      - bool `checkMoved()`
      - void `setAlive()`
      - void `setMoved()`
  - bool `isTargetCaptruable()`
  - bool `isMoveValid()`
  - void `move()`

---
> ### class `Knight` extends `Piece`: 騎士 繼承 棋子
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
      - ID `getPieceID()`
      - void `setColor(char)`
      - void `setName(char)`
      - bool `checkAlive()`
      - bool `checkMoved()`
      - void `setAlive()`
      - void `setMoved()`
  - bool `isTargetCaptruable()`
  - bool `isMoveValid()`
  - void `move()`

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
  - Piece* board[BOARD_SIZE][BOARD_SIZE];
  - bool isWhiteTurn = true;

- methods
  - bool `checkWhiteTurn()`
  - bool isBlackCheckmate()
  - bool isWhiteCheckmate()
  - bool isGameOver()
  - void resetBoard()
  - void moveExecute(Movement&)
  - bool isMoveInRange(Movement&)
  - void switchTurn()

