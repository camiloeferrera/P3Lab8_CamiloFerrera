#include "Comentario.h"

Comentario::Comentario(string autor,string contenido)
{
	this->autor=autor;
	this->contenido=contenido;
}
Comentario::~Comentario()
{
}
string Comentario::getAutor(){
	return this->autor;
}
string Comentario::getContenido(){
	return this->contenido;
}
