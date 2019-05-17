#include "Pack.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>

Pack::Pack() :next(0) {
    cards[0] = Card(Card::RANK_NINE, Card::SUIT_SPADES);
    cards[1] = Card(Card::RANK_TEN, Card::SUIT_SPADES);
    cards[2] = Card(Card::RANK_JACK, Card::SUIT_SPADES);
    cards[3] = Card(Card::RANK_QUEEN, Card::SUIT_SPADES);
    cards[4] = Card(Card::RANK_KING, Card::SUIT_SPADES);
    cards[5] = Card(Card::RANK_ACE, Card::SUIT_SPADES);
    cards[6] = Card(Card::RANK_NINE, Card::SUIT_HEARTS);
    cards[7] = Card(Card::RANK_TEN, Card::SUIT_HEARTS);
    cards[8] = Card(Card::RANK_JACK, Card::SUIT_HEARTS);
    cards[9] = Card(Card::RANK_QUEEN, Card::SUIT_HEARTS);
    cards[10] = Card(Card::RANK_KING, Card::SUIT_HEARTS);
    cards[11] = Card(Card::RANK_ACE, Card::SUIT_HEARTS);
    cards[12] = Card(Card::RANK_NINE, Card::SUIT_CLUBS);
    cards[13] = Card(Card::RANK_TEN, Card::SUIT_CLUBS);
    cards[14] = Card(Card::RANK_JACK, Card::SUIT_CLUBS);
    cards[15] = Card(Card::RANK_QUEEN, Card::SUIT_CLUBS);
    cards[16] = Card(Card::RANK_KING, Card::SUIT_CLUBS);
    cards[17] = Card(Card::RANK_ACE, Card::SUIT_CLUBS);
    cards[18] = Card(Card::RANK_NINE, Card::SUIT_DIAMONDS);
    cards[19] = Card(Card::RANK_TEN, Card::SUIT_DIAMONDS);
    cards[20] = Card(Card::RANK_JACK, Card::SUIT_DIAMONDS);
    cards[21] = Card(Card::RANK_QUEEN, Card::SUIT_DIAMONDS);
    cards[22] = Card(Card::RANK_KING, Card::SUIT_DIAMONDS);
    cards[23] = Card(Card::RANK_ACE, Card::SUIT_DIAMONDS);
}

Pack::Pack(std::istream& pack_input) :next(0){
    std::string rank;
    std::string of;
    std::string suit;
    for (int i = 0; i < 24; ++i){
        pack_input >> rank >> of >> suit;
        cards[i] = Card(rank, suit);
    }
}

Card Pack::deal_one(){
    ++next;
    return cards[next - 1];
}

void Pack::reset(){
    next = 0;
}

void Pack::shuffle(){
    for (int i = 0; i < 7; ++i){
        int index = 0;
        Card firstHalf [12];
        Card secondHalf [12];
        for (int j = 0; j < 12; ++j){
            firstHalf[j] = cards[j];
            secondHalf[j] = cards[12 + j];
        }
        // splits pack into two parts
        for (int q = 0; q < 12; ++q){
            cards[index] = secondHalf[q];
            ++index;
            cards[index] = firstHalf[q];
            ++index;
        }
        // inshuffles them together
    }
    next = 0;
}

bool Pack::empty() const{
    return (next >= PACK_SIZE);
}
