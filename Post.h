#ifndef POST_H
#define POST_H
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "Comentario.h"

class Post
{
	public:
		Post(string,string);
		~Post();
		string getTitulo();
		string getContenido();
		int getLikes();
		int getHates();
		vector<Comentario*>& getComentarios();
		void aumentarLikes();
		void aumentarHates();
	protected:
		string titulo,contenido;
		int likes = 0,hates = 0;
		vector<Comentario*> comentarios;
		
};

#endif
