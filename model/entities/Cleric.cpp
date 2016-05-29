
class Cleric : public Adventurer {
private :
	
public :
	void levelUp(){
		this->ataque += 3;
		this->defesa += 3;
		this->level++;
	}

	int getAtaque(){
		return this->ataque + this->itens[itemAtaqueEquipado].getAtaque();
	}

	int getDefesa(){
		return this->defesa + this->itens[itemDefesaEquipado].getDefesa();
	}
};