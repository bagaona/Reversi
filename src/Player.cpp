//
// Created by amir on 02/11/17.
//

#include "../include/Player.h"
#include <iostream>

using namespace std;

Player::Player(const char t) : sign(t) {
}
Player::~Player() {
}
char Player::getToken() {
    return sign;
}
