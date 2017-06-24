#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <string>
#include <sstream>
#include "bot.h"
#include "process.h"

class Parser
{
public:
  Parser(Bot &bot);
  void parseLine();
private:
  Bot bot;
  int width;
  int height;
};

#endif