
class Archer : public Adventurer {
private :
	
public :
	void levelUp(){
		this->ataque += 3;
		this->defesa += 2;
		this->level++;
	}

	int getAtaque(){
		return this->getAtaque() + this->itens[itemAtaqueEquipado].getAtaque();
	}

	int getDefesa(){
		return this->defesa + this->itens[itemDefesaEquipado].getDefesa();
	}
};