#include "Player.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

class Simple: public Player{
 private:
  string name;
  vector<Card> hand;
  int total;
 public:
  Simple (string input)
  : name (input) { } 

  virtual const std::string & get_name() const override {
      return name;
  }

  virtual void add_card(const Card &c) override {
      hand.push_back(c);
  }

  virtual void calculate_total() override {
      int sum = 0;
      bool hasAce = false;
      for (int i = 0; i < hand.size(); ++i) {
          sum += hand[i].get_value();
          if (hand[i].get_rank() == Card::RANK_ACE) {
              hasAce = true;
          }
      }
      if (hasAce) {
          if (sum > 21) {
              sum -= 10;
          }
      }
    total = sum;
  }

  virtual bool take_hit() override {
      if (total < 17) {
          return true;
      }
      return false;
  }
  

};

class Human: public Player{
 private:
  string name;
  vector<Card> hand;
  int total;
 public:
  Human (string input)
  : name (input) { } 

  virtual const std::string & get_name() const override {
      return name;
  }

  virtual void add_card(const Card &c) override {
      hand.push_back(c);
  }

  virtual void calculate_total() override {
      int sum = 0;
      bool hasAce = false;
      for (int i = 0; i < hand.size(); ++i) {
          sum += hand[i].get_value();
          if (hand[i].get_rank() == Card::RANK_ACE) {
              hasAce = true;
          }
      }
      if (hasAce) {
          if (sum > 21) {
              sum -= 10;
          }
      }
    total = sum;
  }

  virtual bool take_hit() override {
     cout << "Human player " << name << ", please enter \"hit\", or \"stand\":" << endl;
     string response; 
     cin >> response;
     while (response != "hit" && response != "stand") {
        cout << "Enter a valid command:" << endl;
        cin >>response;
     }
     if (response == "hit") {
        return true;
     }
     return false; 
  }



};

Player * Player_factory(const std::string &name, const std::string &strategy){
    if (strategy == "Simple"){
        return new Simple(name);
    }
    if (strategy == "Human"){
        return new Human(name);
    }
    assert(false);
    return nullptr;
}

std::ostream & operator<<(std::ostream &os, const Player &p){
    return os << p.get_name();
}
