#include "Obstacle.h"

void Obstacle::SetLength(int l) {
	length = l;
}

int Obstacle::GetLength() {
	return length;
}

ObstacleBody Obstacle::GetBodyPart() {
	return body;
}