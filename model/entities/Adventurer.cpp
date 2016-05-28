#include "Entity.cpp"
#include "../environment/Item.cpp"


class Adventurer : public Entity{
protected :
	int itemAtaqueEquipado, itemDefesaEquipado, qntItens;
	Item itens[10];
public :
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