//******************************************************
// IMPLEMENTATION FILE for class Suits
//******************************************************

#include "Suits.h"

#include <algorithm>
#include <cctype>     // For toupper
#include <map>
#include <string>

// 2026-11-17 TSM: Need a local function to resolve the "transform" below
char suits_uppercase(unsigned char c) {
    return std::toupper(c);
}

Suits::Suits() { mySuit = CLUBS; }

//******************************************************

Suits::Suits(string initString) {
  // Create a mapping between strings and enums
  map<string, Suit> lookup;
  lookup["CLUBS"] = CLUBS;
  lookup["DIAMONDS"] = DIAMONDS;
  lookup["HEARTS"] = HEARTS;
  lookup["SPADES"] = SPADES;
  // Convert the string to uppercase
  // 2026-11-17 TSM:  Need a local function to compile the "transform" in Qt Creator
  //transform(initString.begin(), initString.end(), initString.begin(), toupper);
    transform(initString.begin(), initString.end(), initString.begin(), suits_uppercase);
  // Get the corresponding enum
  mySuit = lookup[initString];
}

//******************************************************

Suits::Suits(int initInt) { mySuit = Suit(initInt); }

//******************************************************

string Suits::toString() const {
  string suitString[4] = {"CLUBS", "DIAMONDS", "HEARTS", "SPADES"};
  return suitString[mySuit];
}
//******************************************************

int Suits::toInt() const { return int(mySuit); }

//******************************************************

bool Suits::operator<(Suits otherSuit) const {
  return mySuit < otherSuit.toInt();
}

//******************************************************

bool Suits::operator==(Suits otherSuit) const {
  return mySuit == otherSuit.toInt();
}
