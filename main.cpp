//
//  main.cpp
//  Ejercicio10t6
//
//  Created by Dani on 11/03/13.
//  Copyright (c) 2013 EDA. All rights reserved.
//

#include <iostream>
#include "ColaVector.h"

using namespace std;

int main(int argc, const char * argv[]) {
    ColaVector<int> b;
    ColaVector<int> a;
    
    cout << "rellenando colas" << endl;
    for(int i = 0; i < 5; i++) {
        b.ponDetras(i);
        a.ponDetras(i);
    }
    
    try {
        cout << "mostrando contenido" << endl;
        cout << "numElems: " << a.numElems() << endl;
        while ( a.numElems() > 0) {
            cout << a.primero();
            cout << b.primero() << endl;
            
            a.quitaPrim();
            b.quitaPrim();
        }
    } catch (EColaVacia e) {
        cout << e.msg() << endl;
    }
    
    cout << "son iguales sin elementos?" << endl;
    cout << (b == a) << endl;
    cout << (a == a) << endl;
     
    cout << "rellenando colas" << endl;
    for(int i = 0; i < 5; i++) {
        b.ponDetras(i);
        a.ponDetras(i);
    }
    
    cout << "son iguales con números?" << endl;
    cout << (b == a) << endl;
    cout << (a == a) << endl;
    
    try {
        
        cout << "mostrando contenido" << endl;
        cout << "numElems: " << a.numElems() << endl;
        while ( a.numElems() > 0) {
            cout << a.primero();
            cout << b.primero() << endl;
            
            a.quitaPrim();
            b.quitaPrim();
        }
    } catch (EColaVacia e) {
        cout << e.msg() << endl;
    }
    
    cout << "rellenando cola b" << endl;
    for(int i = 0; i < 5; i++) {
        b.ponDetras(i);
    }
    
    ColaVector<int> c(b);
    
    try {
        
        cout << "mostrando contenido" << endl;
        cout << "numElems: " << c.numElems() << endl;
        while ( c.numElems() > 0) {
            cout << c.primero();
            cout << b.primero() << endl;
            
            c.quitaPrim();
            b.quitaPrim();
        }
    } catch (EColaVacia e) {
        cout << e.msg() << endl;
    }
    
    return 0;
}

