//#include "../environment/Item.cpp"
//#include "Entity.cpp"

class Npc : public Entity{
protected :

public :
	int soltarItem(int level){
		std::string nome = "newName";
		Item item(nome,level);
		//drawItem(dx,dy);
	}
};