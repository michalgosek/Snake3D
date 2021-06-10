#include "Food.h"

void Food::SetLength(int l) {
	length = l;
}

int Food::GetLength() {
	return length;
}

FoodBody Food::GetBodyPart() {
	return body;
}