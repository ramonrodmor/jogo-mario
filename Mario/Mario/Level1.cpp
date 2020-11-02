/**********************************************************************************
// Level1 (Código Fonte)
//
// Criação:		14 Fev 2013
// Atualização:	18 Jun 2014
// Compilador:	Visual C++ 12
//
// Descrição:	Nível 1 do jogo Mario
//
**********************************************************************************/

#include "Engine.h"
#include "Mario.h"
#include "Menu.h"
#include "Level1.h"
#include "Derrota.h"
#include "Player.h"
#include "Inimigo.h"
#include "Platform.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

// inicializa membros da classe
Scene * Level1::scene = nullptr;

// ------------------------------------------------------------------------------

void Level1::Init()
{
	// cria gerenciador de cena
	scene = new Scene();
	
	// cria fontes
	marioFonte = new Font("Resources/fonteMario.png");
	marioFonte->Spacing(20);

	// pano de fundo do jogo
	fundo = new Background();
	scene->Add(fundo, STATIC);

	// cria jogador
	player = new Player;
	scene->Add(player, MOVING);
	scene->CollisionResolution(player);

	// cria inimigos
	inimigo = new Inimigo;
	scene->Add(inimigo, STATIC);
	scene->CollisionResolution(player);
	inimigo->MoveTo(1000.0f, 500.0f, 0.0f);

	inimigo = new Inimigo;
	scene->Add(inimigo, STATIC);
	scene->CollisionResolution(player);
	inimigo->MoveTo(1100.0f, 300.0f, 0.0f);
	
	inimigo = new Inimigo;
	scene->Add(inimigo, STATIC);
	scene->CollisionResolution(player);
	inimigo->MoveTo(1200.0f, 200.0f, 0.0f);

	// ----------------------
	// cria plataformas
	// ----------------------
	Platform * plat;
	float posX, posY;
	uint  platType;
	ifstream fin;

	fin.open("Resources/Level1.txt");
	fin >> posX;
	while (!fin.eof())
	{
		if (fin.good())
		{
			// lê linha com informações da plataforma
			fin >> posY; fin >> platType;
			plat = new Platform(posX, posY, platType);
			scene->Add(plat, STATIC);
		}
		else
		{
			// ignora comentários
			fin.clear();
			char temp[80];
			fin.getline(temp, 80);
		}

		fin >> posX;
	}
	fin.close();
	
	// ----------------------

	// toca som da fase
	Mario::audio->Play(FASE1, TRUE);
}

// ------------------------------------------------------------------------------

void Level1::Update(float gameTime)
{
	if (window->KeyDown(VK_ESCAPE))
	{	
		Mario::audio->Stop(FASE1);
		Mario::NextLevel<Menu>();
	}
	else if (player->Bottom() < 0 || player->Top() > window->Height() || player->vidas < 1)
	{
		Mario::audio->Stop(FASE1);
		Mario::NextLevel<Derrota>();
	}
	else if (Player::passarLevel == true)
	{
		Player::passarLevel = false;
		Sleep(3000);
		Mario::audio->Stop(FASE1);
		Mario::NextLevel<Level2>();
	}
	// passagem manual
	else if (window->KeyDown('N'))
	{
		Sleep(3000);
		Mario::audio->Stop(FASE1);
		Mario::NextLevel<Level2>();
	}
	else
	{
		scene->Update(gameTime);
		scene->CollisionDetection();
	}
}

// ------------------------------------------------------------------------------

void Level1::Draw()
{
	Color black(0.0f, 0.0f, 0.0f, 0.0f);
	Color blue(0.2f, 0.2f, 1.0f, 1.0f);
	Color red(1.0f, 0.2f, 0.2f, 1.0f);
	Color green(0.1f, 0.6f, 0.1f, 1.0f);

	fundo->Draw();
	scene->Draw();
	
	if (Player::passarLevel == true)
	{
		marioFonte->Draw(100, 200, "passou de nivel!", black, 0.0f, 0.75f, 0.0f);
		marioFonte->Draw(100, 300, "seus pontos: " + to_string(Player::pontos), black, 0.0f, 0.75f, 0.0f);
	}

	if (Mario::viewBBox)
	{
		// desenha bounding box dos objetos
		Engine::renderer->BeginPixels();
		scene->Begin();
		Object * obj = nullptr;
		while (obj = scene->Next())
		if (obj->bbox)
			Engine::renderer->Draw(obj->bbox, 0xffff00ff);
		Engine::renderer->EndPixels();
	}
}

// ------------------------------------------------------------------------------

void Level1::Finalize()
{
	delete scene;
}

// ------------------------------------------------------------------------------
