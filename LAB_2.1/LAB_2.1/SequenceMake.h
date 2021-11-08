#pragma once
template<typename T>
T* makeSequenceRand(int dimension) {
    srand(500);
    T* memory = new T[dimension];
    for (int i = 0; i < dimension; i++) {
        memory[i] = rand() % 1000;
    }
    return memory;
}

template<typename T>
T* makeSequence(int dimension) {
    cout << "Fill the Sequence" << "\n";
    T* memory = new T[dimension];
    for (int i = 0; i < dimension; i++) {
        T el;
        cin >> el;
        memory[i] = el;
    }
    return memory;
}

template<typename T>
T* makeSequenceSortEnd(int dimension) {
    cout << "Fill the Sequence" << "\n";
    T* memory = new T[dimension];
    for (int i = 0; i < dimension; i++) {
        memory[i] = dimension - i;
    }
    return memory;
}

template<typename T>
T* makeSequenceSort(int dimension) {
    cout << "Fill the Sequence" << "\n";
    T* memory = new T[dimension];
    for (int i = 0; i < dimension; i++) {
        memory[i] = i;
    }
    return memory;
}
