/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AIPlayer.h
 * Author: BenjaminK
 *
 * Created on July 13, 2019, 4:29 PM
 */

#ifndef AIPLAYER_H
#define AIPLAYER_H

#include <map>
using std::map;
#include "Player.h"


class AIPlayer : public Player{
public:
    AIPlayer(int n);
    virtual int Play(Pile* pl, Deck* d);
    virtual void TakeCard(Card* c);
private:
    map<int, vector<Card*>> plays;
};

#endif /* AIPLAYER_H */

