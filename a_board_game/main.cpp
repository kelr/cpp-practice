#include "AllUnits.h"

/*
Todo list:

- If a unit dies and it was the last one in the all vector, trying to attack that unit again will still work. 
	Fix that by checking if an iterator is legit in a vector (impossible)
	or add a 'dead' flag to prevent attacking dead units 
	This is a serious bug since attacking a dead unit leads to another unit that isnt the target getting popped off the vector
- If a unit gets spawned, there's no error or check that it spawned ontop of another unit
- Deal with comments
- Fix bugs I dont know about
*/

int main()
{
	AllUnits field;

	Unit paladin;
	field.AddUnit(paladin);
	field.PrintUnit(0);
    
    Unit raid_boss(7,7,1,25000,3,2,COMPUTER);
	field.AddUnit(raid_boss);
	field.PrintUnit(1);
    
    Unit raid_boss2(1,1,1,25000,3,2,COMPUTER);
	field.AddUnit(raid_boss2);
	field.PrintUnit(2);
    
    printf("Adding 1,000,000 units\n");
    // This is blazing fast
    for (int i=2;i < 1000000;i++)
    {
        Unit wat(i,0,3,3,1,7,PLAYER);
        field.AddUnit(wat);
        //printf("Tried to spawn: %d\n",i);
    }
    /*
    
	
	Unit lizard_man(2,2,1,3,1,7,PLAYER);
	field.AddUnit(lizard_man);
	field.PrintUnit(1);
	
	Unit raid_boss(7,7,1,2500,3,2,COMPUTER);
	field.AddUnit(raid_boss);
	field.PrintUnit(2);
	
	Unit snacks(-5,3,2,1,2,5,PLAYER);
	field.AddUnit(snacks);
	field.PrintUnit(3);
	
    for (int i=4;i < 1500;i++)
    {
        Unit wat(i,0,1,3,1,7,PLAYER);
        field.AddUnit(wat);
    }
    */
    
	field.Affect(2);

	field.SelectUnit(0,0);
	
	field.MoveUnit(0, 7,7);
	field.MoveUnit(0, 5,5);
	field.MoveUnit(0, 3,3);
	printf("Selecting a lot of units\n");
    // The bigger this is the slower it gets
	field.SelectUnits(0,0,200000,0);
	

    field.Affect(1);
    
    
	//field.PrintSelectedUnits();

	//field.PrintAllUnits();
    
	return 0;
}