
class Enemy : public Npc {
private :
	
public :
	int getAtaque(){
		return this->getAtaque();
	}

	int getDefesa(){
		return this->getDefesa();
	}
        
        void virtual draw(){
            glPushMatrix();
            //glTranslatef(this->dx,this->dy,0);
            
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