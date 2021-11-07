#pragma once
template<typename T>
T* makeSeq(int dimension) {
    srand(500);
    T* memory = new T[dimension];
    for (int i = 0; i < dimension; i++) {
        memory[i] = rand() % 100;
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
T* makeSortedSequence(int dimension) {
    T* memory = new T[dimension];
    for (int i = 0; i < dimension; i++) {
        memory[i] = dimension - i;
    }
    return memory;
}
template<typename T>
T* makeEqualSequence(int dimension) {
    T* memory = new T[dimension];
    for (int i = 0; i < dimension; i++) {
        memory[i] = 4;
    }
    return memory;
}