/**********************************************************************************
// Background (Código Fonte)
// 
// Criação:		21 Abr 2012
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Plano de fundo do jogo
//
**********************************************************************************/

#include "Background.h"

// ---------------------------------------------------------------------------------

Background::Background()
{
	MoveTo(window->CenterX(), 350, 0.9f);
	xF = xB = x;

	// cria sprites do plano de fundo
	sky    = new Sprite("Resources/Sky.jpg");	
	//backgF = new Sprite("Resources/BackgFront.png");
	backgB = new Sprite("Resources/BackgBack.png");	
}

// ---------------------------------------------------------------------------------

Background::~Background()
{
	//delete backgF;
	delete backgB;	
	delete sky;
}

// -------------------------------------------------------------------------------

void Background::Update(float gameTime)
{
	// move sprites com velocidades diferentes
	if (Player::centro == true && ((Player::estado == PANDARDIR) || (Player::estado == GANDARDIR) ||
		(Player::estado == PPULARDIR) || (Player::estado == GPULARDIR)))
	{
		xF -= 200 * gameTime;
		xB -= 150 * gameTime;
	}
	if ((Player::estado == PANDARESQ) || (Player::estado == GANDARESQ) ||
		(Player::estado == PPULARESQ) || (Player::estado == GPULARESQ))
	{
		xF += 200 * gameTime;
		xB += 150 * gameTime;
	}
}

// -------------------------------------------------------------------------------

void Background::Draw()
{
	sky->Draw(window->CenterX(), window->CenterY(), 0.9f);

	backgB->Draw(xB, 350, 0.9f);
	
	if (xB + backgB->Width()/2.0f < window->Width())
		backgB->Draw(xB + backgB->Width(), Y(), 0.9f); 

	if (xB + backgB->Width()/2.0f < 0)
		xB += backgB->Width();
	
	if (xB - backgB->Width() / 2.0f > window->Width())
		backgB->Draw(xB - backgB->Width(), Y(), 0.9f);

	if (xB - backgB->Width() / 2.0f > 0)
		xB -= backgB->Width();

/*	backgF->Draw(xF, 500, 0.8f);
	
	if (xF + backgF->Width()/2.0f < window->Width())
		backgF->Draw(xF + backgF->Width(), window->Height()/2.0f, 0.8f); 

	if (xF + backgF->Width()/2.0f < 0)
		xF += backgF->Width();
	
	if (xF - backgF->Width() / 2.0f > window->Width())
		backgF->Draw(xB - backgF->Width(), Y(), 0.9f);

	if (xF - backgF->Width() / 2.0f > 0)
		xF -= backgF->Width();*/
}

// -------------------------------------------------------------------------------
