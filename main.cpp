#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <locale.h>
#include <vector>
using std::vector;
#include "Usuario.h"

// variables globales
vector<Usuario*> usuarios;
int u;
//prototipos
int menuPrincipal();
void registro();
bool logIn();
int menuUsuario();
void crearPost();
void comentarPost();
void darLike();
void seguirUsuario();
void unfollowUsuario();

int main(){
	setlocale(LC_ALL,"spanish");
	usuarios.push_back(new Usuario("Camilo","camiloeferrera","java123"));
	usuarios[0]->getPosts().push_back(new Post ("Bienvenido","Hola Juda!"));
	usuarios[0]->getPosts().push_back(new Post ("Lab#7","Jovenes, ya esta su nota!"));
	usuarios.push_back(new Usuario("Juda","judaponce","java123"));
	while(true){
		switch(menuPrincipal()){
			case 1:{
				if(logIn()){
					while(true){
						int opcionUsuario = menuUsuario();
						if(opcionUsuario==1){
							crearPost();
						} else if(opcionUsuario==2){
							comentarPost();
						} else if(opcionUsuario==3){
							darLike();
						} else if(opcionUsuario==4){
							
						} else if(opcionUsuario==5){
							seguirUsuario();
						} else if (opcionUsuario==6){
							unfollowUsuario();
						} else if(opcionUsuario==7){
							break;
						} else {					
							cout << "Opcion incorrecta..." << endl << endl;
						}
					}
				}
				break;
			}
			case 2:{
				registro();
				break;
			}
			case 3:{
				for(int i=0;i<usuarios.size();i++){
					usuarios[i] = NULL;
					delete usuarios[i];
				}
				return 0;
			}
			default:{
				cout << "Opcion incorrecta..." << endl << endl;
				break;
			}
		}
	}
}

