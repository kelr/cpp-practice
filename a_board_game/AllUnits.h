#ifndef _ALL_UNITS_H_
#define _ALL_UNITS_H_

#include <vector>
#include <map>
#include "stdio.h"

typedef std::pair<int, int> coord;
typedef std::map<coord, int> board;

// Enumeration for all possible owners of units
enum Under_command_of
{
	PLAYER,
	COMPUTER
};

// Class representing a unit
class Unit
{

public:
	// Default constructor. Initializes and returns Unit object to default values
	Unit();
	
	// Constructor with pre defined default values
	Unit(int x_val, int y_val, unsigned short size_val, unsigned short hp_val, unsigned short armor_val, unsigned short base_impact_val, Under_command_of owner_val);
	
	// Default destructor
	~Unit();
	
	// Returns the x position of a unit
	int getPositionX() const;
	
	// Returns the y position of a unit
	int getPositionY() const;
	
	// Returns the size of a unit
	unsigned short getSize() const;
	
	// Returns the current HP of a unit
	unsigned short getHp() const;
	
	// Returns the current HP of a unit
	unsigned short getArmor() const;
	
	// Returns the attack damage of a unit
	unsigned short getBaseImpact() const;
	
	// Returns the owner of the unit
	Under_command_of getOwner() const;
    
    // Returns the current status of the unit
    bool getUnitStatus() const;
	
	// Sets the x position of the unit
	void setPositionX(int x_val);
	
	// Sets the y position of the unit
	void setPositionY(int y_val);
	
	// Sets the size of the unit
	void setSize(unsigned short size_val);
	
	// Sets the hp of the unit
	void setHp(unsigned short hp_val);
	
	// Sets the armor of the unit
	void setArmor(unsigned short armor_val);
	
	// Sets the attack damage of the unit
	void setBaseImpact(unsigned short base_impact_val);
	
	// Sets the owner of the unit
	void setOwner(Under_command_of owner_val);
    
    // Sets the status of the unit
	void setUnitStatus(bool status);
    
private:
	// x coordinate of the unit
	int x;
	
	// y coordinate of the unit
	int y;
	
	// size of the unit
	unsigned short size;
	
	// hp of the unit
	unsigned short hp;
	
	// armor of the unit
	unsigned short armor;
	
	// attack value
	unsigned short base_impact;
	
	// owner of the unit
	Under_command_of owner;
    
    // Is this unit alive?
    bool isalive;
};

// Class that encompasses all units and their interactions
class AllUnits
{

public:
	// Default constructor
	AllUnits();
	
	// Default destructor
	~AllUnits();
	
    // Map with a pair of coordinates as the key to track where each unit is
    int CheckBoard(coord positions);
    
	// Checks if an x,y coordinate has any units associated with it. Returns -1 if empty.
	int GetUnit(int x, int y);
	
	// Selects a unit associated with a coordinate x,y if it's owned by the player.
	void SelectUnit(int x, int y);
	
	// Selects all player controlled units in a rectangle. This includes if you partially selected a fat unit on the edge.
	void SelectUnits(int x1, int y1, int x2, int y2);
	
	// Adds a unit to the playing field (all vector)
	void AddUnit(const Unit &new_unit);
	
	// Moves unit with index i to the new coordinate if it is possible. Returns true if success, return false and don't move if impossible.
	bool MoveUnit(int i, int new_x, int new_y);

	// Make currently selected units attack the unit defined by target_index
	void Affect(int target_index);
	
	// Prints the stats of a unit with index i
	void PrintUnit(int i) const;
	
	// Prints the stats of all selected units
	void PrintSelectedUnits() const;
	
	// Prints the stats of all units on the field
	void PrintAllUnits() const;
	
private:
	// Vector of all the units on the field
	std::vector<Unit> all;

	// Indexes of all units selected in the all vector
	std::vector<int> selected;
    
    board current_board;
    
};

#endif