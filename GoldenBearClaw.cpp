#include "Constants.h"
#include "Area.h"
#include <iostream>
#include <array>
#include <string>
#include <vector>
#include <locale>

using namespace std;

bool endGame = false;
string userInput, command, phrase;
int currArea, score;
vector<string> inventory;
bool wearingArmor = false;
bool ladder = false;
Area* world[14];

void initializeWorld(){
    cout << "*****Welcome to Golden Bear Claw Adventure!!!*****" << endl;
    
    world[HOME] = new Area();
    world[CITY] = new Area();
    world[WEST_FOREST] = new Area();
    world[EAST_FOREST] = new Area();
    world[SWAMP] = new Area();
    world[CABIN] = new Area();
    world[GATE] = new Area();
    world[SCARY_HOUSE_HALL] = new Area();
    world[SCARY_HOUSE_HALL2] = new Area();
    world[LEFT_ROOM] = new Area();
    world[RIGHT_ROOM] = new Area();
    world[LEFT_ROOM2] = new Area();
    world[RIGHT_ROOM2] = new Area();
    world[UPSTAIRS] = new Area();
    
    world[HOME] -> setSouth(CITY);
    world[CITY] -> setNorth(HOME);
    world[CITY] -> setEast(WEST_FOREST);
    world[WEST_FOREST] -> setSouth(SWAMP);
    world[WEST_FOREST] -> setWest(CITY);
    world[WEST_FOREST] -> setEast(EAST_FOREST);
    world[EAST_FOREST] -> setWest(WEST_FOREST);
    world[EAST_FOREST] -> setEast(CABIN);
    world[EAST_FOREST] -> setNorth(GATE);
    world[SWAMP] -> setNorth(WEST_FOREST);
    world[CABIN] -> setWest(EAST_FOREST);
    world[GATE] -> setSouth(EAST_FOREST);
    world[SCARY_HOUSE_HALL] -> setSouth(GATE);
    world[SCARY_HOUSE_HALL2] -> setSouth(SCARY_HOUSE_HALL);
    world[LEFT_ROOM] -> setEast(SCARY_HOUSE_HALL);
    world[RIGHT_ROOM] -> setWest(SCARY_HOUSE_HALL);
    world[LEFT_ROOM2] -> setEast(SCARY_HOUSE_HALL2);
    world[RIGHT_ROOM2] -> setWest(SCARY_HOUSE_HALL2);
    
    world[WEST_FOREST] -> addItem("rusty key");
    world[SWAMP] -> addItem("diamond dagger");
    world[LEFT_ROOM2] -> addItem("ray gun");
    world[RIGHT_ROOM2] -> addItem("armor");
    world[EAST_FOREST] -> addItem("elixir");
    
    world[HOME] -> setShortDescription("          Home          \n|_______________________|\n|_______________________|\n|                       |\n|                       |\n|                       |\n|          :)-<         |\n|                       |\n|_______________________|\n\n\n");
    world[CITY] -> setShortDescription("       City of Sparta       \n_______________________________\n_______________________________\n~~ []    []     []     []      *  \n~~    []     []     []        *** \n~~ []    []     []     []    *****\n~~    []     []     []         |  \n~~ []    []     []     [] :)-<    \n~~    []     []     []         *  \n~~ []    []     []     []     *** \n~~    []     []     []       *****\n~~ []    []     []     []      |  \n__________________________________\n__________________________________\n\n\n");
    world[WEST_FOREST] -> setShortDescription("        Westside of Larkin Forest        \n------------------------------------\n  *        *         *         *    \n ***      ***       ***       ***   \n*****    *****     *****     *****  \n  |        |         |         |    \n      *          *         *        \n     ***        ***       ***       \n    ***** :)-< *****     *****      \n      |          |         |        \n  *       *         *          *    \n ***     ***       ***        ***   \n*****   *****     *****      *****  \n  |       |         |          |    \n      *         *         *         \n     ***       ***       ***        \n    *****     *****     *****       \n      |         |         |         \n__________________________________\n__________________________________\n\n\n");
    world[EAST_FOREST] -> setShortDescription("        Eastside of Larkin Forest        \n------------------------------------\n  *        *         *         *    \n ***      ***       ***       ***   \n*****    *****     *****:)-<*****  \n  |        |         |         |    \n      *          *         *        \n     ***        ***       ***       \n    *****      *****     *****      \n      |          |         |        \n  *       *         *          *    \n ***     ***       ***        ***   \n*****   *****     *****      *****  \n  |       |         |          |    \n      *         *         *         \n     ***       ***       ***        \n    *****     *****     *****       \n      |         |         |         \n__________________________________\n__________________________________\n\n\n");
    world[SWAMP] -> setShortDescription("         Menace Swamp        \n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|:)-< |~~~~~~~~~\n\n\n");
    world[CABIN] -> setShortDescription("        Abandoned Cabin        \n|---------------------|\n|                     |\n|                     |\n|   :(-<       <--(   |\n|                     |\n|                     |\n|_____________________|\n\n\n");
    world[GATE] -> setShortDescription("        Locked Gate Entrance        \n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n|||||||||||||||||||||||||||||||| \n|||||||||||||||||||||||||||||||| \n|||||||||||||||||||||||||||||||| \n||||||||||||||||||||||||||||||||\n||||||||||||||||||||||||||||||||\n||||||||||||||||||||||||||||||||\n--------------------------------\n                :)-<             \n\n\n");
    world[SCARY_HOUSE_HALL] -> setShortDescription("        South Hall of House of Fear        \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n\n\nWhat gets wetter as it dries?\n");
    world[SCARY_HOUSE_HALL2] -> setShortDescription("        North Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\nWhat has a face and two hands but no arms or legs?\n");
    world[UPSTAIRS] -> setShortDescription("        Goblin Room        \n________________________________\n|            >:(-<            |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n\n\n");
    world[LEFT_ROOM] -> setShortDescription("          Little Girl's Room         \n________________________________\n|                             |\n|        :p    |-<            |\n|                             |\n|                             |\n|                             |\n|            :o-<             |\n|                             |\n------------     --------------\n\n\n");
    world[LEFT_ROOM2] -> setShortDescription("      Killer Clown Room       \n________________________________\n|                             |\n|        ಠ╭╮ಠ                |\n|                             |\n|                             |\n|                             |\n|            :o-<             |\n|                             |\n------------     --------------\n\n\n");
    world[RIGHT_ROOM] -> setShortDescription("            Windowless Room          \n________________________________\n|                             |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n\n\n");
    world[RIGHT_ROOM2] -> setShortDescription("        Armory        \n________________________________\n|              ◎             |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n\n\n");
    
    world[HOME] -> setLongDescription("          Home          \n|_______________________|\n|_______________________|\n|                       |\n|                       |\n|                       |\n|          :)-<         |\n|                       |\n|_______________________|\n\n\n-You are an archeaeologist and recently found an ancient scroll that mentions the Golden Bear Claw, a long lost ancient artificat.\n");
    world[CITY] -> setLongDescription("     City of Sparta     \n _______________________________\n_______________________________\n~~ []    []     []     []      *  \n~~    []     []     []        *** \n~~ []    []     []     []    *****\n~~    []     []     []         |  \n~~ []    []     []     [] :)-<    \n~~    []     []     []         *  \n~~ []    []     []     []     *** \n~~    []     []     []       *****\n~~ []    []     []     []      |  \n__________________________________\n__________________________________\n\n\n-You have exited out of your house in search of the Golden Bear Claw.\n-Now begin your journey to acquire this artifact.\n-You DO NOT know how to swim.\n");
    world[WEST_FOREST] -> setLongDescription(" Westside of Larkin Forest \n------------------------------------\n  *        *         *         *    \n ***      ***       ***       ***   \n*****    *****     *****     *****  \n  |        |         |         |    \n      *          *         *        \n     ***        ***       ***       \n    ***** :)-< *****     *****      \n      |          |         |        \n  *       *         *          *    \n ***     ***       ***        ***   \n*****   *****     *****      *****  \n  |       |         |          |    \n      *         *         *         \n     ***       ***       ***        \n    *****     *****     *****       \n      |         |         |         \n__________________________________\n__________________________________\n\n\n-You have entered the dark forest where only the bravest of souls venture.\n-Search for items but beware of potential dangers.\n");
    world[EAST_FOREST] -> setLongDescription(" Eastside of Larkin Forest \n------------------------------------\n  *        *         *         *    \n ***      ***       ***       ***   \n*****    *****     *****:)-<*****  \n  |        |         |         |    \n      *          *         *        \n     ***        ***       ***       \n    *****      *****     *****      \n      |          |         |        \n  *       *         *          *    \n ***     ***       ***        ***   \n*****   *****     *****      *****  \n  |       |         |          |    \n      *         *         *         \n     ***       ***       ***        \n    *****     *****     *****       \n      |         |         |         \n__________________________________\n__________________________________\n\n\n-You have entered the eastern side of the dark forest.\n-This side of the forest is much scarier than the west side.\n");
    world[SWAMP] -> setLongDescription("     Menace Swamp       \n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|     |~~~~~~~~~\n~~~~~~~~~|:)-< |~~~~~~~~~\n\n\n-You have entered the damp swamp.\n-You may find something sharp and useful here.\n-Be weary of the lurking crocodiles to your left and right.\n");
    world[CABIN] -> setLongDescription("         Cabin         \n|---------------------|\n|                     |\n|                     |\n|   :(-<       <--(   |\n|                     |\n|                     |\n|_____________________|\n\n\n-You have stumbled upon an abandoned house.\n-An arrow is flying toward you with great velocity.\n-Move out of the way to dodge the arrow or face death.\n ");
    world[GATE] -> setLongDescription("        Gate Entrance        \n^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^ \n|||||||||||||||||||||||||||||||| \n|||||||||||||||||||||||||||||||| \n|||||||||||||||||||||||||||||||| \n||||||||||||||||||||||||||||||||\n||||||||||||||||||||||||||||||||\n||||||||||||||||||||||||||||||||\n--------------------------------\n                :)-<             \n\n\n-You have reached the towering rusty gates surrounding the haunted mansion that holds the Golden Bear Claw");
    world[SCARY_HOUSE_HALL] -> setLongDescription("         South Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n\n\n-You have entered an unknown and abandoned house.\n-An evil hunchback approaches.\n-He says you must answer his riddles correctly in order to enter the rooms.\nWhat gets wetter as it dries?\n");
    world[SCARY_HOUSE_HALL2] -> setLongDescription("        North Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\n-You have walked down the hall. The evil hunchback stops you again.\n-You must answer another one of his riddles in order to enter the next set of rooms.\nWhat has a face and two hands but no arms or legs?\n");
    world[RIGHT_ROOM] -> setLongDescription("            Windowless Room          \n________________________________\n|                             |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n\n\n-You have entered a dark windowless room.\n");
    world[LEFT_ROOM] -> setLongDescription("    Little Girl's Room        \n________________________________\n|                             |\n|        :p    |-<            |\n|                             |\n|                             |\n|                             |\n|            :o-<             |\n|                             |\n------------     --------------\n\n\n-The dark room has a distinct smell of a rotting corpse that is circulating through the room.\n-You begin to walk around and notice that there are puddles of liquid on the floor.\n-You squint in order to see what it is.\n-You notice a small curled figure in the corner.\n-You move closer to and realize there is dead child lying in a pool of blood.\n-You hear a loud shriek and must leave the doors lock and you are locked in there for eternity.\n");
    world[RIGHT_ROOM2] -> setLongDescription("        Armory        \n________________________________\n|              ◎             |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n\n\nYou have entered a dark room that contains armor made from the best blacksmith.\n");
    world[LEFT_ROOM2] -> setLongDescription("      Killer Clown Room       \n________________________________\n|                             |\n|        ಠ╭╮ಠ                |\n|                             |\n|                             |\n|                             |\n|            :o-<             |\n|                             |\n------------     --------------\n\n\n-You enter and there a blood thirsty clown that is waiting to murder you.\n-There is a ray gun in the corner of the room.\n-Aquire the weapon and kill the clown.\n");
    world[UPSTAIRS] -> setLongDescription("        Goblin Room        \n________________________________\n|            >:(-<            |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n\n\n-You are now upstairs.\n-You immediately notice a hideous looking goblin.\n-You must find the Golden Bear Claw within the room, however the goblin has caught you within his sights.\n-The goblin is after you and you must find the Golden Bear Claw it catches you.\n ");
    
    currArea = HOME;
}

