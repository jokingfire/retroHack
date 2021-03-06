#include "stdafx.h"
#include <iostream>
#include <string>
#include<stdlib.h>
#include<time.h>

using namespace std;

void command();

int main() {
	//variables
	int xPos = 0;
	int yPos = 0;
	int hp = 50;
	char facing = 'N';
	string inv[100];
	string input = "";
	string input2 = "";
	string lastInput = "";
	bool done = true;
	bool key = false;
	bool bolt = false;
	bool needle = false;
	//descriptions booleans
	bool one = false;
	bool two = false;
	bool three = false;
	bool four = false;
	bool five = false;
	bool six = false;
	bool seven = false;
	bool eight = false;
	bool nine = false;
	bool ten = false;
	bool eleven = false;
	bool twelve = false;
	int digits = 0;
	int constitution = 0;
	int combatA = 1;
	int combatB = 1;
	int combatC = 1;
	int hatchetDMG = 4;
	int punchDMG = 1;
	char battleinput = 'A';
	
	cout << "TIPS\n Your compass orientation remains the same when changing scenes.\n  Remember to use Turn l or Turn r to veiw all sides of a room" << endl;
	cout << "You awake in a room.  It seems distant yuet oddly familiar.  You think back to the last thing you remember, but cannot grasp any of the fleeting images that you see"<<endl;
	cout << "You approach your desk and see your computer. It is now outdated by at least ten years, but works well enough.  What do you do  (Use HELP for a list of commands)?" << endl;


	while (done) {
		//inputs
		getline(cin, input);

		if (input == "Last Input" || input == "LAST INPUT" || input == "LAST" || input == "L" || input == "l" || input == "last" || input == "last input") {
			input = lastInput;
		}
		lastInput = input;
		if (input == "Help" || input == "HELP" || input == "H" || input == "h" || input == "help") {
			cout << "Turn- turns the given direction(L for LEFT, R for RIGHT)" << endl << "GO-move in a direction NORTH SOUTH EAST WEST or N S E W" << endl << "Take (item)-takes the object specified by the user" << endl << "Inventory or INV - View your inventory" << endl << "Use (item) - use the specified item" << endl << "Attack (Entity) with (Weapon in Inventory) - this will attack the given entity with a specific weapon in your inventory" << endl << "Health - view your health" << endl << "Last or l - Repeat previous Dialogue" << endl;
		}
		else if (input == "TURN L" || input == "TURN l" || input == "Turn L" || input == "Turn l" || input == "turn L" || input == "turn l") {
			if (facing == 'N') {
				facing = 'W';
			}
			else if (facing == 'W') {
				facing = 'S';
			}
			else if (facing == 'S') {
				facing = 'E';
			}
			else {
				facing = 'N';
			}
		}
		else if (input == "TURN R" || input == "TURN r" || input == "Turn R" || input == "Turn r" || input == "turn R" || input == "turn r") {
			if (facing == 'N') {
				facing = 'E';
			}
			else if (facing == 'W') {
				facing = 'N';
			}
			else if (facing == 'S') {
				facing = 'W';
			}
			else {
				facing = 'S';
			}
		}
		else if (input == "Take Bottle" && xPos == 2 && yPos == -1 && facing == 'N') {
			inv[0] = "Bottle";
			three = true;
			cout << "Item added to Inv: " << inv[0] << endl;
		}
		else if (input == "Take Black square" && xPos == 2 && yPos == -2 && facing == 'W') {
			four = true;
			inv[1] = "Floppy disk";
			cout << "Item added to Inv: " << inv[1] << endl;
		}
		else if (input == "Take Wire coat hanger" && xPos == 2 && yPos == -2 && facing == 'W') {
			five = true;
			inv[2] = "Wire coat hanger";
			cout << "Item added to Inv: " << inv[2] << endl;
		}
		else if (input == "Take Picture frame" && xPos == -2 && yPos == -1 && facing == 'S') {
			ten = true;
			inv[3] = "Framed needlework";
			cout << "Item added to Inv: " << inv[3] << endl;
		}
		else if (input == "Take Rusted hatchet" && xPos == -2 && yPos == 3 && facing == 'N') {
			six = true;
			inv[4] = "Rusted hatchet";
			cout << "Item added to Inv: " << inv[4] << endl;
		}
		else if (input == "Take Gold coin" && xPos == -3 && yPos == 1 && facing == 'S') {
			seven = true;
			inv[5] = "Gold coin";
			cout << "Item added to Inv: " << inv[5] << endl;
		}
		else if (input == "Take Red book" && xPos == -1 && yPos == -3 && facing == 'N') {
			xPos = 2;
			yPos = -3;
			inv[7] = "Red book";
			cout << "Item added to Inv: " << inv[7] << endl;
			cout << "The Floor beneath opens up and you plunge into darkness.  You slowly stand up." << endl;
		}
		else if (input == "Take Blue book" && xPos == -1 && yPos - 3 && facing == 'N') {
			cout << "The Blue book is fixed to the shelf and cannot move" << endl;
		}
		else if (input == "Take Blue book" && xPos == 2 && yPos == -3) {
			inv[8] = "Blue book";
			cout << "Item added to Inv: " << inv[8] << endl;
			cout << "  This book is damp and cold.  You bring it near the torch to get a better view.  The pages are blank, but contained in its cover is a lead pencil.  It looks as though your only option is to record these thoughts by torchlight until your inevitable demise.  Is there anybody out there?" << endl;
			done = false;
		}

		else if (input == "Take Pouch" && xPos == -1 && yPos == -2)
		{
			inv[9] = "Pouch";
			cout << "Item added to Inv: " << inv[9] << endl;
		}



		//puzzle for key
		else if (input == "Use Wire coat hanger" && inv[2] == "Wire coat hanger" && xPos == 1 && yPos == -3 && facing == 'S') {
			inv[6] = "Key";
			nine = true;
			cout << "With A little effort, you manage to snag the key with the hangar and raise it from the grate.  It has been added to your inventory" << endl;
		}
		//key
		else if (input == "Use Key" && inv[6] == "Key" && xPos == -1 && yPos == -1 && facing == 'W') {
			xPos--;
			key = true;
			one = true;
			cout << "The key fits the lock an the tumblers turn instantly.  The paint chips from the hinges as the door is forced open" << endl;
		}
		//needlework
		else if (input == "Use Framed needlework" && inv[3] == "Framed needlework" && xPos == 0 && yPos == -1 && facing == 'S') {
			needle = true;
			two = true;
			cout << "You hang the needlework up on the wall.  The frame sinks slightly as you release it.  A muffled 'klunk' is heard from somewhere downstairs" << endl;
		}
		//floppy disk
		else if (input == "Use Floppy disk" && inv[1] == "Floppy disk" && xPos == 0 && yPos == 0 && facing == 'N') {
			cout << "The computer manages to start up after some thime the floppy disk is inserted.";
			cout << "WELCOME/n  Enter the four single digits" << endl;
			getline(cin, input2);
			if (input2 == "0100") {
				digits++;
				cout << "Access Granted" << endl;
				cout << "A mechanical click is heard from somewhere downstairs";
			}
		}
		else if (input == "Use Gold coin" && inv[5] == "Gold coin" && xPos == -1 && yPos == -3 && facing == 'S') {
			digits++;
			cout << "You drop the gold coin into the slot in the desk hesitantly" << endl;
		}

		else if (input == "Use Pouch" && inv[9] == "Pouch")
		{
			hp += 15;
			inv[9] = "";
		}
		else if (input == "Go N" || input == "Go NORTH" || input == "GO N" || input == "GO NORTH" || input == "go NORTH" || input == "go N" || input == "Go n" || input == "Go North" || input == "Go north" || input == "GO n" || input == "GO North" || input == "GO north" || input == "go North" || input == "go n" || input == "go north") {
			if ((xPos != 0 || yPos != 0) && (xPos != 1 || yPos != -1) && (xPos != -1 || yPos != -1) && (xPos != 2 || yPos != -1) && (xPos != 1 || yPos != -3) && (xPos != -2 || yPos != 3) && (xPos != -1 || yPos != -3) && (xPos != 2 || yPos != -3) && (xPos != -3 || yPos != 2) && (xPos != -2 || yPos != -2) && (xPos != -1 || yPos != -2)) {
				yPos++;
				//deadbolt
				if (xPos == 0 && yPos == -3) {
					bolt = true;
					eight = true;
					eleven = true;
					cout << "You unlocked the deadbolt." << endl;
				}
			}
			else
				cout << "You can't walk through that, Good try." << endl;
		}

		else if (input == "Go S" || input == "Go SOUTH" || input == "GO S" || input == "GO SOUTH" || input == "go SOUTH" || input == "go S" || input == "Go s" || input == "Go South" || input == "Go south" || input == "GO s" || input == "GO South" || input == "GO south" || input == "go South" || input == "go s" || input == "go south")
		{
			if ((xPos != 0 || yPos != -1) && (xPos != -1 || yPos != -1) && (xPos != 2 || yPos != -2) && (xPos != 1 || yPos != -2) && (xPos != 1 || yPos != -3) && ((xPos != 0 || yPos != -3) || bolt) && (xPos != 0 || yPos != -4) && (xPos != -2 || yPos != -1) && (xPos != -1 || yPos != -3) && (xPos != 2 || yPos != -3) && (xPos != -3 || yPos != 1) && (xPos != -2 || yPos != -3) && (xPos != -1 || yPos != -2))
				yPos--;
			else
				cout << "You can't walk through that, Good try." << endl;
		}
		else if ((input == "Go E" || input == "Go EAST" || input == "GO E" || input == "GO EAST" || input == "go EAST" || input == "go E" || input == "Go e" || input == "Go East" || input == "Go east" || input == "GO e" || input == "GO East" || input == "GO east" || input == "go East" || input == "go e" || input == "go east") && (xPos == -2 && yPos == 2)) {
			xPos = 0;
			yPos = -4;
		}
		else if ((input == "Go E" || input == "Go EAST" || input == "GO E" || input == "GO EAST" || input == "go EAST" || input == "go E" || input == "Go e" || input == "Go East" || input == "Go east" || input == "GO e" || input == "GO East" || input == "GO east" || input == "go East" || input == "go e" || input == "go east") && (xPos == 0 && yPos == -4)) {
			xPos = -2;
			yPos = 2;
		}
		else if (input == "Go E" || input == "Go EAST" || input == "GO E" || input == "GO EAST" || input == "go EAST" || input == "go E" || input == "Go e" || input == "Go East" || input == "Go east" || input == "GO e" || input == "GO East" || input == "GO east" || input == "go East" || input == "go e" || input == "go east")
		{
			if ((xPos != 0 || yPos != 0) && (xPos != 2 || yPos != -1) && (xPos != 2 || yPos != -2) && (xPos != 1 || yPos != -2) && (xPos != 1 || yPos != -3) && (xPos != -2 || yPos != 0) && (xPos != -2 || yPos != 1) && (xPos != 2 || yPos != -2) && (xPos != -2 || yPos != 3) && (xPos != 2 || yPos != -3) && (xPos != -3 || yPos != 1) && (xPos != -2 || yPos != -3))
				xPos++;
			else
				cout << "You can't walk through that, Good try." << endl;
		}

		else if (input == "Go W" || input == "Go WEST" || input == "GO W" || input == "GO WEST" || input == "go WEST" || input == "go W" || input == "Go w" || input == "Go West" || input == "Go west" || input == "GO w" || input == "GO West" || input == "GO west" || input == "go West" || input == "go w" || input == "go west")
		{
			if ((xPos != 0 || yPos != 0) && ((xPos != -1 || yPos != -1) || key) && (xPos != 2 || yPos != -2) && (xPos != 0 || yPos != -4) && (xPos != -2 || yPos != -1) && (xPos != -2 || yPos != 0) && (xPos != -2 || yPos != 1) && (xPos != -2 || yPos != 3) && (xPos != -1 || yPos != -3) && (xPos != 2 || yPos != -3) && (xPos != -3 || yPos != 2) && (xPos != -3 || yPos != 1) && (xPos != -2 || yPos != -3) && (xPos != -2 || yPos != -2) && ((xPos != 0 || yPos != -3) || needle)) {
				xPos--;
			}
			else
				cout << "You can't walk through that, Good try." << endl;
		}

		else if (input == "Inventory" || input == "Inv" || input == "inv" || input == "INVENTORY" || input == "INV" || input == "I" || input == "i") {
			cout << "Inventory: " << inv[0];
			for (int i = 1; i < 100; i++) {
				cout << "   " << inv[i];
			}
		}
		else if (input == "Health" || input == "hp" || input == "HEALTH" || input == "HP" || input == "Hp" || input == "health" || input == "H" || input == "h") {
			cout << "Health Points: " << hp << endl;
		}
		else {
			cout << "Invalid Command, Try Again..." << endl;
		}

		//location messages
		if (xPos == 0 && yPos == 0) {
			if (facing == 'N') {
				cout << "You approach your desk and see your computer. It is now outdated by at least ten years, but works well enough.  What do you do?" << endl;
			}
			else if (facing == 'E') {
				cout << "A Wall.  No notable features.  It is colored beige and faded with time." << endl;
				command();
			}
			else if (facing == 'S') {
				cout << "A door lies in the middle of the wall, standing out in a dark oak against the beige drywall." << endl;
				command();
			}
			else if (facing == 'W') {
				cout << "A singular window obscured by a black sheet to prevent any natural light from entering the room." << endl;
				command();
			}
		}
		else if (xPos == 1 && yPos == -1) {
			if (facing == 'N') {
				cout << "A red wall.  A door lies to your right and the stairwell behind you." << endl;;
				command();
			}
			else if (facing == 'E') {
				cout << "A White door with a black enameled knob.  It appears unlocked" << endl;
				command();
			}
			else if (facing == 'S') {
				cout << "A stairwell with a landing halfway down.  Below you can see a dark door.  The remains of a chandelier hang above." << endl;
				command();
			}
			else if (facing == 'W') {
				cout << "The Faded red hallway.  The linen closet at the end of the hall and the computer room to the right" << endl;
				command();
			}
		}
		else if (xPos == -1 && yPos == -1) {
			if (facing == 'N') {
				cout << "A Small rectangular wall next to the door to the computer room." << endl;
				command();
			}
			else if (facing == 'E') {
				cout << "A Faded Red hallway.  The computer room is haead on the left, and further down at the end of the hall is a closed door.  a stairwell is further down the hall on the right.  " << endl;
				command();
			}
			else if (facing == 'S') {
				cout << "A Wall.  Nothing special about it" << endl;
				command();
			}
			else if (facing == 'W') {
				if (!one)
					cout << "The Locked closet.  Upon closer inspection, it appears the hinges have been painted over." << endl;
				else if (one)
					cout << "The unlocked closet.  Upon closer inspection, it appears the hinges have been painted over." << endl;
				command();
			}
		}
		else if (xPos == 2 && yPos == -1) {
			if (facing == 'N') {
				//bottle
				if (!three)
					cout << ("A window, its glass rippled with age allows some sunlight in.  It can be seen that you are on the second floor.  On the ground is a green glass Bottle with no label.") << endl;
				else if (three)
					cout << "A window, its glass rippled with age allows some sunlight in.  It can be seen that you are on the second floor." << endl;
				command();
			}
			else if (facing == 'E') {
				cout << ("A wall with another ancient window boarded over ages ago.  On the boards is a painted number 4") << endl;
				command();
			}
			else if (facing == 'S') {
				cout << ("A shallow closet with one of its sliding doors missing.  It looks like there is just enough room to squeeze inside.") << endl;
				command();
			}
			else if (facing == 'W') {
				cout << ("The Faded red hallway lies through the white door.  The closet lies at the end, with the computer room slightly closer on your right.  A stairwell is to your left.  ") << endl;
				command();
			}
		}
		else if (xPos == 0 && yPos == -1)
		{
			if (facing == 'N') {
				cout << ("The otherside of the oak door, painted white.  The walls are a shade of red that was rich when it was first put there, but now appeared as a ghost of the shade it once was") << endl;
				command();
			}
			else if (facing == 'E') {
				cout << ("A hallway.  A door lies at the end near a stairwell.") << endl;
				command();
			}
			else if (facing == 'S') {
				if (!two)
					cout << ("A faded red wall.  There is a stain of darker red where a portrait had hung at one point.") << endl;
				else if (two)
					cout << "A Faded red wall.   The Framed needlepoint is now hung here." << endl;
				command();
			}
			else if (facing == 'W') {
				cout << ("A locked linen closet with an off-white paint.  It has not been opened in years. ") << endl;
				command();
			}
		}
		else if (xPos == 2 && yPos == -2)
		{
			if (facing == 'N') {
				cout << ("The room with the boarded window lies before you.  The Number four is painted on the boards") << endl;
				command();
			}
			else if (facing == 'E') {
				cout << ("The exposed interior wall of the closet.  There is a clear line where the sun has faded the paint.") << endl;
				command();
			}
			else if (facing == 'S') {
				cout << ("The back wall of the closet.  Nothing of note .") << endl;
				command();
			}
			//FLoppy disk and hanger
			else if (facing == 'W') {
				if (!four && !five)
					cout << ("The wall of the closet that the door still covered.  There is a Wire coat hangar on the bar and a small Black square on the ground obscured in the shadows.") << endl;
				else if (four && !five)
					cout << "The wall of the closet that the door still covered.  There is a Wire coat hangar on the bar." << endl;
				else if (!four && five)
					cout << "The wall of the closet that the door still covered.  There is a small Black square on the ground obscured in the shadows." << endl;
				else if (four && five)
					cout << "The wall of the closet that the door still covered." << endl;

				command();
			}
		}
		else if (xPos == -2 && yPos == -1)
		{
			if (facing == 'N') {
				cout << ("In front of you lies a hole down to the next room.  The jump seems survivable, but you would not be able to go back up.") << endl;
				command();
			}
			else if (facing == 'E') {
				cout << ("The faded red hallway lies through the door") << endl;
				command();
			}
			//Framed Needlework
			else if (facing == 'S') {
				if(!ten)
				cout << ("A Wall lies roughy a foot in front of you. On the ground is a picture frame with its back to you.") << endl;
				if (ten)
					cout << ("A Wall lies roughy a foot in front of you.") << endl;
				command();
			}
			else if (facing == 'W') {
				cout << ("The shallow wall of the closet where shelves once hung as hinted at by the faded marks on the wall") << endl;
				command();
			}
		}
		else if (xPos == -2 && yPos == 0)
		{
			if (facing == 'N') {
				cout << (" A Dark staircase lies in fron of you.  It appears to be the only exit from this room.") << endl;
				command();
			}
			else if (facing == 'E') {
				cout << ("An unpainted wall with a thin crack in the corner.") << endl;
				command();
			}
			else if (facing == 'S') {
				cout << ("The Wall benath the hole in the floor.  The unpainted drywall suggests that this room was not meant to be seen") << endl;
				command();
			}
			else if (facing == 'W') {
				cout << ("An Unpainted Wall") << endl;
				command();
			}
		}
		else if (xPos == -2 && yPos == 1)

		{
			if (facing == 'N') {
				cout << ("A dark and narrow passage.  The exit appears to be ahead.") << endl;
				command();
			}
			else if (facing == 'E') {
				cout << ("A damp earthen wall.") << endl;
				command();
			}
			else if (facing == 'S') {
				cout << ("The Small unpainted room lies at the top of the stairs") << endl;
				command();
			}
			else if (facing == 'W') {
				cout << ("A Wall with several rotting boards supporting the earth behind them.") << endl;
				command();
			}

		}
		else if (xPos == -2 && yPos == 2)
		{
			if (facing == 'N') {
				cout << "A slightly worn path in the underbrush.  It seems to have been used recently" << endl;
				command();
			}
			else if (facing == 'E') {
				cout << "a heavily worn path through the trees." << endl;
				command();
			}
			else if (facing == 'S') {
				cout << "The Entrance to a narrow tunnel dug into the earth" << endl;
				command();
			}
			else if (facing == 'W') {
				cout << "A Steep and unsurmountable cliff face that towers above the clearing" << endl;
				command();
			}
		}
		else if (xPos == 1 && yPos == -2)
		{
			if (facing == 'N') {
				cout << "The stairs that ascend to the faded red hallway" << endl;
				command();
			}
			else if (facing == 'E') {
				cout << "The stairs that descend into a small foyer" << endl;
				command();
			}
			else if (facing == 'S') {
				cout << "The railing across the landing.  The dining room can be seen in the distance" << endl;
				command();
			}
			else if (facing == 'W') {
				cout << "The wall of the landing. This is where the faded red turns to a more pinkish color" << endl;
				command();
			}
		}
		else if (xPos == 0 && yPos == -2)
		{
			if (facing == 'N') {
				cout << ("A rather hastily constructed baricade created from an end table, an overturned armchair and several wooden chars at various angles.  There is no way to bypass") << endl;
				command();
			}
			else if (facing == 'E') {
				cout << "The stairs ascending to the landing" << endl;
				command();
			}
			else if (facing == 'S') {
				cout << "The remainder of the foyer.  The Front door can be seen at the end." << endl;
				command();
			}
			else if (facing == 'W') {
				cout << "A dutch door, whose top half has long since vanished.  The wood of the door has deep gouges in it." << endl;
				command();
			}
		}
		else if (xPos == 0 && yPos == -3)
		{
			if (facing == 'N') {
				cout << ("The remainder of the foyer.  The barricade stands at the end.") << endl;
				command();
			}
			else if (facing == 'E') {
				cout << ("The Dining room seen from the landing") << endl;
				command();
			}
			else if (facing == 'S') {
				if (!eight)
					cout << ("A door with standed a stained glass window.  The design appears to be a black rose with red stem and a bright green background.  The Door is locked from the outside.") << endl;
				else if (eight)
					cout << "A door with standed a stained glass window.  The design appears to be a black rose with red stem and a bright green background.  The Door has been unlocked from the outside." << endl;
				command();
			}
			else if (facing == 'W') {
				if (digits != 2)
					cout << ("A wall with two large dark wooden panels.  A thin beam of light shines between the two.") << endl;
				else if (digits == 2)
					cout << "A wall with two large, open dark wooden panels.  A thin beam of light shines between them." << endl;
				command();
			}
		}
		else if (xPos == 1 && yPos == -3)
		{
			if (facing == 'N') {
				cout << ("A wall at Half height with a railing on top") << endl;
				command();
			}
			else if (facing == 'E') {
				cout << ("A wall entirely comprised of windows.  Tall Mountain pines can be seen in the distance") << endl;
				command();
			}
			else if (facing == 'S') {
				if (!nine)
					cout << ("A wall Half composed of windows.  A dirt road can be seen leading to the house from the east.  a grate with a silver key trapped at the bottom lies below the window") << endl;
				else if (nine)
					cout << "A wall Half composed of windows.A dirt road can be seen leading to the house from the east.a grate lies below the window" << endl;
				command();
			}
			else if (facing == 'W') {
				cout << ("The foyer with its wood panels in front of you and front door to your left.") << endl;
				command();
			}
		}
		else if (xPos == -2 && yPos == 3)
		{
			if (facing == 'N') {
				if (!six)
					cout << ("A clearing.  A tree stump lies near the woodline with a Rusted hatchet embedded in it") << endl;
				else if (six)
					cout << "A clearing.  A tree stump lies near the woodline" << endl;

				command();
			}
			else if (facing == 'E') {
				cout << ("The clearing ends with a thickly wooded forest") << endl;
				command();
			}
			else if (facing == 'S') {
				cout << ("The path returning to the first clearing with the tunnel") << endl;
				command();
			}
			else if (facing == 'W') {
				cout << ("A fallen tree blocks your path") << endl;
				command();
			}
		}
		else if (xPos == -3 && yPos == 2)
		{
			if (facing == 'N') {
				cout << ("The edge of the clearing leads into a thick forest");
				command();
			}
			else if (facing == 'E') {
				cout << ("The path leads back to the previous clearing");
				command();
			}
			else if (facing == 'S') {
				cout << ("At the edge of the clearing is a boulder with a strange square shape raised");
				command();
			}
			else if (facing == 'W') {
				cout << ("The clearing ends with a rather steep cliff");
				command();
			}
		}
		else if (xPos == -3 && yPos == 1)
		{
			//Gold Coin
			if (facing == 'N') {
				cout << ("The path that goes behind the boulder");
				command();
			}
			else if (facing == 'E') {
				cout << ("A fallen tree blocks the path");
				command();
			}
			else if (facing == 'S') {
				if (!seven)
					cout << ("A stone pedestal with a single Gold coin on top sits before the cliff face");
				else if (seven)
					cout << ("A stone pedestal sits before the cliff face.");

				command();
			}
			else if (facing == 'W') {
				cout << ("An unsurmountable cliff lies to your right.");
				command();
			}
		}
		else if (xPos == -1 && yPos == -2)
		{
			int hit = 0;
			int creatureAhp = 5;
			int bottledmg = 2;
			srand((unsigned)time(NULL));


			if (combatA == 1) {
				cout << "  As you enter the room, you hear a hideous shriek.  Something darts to the West from the South.  Silouetted before the screen door and the west wall of the room is a beast, entirely black with piercing red eyes.  IT has a fierce, bipedal stance with long arms.  It's hands have three fingers each, ending with razor sharp claws.  It shrieks again.  What will you do..?   " << endl;
				do {
					getline(cin, input);
					if (input == "Help" || input == "HELP" || input == "H" || input == "h" || input == "help") {
						cout << "Inventory or INV - View your inventory" << endl << "Attack (Entity) with (Weapon in Inventory) - this will attack the given entity with a specific weapon in your inventory" << endl << "Health - view your health" << endl << "Last or l - Repeat previous Dialogue" << endl;
					}
					if (input == "l" || input == "last" || input == "L" || input == "Last") {
						input = lastInput;
					}
					lastInput = input;
					int random = (rand() % 10) + 1;
					if (input == "ATTACK Beast with Bottle" && inv[0] == "Bottle")
					{
						hit = 7;
						if (hit <= random)
						{
							creatureAhp -= bottledmg;
							cout << "You did damage." << endl;
						}

						else if (hit >random)
						{
							hp -= 1;
							cout << "You missed and got hit by the beast." << endl;
						}
					}

					else if (input == "ATTACK Beast with Rusted hatchet" && inv[4] == "Rusted hatchet")
					{
						hit = 3;
						if (hit <= random)
						{
							creatureAhp -= hatchetDMG;
							cout << "You did damage." << endl;
						}

						else if (hit > random)
						{
							hp -= 1;
							cout << "You missed and got hit by the beast." << endl;
						}
					}
					else if (input == "ATTACK Beast with Fists")
					{
						hit = 9;
						if (hit <= random)

						{
							creatureAhp -= punchDMG;
							cout << "You did damage." << endl;
						}

						else if (hit > random)
						{
							hp -= 1;
							cout << "You missed and got hit by the beast." << endl;
						}

					}

				} while (creatureAhp > 0 && hp > 0);
				if (hp == 0) { cout << "You Died" << endl; }
				else if (creatureAhp <= 0)
				{
					cout << "The creature falls with a shrill yell.  The creature begins to dissolve into a wispy black smoke until all that remains is a small leather pouch." << endl;
					combatA = 0;

				}
			}
			if (facing == 'N') {
				cout << ("A wall with a rather decrepit sink in front.  The pipes have long since rusted shut. ");
				command();
			}
			else if (facing == 'E') {
				cout << ("The doorway leading back to the foyer.  A portion of the destroyed Dutch door lies on the ground");
				command();
			}
			else if (facing == 'S') {
				cout << ("The direction that whatever attacked you came from.  When it was defeated, it disappeared and a small pouch was left in its place.  On the wall is an oven, rusted shut.  ");
				command();
			}
			else if (facing == 'W') {
				cout << ("The frame of a screen door, with all the mesh missing.  It leads to a wrap-around porch");
				command();
			}
		}
		else if (xPos == -2 && yPos == -2)
		{
			if (facing == 'N') {
				cout << ("THe railing of the porch.  In the background are hundreds of tall pine trees.");
				command();
			}
			else if (facing == 'E') {
				cout << ("The door leading back to the kitchen.  The yellow paint on the houses siding has begun to peel.");
				command();
			}
			else if (facing == 'S') {
				cout << ("The porch seems to wrap around to the front.  The green paint on the wooden floor is worn in a circular pattern close to the corner.");
				command();
			}
			else if (facing == 'W') {
				cout << ("A railing, behind which lies a steep clifface.");

			}
		}

		else if (xPos == -2 && yPos == -3)
		{
			int hit = 0;
			int creatureAhp = 5;
			int bottledmg = 2;
			srand((unsigned)time(NULL));


			if (combatB == 1) {
				cout << "As you approach the corner of the porch, a Dark figure swoops out at you from somewhere in from of the house, nearly striking you.  The shriek produced by this creature is heartier, but none the less still ear-peircing.  What will you do?" << endl;
				do {
					getline(cin, input);
					if (input == "Help" || input == "HELP" || input == "H" || input == "h" || input == "help") {
						cout << "Inventory or INV - View your inventory" << endl << "Attack (Entity) with (Weapon in Inventory) - this will attack the given entity with a specific weapon in your inventory" << endl << "Health - view your health" << endl << "Last or l - Repeat previous Dialogue" << endl;
					}
					if (input == "l" || input == "last" || input == "L" || input == "Last") {
						input = lastInput;
					}
					lastInput = input;
					int random = (rand() % 10) + 1;
					if (input == "ATTACK Dark figure with Bottle" && inv[0] == "Bottle")
					{
						hit = 7;
						if (hit <= random)
						{
							creatureAhp -= bottledmg;
							cout << "You did damage." << endl;
						}

						else if (hit >random)
						{
							hp -= 2;
							cout << "You missed and got hit by the beast." << endl;
						}
					}

					else if (input == "ATTACK Dark figure with Rusted hatchet" && inv[4] == "Rusted hatchet")
					{
						hit = 3;
						if (hit <= random)
						{
							creatureAhp -= hatchetDMG;
							cout << "You did damage." << endl;

						}

						else if (hit > random)
						{
							hp -= 2;
							cout << "You missed and got hit by the beast." << endl;
						}
					}
					else if (input == "ATTACK Dark figure with Fists")
					{
						hit = 9;
						if (hit <= random)

						{
							creatureAhp -= punchDMG;
							cout << "You did damage." << endl;
						}

						else if (hit > random)
						{
							hp -= 1;
							cout << "You missed and got hit by the beast." << endl;
						}

					}

				} while (creatureAhp > 0 && hp > 0);
				if (hp == 0) { cout << "You Died" << endl; }
				else if (creatureAhp <= 0)
				{
					cout << "The creature falls with a shrill yell.  The creature begins to dissolve into a wispy black smoke until it s gone completely." << endl;
					combatB = 0;

				}
			}
			if (facing == 'N') {
				cout << ("The porch ");
				command();
			}
			else if (facing == 'E') {
				cout << ("The remainder of the wrap-around porch ends abruptly after the corner of the house, weathered by time until it fell away.");
				command();
			}
			else if (facing == 'S') {
				cout << ("A railing is present.  The trees behind it end rather abruptly into a cliff.");
				command();
			}
			else if (facing == 'W') {
				cout << ("A railing, behind which is a cliff face.");
				command();
			}
		}
		else if (xPos == 0 && yPos == -4)
		{
			if (facing == 'N') {
				if (!eleven)
					cout << ("The front door of the house, with its stained glass window.  The door has a deadbolt on the outside.");
				else if (eleven)
					cout << "The front door of the house, with its stained glass window.  The deadbolt is unlocked.";
				command();
			}
			else if (facing == 'E') {
				cout << ("The path that leads behind the house to the clearing.");
				command();
			}
			else if (facing == 'S') {
				cout << ("A cliff face just beyond the road.");
				command();
			}
			else if (facing == 'W') {
				cout << ("The remains of a porch stand silouetted against the unsurmountable cliff face");
				command();
			}
		}//ATTATCK!!!! COMABR SEQUENCE
		else if (xPos == -1 && yPos == -3)
		{
			int hit = 0;
			int creatureAhp = 5;
			int bottledmg = 2;
			srand((unsigned)time(NULL));


			if (combatC == 1) {
				cout << "As the panels part and you make your way inside, you are met with a hideous yauwp.  The red eyes of the shadowy winged beast gleam.  The Eldritch abomination moves towards you.  What do you do?" << endl;
				do {
					getline(cin, input);
					if (input == "Help" || input == "HELP" || input == "H" || input == "h" || input == "help") {
						cout << "Inventory or INV - View your inventory" << endl << "Attack (Entity) with (Weapon in Inventory) - this will attack the given entity with a specific weapon in your inventory" << endl << "Health - view your health" << endl << "Last or l - Repeat previous Dialogue" << endl;
					}
					if (input == "l" || input == "last" || input == "L" || input == "Last") {
						input = lastInput;
					}
					lastInput = input;
					int random = (rand() % 10) + 1;
					if (input == "ATTACK Eldritch abomination with Bottle" && inv[0] == "Bottle")
					{
						hit = 7;
						if (hit <= random)
						{
							creatureAhp -= bottledmg;
							cout << "You did damage." << endl;
						}

						else if (hit >random)
						{
							hp -= 4;
							cout << "You missed and got hit by the beast." << endl;
						}
					}

					else if (input == "ATTACK Eldritch abomination with Rusted hatchet" && inv[4] == "Rusted hatchet")
					{
						hit = 3;
						if (hit <= random)
						{
							creatureAhp -= hatchetDMG;
							cout << "You did damage." << endl;
						}

						else if (hit > random)
						{
							hp -= 4;
							cout << "You missed and got hit by the beast." << endl;
						}
					}
					else if (input == "ATTACK Eldritch abomination with Fists")
					{
						hit = 9;
						if (hit <= random)

						{
							creatureAhp -= punchDMG;
							cout << "You did damage." << endl;
						}

						else if (hit > random)
						{
							hp -= 1;
							cout << "You missed and got hit by the beast." << endl;
						}

					}

				} while (creatureAhp > 0 && hp > 0);
				if (hp == 0) { cout << "You Died" << endl; }
				else if (creatureAhp <= 0)
				{
					cout << "The creature falls with a shrill yell.  The creature begins to dissolve into a wispy black smoke until there is no trace such a creature ever existed." << endl;
					combatC = 0;

				}
			}
			if (facing == 'N') {
				cout << ("A wall covered in bookselves.  FLoor to ceiling the anciet tomes lend their exotic titles to you.");
				if (digits == 2) {
					cout << "A Red Book and a Blue Book stick out of the shelf." << endl;
				}
				command();
			}


			else if (facing == 'E') {
				cout << ("The door previously obscured by the panels leading back into the foyer");
				command();
			}
			else if (facing == 'S') {
				cout << ("A Large desk, Complete with Inkwell.  A strange thin slot is on the desks left side.");
				command();
			}
			else if (facing == 'W') {
				cout << ("A wall with a singular framed canvas, dyed bloody scarlet in color.");
				command();
			}
		}
		else if (xPos == 2 && yPos == -3)
		{
			if (facing == 'N') {
				cout << ("A torch hangs on a Brick Wall");
				command();
			}
			else if (facing == 'E') {
				cout << ("A Mirror of significant antiquity hangs.  Its golden leaf frame chipped in several areas.");
				command();
			}
			else if (facing == 'S') {
				cout << ("A book Sits on the ground");
				command();
			}
			else if (facing == 'W') {
				cout << ("A Brick wall with no opening");
				command();
			}
		}
		cout << endl;
	}
}
void command()
{
	cout << ("What would you like to do?") << endl;
}
