#pragma once
#include"Presentation.h"
#include"myTP.hpp"
#include"pile.hpp"
#include"AlgoFIFO.hpp"
#include"AlgoLRU.hpp"
#include"AlgoOPT.hpp"
#include<iostream>
#include<string>
#include<windows.h>


enum TP { QUITTER, AlgoFIFO, AlgoLRU, AlgoOPT , AlgoSecondChance};
const std::string welcomText = "Welcome to my attempt for solving the memory management (PW)\n of the first year DSIA\n";