void inventoryDisplay(){
    if(!inventory.empty()){
        cout << "Inventory:" << endl;
        for(int i = 0; i < inventory.size(); i++){
            cout << inventory.at(i) << endl;
        }
    }
    else{
        cout << "You have nothing in your inventory." << endl;
    }
}

void move(string direction){
    if(direction == "north"){
        if(world[currArea] -> getNorth() == NO_EXIT){
            cout << "You cannot go that way. Pick another direction." << endl;
        }
        else{
            currArea = world[currArea] -> getNorth();
        }
    }
    else if(direction == "south"){
        if(world[currArea] -> getSouth() == NO_EXIT){
            cout << "You cannot go that way. Pick another direction." << endl;
        }
        else{
            currArea = world[currArea] -> getSouth();
        }
    }
    else if(direction == "west"){
        if(world[currArea] -> getWest() == NO_EXIT){
            cout << "You cannot go that way. Pick another direction." << endl;
        }
        else{
            currArea = world[currArea] -> getWest();
        }
    }
    else if(direction == "east"){
        if(world[currArea] -> getEast() == NO_EXIT){
            cout << "You cannot go that way. Pick another direction." << endl;
        }
        else{
            currArea = world[currArea] -> getEast();
        }
    }
    return;
}

string formatString(string input){
    locale loc;
    string newString = "";
    for(unsigned int i = 0; i < input.length(); i++){
        newString += tolower(input[i],loc);
    }
    
    if(newString.find(" the ") != string::npos){
        newString.replace(newString.find(" the "), 4, "");
    }
    if(newString.find(" a ") != string::npos){
        newString.replace(newString.find(" a "), 2, "");
    }
    if(newString.find(" an ") != string::npos){
        newString.replace(newString.find(" a "), 3, "");
    }
    if(newString.find(" this ") != string::npos){
        newString.replace(newString.find(" this "), 5, "");
    }
    if(newString.find(" that ") != string::npos){
        newString.replace(newString.find(" that "), 5, "");
    }
    if(newString.find(" to ") != string::npos){
        newString.replace(newString.find(" to "), 3, "");
    }
    while(newString.find("  ") != string::npos){
        newString.replace(newString.find("  "), 1, "");
    }
    
    return newString;
}

