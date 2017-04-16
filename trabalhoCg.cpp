/* Código inicial no OpenGL */

#include <GL/glut.h>

#define LARGURA  500		/* Width */
#define ALTURA   500		/* Heigth */

GLfloat angulo = 0;
GLfloat anguloAnte = 0;
GLfloat tx = 0;
GLfloat ty = 0;
GLfloat sx = 1;
GLfloat sy = 1;
void Desenha_braco()
{

	/* Define a cor do quadrado para verde */
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2i(200, 300);
		glVertex2i(225, 300);
		glVertex2i(225, 180);
		glVertex2i(200, 180);
	glEnd();

	/* Define um ponto na cor preta */
	glColor3f(0.0, 0.0, 0.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(212.5, 300);
	glEnd();
}

void Desenha_antebraco()
{
	/* Define a cor do quadrado para verde */
	//glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2i(200, 180);
		glVertex2i(225, 180);
		glVertex2i(225, 100);
		glVertex2i(200, 100);
	glEnd();

	/* Define um ponto na cor preta */
	glColor3f(0.0, 0.0, 0.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(212.5, 180);
	glEnd();
}

void Desenha_cabeca_verde()
{
	/* Define a cor do quadrado para verde */
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_QUADS);
		glVertex2i(75, 310);
		glVertex2i(175, 310);
		glVertex2i(175, 410);
		glVertex2i(75, 410);
	glEnd();

	/* Define um ponto na cor preta */
	glColor3f(0.0, 0.0, 0.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(250, 250);
	glEnd();
}

void Desenha_quadrado_cor_azul()
{
	/* Define a cor do quadrado para azul */
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_QUADS);
		glVertex2i(50, 50);
		glVertex2i(200, 50);
		glVertex2i(200, 300);
		glVertex2i(50, 300);
	glEnd();

	/* Define um ponto na cor preta */
	glColor3f(0.0, 0.0, 0.0);
	/* Define o tamanho do ponto para 4x4 pixels */
	glPointSize(4);
	glBegin(GL_POINTS);
		glVertex2i(250, 100);
	glEnd();
}

/* Função callback chamada para fazer o desenho */
void Desenha(void)
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();	/* Carrega na matriz corrente a matriz identidade */

	/* Limpa a janela de visualização com a cor de fundo especificada */
	glClear(GL_COLOR_BUFFER_BIT);

	/* P_vermelhor = (250, 400) */
	/* P_verde = (250, 250) */
	/* P_azul = (250, 100) */

	/*glTranslatef(250.0, 400.0, 0.0);
	glScalef(0.5, 0.5, 1.0);
	glTranslatef(-250.0, -400.0, 0.0);
	Desenha_quadrado_cor_vermelho();

	glPushMatrix();
	glLoadIdentity();

	glTranslatef(250.0, 250.0, 0.0);
	glRotatef(30.0, 0.0, 0.0, 1.0);
	glTranslatef(-250.0, -250.0, 0.0);
	Desenha_quadrado_cor_verde();

	glPopMatrix();

	glLoadIdentity();*/
	//
	//ROTACIONANDO O BRAÇO
	glPushMatrix();
	//glLoadIdentity();

	glTranslatef(tx, ty , 0.0);
	glScalef(sx,sy,1.0f);
	Desenha_quadrado_cor_azul();
	Desenha_cabeca_verde();
	glTranslatef(212.5, 300.0, 0.0);
	glRotatef(angulo, 0.0, 0.0, 1.0);
	glTranslatef(-212.5, -300.0, 0.0);

	Desenha_braco();

	glTranslatef(212.5, 180.0, 0.0);
	glRotatef(anguloAnte, 0.0, 0.0, 1.0);
	glTranslatef(-212.5, -180.0, 0.0);

	Desenha_antebraco();
	glPopMatrix();

	//ROTACIONANDO O ANTEBRAÇO
	
	//glRotatef(angulo,0.0,0.0,1.0);
	
	//Desenha_braco();
	//Desenha_antebraco();

	/* Executa os comandos OpenGL */
	glFlush();
}

void GerenciaTeclado(unsigned char key, int x, int y)
{
    switch (key)
     {

		case 'r':/* muda a cor corrente para vermelho */
		{	
			angulo++;
		}

		break;

		case 'e':/* muda a cor corrente para vermelho */
		{	
			anguloAnte++;
		}

		break;

		case 's':
		{
			sx = sx+0.1;
			sy = sy+0.1;
		}
			break;

		case 'S':
		{
			sx = sx-0.1;
			sy = sy-0.1;
			break;
		}


		case 'q':
			exit(1);
			break;
    }



    /* Necessário chamar toda vez que se faz uma alteração ou evento na janela
     * Indica a funcao glutMainLoop a chamar glutDisplayFunc com as alterações */
    glutPostRedisplay();
}

void GerenciaTeclasDirecionais (int key, int x, int y)
{

		switch(key)
		{
					case GLUT_KEY_UP :
				{
					ty++;
				}

				break;

				case GLUT_KEY_DOWN :
				{
					ty--;
				}

				break;

				case GLUT_KEY_RIGHT :
				{
					tx++;
				}

				break;

				case GLUT_KEY_LEFT :
				{
					tx--;
				}

				break;
				
		}
		

		glutPostRedisplay();
}

/* Inicializa parâmetros de rendering */
void Inicializa (void)
{
    /* Define a cor de fundo da janela de visualização como branca */
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

    /* Modo de projecao ortogonal */
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, LARGURA, 0, ALTURA, -1 ,1);
}

/* Programa Principal */
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize (LARGURA, ALTURA);
	glutInitWindowPosition (100, 100);
	glutCreateWindow("Transformacoes");
	glutDisplayFunc(Desenha);
	glutSpecialFunc(GerenciaTeclasDirecionais);
	glutKeyboardFunc(GerenciaTeclado); 
	Inicializa();
	glutMainLoop();
}

