/*
 * File:   Cola-vector.h
 * Author: dserrano
 *
 * Created on 11 de marzo de 2013, 19:24
 */

#ifndef COLA_VECTOR_H
#define	COLA_VECTOR_H

#include "Excepciones.h"

/**
 Implementación del TAD Cola utilizando una lista enlazada.
 
 Las operaciones son:
 
 - ColaVacia: -> Cola. Generadora implementada en el
 constructor sin parámetros.
 - PonDetras: Cola, Elem -> Cola. Generadora
 - quitaPrim: Cola - -> Cola. Modificadora parcial.
 - primero: Cola - -> Elem. Observadora parcial.
 - esVacia: Cola -> Bool. Observadora.
 - numElems: Cola -> Entero. Observadora.
 */
template <class T>
class ColaVector {
    private:
        T *_v;
        int _cero;
        int _ultimo;
        
    public:
        ColaVector() : _cero(0), _ultimo(0), _v(NULL) {}
        
        ~ColaVector() {
            libera();
        }
        
        /**
         Añade un elemento en la parte trasera de la cola.
         Operación generadora.
         
         @param elem Elemento a añadir.
         */
        void ponDetras(const T &elem) {
            if (_v == NULL) {
                _v = new T[2];
            }
            
            if (_v)
                
                _v[_ultimo] = elem;
            
            _ultimo++;
        }
        
        /**
         Elimina el primer elemento de la cola.
         Operación modificadora parcial, que falla si
         la cola está vacía.
         
         quitaPrim(PonDetras(elem, ColaVacia)) = ColaVacia
         quitaPrim(PonDetras(elem, xs)) = PonDetras(elem, quitaPrim(xs)) si !esVacia(xs)
         error: quitaPrim(ColaVacia)
         */
        void quitaPrim() {
            if (esVacia()) {
                throw EColaVacia();
            }
            
            _cero++;
        }
        
        /**
         Devuelve el primer elemento de la cola. Operación
         observadora parcial, que falla si la cola está vacía.
         
         primero(PonDetras(elem, ColaVacia)) = elem
         primero(PonDetras(elem, xs)) = primero(xs) si !esVacia(xs)
         error: primero(ColaVacia)
         
         @return El primer elemento de la cola.
         */
        const T &primero() const {
            if (esVacia())
                throw EColaVacia();
            
            return _v[_cero];
        }
        
        /**
         Devuelve true si la cola no tiene ningún elemento.
         
         esVacia(Cola) = true
         esVacia(PonDetras(elem, p)) = false
         
         @return true si la cola no tiene ningún elemento.
         */
        bool esVacia() const {
            return ((_ultimo - _cero) <= 0);
        }
        
        /**
         Devuelve el número de elementos que hay en la
         cola.
         numElems(ColaVacia) = 0
         numElems(PonDetras(elem, p)) = 1 + numElems(p)
         
         @return Número de elementos.
         */
        int numElems() const {
            return (_ultimo - _cero);
        }
        
        // //
        // MÉTODOS DE "FONTANERÍA" DE C++ QUE HACEN VERSÁTIL
        // A LA CLASE
        // //
        
        /** Constructor copia */
        ColaVector(const ColaVector<T> &other) : _cero(0) {
            _ultimo = other.numElems() + 1;
            copia(other);
        }
        
        /** Operador de asignación */
        ColaVector<T> &operator=(const ColaVector<T> &other) {
            if (this != &other) {
                libera();
                copia(other);
            }
            
            return *this;
        }
        
        /** Operador de comparación. */
        bool operator==(const ColaVector<T> &other) const {
            bool resultado = true;
            
            
            if ( numElems() != other.numElems() ) {
                resultado = false;
            }
            
            T elemento = _v[_cero];
            T elementoOther = other.primero();
            
            int i = 1;
            
            do {
                if (elemento != elementoOther) {
                    resultado = false;
                }
                
                elemento = _v[i];
                elementoOther = *( &(other.primero())+1 );
                
                i++;
                
            } while( resultado && (i < other.numElems()) );
            
            return resultado;
        }
        
        bool operator!=(const ColaVector<T> &other) const {
            return !(*this == other);
        }
        
    protected:
        
        void libera() {
            delete []_v;
        }
        
        void copia(const ColaVector &other) {
            
            ColaVector o = other;
            
            if (other.esVacia()) {
                _cero = _ultimo = 0;
            } else {
                
                for (int i = 0; i < other.numElems(); i++) {
                    _v[_cero + i] = o.primero();
                    o.quitaPrim();
                }
            }
        }
};

#endif	/* COLA_VECTOR_H */

