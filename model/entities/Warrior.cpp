#include "Adventurer.cpp"

class Warrior : public Adventurer {
private :
	
public :
	void levelUp(){
		this->ataque += 4;
		this->defesa += 1;
		this->level++;
	}

	int getAtaque(){
		return this->ataque + this->itens[itemAtaqueEquipado].getAtaque();
	}

	int getDefesa(){
		return this->defesa + this->itens[itemDefesaEquipado].getDefesa();
	}
};