//#include "../environment/Item.cpp"
//#include "Entity.cpp"

class Adventurer : public Entity{
protected :
	
public :
	Item itens[10];
	int itemAtaqueEquipado, itemDefesaEquipado, qntItens;
	void setItemAtaque(int itemAtaque){
		this->itemAtaqueEquipado = itemAtaque;
	}

	void setItemDefesa(int itemDefesa){
		this->itemDefesaEquipado = itemDefesa;
	}

	int pegarItem(Item item){
		if(qntItens == 10) return 1; // Mochila cheia.
		itens[qntItens] = item;
	}
};