#include <iostream>
#define TAM 50

class Alumno{
private:
    std::string nombre;
    std::string carrera;
    int materiasAprobadas;
    int promedio;

public:
    Alumno(){};
    friend std::ostream & operator<<(std::ostream &O, Alumno &x){
        O<<"\n Nombre: "<<x.nombre<<std::endl;
        O<<"\n Carrera: "<<x.carrera<<std::endl;
        O<<"\n Materias Aprobadas: "<<x.materiasAprobadas<<std::endl;
        O<<"\n Promedio: "<<x.promedio<<std::endl;
        return O;
    }
    friend std::istream & operator>>(std::istream &O, Alumno &x){
        std::cout<<"\n Nombre: ";
        O>>x.nombre;
        std::cout<<"\n Carrera: ";
        O>>x.carrera;
        std::cout<<"\n Materias Aprobadas: ";
        O>>x.materiasAprobadas;
        std::cout<<"\n Promedio: ";
        O>>x.promedio;
        return O;
    }
    bool operator==(Alumno &x){
        return (nombre==x.nombre && carrera==x.carrera && materiasAprobadas==x.materiasAprobadas && promedio==x.promedio);
    }
};

template<class T>
class Cola{
private:
    T datos[TAM];
    int ult;
    bool inserta(T , int);
    bool elimina(int);
    T recupera(int)const;
    int primero()const;
    int ultimo()const;
public:
    Cola():ult(-1){}
    bool vacia()const;
    bool llena()const;
    bool  Queue(T&);
    bool Dequeue();
    T Front()const;
    void imprime()const;
    int busqueda(T);

};

template<class T>
T Cola<T>::Front()const{
    T x=datos[primero()];
    return x;
}

template<class T>
bool Cola<T>::Dequeue(){
    if(vacia()){
        return false;
    }
    else{
        elimina(primero());
    }
    return true;
}

template<class T>
bool Cola<T>::Queue(T& elem){
    if(llena()){
        return false;
    }
    if(vacia()){
        inserta(elem,0);
    }
    else{
        inserta(elem, ultimo()+1);
    }
    return true;
}

template<class T>
void Cola<T>::imprime()const{
    if(!vacia()){
        for(int i=0; i<=ult; i++){
            Alumno x=datos[i];
            std::cout<<x<<std::endl;
        }
    }
}

template<class T>
bool Cola<T>::vacia()const{
    return ult==-1;
}

template<class T>
bool Cola<T>::llena()const{
    return ult==TAM-1;
}

template<class T>
int Cola<T>::busqueda(T elem){
    if(vacia()){
        std::cout<<"\n Lista se encuentra vacia\n\n";
        return -1;
    }
    for(int i=0;i<=ult;i++){
        if(datos[i]==elem){
            return i;
        }
    }
    std::cout<<"Alumno no encontrado"<<std::endl;
    return -1;
}

template<class T>
bool Cola<T>::inserta(T elem, int pos){
    if(llena() || pos<0 || pos>ult+1){
        std::cout<<"\n No se pudo insertar";
        return false;
    }
    int i=ult+1;
    while(i>pos){
        datos[i]=datos[i-1];
        i--;
    }
    datos[pos]=elem;
    ult++;
    return true;
}

template<class T>
bool Cola<T>::elimina(int pos){
    if(vacia() || pos<0 || pos>ult){
        std::cout<<"\n No se pudo eliminar";
        return false;
    }
    int i=pos;
    while(i<ult){
        datos[i]=datos[i+1];
        i++;
    }
    ult--;
    return true;
}

template<class T>
T Cola<T>::recupera(int pos)const{
    if(vacia() || pos<0 || pos>ult-1){
        std::cout<<"\n Insuficiencia de datos";
        //Manejar exceptions
    }
    else{
       return datos[pos];
    }
}

template<class T>
int Cola<T>::primero()const{
    if(vacia()){
       return -1;
    }
    return 0;
}

template<class T>
int Cola<T>::ultimo()const{
    if(vacia()){
       return -1;
    }
    return ult;
}

void menuPrincipal(){
    std::cout<<"1. Encolar alumno"<<std::endl;
    std::cout<<"2. Desencolar alumno"<<std::endl;
    std::cout<<"3. Mostrar cola"<<std::endl;
    std::cout<<"4. Buscar alumno"<<std::endl;
    std::cout<<"5. Salir"<<std::endl;
    std::cout<<"Opcion: ";
}

int main()
{
    Cola<Alumno> MiCola;
    Alumno x;
    int opt,i;
    do{
    system("cls");
    menuPrincipal();
    std::cin>>opt;
    switch(opt){
        case 1:
            std::cout<<"Encolando nuevo alumno"<<std::endl;
            std::cin>>x;
            MiCola.Queue(x);
            system("pause");
            break;
        case 2:
            if(MiCola.vacia()){
                std::cout<<"La cola se encuentra vacia\n\n";
                system("pause");
                break;}
            std::cout<<"Desencolando alumno. . ."<<std::endl;
            x=MiCola.Front();
            std::cout<<x<<std::endl<<std::endl;
            MiCola.Dequeue();
            std::cout<<"Alumno desacolado exitosamente."<<std::endl<<std::endl;
            system("pause");
            break;
        case 3:
            if(MiCola.vacia()){
                std::cout<<"La cola se encuentra vacia\n\n";
                system("pause");
                break;}
            std::cout<<"Mostrando cola:"<<std::endl;
            MiCola.imprime();
            system("pause");
            break;
        case 4:
            std::cout<<"Datos de alumno a buscar"<<std::endl;
            std::cin>>x;
            i=MiCola.busqueda(x);
            if(i==-1){
                system("pause");
                break;}
            std::cout<<"Turno: "<<i+1<<std::endl;
            system("pause");
            break;
        default:
            std::cout<<"Opcion invalida. . .";
    }
    }
    while(opt!=5);
    return 0;
}
