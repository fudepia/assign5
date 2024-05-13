#include "room.h"
#include<cstring>
#include "roomdata.h"
#include "../../functions/AnsiPrint/AnsiPrint.h"

// read data to the Room class
Room::Room(RoomData data):roomID(data.id), roomName(data.name), roomDescription(data.description), playerInitialPosition(data.playerInitialPosition) {
	memcpy(&defaultRoomObjectMap[0][0],
		&data.defaultRoomObjectMap[0][0],
		GAME_WINDOW_SIZE_Y*GAME_WINDOW_SIZE_X*sizeof(data.defaultRoomObjectMap[0][0]));
}

// add your code to implement the Room class here
















// render
void Room::render(Position position) {
    switch(this->defaultRoomObjectMap[position.getY()][position.getX()]) {
        case OBJECT_NONE:
            AnsiPrint("  ", black, black);
            break;
        case OBJECT_DOOR:
            AnsiPrint("DR", yellow, black);
            break;
        case OBJECT_WALL:
            AnsiPrint("██", white, black);
            break;
        case OBJECT_GRASS:
            AnsiPrint("WW", green, black);
            break;
        case OBJECT_ROCK:
            AnsiPrint("▲▲", yellow, black);
            break;
        case OBJECT_WATER:
            if(rand() % 2 == 0) {
                AnsiPrint("~~", cyan, blue);
            } else {
                AnsiPrint("……", cyan, blue);
            }
            break;
    }
}
