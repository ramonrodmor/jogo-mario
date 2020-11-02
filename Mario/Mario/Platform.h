/**********************************************************************************
// Platform (Arquivo de Cabe�alho)
//
// Cria��o:		21 Abr 2012
// Atualiza��o:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Plataformas do jogo
//
**********************************************************************************/

#ifndef _MARIO_PLATFORM_H_
#define _MARIO_PLATFORM_H_

// ---------------------------------------------------------------------------------

#include "Types.h"						// tipos espec�ficos da engine
#include "Object.h"						// interface de Object
#include "Sprite.h"						// background � composto por sprites
#include "Mario.h"

// ---------------------------------------------------------------------------------

//enum TYPES { SMALL, MEDIUM, BLOCO, CASTELO, CANO, CANO2, CASTELOFINAL, PORTA, CHAOCASTELO, PAREDE, MOEDAS};

// ---------------------------------------------------------------------------------

class Platform : public Object
{
private:
	Sprite * platform;					// sprite da plataforma

public:
	Platform(float posX, float posY, uint platType);
	~Platform();

	void Update(float gameTime);		// atualiza��o do objeto
	void Draw();						// desenho do objeto
};

// ---------------------------------------------------------------------------------
// Fun��o Membro Inline

inline void Platform::Draw()
{
	platform->Draw(x, y, z);
}

// ---------------------------------------------------------------------------------

#endif