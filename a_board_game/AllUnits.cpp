#include "AllUnits.h"

// Default constructor. Initializes a Unit to default values
Unit::Unit(void)
{
	Under_command_of new_owner = PLAYER;
	
	x = 0;
	y = 0;
	size = 3;
	hp = 10;
	armor = 1;
	base_impact = 2;
	owner = new_owner;
    isalive = true;
}

// Constructor with pre defined default values
Unit::Unit(int x_val, int y_val, unsigned short size_val, unsigned short hp_val, unsigned short armor_val, unsigned short base_impact_val, Under_command_of owner_val)
{
	x = x_val;
	y = y_val;
	size = size_val;
	hp = hp_val;
	armor = armor_val;
	base_impact = base_impact_val;
	owner = owner_val;
    isalive = true;
}

// Default destructor
Unit::~Unit()
{

}

// Returns the x position of a unit
int Unit::getPositionX() const
{
	return x;
}

// Returns the y position of a unit
int Unit::getPositionY() const
{
	return y;
}

// Returns the size of a unit
unsigned short Unit::getSize() const
{
	return size;
}

// Returns the current HP of a unit
unsigned short Unit::getHp() const
{
	return hp;
}

// Returns the current HP of a unit
unsigned short Unit::getArmor() const
{
	return armor;
}

// Returns the attack damage of a unit
unsigned short Unit::getBaseImpact() const
{
	return base_impact;
}

// Returns the owner of the unit
Under_command_of Unit::getOwner() const
{
	return owner;
}

bool Unit::getUnitStatus() const
{
    return isalive;
}
// Sets the x position of the unit
void Unit::setPositionX(int x_val)
{
	x = x_val;
}

// Sets the y position of the unit
void Unit::setPositionY(int y_val)
{
	y = y_val;
}

// Sets the size of the unit
void Unit::setSize(unsigned short size_val)
{
	size = size_val;
}

// Sets the hp of the unit
void Unit::setHp(unsigned short hp_val)
{
	hp = hp_val;
}

// Sets the armor of the unit
void Unit::setArmor(unsigned short armor_val)
{
	armor = armor_val;
}

// Sets the attack damage of the unit
void Unit::setBaseImpact(unsigned short base_impact_val)
{
	base_impact = base_impact_val;
}

// Sets the owner of the unit
void Unit::setOwner(Under_command_of owner_val)
{
	owner = owner_val;
}

void Unit::setUnitStatus(bool status)
{
    isalive = status;
}
// Default constructor. Initializes the playing field with no Units
AllUnits::AllUnits(void)
{

}

// Default destructor
AllUnits::~AllUnits(void)
{

}

int AllUnits::CheckBoard(coord positions)
{
    return current_board[positions];
}

// Checks if an x,y coordinate has any units associated with it. Returns -1 if empty.
int AllUnits::GetUnit(int x, int y)
{
    coord check_coordinate(x,y);
    // See if the coordinate we're looking at is occupied
    if (current_board.find(check_coordinate) == current_board.end())
    {
        return -1;
    }
    // Who is occupying it?
    else
    {
        return CheckBoard(check_coordinate);
    }
}

// Selects a unit associated with a coordinate x,y if it's owned by the player.
void AllUnits::SelectUnit(int x, int y)
{
	// Get the index of the unit associated with this square, or nothing
	int this_unit = GetUnit(x, y);
	
	// Clear things we selected before, if any
	selected.clear();
	
	// If the square has a unit and is owned by the player and it is not already selected, select that unit
	if (this_unit != -1 && all[this_unit].getOwner() == PLAYER)
	{
		printf("Selected Unit %d\n",this_unit);
		selected.push_back(this_unit);
	}
}

