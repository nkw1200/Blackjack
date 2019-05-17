#include "Card.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cassert>
#include <string>
#include <array>
#include <vector>
#include <sstream>
#include <algorithm>

Card::Card()
    :Card(RANK_TWO, SUIT_SPADES) { }
//default constructor by delegating constructors

Card::Card(const std::string &rank_in, const std::string &suit_in)
    :rank(rank_in), suit(suit_in) { }
//constructor with input

std::string Card::get_rank() const {
    return rank;
}

std::string Card::get_suit() const {
    return suit;
}

int Card::get_value() const {
    if (rank == RANK_TWO) {
        return 2;
    }

    if (rank == RANK_THREE) {
        return 3;
    }

    if (rank == RANK_FOUR) {
        return 4;
    }

    if (rank == RANK_FIVE) {
        return 5;
    }

    if (rank == RANK_SIX) {
        return 6;
    }

    if (rank == RANK_SEVEN) {
        return 7;
    }

    if (rank == RANK_EIGHT) {
        return 8;
    }

    if (rank == RANK_NINE) {
        return 9;
    }

    if (rank == RANK_TEN) {
        return 10;
    }

    if (rank == RANK_JACK) {
        return 10;
    }

    if (rank == RANK_QUEEN) {
        return 10;
    }

    if (rank == RANK_KING) {
        return 10;
    }

    if (rank == RANK_ACE) {
        return 11;
    }
}

std::ostream & operator<<(std::ostream &os, const Card &card){
    return os << card.get_rank() << " of " << card.get_suit();
}
