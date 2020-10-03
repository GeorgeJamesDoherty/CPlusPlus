/* Please note: even though it says IMPLEMENT ME, in some cases
   the implementation can be empty. In fact, you may wish to remove
   some of the functions entirely
*/
#include "Football.h"
#include <iostream>
using namespace std;
// -------------- Team --------------------

Team::Team(const string& name) {
	//sets up team name and score
	teamName = name;
	conceded = 0;
}

void Team::addGoalsConceded(int g) {
	//adds goals agaisnt the team
	conceded = conceded + g;
}

Team::~Team() {
}

// -------------- Player ------------------

Player::Player(const string& name, Team* t){
	//sets up player name team and score
	playerName = name;
	playerTeam = t;
	goals = 0;
	assists = 0;
}

// don't remove this even if you want to make the destructor pure virtual
Player::~Player() {
}

void Player::addAssists(int a) {
	//adds an assist to the player
	assists = assists + a;
}
// -------------- Attacker ------------------

Attacker::Attacker(const string& name, Team* t) : Player (name, t) {
	//sets attackers goals and assists to 0
	this->goals = 0;
	this->assists = 0;
}

Attacker::~Attacker() {
	// IMPLEMENT ME
}

// -------------- Midfielder ------------------

Midfielder::Midfielder(const string& name, Team* t):Player(name, t) {
	//sets attackers goals and assists to 0
	this->goals = 0;
	this->assists = 0;
}

Midfielder::~Midfielder() {
}

// -------------- Defender ------------------

Defender::Defender(const string& name, Team* t) :Player(name, t) {
	//sets attackers goals and assists to 0
	this->goals = 0;
	this->assists = 0;
}

Defender::~Defender() {
}
// -------------- Goalkeeper ------------------

Goalkeeper::Goalkeeper(const string& name, Team* t): Player(name,t) {
	//sets attackers goals and assists to 0
	shotsSaved = 0;
	this->goals = 0;
	this->assists = 0;
}

Goalkeeper::~Goalkeeper() {
}

void Goalkeeper::addShotsSaved(int ss) {
	//adds a shot saved to goal keeper
	shotsSaved = shotsSaved + ss;
}


// -------------- FantasyTeam ------------------

FantasyTeam::FantasyTeam() {
	//initalises player number
	playerNo = 0;
}

FantasyTeam::~FantasyTeam() {
}

bool FantasyTeam::addPlayer(Player* p) {
	//checks player number is valid
	if (playerNo > 10) {
		return false;
	}
	//checks player isnt already on the team
	for (int i = 0; i < playerNo; i++) {
		if (players[i] == p){
			return false;
		}
	}
	//adds player to the team
	players[playerNo] = p;
	playerNo++;
	return true;
}

int FantasyTeam::getScore() const {
	int temp = 0;
	int score = 0;
	//gets players score and adds it to the rest
	for (int i = 0; i < playerNo; i++) {
		temp = (players[i]->getScore());
		score += temp;
	}
	return score;
}