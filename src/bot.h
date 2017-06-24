#ifndef BOT_H
#define BOT_H
#include <string>
#include <vector>
#include <iostream>
#include "process.h"
#include "util.h"

#define UP_P0 -1
#define DOWN_P0 -2
#define LEFT_P0 -3
#define RIGHT_P0 -4
#define ANY_P0 -5

#define UP_P1 1
#define DOWN_P1 2
#define LEFT_P1 3
#define RIGHT_P1 4
#define ANY_P1 5

#define EMPTY 0
#define WALL 666

#define MOVED_LEFT -1
#define MOVED_RIGHT 1
#define MOVED_UP (-16)
#define MOVED_DOWN (16)

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
  int convertPosition(std::string position, int p);
  char fieldToChar(int f);
  void initialiseField();
  void printSettings();
  void printField();
  int timeBank;
  int timePerMove;
  std::vector<std::string> names;
  std::string player;
  int id;
  int width;
  int height;
  int round;
  int last_p0;
  int last_p1;
  std::vector<std::vector<int>> field;
};

#endif