#include <GL/glut.h>
#include <iostream>
#include <math.h>

using namespace std;

int figura = 1;
int mouseEsq = 0, mouseDir = 0;
int larx=0, alty=0;
int teclas[255];
float currentTime=0,timeDifference=0.3,previousTime=0;
int ortoSetting = 1000;
int mousex = 0, mousey = 0;
int correctionValue = 10;
int outOfLimits = 0;
int catchItem = 0;
int pegarItem = 0;

void drawItem(int size){
    glPushMatrix();
    glTranslatef(500,-500,0);
    glColor3f(0.0,1.0,0.0);
    glBegin(GL_QUADS);
        glVertex2i(0,0);
        glVertex2i(0,size);
        glVertex2i(size,size);
        glVertex2i(size,0);
    glEnd();
    glPopMatrix();
}

void drawCharacter(int size){
    glPushMatrix();
    glTranslatef(larx,alty,0);
    glColor3f(0.0,0.0,0.0);
    glBegin(GL_QUADS);
        glVertex2i(0,0);
        glVertex2i(0,size);
        glVertex2i(size,size);
        glVertex2i(size,0);
    glEnd();
    glPopMatrix();
}

void drawScenario(){
    glPushMatrix();
    glColor3f(0.32f,0.2f,0.11f); // marrom
    glBegin(GL_QUADS);
        glVertex2i(-1000,-1000);
        glVertex2i(-1000,-250);
        glVertex2i(-250,-250);
        glVertex2i(-250,-1000);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(-1000,250);
        glVertex2i(-1000,1000);
        glVertex2i(-250,1000);
        glVertex2i(-250,250);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(250,250);
        glVertex2i(250,1000);
        glVertex2i(1000,1000);
        glVertex2i(1000,250);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(250,-1000);
        glVertex2i(250,-900);
        glVertex2i(1000,-900);
        glVertex2i(1000,-1000);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(250,-900);
        glVertex2i(250,-250);
        glVertex2i(350,-250);
        glVertex2i(350,-900);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(450,-350);
        glVertex2i(450,-250);
        glVertex2i(1000,-250);
        glVertex2i(1000,-350);
    glEnd();

    glBegin(GL_QUADS);
        glVertex2i(900,-900);
        glVertex2i(900,-350);
        glVertex2i(1000,-350);
        glVertex2i(1000,-900);
    glEnd();
    glPopMatrix();
}

void display( void )
{
    glClear( GL_COLOR_BUFFER_BIT );
    //drawCharacter(0,0,10);
    
    drawCharacter(40);
    if(pegarItem != 1){
         drawItem(20);
    }
    drawScenario();
    glutSwapBuffers();
    glutPostRedisplay();
}
void scenarioColision(){

    //mapBox
    if(larx < -980 || larx > 980 || alty > 980 || alty < -980){
        if(larx < -990) larx += correctionValue;
        if(larx > 990) larx -= correctionValue;
        if(alty > 990) alty -= correctionValue;
        if(alty < -990) alty += correctionValue;
    } 

    //quadrado inferior esquerdo
    if(larx < -240 && alty < -240){
        if(teclas['w'] && teclas['a']){
            larx += correctionValue;
            alty += correctionValue;
        } else if(teclas['a'] && teclas['s'] && alty > -250){
            larx -= correctionValue;
            alty += correctionValue;
        } else if(teclas['s'] && teclas ['d']){
            larx += correctionValue;
            alty += correctionValue;
        } else if( teclas['a'] && teclas['s'] && alty < -250){
            larx += correctionValue;
            alty -= correctionValue;
        } else if(teclas['a']){
            larx += correctionValue;
        } else if(teclas['s']) {
            alty += correctionValue;
        }
    }
}
void detectColision(){
    scenarioColision();
}