int menuPrincipal(){
	int opcion;
	cout << "[MENÚ PRINCIPAL]" << endl
	<< "1. Iniciar Sesion" << endl
	<< "2. Registrarse" << endl
	<< "3. Salir" << endl
	<< "Ingrese opcion: "; cin >> opcion;
	cout << endl;
	return opcion;
}
void registro(){
	string nombre,nombreUsuario,contrasena;
	cout << "[REGISTRO]" << endl
	<<"Ingrese su nombre: "; cin >> nombre;
	cout << "Ingrese nombre de usuario: "; cin >> nombreUsuario;
	cout << "Ingrese contraseña: "; cin >> contrasena;
	cout << endl;
	
	bool datosOcupados = false;
	for(Usuario* u:usuarios){
		if(u->getNombre()==nombre){
			cout << "Ya hay un usuario con ese nombre..." << endl << endl;
			datosOcupados = true;
		}
		if(u->getNombreUsuario()==nombreUsuario){
			cout << "Ya hay un usuario con ese nombre de usuario..." << endl << endl;
			datosOcupados = true;
		}
		if(datosOcupados)
			break;
	}
	
	if(!datosOcupados){
		usuarios.push_back(new Usuario(nombre,nombreUsuario,contrasena));
		cout << "Usuario registrado con exito!" << endl << endl;
	}
}
bool logIn(){
	string nombreUsuario,contrasena;
	cout << "[LOG IN]" << endl
	<< "Ingrese nombre de usuario: "; cin >> nombreUsuario;
	cout << "Ingrese contraseña: "; cin >> contrasena;
	cout << endl;
	
	for (int i=0;i<usuarios.size();i++){
		if (usuarios[i]->getNombreUsuario()==nombreUsuario && usuarios[i]->getContrasena()==contrasena){
			u=i;
			return true;
		}
	}
	
	cout << "Datos no encontrados en el sistema..." << endl << endl;
	return false;
}
int menuUsuario(){
	cout << "[HOLA " << usuarios[u]->getNombre() << "!]" << endl;
	for(int i=0;i<usuarios[u]->getSeguidos().size();i++){
		if (i==0){
			cout << endl;
		}
		for (int j=0;j<usuarios[u]->getSeguidos()[i]->getPosts().size();j++){
			cout << "#" << j << " de " << usuarios[u]->getSeguidos()[i]->getNombre() << endl
			<< ".:" << usuarios[u]->getSeguidos()[i]->getPosts()[j]->getTitulo() << ":." << endl
			<< "[" << usuarios[u]->getSeguidos()[i]->getPosts()[j]->getContenido() << "]" << endl
			<< "Likes: " << usuarios[u]->getSeguidos()[i]->getPosts()[j]->getLikes() << " Hates: " << usuarios[u]->getSeguidos()[i]->getPosts()[j]->getHates() << endl << endl;
			
			cout << "[COMENTARIOS]" << endl;
			for (int k=0; k < usuarios[u]->getSeguidos()[i]->getPosts()[j]->getComentarios().size();k++){
				cout << "De: " << usuarios[u]->getSeguidos()[i]->getPosts()[j]->getComentarios()[k]->getAutor() << endl
				<< "|" << usuarios[u]->getSeguidos()[i]->getPosts()[j]->getComentarios()[k]->getContenido() << "|"  << endl;
			}
			
			cout << "----------------------" << endl;
		}
	}
	
	int opcion;
	cout << "1. Crear Post" << endl
	<< "2. Comentar Post" << endl
	<< "3. Dar Like" << endl
	<< "4. Dar Hate" << endl
	<< "5. Seguir Usuario" << endl
	<< "6. Dejar de Seguir a un Usuario" << endl
	<< "7. Cerrar Sesión" << endl
	<< "Ingrese opcion: "; cin >> opcion;
	cout << endl;
	
	return opcion; 
}
void crearPost(){
	string titulo,contenido;
	cout << "Ingrese título del post: "; cin >> titulo;
	cout << "Ingresa contenido: "; 
	getline(cin,contenido);
	getline(cin,contenido);
	

	usuarios[u]->getPosts().push_back(new Post(titulo,contenido));
	cout << endl << "Post añadido con exito" << endl << endl;
}
void comentarPost(){
	vector<Post*> posts;
	for(int i=0;i<usuarios[u]->getSeguidos().size();i++){
		for (int j=0; j<usuarios[u]->getSeguidos()[i]->getPosts().size();j++){
			posts.push_back(usuarios[u]->getSeguidos()[i]->getPosts()[j]);
		}
	}
	
	if (posts.size()==0){
		cout << "No hay posts para comentar :(" << endl << endl;
	} else {
		int opcion;
		string contenido;
		cout << "Ingrese el # del post de su feed a comentar: "; cin >> opcion;
		cout << "Ingrese contenido: "; cin >> contenido;
		cout << endl;
		
		if (opcion < 0 || opcion >= posts.size()){
			cout << "Este post no existe" << endl << endl;
		} else {
			posts[opcion]->getComentarios().push_back(new Comentario(usuarios[u]->getNombre(),contenido));
		}
	}		
	
}
void darLike(){
	vector<Post*> posts;
	for(int i=0;i<usuarios[u]->getSeguidos().size();i++){
		for (int j=0; j<usuarios[u]->getSeguidos()[i]->getPosts().size();j++){
			posts.push_back(usuarios[u]->getSeguidos()[i]->getPosts()[j]);
		}
	}
	
	if (posts.size()==0){
		cout << "No hay posts para likear :(" << endl << endl;
	} else{
		int opcion;
		cout << "Ingrese el # del post de su feed a comentar: "; cin >> opcion;
		cout << endl;
			
		if (opcion < 0 || opcion >= posts.size()){
			cout << "Este post no existe" << endl << endl;
		} else {
			posts[opcion]->aumentarLikes();
		}
		
	}
}
void seguirUsuario(){
	if (usuarios.size()==1){
		cout << "Solo tu estas en la platadorma :( no hay a quien seguir." << endl << endl;
	} else {
		int opcion;
		for(int i=0;i<usuarios.size();i++){
			cout << (i+1) << ". Nombre: " << usuarios[i]->getNombre() << ", Nombre de usuario: " << usuarios[i]->getNombreUsuario() << endl;
		}
		cout << "Selecciona usuario a seguir: "; cin >> opcion;
		cout << endl;
		opcion--;
		if (opcion==u){
			cout << "No te puedes seguir a ti mismo..." << endl << endl;
		} else{
			bool following = true;
			for (int i=0; i < usuarios[u]->getSeguidos().size();i++){
				if(*usuarios[opcion] == usuarios[u]->getSeguidos()[i]){
					cout << "Ya estas siguiendo a este usuario!" << endl << endl;
					following = false;
					break;
				}
			}
			if (following){
				usuarios[u]->getSeguidos().push_back(usuarios[opcion]);
				cout << "Ahora sigues a " << usuarios[opcion]->getNombre() << "!" << endl << endl;
			}
		}
	}
}
void unfollowUsuario(){
	if (usuarios[u]->getSeguidos().size() == 0){
		cout << "No sigues a nadie..." << endl << endl;
	} else {
		int opcion;
		for(int i=0;i<usuarios.size();i++){
			cout << (i+1) << ". Nombre: " << usuarios[i]->getNombre() << ", Nombre de usuario: " << usuarios[i]->getNombreUsuario() << endl;
		}
		cout << "Selecciona usuario para dejar de seguirlo: "; cin >> opcion;
		cout << endl;
		opcion--;
		
		usuarios[u]->getSeguidos()[opcion] = NULL;
		delete usuarios[u]->getSeguidos()[opcion];
		usuarios[u]->getSeguidos().erase(usuarios[u]->getSeguidos().begin() + opcion);
		cout << "Ya no sigues a este usuario!" << endl << endl;
	}
}
