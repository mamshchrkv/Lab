#ifndef Polinomial_h
#define Polinomial_h
#include "Sequence.h"

template<typename T>
class Polinomial {
public:
    Polinomial<T>(int size) {
        data = ArraySequence<T>(size);
        for (int i = 0; i < GetSize(); i++) {
            Set(i, T(0));
        }
    }
    Polinomial<T>(const Polinomial<T>& polinom) {
        data = ArraySequence<T>(polinom.data);
    }
    int GetSize() {
        return data.GetLength();
    }
    void Delete() {
        data.Delete();
    }



    static Polinomial<T> sum(Polinomial<T> P1, Polinomial<T> P2) {
        Polinomial<T> P3 = Polinomial<T>(std::max(P1.GetSize(), P2.GetSize()));
        if (P1.GetSize() >= P2.GetSize()) {
            for (int i = 0; i < P2.GetSize(); i++) {
                P3.Set(i, P1.Get(i) + P2.Get(i));
            }
            for (int i = P2.GetSize(); i < P1.GetSize(); i++) {
                P3.Set(i, P1.Get(i));
            }
        }
        else {
            for (int i = 0; i < P1.GetSize(); i++) {
                P3.Set(i, P1.Get(i) + P2.Get(i));
            }
            for (int i = P1.GetSize(); i < P2.GetSize(); i++) {
                P3.Set(i, P2.Get(i));
            }
        }
        return P3;
    }
    static Polinomial<T> sub(Polinomial<T> P1, Polinomial<T> P2) {
        Polinomial<T> P3 = Polinomial<T>(std::max(P1.GetSize(), P2.GetSize()));
        if (P1.GetSize() >= P2.GetSize()) {
            for (int i = 0; i < P2.GetSize(); i++) {
                P3.Set(i, P1.Get(i) - P2.Get(i));
            }
            for (int i = P2.GetSize(); i < P1.GetSize(); i++) {
                P3.Set(i, P1.Get(i));
            }
        }
        else {
            for (int i = 0; i < P1.GetSize(); i++) {
                P3.Set(i, P1.Get(i) - P2.Get(i));
            }
            for (int i = P1.GetSize(); i < P2.GetSize(); i++) {
                P3.Set(i, P2.Get(i));
            }
        }
        return P3;
    }
    static Polinomial<T> multiplication(Polinomial<T> P1, Polinomial<T> P2) {
        Polinomial<T> P3 = Polinomial<T>(P1.GetSize() + P2.GetSize() - 1);
        for (int i = 0; i < P3.GetSize(); i++) {
            P3.Set(i, 0);
        }
        for (int i = 0; i < P1.GetSize(); i++) {
            for (int j = 0; j < P2.GetSize(); j++) {
                P3.Set(i + j, P3.Get(i + j) + P1.Get(i) * P2.Get(j));
            }
        }
        return P3;
    }
    static void scalar(Polinomial<T>& P1, T a) {
        for (int i = 0; i < P1.GetSize(); i++) {
            P1.Set(i, P1.Get(i) * a);
        }
    }
    static int compare(Polinomial<T> P1, Polinomial<T> P2) {
        if (P1.GetSize() == P2.GetSize()) {
            for (int i = 0; i < P1.GetSize(); i++) {
                if (std::abs(P1.Get(i) - P2.Get(i))>0.000001) {
                    return 0;
                }
            }
            return 1;
        }
        else return 0;
    }

    T value(T t) {
        T sum = 0;
        for (int i = GetSize() - 1; i >= 1; i--) {
            sum += Get(i);
            sum *= t;
        }
        sum += Get(0);
        return sum;
    }

    Polinomial<T> composition(Polinomial<T> t) {
        Polinomial<T> sum(1);
        sum.Set(0, 0);
        for (int i = GetSize() - 1; i >= 1; i--) {
            sum = sum + Get(i);
            sum = t * sum;
        }
        sum = sum + Get(0);
        return sum;
    }
    void Set(int i, T item) {
        data.Set(i, item);
    }
    T Get(int i) {
        return data.Get(i);
    }

private:
    ArraySequence<T> data;
};

template <typename T>
std::ostream& operator << (std::ostream& out, Polinomial<T> a) {
    for (int i = 0; i < a.GetSize() - 1; ++i) {
        out << a.Get(i)<< "X^" << i << "+ ";
    }
    out<< a.Get(a.GetSize() - 1)<< "X^"<< a.GetSize() - 1;
    return out;
}

template <typename T>
std::istream& operator >> (std::istream& in, Polinomial<T>& a) {
    T q;
    for (int i = 0; i < a.GetSize(); i++) {
        in >> q;
        a.Set(i, q);
    }
    return in;
}
template <typename T>
Polinomial<T> operator + (Polinomial<T> a, Polinomial<T> b) {
    return Polinomial<T>::sum(a, b);
}

template <typename T>
Polinomial<T> operator + (Polinomial<T> a, T b) {
    Polinomial<T> P(1);
    P.Set(0, b);
    return Polinomial<T>::sum(a, P);
}

template<typename T>
Polinomial<T> operator *= (Polinomial<T>& a, T& b) {
    Polinomial<T>::scalar(a, b);
    return a;
}


template<typename T>
Polinomial<T> operator * (Polinomial<T> a, Polinomial<T> b) {
    return Polinomial<T>::multiplication(a, b);
}

#endif
