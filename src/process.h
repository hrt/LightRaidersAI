#ifndef PROCESS_H
#define PROCESS_H
#include <string>

#define FIELD_WIDTH 16
#define FIELD_HEIGHT 16

#define FIELD_WIDTH_R 15
#define FIELD_HEIGHT_R 15

#define PID_0 0
#define PID_1 1

const std::string PROCESS_SETTINGS = std::string("settings");
const std::string PROCESS_UPDATE = std::string("update");
const std::string PRCOESS_ACTION = std::string("action");

const std::string SETTINGS_TIMEBANK = std::string("timebank");
const std::string SETTINGS_TIME_PER_MOVE = std::string("time_per_move");
const std::string SETTINGS_PLAYER_NAMES = std::string("player_names");
const std::string SETTINGS_YOUR_BOT = std::string("your_bot");
const std::string SETTINGS_YOUR_BOT_ID = std::string("your_botid");
const std::string SETTINGS_FIELD_WIDTH = std::string("field_width");
const std::string SETTINGS_FIELD_HEIGHT = std::string("field_height");

const std::string UPDATE_GAME_ROUND = std::string("round");
const std::string UPDATE_GAME_FIELD = std::string("field");

const std::string ACTION_MOVE = std::string("move");

const std::string MOVE_UP = std::string("up");
const std::string MOVE_DOWN = std::string("down");
const std::string MOVE_LEFT = std::string("left");
const std::string MOVE_RIGHT = std::string("right");

const char POS_DELIM = ',';
const std::string POS_EMPTY = std::string(".");
const std::string POS_WALL = std::string("x");
const std::string POS_P0 = std::string("0");
const std::string POS_P1 = std::string("1");
#endif