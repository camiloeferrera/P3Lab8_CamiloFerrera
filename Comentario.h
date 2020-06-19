#ifndef COMENTARIO_H
#define COMENTARIO_H
#include <string>
using std::string;

class Comentario
{
	public:
		Comentario(string,string);
		~Comentario();
		
		string getAutor();
		string getContenido();
	protected:
		string autor,contenido;
};

#endif
