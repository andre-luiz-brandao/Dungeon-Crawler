
class Warrior : public Adventurer {
private :
	
public :
	void levelUp(){
            if(this->getXp() >= this->getNextLvl()){
                this->setAtaque(this->getAtaque() + 4);
		this->setDefesa(this->getDefesa() + 1);
		this->setLevel();
                this->setNextLvl(this->getNextLvl() * 2);
            }
		
	}

	int virtual getAtaque(){
		return getAtaque();
	}

	int virtual getDefesa(){
		return getDefesa();
	}
        
        void virtual draw(){
            glPushMatrix();
            glTranslatef(this->dx,this->dy,0);
            
            this->glDraw(this->initDx, this->initDy);
            glPopMatrix();
        }
        
        void glDraw(int posx, int posy){
            glColor3f(1.0,0.0,0.0);
            glBegin(GL_QUADS);
                glVertex2i(posx,posy);
                glVertex2i(posx,40);
                glVertex2i(40,40);
                glVertex2i(40,posy);
            glEnd();
        }
};


