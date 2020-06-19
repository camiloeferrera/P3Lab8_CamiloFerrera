#include "Post.h"

Post::Post(string titulo,string contenido)
{
	this->titulo = titulo;
	this->contenido = contenido;
}
Post::~Post()
{
	for (int i=0;i<this->comentarios.size();i++){
		delete this->comentarios[i];
	}
}
string Post::getTitulo(){
	return this->titulo;
}
string Post::getContenido(){
	return this->contenido;
}
int Post::getLikes(){
	return this->likes;
}
int Post::getHates(){
	return this->hates;
}
vector<Comentario*>& Post::getComentarios(){
	return this->comentarios;
}
void Post::aumentarLikes(){
	this->likes++;
}
void Post::aumentarHates(){
	this->hates++;
}
