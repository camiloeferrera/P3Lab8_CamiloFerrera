#ifndef USUARIO_H
#define USUARIO_H
#include <string>
using std::string;
#include <vector>
using std::vector;
#include "Post.h"

class Usuario
{
	public:
		Usuario(string,string,string);
		~Usuario();
		string getNombre();
		string getNombreUsuario();
		string getContrasena();
		vector<Usuario*>& getSeguidos();
		vector<Post*>& getPosts();
		
		bool operator==(Usuario* der){
			if (this->nombre == der->getNombre())
				return true;
			else
				return false;	
		}
	protected:
		string nombre,nombreUsuario,contrasena;
		vector<Usuario*> seguidos;
		vector<Post*> posts;
};

#endif
