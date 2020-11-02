/**********************************************************************************
// Scene (Arquivo de Cabe�alho)
// 
// Cria��o:		16 Mar 2012
// Atualiza��o:	18 Mai 2014
// Compilador:	Visual C++ 12
//
// Descri��o:	Define uma classe para gerenciar o cen�rio do jogo.
//				
//				Um gerenciador de cena � respons�vel por guardar os objetos 
//				da cena, atualizando-os e desenhando-os de forma mais pr�tica. 
//              Ele pode ser usado tamb�m para outras tarefas que impliquem em
//              percorrer a lista de objetos, como detec��o de colis�o.
//
**********************************************************************************/

#ifndef _DESENVJOGOS_SCENE_H_
#define _DESENVJOGOS_SCENE_H_

// ---------------------------------------------------------------------------------
// Inclus�es

#include "Geometry.h"							// bounding boxes dos objetos
#include <list>									// lista da biblioteca STL 
#include <unordered_set>						// tabela de dispers�o
using std::list;								// acessa list sem precisar do std::
using std::pair;								// acessa pair sem precisar do std:
using std::unordered_set;						// acesssa unorndered_map sem std::
class Object;									// declara��o avan�ada

// ---------------------------------------------------------------------------------

typedef pair<Object*, Object*>  ObjectPair;
typedef pair<Object*, int>      ObjectDel;

// ---------------------------------------------------------------------------------

class Scene
{
private:
	list<Object*>          staticObjects;		// lista de objetos est�ticos (n�o colidem entre si)
	list<Object*>          movingObjects;		// lista de objetos em movimento (podem colidir entre si e com os est�ticos)
	list<ObjectPair>       collisions;			// lista de pares de objetos em colis�o
	list<ObjectDel>        toDelete;			// lista de objetos a deletar da cena
	unordered_set<Object*> resolutions;			// objetos registrados para a resolu��o de colis�o

	list<Object*>::iterator its;				// iterador para elemento est�tico
	list<Object*>::iterator itm;				// iterador para elemento em movimento
	list<Object*>::iterator it;					// iterador para elemento atual

	int processingElements;						// indica qual lista est� sendo processada

	bool Collision(Point* p, Rect*   r);		// colis�o entre ponto e ret�ngulo	
	bool Collision(Point* p, Circle* c);		// colis�o entre ponto e c�rculo

	bool Collision(Rect* ra, Rect*   rb);		// colis�o entre ret�ngulos
	bool Collision(Rect* r, Point*  p);			// colis�o entre ret�ngulo e ponto (inline)
	bool Collision(Rect* r, Circle* c);			// colis�o entre ret�ngulo e c�rculo

	bool Collision(Circle* ca, Circle* cb);		// colis�o entre c�rculos
	bool Collision(Circle* c, Point*  p);		// colis�o entre c�rculo e ponto (inline)
	bool Collision(Circle* c, Rect*   r);		// colis�o entre c�rculo e ret�ngulo (inline)

	bool Collision(Multi* m, Geometry* s);		// colis�o entre multi e uma forma qualquer
	bool Collision(Geometry* s, Multi* m);		// colis�o entre multi e uma forma qualquer (inline)
	
public:
	Scene();									// construtor
	~Scene();									// destrutor da cena

	void Add(Object* obj, int type);			// adiciona objeto na cena (tipo STATIC ou MOVING)
	void Remove(Object* obj, int type);			// adiciona objeto a lista de elementos a remover
	void Remove();								// remove objeto sendo processado na cena
	void ProcessDeleted();						// apaga elementos marcados para exclus�o

	void Begin();								// inicia percurso na lista de objetos
	Object * Next();							// retorna pr�ximo objeto da lista

	void Update(float gameTime);				// atualiza todos os objetos da cena
	void Draw();								// desenha todos os objetos da cena

	bool Collision(Object* oa, Object* ob);		// verifica se h� colis�o entre dois objetos
	void CollisionDetection();					// trata a colis�o entre objetos da cena
	void CollisionResolution(Object* obj);		// registra fun��o para tratar colis�o de objeto	
};

// --------------------------------------------------------------------------------
// Fun��es Membro Inline

// colis�o entre ret�ngulo e ponto
inline bool Scene::Collision(Rect* r, Point* p)
{ return Collision(p, r); }

// colis�o entre c�rculo e ponto
inline bool Scene::Collision(Circle* c, Point* p)
{ return Collision(p, c); }

// colis�o entre c�rculo e ret�ngulo
inline bool Scene::Collision(Circle* c, Rect* r)
{ return Collision(r, c); }

// colis�o entre multi e uma forma qualquer
inline bool Scene::Collision(Geometry* s, Multi* m)
{ return Collision(m, s); }

// ---------------------------------------------------------------------------------

#endif