/**********************************************************************************
// Mouse (Código Fonte)
// 
// Criação:		14 Mai 2012
// Atualização:	20 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Gerencia mouse na tela
//
**********************************************************************************/

#include "Mouse.h"
#include "Item.h"
#include "Mario.h"

// ---------------------------------------------------------------------------------

Mouse::Mouse()
{
	POINT mouse = window->Mouse();
	x = float(mouse.x);
	y = float(mouse.y);
	bbox = new Point(x, y);
}

// ---------------------------------------------------------------------------------

Mouse::~Mouse()
{
	delete bbox;
}

// -------------------------------------------------------------------------------

void Mouse::Update(float gameTime)
{
	POINT mouse = window->Mouse();
	MoveTo(float(mouse.x), float(mouse.y));
}

// -------------------------------------------------------------------------------

void Mouse::Draw()
{
}

// -------------------------------------------------------------------------------

bool Mouse::Clicked()
{
	if (window->KeyCtrl(VK_LBUTTON))
		return true;
	else
		return false;
}

// -------------------------------------------------------------------------------