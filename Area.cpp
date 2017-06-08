#include "Area.h"
#include <iostream>
#include "Constants.h"

using namespace std;

Area::Area(){
    north = NO_EXIT;
    south = NO_EXIT;
    east = NO_EXIT;
    west = NO_EXIT;
    visited = false;
    for(int i = 0; i < 5; i++){
        inventory[i] = "";
    }
    shortDescription = "";
    longDescription = "";
}

void Area::setNorth(int newNorth){
    north = newNorth;
}
void Area::setSouth(int newSouth){
    south = newSouth;
}
void Area::setEast(int newEast){
    east = newEast;
}
void Area::setWest(int newWest){
    west = newWest;
}
void Area::setVisited(bool newVisit){
    visited = newVisit;
}
void Area::setLongDescription(string newLong){
    longDescription = newLong;
}
void Area::setShortDescription(string newShort){
    shortDescription = newShort;
}
int Area::getNorth(){
    return north;
}
int Area::getSouth(){
    return south;
}
int Area::getWest(){
    return west;
}
int Area::getEast(){
    return east;
}
bool Area::getVisited(){
    return visited;
}
string Area::getLongDescription(){
    return longDescription;
}
string Area::getShortDescription(){
    return shortDescription;
}
void Area::addItem(string newItem){
    for(int i = 0; i < 5; i++){
        if(inventory[i] == ""){
            inventory[i] = newItem;
            break;
        }
    }
}
bool Area::removeItem(string removeItem){
    bool temp = false;
    for(int i = 0; i < 2; i++){
        if(inventory[i] == removeItem){
            temp = true;
            inventory[i] = "";
        }
    }
    if(inventory[0] == ""){
        inventory[0] = inventory[1];
        inventory[1] = "";
    }
    return temp;
}
void Area::displayInventory(){
    if(inventory[0] == ""){
        return;
    }
    cout << "This place contains: " << endl;
    for(int i = 0; i < 2; i++){
        if(inventory[i] != ""){
            cout << inventory[i] << endl;
        }
    }
}
void Area::displayExits(){
    if(south == NO_EXIT && north == NO_EXIT && east == NO_EXIT && west == NO_EXIT){
        cout << "You cannot go anywhere from here. There are no valid exits.";
    }
    else{
        cout << "From here you can go:" << endl;
        if(north != NO_EXIT){
            cout << "North ";
        }
        if(south != NO_EXIT){
            cout << "South ";
        }
        if(east != NO_EXIT){
            cout << "East ";
        }
        if(west != NO_EXIT){
            cout << "West ";
        }
    }
    cout << endl;
}