string getCommand(string input){
    if(input.find(" ") > 0){
        input = input.substr(0, input.find(" "));
        return input;
    }
    else{
        return input;
    }
}

string getPhrase(string input){
    if(input.find(" ") > 0){
        input = input.substr(input.find(" ") + 1, input.length() - 1);
        return input;
    }
    else{
        return input;
    }
}

void displayCurrentArea(){
    cout << "--------------------------------------------------" << endl;
    if(world[currArea] -> getVisited()){
        cout << world[currArea] -> getShortDescription() << endl;
    }
    else{
        cout << world[currArea] -> getLongDescription() << endl;
        world[currArea] -> setVisited(true);
    }
    
    cout << "                                       Type h for help" << endl;
    world[currArea] -> displayInventory();
    world[currArea] -> displayExits();
}

void getUserInput(){
    getline(cin, userInput);
    userInput = formatString(userInput);
    command = getCommand(userInput);
    phrase = getPhrase(userInput);
}

void parseUserInput(){
    if (command == "q" || command == "quit"){
        endGame=true;
        return;
    }
    if (command == "look" || command == "l"){
        cout << world[currArea] -> getLongDescription();
    }
    if(command == "i" || command == "inv" || command == "inventory"){
        inventoryDisplay();
    }
    if(command == "h" || command == "help"){
        cout << "Use keywords such as grab, look, inventory, use, and score" << endl;
    }
    if(command == "score"){
        cout << "You currently have " << score << " out of 50 points!" << endl;
        if(score < 11){
            cout << "You are ranked as Amateur Explorer." << endl;
        }
        else if(score < 21){
            cout << "You are ranked as Proficient Explorer." << endl;
        }
        else if(score < 41){
            cout << "You are ranked as Advanced Explorer!" << endl;
        }
        else{
            cout << "You are ranked as Legendary Explorer!!!" << endl;
        }
    }
    if(command == "n" || command == "N" || command == "North" || command == "north"){
        bool check;
        command = "north";
        for(int i = 0; i < inventory.size(); i++){
            if(inventory.at(i) == "diamond dagger"){
                check = true;
            }
        }
        if(currArea == UPSTAIRS && !check){
            endGame == true;
            if(score < 50){
                score = 45;
            }
        }
        move(command);
    }
    else if(command == "s" || command == "S" || command == "South" || command == "south"){
        command = "south";
        move(command);
    }
    else if(command == "e" || command == "E" || command == "East" || command == "east"){
        command = "east";
        if(currArea == LEFT_ROOM2 && !ladder){
            endGame == true;
            if(score < 50){
                score = 41;
            }
        }
        move(command);
    }
    else if(command == "w" || command == "W" || command == "West" || command == "west"){
        command = "west";
        move(command);
    }
    
    if(command == "go" || command == "walk" || command == "run"){
        if(command == "n" || command == "N" || command == "North" || command == "north"){
            bool check;
            command = "north";
            for(int i = 0; i < inventory.size(); i++){
                if(inventory.at(i) == "diamond dagger"){
                    check = true;
                }
            }
            if(currArea == UPSTAIRS && !check){
                endGame == true;
                if(score < 50){
                    score = 45;
                }
            }
            move(command);
        }
        else if(command == "s" || command == "S" || command == "South" || command == "south"){
            command = "south";
            move(command);
        }
        else if(command == "e" || command == "E" || command == "East" || command == "east"){
            command = "east";
            if(currArea == LEFT_ROOM2 && !ladder){
                endGame == true;
                if(score < 50){
                    score = 41;
                }
            }
            move(command);
        }
        else if(command == "w" || command == "W" || command == "West" || command == "west"){
            command = "west";
            move(command);
        }
        else{
            cout << "Which way do you want to go?" << endl;
        }
    }
    
    if(command == "take" || command == "get" || command == "grab" || command == "grasp" || command == "pick"){
        if(world[currArea] -> removeItem(phrase)){
            inventory.push_back(phrase);
            cout << "You have picked up " << phrase << endl;
            score += 1;
        }
        else{
            cout << "That item is not here" << endl;
        }
    }
    
    if(command == "drop"){
        int loc = - 1;
        for(int i = 0; i < inventory.size(); i++){
            if(inventory.at(i) == phrase){
                loc = i;
                break;
            }
        }
        if(loc != - 1){
            world[currArea] -> addItem(phrase);
            inventory.at(loc) = "";
            for(int i = loc; i < inventory.size() - 1; i++){
                inventory.at(i) = inventory.at(i + 1);
            }
            inventory.at(inventory.size() - 1) = "";
            cout << "You have dropped " << phrase << endl;
        }
        else{
            cout << "That item is not here" << endl;
        }
    }
    
    if(command == "unlock"){
        if(phrase == "gate" && currArea == GATE){
            cout << "What do you want to unlock the gate with?" << endl;
        }
        else if(phrase == "gate with rusty key" && currArea == GATE){
            int loc = - 1;
            for(int i = 0; i < inventory.size(); i++){
                if(inventory.at(i) == "rusty key"){
                    loc = i;
                    break;
                }
            }
            if(loc != - 1){
                cout << "The gate is unlocked!" << endl;
                world[GATE] -> setNorth(SCARY_HOUSE_HALL);
                score += 5;
            }
            else{
                cout << "You do not have that item" << endl;
            }
        }
        else if(currArea != GATE){
            cout << "I don't see anything to unlock" << endl;
        }
    }
    
    if(command == "towel" || phrase == "towel"){
        if(currArea == SCARY_HOUSE_HALL){
            world[currArea] -> setEast(RIGHT_ROOM);
            world[currArea] -> setWest(LEFT_ROOM);
            world[currArea] -> setNorth(SCARY_HOUSE_HALL2);
            world[SCARY_HOUSE_HALL] -> setShortDescription("         South Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n\n\nThe hunchback is livid because you were able to answer his question.\n");
            world[SCARY_HOUSE_HALL] -> setLongDescription("         South Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n\n\n-You have entered an unknown and abandoned house.\n-The hunchback is livid because you were able to answer his question.\n");
        }
        else{
            cout << "What?" << endl;
        }
    }
    
    if(command == "clock" || phrase == "clock"){
        if(currArea == SCARY_HOUSE_HALL2){
            world[currArea] -> setEast(RIGHT_ROOM2);
            world[currArea] -> setWest(LEFT_ROOM2);
            world[SCARY_HOUSE_HALL2] -> setShortDescription("        North Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\nYou were able to answer his question and the hunchback has gotten even more angry!\n");
            world[SCARY_HOUSE_HALL2] -> setLongDescription("        North Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\n-You have walked down the hall. The evil hunchback has gotten even more angry because you were able to answer his riddle again\n");
        }
        else{
            cout << "What?" << endl;
        }
    }
    
    if(command == "yardstick" || phrase == "yardstick"){
        if(ladder && currArea == SCARY_HOUSE_HALL2){
            world[currArea] -> setNorth(UPSTAIRS);
            world[SCARY_HOUSE_HALL2] -> setShortDescription("        North Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\nYou were able to answer his question and the hunchback has gotten even more angry!\n");
            world[SCARY_HOUSE_HALL2] -> setLongDescription("        North Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\n-You have walked down the hall. The evil hunchback has gotten even more angry because you were able to answer his riddle again\n");
        }
        else{
            cout << "What?" << endl;
        }
    }
    
    if(command == "stab" || command == "kill"){
        if(phrase == "goblin" && currArea == UPSTAIRS){
            cout << "What do you want to kill it with?" << endl;
        }
        else if(phrase == "goblin with diamond dagger" && currArea == UPSTAIRS){
            int loc = - 1;
            for(int i = 0; i < inventory.size(); i++){
                if(inventory.at(i) == "diamond dagger"){
                    loc = i;
                    break;
                }
            }
            if(loc != - 1){
                world[currArea] -> addItem("diamond dagger");
                inventory.at(loc) = "";
                for(int i = loc; i < inventory.size() - 1; i++){
                    inventory.at(i) = inventory.at(i - 1);
                }
                inventory.at(inventory.size() - 1) = "";
                cout << "The goblin has died!\nBehold, The Golden Bear Claw!" << endl;
                world[UPSTAIRS] -> addItem("Golden Bear Claw");
                score = 50;
                world[UPSTAIRS] -> addItem("diamond dagger");
                world[currArea] -> setLongDescription("________________________________\n|              ⚕              |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n");
                world[currArea] -> setShortDescription("________________________________\n|              ⚕              |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n");
                endGame = true;
            }
            else{
                cout << "You do not have that item" << endl;
            }
        }
        else if(currArea == LEFT_ROOM2 && command == "kill" && phrase == "clown with ray gun"){
            int loc = - 1;
            for(int i = 0; i < inventory.size(); i++){
                if(inventory.at(i) == "ray gun"){
                    loc = i;
                    break;
                }
            }
            if(loc != - 1){
                if(currArea == LEFT_ROOM2){
                world[currArea] -> addItem("ray gun");
                inventory.at(loc) = "";
                for(int i = loc; i < inventory.size() - 1; i++){
                    inventory.at(i) = inventory.at(i - 1);
                }
                inventory.at(inventory.size() - 1) = "";
                cout << "The clown has died!\n" << endl;
                ladder = true;
                world[SCARY_HOUSE_HALL2] -> setShortDescription("        North Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\nYou were able to answer his question and the hunchback has gotten even more angry!\nHe has come up with another riddle!\nWhat has three feet but cannot walk?");
                world[SCARY_HOUSE_HALL2] -> setLongDescription("        North Hall              \n          __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\n-You have walked down the hall. You were able to answer his question and the hunchback has gotten even more angry!\nHe has come up with one last riddle!\nWhat has three feet but cannot walk?\n");
                }
                else{
                    cout << "You cannot use that here." << endl;
                }
            }
            else{
                cout << "You do not have that item" << endl;
            }
        }
        else if(currArea != UPSTAIRS){
            cout << "I don't see anything to kill here." << endl;
        }
    }
    
    if(currArea == LEFT_ROOM2 && command == "shoot" && phrase == "clown with ray gun"){
        int loc = - 1;
        for(int i = 0; i < inventory.size(); i++){
            if(inventory.at(i) == "ray gun"){
                loc = i;
                break;
            }
        }
        if(loc != - 1){
            world[currArea] -> addItem("ray gun");
            inventory.at(loc) = "";
            for(int i = loc; i < inventory.size() - 1; i++){
                inventory.at(i) = inventory.at(i - 1);
            }
            inventory.at(inventory.size() - 1) = "";
            cout << "The clown has died!\n" << endl;
            ladder = true;
            world[SCARY_HOUSE_HALL2] -> setShortDescription("        North Hall              \n           __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\nYou were able to answer his question and the hunchback has gotten even more angry!\nHe has come up with another riddle!\nWhat has three feet but cannot walk?");
            world[SCARY_HOUSE_HALL2] -> setLongDescription("        North Hall              \n           __              \n          _______            \n         _________           \n          |     |            \n          |     |            \n       []=      =[]          \n          |[*L*]|            \n          |  |  |            \n          |  ^  |            \n          |:)-< |            \n       []=      =[]          \n          |     |            \n          |     |            \n          |     |            \n          |     |            \n\n\n-You have walked down the hall. You were able to answer his question and the hunchback has gotten even more angry!\nHe has come up with one last riddle!\nWhat has three feet but cannot walk?\n");
        }
        else{
            cout << "You do not have that item" << endl;
        }
    }
    
    if(command == "wear"){
        if(currArea != RIGHT_ROOM2){
            cout << "There is nothing to wear here." << endl;
        }
        else if(phrase != "armor"){
            cout << "You cannot wear that." << endl;
        }
        else if(world[currArea] -> removeItem(phrase)){
            inventory.push_back(phrase);
            cout << "You put on the armor." << endl;
            wearingArmor = true;
            world[RIGHT_ROOM2] -> setLongDescription("        Armory        \n________________________________\n|                             |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n-You have entered a dark room that contains armor made from the best blacksmith.\n");
            world[RIGHT_ROOM2] -> setShortDescription("        Armory        \n________________________________\n|                             |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :)-<             |\n|                             |\n------------     --------------\n\n\n");
            score += 15;
        }
        else{
            cout << "There is nothing to wear here." << endl;
        }
    }
    
    if(command == "use"){
        if(currArea != LEFT_ROOM && phrase == "elixir"){
            cout << "You cannot use the elixir here." << endl;
        }
        else if(currArea == LEFT_ROOM && phrase == "elixir"){
            int loc = - 1;
            for(int i = 0; i < inventory.size(); i++){
                if(inventory.at(i) == phrase){
                    loc = i;
                    break;
                }
            }
            if(loc != - 1){
                inventory.at(loc) = "";
                for(int i = loc; i < inventory.size() - 1; i++){
                    inventory.at(i) = inventory.at(i - 1);
                }
                inventory.at(inventory.size() - 1) = "";
                cout << "You have revived the girl!\nShe wakes up with terror in her eyes and scurries out the door." << endl;
                world[LEFT_ROOM] -> setLongDescription("    Little Girl's Room        \n________________________________\n|                             |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :o-<             |\n|                             |\n------------     --------------\n\n\n-The dark room has a distinct smell of a rotting corpse that is circulating through the room.\n-You begin to walk around and notice that there are puddles of liquid on the floor.\n-You squint in order to see what it is.\n-You notice a small curled figure in the corner.\n-You move closer to and realize there is dead child lying in a pool of blood.\n-You hear a loud shriek and must leave the doors lock and you are locked in there for eternity.\n");
                world[LEFT_ROOM] -> setShortDescription("    Little Girl's Room        \n________________________________\n|                             |\n|                             |\n|                             |\n|                             |\n|                             |\n|            :o-<             |\n|                             |\n------------     --------------\n\n\n");
                score += 20;
            }
            else{
                cout << "You do not have that item" << endl;
            }
        }
        else if(phrase == "rusty key" && currArea == GATE){
            int loc = - 1;
            for(int i = 0; i < inventory.size(); i++){
                if(inventory.at(i) == "rusty key"){
                    loc = i;
                    break;
                }
            }
            if(loc != - 1){
                cout << "The gate is unlocked!" << endl;
                world[GATE] -> setNorth(SCARY_HOUSE_HALL);
                score += 10;
            }
            else{
                cout << "You do not have that item" << endl;
            }
        }
        else if(currArea != GATE && phrase == "rusty key"){
            cout << "I don't see anything to unlock" << endl;
        }
        else{
            cout << "You cannot use that." << endl;
        }
    }
}

void displayFarewellMessage(){
    if(score == 50){
        cout << "Congratulations!!! You seized the Golden Bear Claw!!!" << endl;
        cout << "༼ つ  ͡° ͜ʖ ͡° ༽つ" << endl;
    }
    else{
        cout << "You have died" << endl;
    }
    cout << "You scored " << score << " out of 50." << endl;
    
    if(score < 11){
        cout << "You are ranked as Amateur Explorer." << endl;
    }
    else if(score < 21){
        cout << "You are ranked as Proficient Explorer." << endl;
    }
    else if(score < 41){
        cout << "You are ranked as Advanced Explorer!" << endl;
    }
    else{
        cout << "You are ranked as Legendary Explorer!!!" << endl;
    }
}

int main(){
    initializeWorld();
    
    while(!endGame){
        displayCurrentArea();
        getUserInput();
        parseUserInput();
    }
    
    displayFarewellMessage();
    return 0;
}