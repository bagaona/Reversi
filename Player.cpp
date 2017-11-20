//
// Created by amir on 02/11/17.
//

#include "Player.h"
#include <iostream>

using namespace std;

Player::Player(const char t, Logic* l, Board* b) : token(t) {
}
Player::~Player() {
}
char Player::getToken() {
    return token;
}
