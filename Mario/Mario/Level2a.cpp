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
#include "Level2.h"
#include "Derrota.h"
#include "Player.h"
#include "Inimigo.h"
#include "Platform.h"
#include "Vitoria.h"
#include <string>
#include <fstream>
using std::ifstream;
using std::string;

// ------------------------------------------------------------------------------

// inicializa membros da classe
Scene * Level2::scene = nullptr;

// ------------------------------------------------------------------------------

void Level2::Init()
{
	// cria gerenciador de cena
	scene = new Scene();
	
	// cria fontes
	marioFont = new Font("Resources/fonteMario.png");
	marioFont->Spacing(20);

	// pano de fundo do jogo
	fundo = new Background();
	scene->Add(fundo, STATIC);

	// cria jogador
	player = new Player();
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

	fin.open("Resources/Level2.txt");
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
	Mario::audio->Play(FASE1);
}

// ------------------------------------------------------------------------------

void Level2::Update(float gameTime)
{
	if (window->KeyDown(VK_ESCAPE))
	{
		Mario::audio->Stop(FASE1);
		Mario::NextLevel<Menu>();
	}
	else if (player->Bottom() < 0 || player->Top() > window->Height() || window->KeyDown('N'))
	{
		Mario::audio->Stop(FASE1);
		Mario::NextLevel<Derrota>();
	}
	
	scene->Update(gameTime);
	scene->CollisionDetection();
}

// ------------------------------------------------------------------------------

void Level2::Draw()
{
	Color black(0.0f, 0.0f, 0.0f, 0.0f);
	Color blue(0.2f, 0.2f, 1.0f, 1.0f);
	Color red(1.0f, 0.2f, 0.2f, 1.0f);
	Color green(0.1f, 0.6f, 0.1f, 1.0f);

	fundo->Draw();
	scene->Draw();

	if (Player::passarLevel == true)
	{
		marioFont->Draw(100, 200, "passou de nivel!", black, 0.0f, 0.75f, 0.0f);
		marioFont->Draw(100, 300, "seus pontos: " + to_string(Player::pontos), black, 0.0f, 0.75f, 0.0f);
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

void Level2::Finalize()
{
	delete scene;
}

// ------------------------------------------------------------------------------
