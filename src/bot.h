#ifndef BOT_H
#define BOT_H
#include <string>
#include <vector>
#include <iostream>
#include <time.h>
#include <algorithm>
#include "process.h"
#include "util.h"

#define LEFT -1
#define RIGHT 1
#define UP (-FIELD_WIDTH)
#define DOWN (FIELD_WIDTH)
#define ANY -666

#define EMPTY 0
#define WALL 666

#define MOVED_LEFT -1
#define MOVED_RIGHT 1
#define MOVED_UP (-FIELD_WIDTH)
#define MOVED_DOWN (FIELD_WIDTH)

class Bot
{
public:
  Bot();
  void setTimeBank(int t);
  void setTimePerMove(int t);
  void setPlayerNames(std::string player0, std::string player1);
  void setYourBot(std::string player);
  void setYourBotId(int id);
  void setFieldWidth(int width);
  void setFieldHeight(int height);
  void updateGameRound(int round);
  void updateGameField(std::string field);
  void makeMove(int time);
private:
  std::vector<std::vector<int>> applyMove(int id, int &position, int move, std::vector<std::vector<int>> field);
  std::string moveToString(int move);
  std::vector<int> generateMoves(int id, int position, std::vector<std::vector<int>> field);
  int convertPosition(std::string position, int p);
  char fieldToChar(int f);
  void initialiseField();
  void printSettings();
  void printField(std::vector<std::vector<int>> field);
  int timeBank;
  int timePerMove;
  std::vector<std::string> names;
  std::string player;
  int id;
  int width;
  int height;
  int round;
  int positionP0;
  int positionP1;
  std::vector<std::vector<int>> field;
};

#endif