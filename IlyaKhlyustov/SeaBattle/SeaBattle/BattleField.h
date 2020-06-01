#pragma once
#include<iostream>
#include<vector>

enum TypeField{	Mine, Enemy};

class BattleField{
private:
	std::vector<std::vector<int>> mas;
	TypeField type;
	class BadIndex{};
public:
	BattleField(TypeField _type = Mine);
	BattleField(const BattleField& tmp);
	BattleField& operator=(const BattleField& tmp);
	std::vector<int>& operator[](const int k);
	const std::vector<int>& operator[](const int k) const;
};

