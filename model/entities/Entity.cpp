#include <iostream>
#include <string>

class Entity{
protected :
    //atributos comuns entre os personagens jogáveis.
    //Atributos básicos.
    int ataque,defesa,life,level;
    //posição de respawn.
    float initDx,initDy;
    //Valores para deslocar o personagem
    float dx,dy;
    //valor de rotação do personagem
    int rotZ;
public : 
    void andar(int x, int y){
        this->dx = x;
        this->dy = y;
    }
    
    void setAtaque(int ataque){
            this->ataque = ataque;
    }
    void setDefesa(int defesa){
            this->defesa = defesa;
    }
    void setLife(int life){
            this->life = life;
    }
    void setPosicao(int x, int y){
            this->initDx = x;
            this->initDy = y;
    }
    void setAngle(int rotacao){
            this->rotZ = rotacao;
    }
    void setLevel(){
            this->level++;
    }
    int getLife(){
            return this->life;
    }
    int getLevel(){
            return this->level;
    }
    virtual void draw(){};
        
    virtual int getAtaque() const {
        return ataque;
    }

    virtual int getDefesa() const {
        return defesa;
    }

};