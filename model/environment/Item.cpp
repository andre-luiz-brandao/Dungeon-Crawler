
class Item{
	private :
		char* itemName;
		int ataque,defesa;
	public :

		Item(char *nome, int level){
			this->itemName = nome;
			this->setAtaque(level*4);
			this->setDefesa(level*4);
		}	

		void setAtaque(int ataque) {
			this->ataque = ataque;
		}

		void setDefesa(int defesa) {
			this->defesa = defesa;
		}

		int getAtaque(){
			return this->ataque;
		}

		int getDefesa(){
			return this->defesa;
		}
};