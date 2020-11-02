/**********************************************************************************
// Object (Arquivo de Cabe�alho)
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

#ifndef _DESENVJOGOS_OBJECT_H_
#define _DESENVJOGOS_OBJECT_H_

// -----------------------------------------------------------------------------

#include "Types.h"			// usando os tipos personalizados da engine
#include "Geometry.h"       // todo objeto deve ter uma bounding box
#include "Window.h"			// janela usada para o jogo

// -----------------------------------------------------------------------------

class Object
{
protected:
	static Window * window;	// janela do jogo em que o objeto est� inserido
	float x, y, z;			// coordenadas do objeto	
	uint type;				// tipo do objeto

public:
	Geometry * bbox;		// bounding box do objeto

	Object();				// construtor padr�o de um objeto
	virtual ~Object();		// destrutor virtual

	// ------------------------
	// fun��es virtuais	
	// ------------------------
	// podem ser sobrescritas na classe derivada
	// e chamadas corretamente mesmo usando um
	// ponteiro para a classe base

	// retorna coordenada x do objeto
	virtual float X() const;

	// retorna coordenada y do objeto
	virtual float Y() const;

	// retorna coordenada z do objeto
	virtual float Z() const;

	// retorna tipo do objeto
	virtual uint Type() const;

	// move o objeto por (deltaX, deltaY, deltaZ)
	virtual void Translate(float dx, float dy, float dz = 0.0f);

	// move o objeto para as coordenadas (x,y,z) indicadas
	virtual void MoveTo(float px, float py, float pz);

	// move o objeto para as coordenadas (x,y) indicadas
	virtual void MoveTo(float px, float py);

	// faz a resolu��o de colis�o do objeto
	virtual void OnCollision(Object * obj);

	// ------------------------
	// fun��es virtuais puras	
	// ------------------------	 
	// devem ser obrigatoriamente sobrescritas na classe derivada

	// atualiza estado do objeto
	virtual void Update(float gameTime) = 0;

	// desenha o objeto na tela
	virtual void Draw() = 0;
};

// -----------------------------------------------------------------------------
// M�todos Inline

// retorna coordenada x do objeto
inline float Object::X() const
{ return x; }

// retorna coordenada y do objeto
inline float Object::Y() const 
{ return y; }

// retorna coordenada z do objeto
inline float Object::Z() const 
{ return y; }

// retorna tipo do objeto
inline uint Object::Type() const
{ return type; }

// -----------------------------------------------------------------------------

#endif


