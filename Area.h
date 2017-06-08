#ifndef __AREA_H
#define __AREA_H

#include <array>
#include <string>

using namespace std;

class Area{
    private:
        int north;
        int south;
        int east;
        int west;
        bool visited;
        string inventory[5];
        string shortDescription;
        string longDescription;
    public:
        Area();
        void setNorth(int);
        void setSouth(int);
        void setEast(int);
        void setWest(int);
        void setVisited(bool);
        void setLongDescription(string);
        void setShortDescription(string);
        int getNorth();
        int getSouth();
        int getWest();
        int getEast();
        bool getVisited();
        string getLongDescription();
        string getShortDescription();
        void addItem(string);
        bool removeItem(string);
        void displayInventory();
        void displayExits();
        
};

#endif