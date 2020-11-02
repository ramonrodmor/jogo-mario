/**********************************************************************************
// Object (C�digo Fonte)
//
// Cria��o:		01 Out 2007
// Atualiza��o:	14 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Essa � a classe base para todos objetos do jogo.
//
//				Um objeto do jogo � qualquer coisa que poss�mos querer desenhar
//				ou interagir dentro do jogo. Por exemplo, um soldado, um pr�dio,
//				um proj�til, uma forma geom�trica, etc.
//
**********************************************************************************/

#include "Object.h"
#include "Engine.h"

// -------------------------------------------------------------------------------
// Inicializa��o de vari�veis est�ticas da classe

Window * Object::window = nullptr;		// refer�ncia para a janela do jogo

// -------------------------------------------------------------------------------

Object::Object()
{
	// posi��o do objeto
	x = y = 0.0f;

	// profundidade do objeto
	z = 0.5f;

	//tipo do objeto
	type = 0;

	if (!window)
		window = Engine::window;
}

// -------------------------------------------------------------------------------

Object::~Object()
{
}

// -------------------------------------------------------------------------------

void Object::Translate(float dx, float dy, float dz)
{
	x += dx; 
	y += dy; 
	z += dz;

	if (bbox)
		bbox->Translate(dx, dy);
}

// -------------------------------------------------------------------------------

void Object::MoveTo(float px, float py, float pz)
{
	x = px; 
	y = py; 
	z = pz;

	if (bbox)
		bbox->MoveTo(px, py);
}

// -------------------------------------------------------------------------------

void Object::MoveTo(float px, float py)
{
	x = px; 
	y = py;

	if (bbox)
		bbox->MoveTo(px, py);
}

// -------------------------------------------------------------------------------

void Object::OnCollision(Object * obj)
{
}

// -------------------------------------------------------------------------------