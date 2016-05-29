

class Warrior : public Adventurer {
private :
	
public :
	void levelUp(){
		this->setAtaque(this->getAtaque() + 4);
		this->setDefesa(this->getDefesa() + 1);
		this->setLevel();
	}

	int getAtaque(){
		return getAtaque() + itens[itemAtaqueEquipado].getAtaque();
	}

	int getDefesa(){
		return getDefesa() + itens[itemDefesaEquipado].getDefesa();
	}
};