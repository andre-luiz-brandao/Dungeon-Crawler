#include <vector>

#include "../model/environment/Item.cpp"
#include "../model/entities/Entity.cpp"
#include "../model/entities/Npc.cpp"
#include "../model/entities/Monster.cpp"
#include "../model/entities/Adventurer.cpp"

#include "../model/entities/Warrior.cpp"
#include "../model/entities/Archer.cpp"
#include "../model/entities/Mage.cpp"
#include "../model/entities/Cleric.cpp"
#include "../model/entities/Enemy.cpp"
#include "../model/entities/Friendly.cpp"

class Control {
protected :
    Adventurer* mainCharacter;
    std::vector<Monster*> monstersArray;
    std::vector<Npc*> npcArray;
public :
    Adventurer* getMainCharacter() const {
        return mainCharacter;
    }

    std::vector<Monster*> getMonstersArray() const {
        return monstersArray;
    }

    std::vector<Npc*> getNpcArray() const {
        return npcArray;
    }

    void setMainCharacter(Adventurer* mainCharacter) {
        this->mainCharacter = mainCharacter;
    }

    void setMonster(Monster* monster) {
        this->monstersArray.push_back(monster);
    }

    void setNpc(Npc* npc) {
        this->npcArray.push_back(npc);
    }    
};
