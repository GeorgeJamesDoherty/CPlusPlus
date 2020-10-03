#include <string>
using namespace std;

// Class for a real-life team
class Team {
public:
	// constructor. name is the name of the team.
	// Also should initialise relevant team statistics to 0
	Team(const string& name);

	// destructor
	~Team();

	// Add number of goals conceded by the team by g. If g is omitted,
	// default 1 is assumed.
	void addGoalsConceded(int g = 1);
	
	string teamName;
	int conceded;
private:
};

// Class for a footballer
// You must turn this into an abstract class
class Player {
public:
	// Default constructor.
	// This is only necessary to compile the empty version.
	// If your implementation is correct this can be removed
	Player();

	// Value constructor, specifying the name of the player and
	// the team the player belongs to. 
	// The memory pointed to by t is externally managed and 
	// not owned by this class
	// Also should initialise relevant player statistics to 0
	Player(const string& name, Team* t);

	// Destructor
	~Player();

	// Increases the player's number of goals scored by g. 
	// If g is omitted, 1 is assumed

	//sets virtual function to return add goal
	virtual void addGoalsScored(int g = 1) = 0;

	// Increases the player's number of assists by a. 
	// If a is omitted, 1 is assumed
	void addAssists(int a = 1);

	// Returns the score of this player, based on all the individual
	// and team statistics. It is assumed that the caller knows what
	// they are doing and have called the various add..() functions
	// before calling this function.

	//sets virtual function to return score
	virtual int getScore() const = 0;

	// Returns a string that includes the player's name, the position
	// they play (goalkeeper/attacker etc.), the name of
	// the (real-life) team they belong to, all their statistics such
	// as number of goals scored/conceded, assists etc., and the total
	// points scored.
	// Ideally you should print this exactly as described in the test cases
	// but minor formatting differences will be tolerated

	//sets virtual function to print class
	virtual string print() const = 0;

	// TODO: add any protected/private member variables you need
protected:
	string playerName;
	Team* playerTeam;
	int goals;
	int assists;
	int score;
};

// Classes for each of the 4 roles
// Most functions are explained in the Player class above

class Attacker : public Player {
public:
	Attacker(const string& name, Team* t);
	~Attacker();
	//attacker virtual get score
	int getScore() const {
		return (this -> assists * 3 + this -> goals * 4);;
	}
	//attaker virtual print
	string print() const {
		string toPrint = "Attacker: " + playerName + ", Team: " + (playerTeam->teamName) + "\n";
		toPrint += " Goals scored: " + to_string(this->goals) + "\n";
		toPrint += " Assists: " + to_string(this->assists) + "\n";
		toPrint += " Goals conceded: " + to_string(playerTeam->conceded) + "\n";
		toPrint += " Score: " + to_string(this->getScore());
		return toPrint;
	}
	//attacker virtual add goals score
	void addGoalsScored(int g = 1) {
		this->goals = this->goals + g;
	}
};

class Midfielder : public Player {
public:
	Midfielder(const string& name, Team* t);
	~Midfielder();
	//midfielder virtual get score
	int getScore() const {
		int score = (this ->assists * 3 + this ->goals * 5);
		int gConceded = playerTeam->conceded;
		if (gConceded == 0) {
			return (score + 1);
		}
		else {
			return score;
		}
	}
	//midfielder virtual print
	string print() const {
		string toPrint = "Midfielder: " + playerName + ", Team: " + (playerTeam->teamName) + "\n";
		toPrint += " Goals scored: " + to_string(this->goals) + "\n";
		toPrint += " Assists: " + to_string(this->assists) + "\n";
		toPrint += " Goals conceded: " + to_string(playerTeam->conceded) + "\n";
		toPrint += " Score: " + to_string(this->getScore());
		return toPrint;
	}
	//midfielder virtual add goals
	void addGoalsScored(int g = 1) {
		this->goals = this->goals + g;
	}
};

class Defender : public Player {
public:
	Defender(const string& name, Team* t);
	~Defender();
	//defender virtual get score
	int getScore() const {
		int score = (this -> assists * 3 + this -> goals * 6);
		int gConceded = playerTeam->conceded;
		if (gConceded == 0) {
			return (score + 4);
		}
		else {
			return (score - (gConceded / 2));
		}
	}
	//defender virtual print
	string print() const {
		string toPrint = "Defender: " + playerName + ", Team: " + (playerTeam->teamName) + "\n";
		toPrint += " Goals scored: " + to_string(this->goals) + "\n";
		toPrint += " Assists: " + to_string(this->assists) + "\n";
		toPrint += " Goals conceded: " + to_string(playerTeam->conceded) + "\n";
		toPrint += " Score: " + to_string(this->getScore());
		return toPrint;
	}
	//defender virtual add goals score
	void addGoalsScored(int g = 1) {
		this->goals = this->goals + g;
	}
	// TODO: you can add any private member variables
};

class Goalkeeper : public Player {
public:
	Goalkeeper(const string& name, Team* t);
	~Goalkeeper();
	//goalkeeper virtual get score
	int getScore() const {
		int score = (shotsSaved / 3) + this -> assists * 3 + this -> goals * 6;
		int gConceded = playerTeam->conceded;
		if (gConceded == 0) {
			return score + 4;
		}
		else {
			return score - (gConceded / 2);
		}
	}
	//goalkeeper virtual print
	string print() const {
		string toPrint = "Goalkeeper: " + playerName +", Team: " + (playerTeam->teamName) + "\n";
		toPrint += " Goals scored: " + to_string(this ->goals) + "\n";
		toPrint += " Assists: " + to_string(this->assists) + "\n";
		toPrint += " Goals conceded: " + to_string(playerTeam->conceded) + "\n";
		toPrint += " Shots saved: " + to_string(shotsSaved) + "\n";
		toPrint += " Score: " + to_string(this->getScore());
		return toPrint;
	}
	//goalkeeper virtual addGoals scored
	void addGoalsScored(int g = 1) {
		this->goals = this->goals + g;
	}
	// Increase the number of shots saved by this goalkeeper by ss. 
	// If ss is omitted, 1 is assumed
	void addShotsSaved(int ss = 1);

	// TODO: you can add any private member variables
private:
	int shotsSaved;
};

// Class for a fantasy team
class FantasyTeam {

public:
	// Constructor. Should initialise team to 0 players
	FantasyTeam();

	~FantasyTeam(); // destructor

	// Add p to be part of this fantasy team, returning true if successful.
	// The memory pointed to by p belongs to the caller.
	// The function should check whether the same player (as identified 
	// by pointer equality) is already added, and also if there are
	// already 11 players added. If either is true, return false and
	// do not add the player.
	bool addPlayer(Player* p);

	// Returns the total score of all players in this fantasy team.
	// This should still work if less than 11 players have been added
	// (non-existent players contribute 0 to team score).
	int getScore() const;

private:
	// Member variables: the 11 players
	// You must not change this.
	Player* players[11];
	int playerNo;
	// TODO: You can add additional data members

};
