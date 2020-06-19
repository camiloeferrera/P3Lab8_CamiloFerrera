#include "Usuario.h"

Usuario::Usuario(string nombre,string nombreUsuario,string contrasena)
{
	this->nombre = nombre;
	this->nombreUsuario = nombreUsuario;
	this->contrasena = contrasena;
}
Usuario::~Usuario()
{
	for(int i=0;i<this->seguidos.size();i++){
		delete this->seguidos[i];
	}
	for(int i=0;i<this->posts.size();i++){
		delete this->posts[i];
	}
}

string Usuario::getNombre(){
	return this->nombre;
}
string Usuario::getNombreUsuario(){
	return this->nombreUsuario;
}
string Usuario::getContrasena(){
	return this->contrasena;
}
vector<Usuario*>& Usuario::getSeguidos(){
	return this->seguidos;
}
vector<Post*>& Usuario::getPosts(){
	return this->posts;
}
