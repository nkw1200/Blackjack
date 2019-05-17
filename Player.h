#ifndef PLAYER_H
#define PLAYER_H

#include "Card.h"
#include <string>
#include <vector>

class Player {
 public:
  virtual const std::string & get_name() const = 0;

  virtual void add_card(const Card &c) = 0;

  virtual void calculate_total() = 0;

  virtual bool take_hit() = 0;



  virtual ~Player() {}


};

//EFFECTS: Returns a pointer to a player with the given name and strategy
//To create an object that won't go out of scope when the function returns,
//use "return new Simple(name)" or "return new Human(name)"
//Don't forget to call "delete" on each Player* after the game is over
Player * Player_factory(const std::string &name, const std::string &strategy);

//EFFECTS: Prints player's name to os
std::ostream & operator<<(std::ostream &os, const Player &p);

#endif