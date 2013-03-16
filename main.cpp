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
    
    for(int i = 0; i < 5; i++) {
        b.ponDetras(i);
        a.ponDetras(i);
    }
    
    while ( a.numElems() <= 0) {
        cout << a.primero();
        cout << b.primero();
        
        a.quitaPrim();
        b.quitaPrim();
    }
    
    ColaVector<int> c(b);
    
    cout << (b == a) << endl;
    cout << (a == a) << endl;
    
    return 0;
}