// Selects all player controlled units in a rectangle. This includes if you partially selected a fat unit on the edge.
void AllUnits::SelectUnits(int x1, int y1, int x2, int y2)
{
	bool unit_already_selected = false;
	int this_unit = 0;
	int upper_x = 0;
	int lower_x = 0;
	int upper_y = 0;
	int lower_y = 0;
	// Get the larger x values of the rectangle
	if (x1 > x2)
	{
		upper_x = x1;
		lower_x = x2;
	}
	// If x2 is the larger one...
	else if (x2 > x1)
	{
		upper_x = x2;
		lower_x = x1;
	}
	// They're the same so it doesn't matter
	else
	{
		upper_x = x1;
		lower_x = x1;
	}
	
	// Do the same for y values
	if (y1 > y2)
	{
		upper_y = y1;
		lower_y = y2;
	}
	// If y2 is the larger one...
	else if (y2 > y1)
	{
		upper_y = y2;
		lower_y = y1;
	}
	// They're the same so it doesn't matter
	else
	{
		upper_y = y1;
		lower_y = y1;
	}
	// Select all the units within the box
	for (int x_iter = lower_x; x_iter < upper_x + 1; x_iter++)
	{
		for (int y_iter = lower_y; y_iter < upper_y + 1; y_iter++)
		{
			this_unit = GetUnit(x_iter, y_iter);
			// We only care about real units in the box and if the player owns it
			if (this_unit != -1 && all[this_unit].getOwner() == PLAYER)
			{
				unit_already_selected = false;
				
				// Check the unit was already selected
				for (unsigned int i=0; i < selected.size(); i++)
				{
					if (this_unit == selected[i])
					{
						unit_already_selected = true;
					}
				}
				// Add it to the selected vector if the unit does not exist in it already 
				if (!unit_already_selected)
				{
					selected.push_back(this_unit);
					//printf("Drag selected Unit: %d\n",this_unit);
				}
			}
		}
	}
}

// Adds a unit to the playing field (all vector)
void AllUnits::AddUnit(const Unit &new_unit)
{
    // For small units
    if (new_unit.getSize() == 1)
    {
        if (GetUnit(new_unit.getPositionX(), new_unit.getPositionY()) == -1)
        {
            coord check_coordinate (new_unit.getPositionX(),new_unit.getPositionY());
            current_board[check_coordinate] = all.size();
            all.push_back(new_unit);
        }
        else
        {
            printf("Something is there already!\n");
            return;
        }
    }
    // Calculate extra squares for bigger units
    else
    {
        int this_unit_x = new_unit.getPositionX();
		int this_unit_y = new_unit.getPositionY();
        
        unsigned short size_adjustment = (new_unit.getSize() -1) / 2;
        
        int lower_x = this_unit_x - size_adjustment;
        int upper_x = this_unit_x + size_adjustment;
        int lower_y = this_unit_y - size_adjustment;
        int upper_y = this_unit_y + size_adjustment;
        // Check all the squares if they're available
		for (int x_iter = lower_x; x_iter < upper_x + 1; x_iter++)
		{
			for (int y_iter = lower_y; y_iter < upper_y + 1; y_iter++)
			{
				if(GetUnit(x_iter, y_iter) != -1)
                {
                    //printf("Can't spawn a unit, there's something there!\n");
                    return;
                }
			}
		}
        // Must be available, make all the coordinates checked belong to the current unit
        for (int x_iter = lower_x; x_iter < upper_x + 1; x_iter++)
		{
			for (int y_iter = lower_y; y_iter < upper_y + 1; y_iter++)
			{
                coord check_coordinate(x_iter, y_iter);
                current_board[check_coordinate] = all.size();
			}
		}
        all.push_back(new_unit);
    }
}

// Moves unit i to the new coordinate if it is possible. Returns true if success, return false and don't move if impossible.
bool AllUnits::MoveUnit(int i, int new_x, int new_y)
{	
	// Easy check if size is 1
	if (all[i].getSize() == 1)
	{
		// Check if someone is there already
		if (GetUnit(new_x, new_y) == -1)
		{
			printf("MOVE UNIT: Moved unit %d to %d,%d\n", i, new_x, new_y);
			all[i].setPositionX(new_x);
			all[i].setPositionY(new_y);
			return true;
		}
		else
		{
			printf("MOVE UNIT: Someone's there already\n");
			return false;
		}
	}
	// If the unit we're moving is bigger than size 1, we gotta make sure it doesn't squish anything on the edges
	else
	{
		// Get the full extent of the unit
		// If size is 3, we need to go up and down by 1 in each dimension to get the area covered by the unit. 
		// For 5, its 2. 7 is 3...etc. 
		unsigned short size_adjustment = (all[i].getSize() -1) / 2;
		
		int lower_x = new_x - size_adjustment;
		int upper_x = new_x + size_adjustment;
		int lower_y = new_y - size_adjustment;
		int upper_y = new_y + size_adjustment;
		// Check if anything is in the space the unit needs to fit in
		for (int x_iter = lower_x; x_iter < upper_x + 1; x_iter++)
		{
			for (int y_iter = lower_y; y_iter < upper_y + 1; y_iter++)
			{
				// If something's there, abort
				if (GetUnit(x_iter, y_iter) != -1)
				{
					printf("MOVE UNIT: Someone's there already\n");
					return false;
				}
			}
		}
		
		// Looks like it's all clear
		printf("MOVE UNIT: Moved unit %d to %d,%d\n", i, new_x, new_y);
		all[i].setPositionX(new_x);
		all[i].setPositionY(new_y);
		return true;
	}
	return false;
}