void idle(){
	static char direction = 2;
	static GLdouble previousTime = 0;
	GLdouble currentTime;
	GLdouble timeDifference;

	currentTime = glutGet(GLUT_ELAPSED_TIME);
	timeDifference = currentTime - previousTime;
	previousTime = currentTime;

    detectColision();

	if(larx > ortoSetting){
		larx = -ortoSetting;
	} else if( larx < -ortoSetting){
		larx = ortoSetting;
	}

	if(alty > ortoSetting){
		alty = -ortoSetting;
	} else if(alty < -ortoSetting){
		alty = ortoSetting;
	}

    //if(colisionDetected != 1){
        if(teclas['w']){
            alty += 0.3*timeDifference;
        } 
        if(teclas['s']){
            alty -= 0.3*timeDifference;
        } 
        if(teclas['a']){
            int tempLarx = larx;
            larx -= 0.3*timeDifference;
        } 
        if(teclas['d']){
            int tempLarx = larx;
            larx += 0.3*timeDifference;
        }

        if(sqrt(pow((larx-500),2) + pow((alty + 500),2)) < 100) {
            catchItem = 1; 
        } else { 
            catchItem = 0;
        }
    //}
	
}
void init( void )
{
    glViewport(0,0,ortoSetting,ortoSetting);
	for(int x = 0; x < 255 ; x++){
		teclas[x] = 0;
	}
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
    //Selecionar cor de fundo preto
    glClearColor( 1.0, 1.0, 1.0, 0.0 );
    
    //Inicializar sistema de visualizaçao
    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glOrtho( -ortoSetting, ortoSetting, -ortoSetting, ortoSetting, -200, 200 );
}    

void reshape(int altura, int largura){
    //cout << "altura :" << altura << "largura :" << largura ;
}
void keyboardUp(unsigned char teclado, int x, int y){
	switch (teclado) {
        case 'w' :
        		teclas['w'] = 0;
        	break;
        case 's' :
        		teclas['s'] = 0;
        	break;
        case 'a' :
        		teclas['a'] = 0;
        	break;
        case 'd' :
        		teclas['d'] = 0;
        	break;
        }
}
void keyboard (unsigned char teclado, int x, int y){
    int asciiTecla;
    switch (teclado) {
        case 27 : 
            exit(0);
            break;
        case 'w' :
        		teclas['w'] = 1;
        	break;
        case 's' :
        		teclas['s'] = 1;
        	break;
        case 'a' :
        		teclas['a'] = 1;
        	break;
        case 'd' :
        		teclas['d'] = 1;
        	break;
    }
    glutPostRedisplay();
}

void special(int key, int x, int y){
    switch (key) {
        case GLUT_KEY_RIGHT :
           
            break;
        case GLUT_KEY_LEFT :
        	
            break;
        case GLUT_KEY_DOWN :
        	
            break;
        case GLUT_KEY_UP :
            
            break;
        case GLUT_KEY_F1 : 
            cout << "F1\n" ;
            break;
        case GLUT_KEY_PAGE_UP :
            cout << "Page Up\n";
            break;
        case GLUT_KEY_PAGE_DOWN :
            cout << "Page Down\n";
            break;
        case GLUT_KEY_HOME :
            cout << "Home\n";
            break;
        case GLUT_KEY_END :
            cout << "End \n";
            break;
        case GLUT_KEY_INSERT :
            cout << "Insert\n";
            break;
    }
    glutPostRedisplay();
}

void mouse (int botao, int estado, int x, int y){
    switch (botao) {
        case GLUT_LEFT_BUTTON :
            if(estado == 0){
                if(x >= 750 && x <= 760 && y > 340 && y < 350 && catchItem == 1) {
                    pegarItem = 1;
                }
                cout << "Botao esquerdo pressionado em x :" << x << " y :" << y << "\n";
            } else cout << "Botao esquerdo solto em x : " << x << " y :" << y << "\n";
            break;
        case GLUT_RIGHT_BUTTON : 
            if(estado == 0){
                cout << "Botao direito pressionado em x :" << x << " y :" << y << "\n";
            } else cout << "Botao direito solto em x :" << x << " y :" << y << "\n";
            break;
        case GLUT_MIDDLE_BUTTON : 
            if(estado == 0){
                cout << "Botao central pressionado em x :" << x << " y :" << y << "\n";
            } else cout << "Botao central solto em x :" << x << " y :" << y << "\n";
            break;
    }
}

void motion (int x, int y){
    //cout << "Arrastando : x " << x << " y : " << y << "\n";
}

void passiveMotion(int x, int y){
    //cout << "Movendo : x " << x << " y : " << y << "\n";
}

int main(int argc, char *argv[])
{
    glutInit( &argc, argv );
    glutInitDisplayMode( GLUT_DOUBLE | GLUT_RGB );
    glutInitWindowSize( 800, 600 );
    glutInitWindowPosition( 250, 250 );
    glutCreateWindow( "Hello" );
    glutDisplayFunc( display );
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutKeyboardUpFunc(keyboardUp);
    //glutSpecialFunc(special);
    glutIdleFunc(idle);
    glutMouseFunc(mouse);
    //glutMotionFunc(motion);
    //glutPassiveMotionFunc(passiveMotion);
    init();

    glutMainLoop();
    return 0;
}