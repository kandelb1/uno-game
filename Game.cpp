/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Game.cpp
 * Author: BenjaminK
 * 
 * Created on July 11, 2019, 10:21 AM
 */

#include "Game.h"

Game::Game(int p){
    nplayers = p;
    CreateCards(deck);
    CreatePlayers();
}

Game::~Game(){
    for(Card* x : deck){
        free(x);
    }
}

void Game::CreateCards(vector<Card*> &d){
    //okay. so..the cards. the colors are 'r', 'g', 'b', 'y', 'w'
    for(int i = 0; i <= 12; i++){
        Card* a = new Card('r', i);
        Card* b = new Card('g', i);
        Card* c = new Card('b', i);
        Card* dd = new Card('y', i);
        d.push_back(a);
        d.push_back(b);
        d.push_back(c);
        d.push_back(dd);
    }
    for(int i = 1; i <= 12; i++){
        Card* a = new Card('r', i);
        Card* b = new Card('g', i);
        Card* c = new Card('b', i);
        Card* dd = new Card('y', i);
        d.push_back(a);
        d.push_back(b);
        d.push_back(c);
        d.push_back(dd);
    }
}

void Game::CreatePlayers(){
    for(int i = 0; i<nplayers; i++){
        Player* p = new HumanPlayer(i);
        players.push_back(p);
    }
}

void Game::DealCards(int p, int cards){
    //we are given the player number, and how many cards we want to give to them.
    Player* x = players[p];
    //we should check they are the same number.
    //this is pretty redundant, but better safe than sorry.
    if(x->GetPNumber() == p){
        //if we want to give them 7 cards this loop will run 7 times..
        for(int i = 0; i<cards; i++){
            Card* c = deck.back();
            x->TakeCard(c);
            deck.pop_back();
        }
    }
}

void Game::PrintDeck(){
    cout << "Deck size: " << deck.size() << endl;
    for(Card* x : deck){
        cout << "Color: " << x->GetColor() << " Number: " << x->GetNumber() << endl;
    }
    cout << "End print of deck." << endl;
}

void Game::StartGame(){
    for(int i = 0; i<nplayers; i++){
        DealCards(i, 7);
    }
}

void Game::PrintPlayerHands(){
    for(int i = 0; i<nplayers; i++){
        Player* x = players[i];
        x->PrintHand();
    }
}