

class Monster : public Entity{
protected :

public :
	int soltarItem(int level){
		std::string nome = "newName";
		Item *item = new Item(nome,level);
		//drawItem(dx,dy);
	}
        
        void virtual draw(){
            glPushMatrix();
            glTranslatef(this->initDx,this->initDy,0);
            
            this->glDraw(this->initDx, this->initDy);
            glPopMatrix();
        }
        
        void glDraw(int posx, int posy){
            glColor3f(0.8,0.0,1.0);
            glBegin(GL_QUADS);
                glVertex2i(0,0);
                glVertex2i(0,40);
                glVertex2i(40,40);
                glVertex2i(40,0);
            glEnd();
        }
};