
class Adventurer : public Entity{
private :
    int xp;
    int nextLvl;
protected :
    
public :
    std::vector<Item*> itens;
    int itemAtaqueEquipado, itemDefesaEquipado, qntItens;
    void setItemAtaque(int itemAtaque){
            this->itemAtaqueEquipado = itemAtaque;
    }

    void setItemDefesa(int itemDefesa){
            this->itemDefesaEquipado = itemDefesa;
    }

    int pegarItem(Item * item){
        if(qntItens == 10) return 1; // Mochila cheia.
//            itens[qntItens] = item;
        this->itens.push_back(item);
        this->qntItens++;
    }
    
    int getXp() const {
        return xp;
    }

    void setXp(int xp) {
        this->xp += xp;
    }
    
    int getNextLvl() const {
        return nextLvl;
    }

    void setNextLvl(int nextLvl) {
        this->nextLvl = nextLvl;
    }
};