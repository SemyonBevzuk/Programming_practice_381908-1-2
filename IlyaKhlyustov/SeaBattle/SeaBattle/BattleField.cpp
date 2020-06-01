#include "BattleField.h"

BattleField::BattleField(TypeField _type): type(_type){
	mas.resize(10, std::vector<int>(10, 0));
}

BattleField::BattleField(const BattleField& tmp){
	mas = tmp.mas;
	type = tmp.type;
}

BattleField& BattleField::operator=(const BattleField& tmp){
	if (this == &tmp) return *this;
	mas = tmp.mas;
	type = tmp.type;
	return *this;
}

std::vector<int>& BattleField::operator[](int k){
	try {
		if (k < 0 || k >= 10) throw BadIndex();
		else {
			return mas[k];
		}
	}
	catch (BattleField::BadIndex) {
		std::cout << "Bad Index, try to change!\n";
		return mas[0];//change on smth clever
	}
}

const std::vector<int>& BattleField::operator[](const int k) const{
	try {
		if (k < 0 || k >= 10) throw BadIndex();
		else {
			return mas[k];
		}
	}
	catch (BattleField::BadIndex) {
		std::cout << "Bad Index, try to change!\n";
		return mas[0];//change on smth clever
	}
}