// Currently selected units will affect the unit defined by target_index
void AllUnits::Affect(int target_index)
{
	unsigned short target_armor = all[target_index].getArmor();
	// Make sure we selected something at least
	if (selected.empty())
	{
		printf("ATTACK: I'd like to help you do that, but you selected no units dingus.\n");
		return;
	}
    if (!all[target_index].getUnitStatus())
    {
        printf("ATTACK: That unit is already dead!\n");
        return;
    }
	// For each attacker...
	printf("---------------------BATTLE REPORT---------------------\n");
	for (int i=0; i < selected.size(); i++)
	{
		unsigned short target_health = all[target_index].getHp();
		unsigned short unit_damage = all[selected[i]].getBaseImpact();
		unsigned short damage_on_target = 0;

		printf("ATTACK: Unit %d attacked Unit %d for %d damage!\n",selected[i],target_index,unit_damage);
		
		// Calculate damage reduction due to armor
		if (target_armor >= unit_damage)
		{	
			printf("Unit %d's armor was blocked all the damage! Nice try guy.\n",target_index);
			damage_on_target = 0;
		}
		else
		{
			damage_on_target = unit_damage - target_armor;
			printf("Unit %d took %d damage!\n",target_index, damage_on_target);
			printf("Unit %d's armor mitigated %d damage\n",target_index, unit_damage - damage_on_target);
		}
		
		// If we killed the target
		if (target_health <= damage_on_target)
		{
			printf("Unit %d was killed! ANOTHER TEAM WIPE FOR ALLIANCE\n",target_index);
			all[target_index].setUnitStatus(false);
            coord dead_unit_pos(all[target_index].getPositionX(),all[target_index].getPositionY());
            current_board.erase(dead_unit_pos);
			// Check the deleted unit exists in the selected vector
			for (int j=0; j < selected.size(); j++)
			{
				if (target_index == selected[i])
				{
					selected.erase(selected.begin() + i);
				}
			}
			// Nothing left to do here
			printf("----------------------------------------------------\n");
			return;
		}
		// Target still alive, save new Hp value
		else
		{
			// Do the big damage
			target_health = target_health - damage_on_target;
			all[target_index].setHp(target_health);
			printf("Unit %d has %d health remaining!\n",target_index,target_health);
		}
	}
}

// Prints the stats of a unit with index i
void AllUnits::PrintUnit(int i) const
{

	// Get values
	int current_pos_x = all[i].getPositionX();
	int current_pos_y = all[i].getPositionY();
	unsigned short current_size = all[i].getSize();
	unsigned short current_Hp = all[i].getHp();
	unsigned short current_armor = all[i].getArmor();
	unsigned short current_Base_Impact = all[i].getBaseImpact();
	Under_command_of owner = all[i].getOwner();
	const char* current_owner = NULL;

	// Convert the owner enum to a string
	if (owner == 0)
	{
		current_owner = "PLAYER";
	}
	else if (owner == 1)
	{
		current_owner = "COMPUTER";
	}
	else
	{
		current_owner = "UNDEFINED";
	}
	printf("----------UNIT %d----------\n",i);
	printf("Pos: %d,%d | Size: %d \n", current_pos_x, current_pos_y, current_size);
	printf("HP: %d | DEF: %d | DMG: %d \n", current_Hp, current_armor, current_Base_Impact);
	printf("Controlled by: %s\n", current_owner);
	printf("----------------------------\n");
}

// Prints the stats of all selected units
void AllUnits::PrintSelectedUnits() const
{
	// If we selected something
	if (!selected.empty())
	{
		printf("Currently selected units:\n");
		for (int i=0; i < selected.size(); i++)
		{
			PrintUnit(selected[i]);
		}
	}
	else
	{
		printf("No units selected!\n");
	}
}
// Prints the stats of all units on the field
void AllUnits::PrintAllUnits() const
{
	printf("All units on the field:\n");
	for (int i=0; i < all.size(); i++)
	{
		PrintUnit(i);
	}
}

// Check who owns the current position on the board
//int CheckPosition(int x, int y)
//{
    //pass

//}











