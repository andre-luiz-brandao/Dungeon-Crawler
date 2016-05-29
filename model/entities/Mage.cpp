
class Mage : public Adventurer {
private :
	
public :
	void levelUp(){
		this->ataque += 2;
		this->defesa += 2;
		this->level++;
	}

	int getAtaque(){
		return this->ataque + this->itens[itemAtaqueEquipado].getAtaque();
	}

	int getDefesa(){
		return this->defesa + this->itens[itemDefesaEquipado].getDefesa();
	}
};