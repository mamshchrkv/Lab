#include "Polinom.h"
#include "Line.h"
#include "Sequence.h"
#include <iostream>
#include <complex>
#define CIN_FLUSH if (std::cin.peek()) std::cin.ignore()
const std::string MSG[] = { "0.EXIT  \n", "1. SumP  \n", "2. multiplicationP  \n" , "3. ScalarP  \n" , "4. ValueP  \n","5. SumL  \n", "6. ScalarL  \n", "7. ValueL  \n", "8. CompositionP  \n","9. SubL \n"  };
const int SMSG = 10;
int getmenu() {
    std::string error = "\n";
    int ch = 0;
    do {
        std::cout << error;
        error = "You're wrong. Try again!\n";
        for (int i = 0; i < SMSG; i++) {
            std::cout << MSG[i];
        }
        puts("Make your choice: \n");
        ch = getchar() - '0';
        while (getchar() != '\n') {}
    } while (ch < 0 || ch > SMSG);

    return ch;
}
int main(){
    int turn = 1;
    int res = 0;
    while(turn) {
        res = getmenu();
        switch(res) {
            case 0:{
                std::cout << "Goodbye";
                turn  = 0;
                CIN_FLUSH;
                break;
            }
            case 1:{
                std::cout <<"Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch(choose){
                    case 1:{
                        int n;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P2(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<double> P3 = P1 + P2;
                        std::cout << "Result factors: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P2(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<std::complex<double>> P3 = P1 + P2;
                        std::cout << "Result factors: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;}
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                }
                break;
            }
            case 2:{
                std::cout <<"Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P1(n+1);
                        std::cout<< "Enter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P2(n+1);
                        std::cout<< "Enter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<double> P3 = P1 * P2;
                        std::cout << "Result factors: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P1(n+1);
                        std::cout<< "Enter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P2(n+1);
                        std::cout<< "Enter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<std::complex<double>> P3 = P1 * P2;
                        std::cout << "Result factors: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;}
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                }
                break;
            }
            case 3:{
                std::cout <<"Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n;
                        double a;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<double> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        P1 *= a;
                        std::cout << "Result: " << P1 <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::complex<double> a;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Polinomial<std::complex<double>> P1(n+1);
                        std::cout<< "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        P1 *= a;
                        std::cout << "Result: " << P1 <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                }
                break;
            }
            case 4: {
                std::cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1: {
                        int n;
                        double a;
                        std::cout << "Enter degree\n";
                        std::cin >> n;
                        Polinomial<double> P1(n + 1);
                        std::cout << "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout << "Enter scalar\n";
                        std::cin >> a;
                        double c=P1.value(a);
                        std::cout << "Result: " << c << "\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2: {
                        int n;
                        std::complex<double> a;
                        std::cout << "Enter degree\n";
                        std::cin >> n;
                        Polinomial<std::complex<double>> P1(n + 1);
                        std::cout << "Entter Polinomial\n";
                        std::cin >> P1;
                        std::cout << "Enter scalar\n";
                        std::cin >> a;
                        std::complex<double> c = P1.value(a);
                        std::cout << "Result: " << c << "\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    default: {
                        std::cout << "Incorrect choose";
                        CIN_FLUSH;
                        break; }
                }
                break;
            }
            case 8:{
                std::cout <<"Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n1,n2;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n1;
                        Polinomial<double> P1(n1+1);
                        std::cout<< "Enter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n2;
                        Polinomial<double> P2(n2+1);
                        std::cout<< "Enter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<double> c = P1.composition(P2);
                        std::cout << "Result factors: " << c <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n1, n2;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n1;
                        Polinomial<std::complex<double>> P1(n1+1);
                        std::cout<< "Enter Polinomial\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n2;
                        Polinomial<std::complex<double>> P2(n1+1);
                        std::cout<< "Enter Polinomial\n";
                        std::cin >> P2;
                        Polinomial<std::complex<double>> c = P1.composition(P2);
                        std::cout << "Result factors: " << c <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                }
                break;
            }
            case 5:{
                std::cout <<"Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch(choose){
                    case 1:{
                        int n;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<double> P1(n);
                        std::cout<< "Entter Linefom\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Lineform<double> P2(n);
                        std::cout<< "Entter Linefom\n";
                        std::cin >> P2;
                        Lineform<double> P3 = P1 + P2;
                        std::cout << "Result factors: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<std::complex<double>> P1(n);
                        std::cout<< "Entter Linefom\n";
                        std::cin >> P1;
                        std::cout<< "Enter degree\n";
                        std:: cin >> n;
                        Lineform<std::complex<double>> P2(n);
                        std::cout<< "Entter Linefom\n";
                        std::cin >> P2;
                        Lineform<std::complex<double>> P3 = P1 + P2;
                        std::cout << "Result factors: " << P3 <<"\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;}
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                }
                break;
            }
            case 6:{
                std::cout <<"Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n;
                        double a;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<double> P1(n);
                        std::cout<< "Entter Lineform\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        P1 *= a;
                        std::cout << "Result factors: " << P1 <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::complex<double> a;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<std::complex<double>> P1(n);
                        std::cout<< "Entter Lineform\n";
                        std::cin >> P1;
                        std::cout<< "Enter scalar\n";
                        std:: cin >> a;
                        P1 *= a;
                        std::cout << "Result factors: " << P1 <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                }
                break;
            }
            case 7:{
                std::cout <<"Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose)
                {
                    case 1:{
                        int n;
                        double a,b;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<double> P1(n);
                        std::cout<< "Entter Lineform\n";
                        std::cin >> P1;
                        std::cout<< "Enter vector\n";
                        Lineform<double> P2(n);
                        std:: cin >> P2;
                        b = P1.value(P2);
                        std::cout << "Result factors: " << b <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2:{
                        int n;
                        std::complex<double> a,b;
                        std::cout<< "Enter dimension\n";
                        std:: cin >> n;
                        Lineform<std::complex<double>> P1(n);
                        std::cout<< "Entter Lineform\n";
                        std::cin >> P1;
                        std::cout<< "Enter vector\n";
                        Lineform<std::complex<double>> P2(n);
                        std:: cin >> P2;
                        b = P1.value(P2);
                        std::cout << "Result: " << b <<"\n";
                        P1.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    default:{
                        std::cout<<"Incorrect choose";
                        CIN_FLUSH;
                        break;}
                }
                break;
            }
            case 9: {
                std::cout << "Choose type:\n 1.Double\n 2.Complex\n";
                int choose;
                std::cin >> choose;
                switch (choose) {
                    case 1: {
                        int n;
                        std::cout << "Enter dimension\n";
                        std::cin >> n;
                        Lineform<double> P1(n);
                        std::cout << "Entter Linefom\n";
                        std::cin >> P1;
                        std::cout << "Enter degree\n";
                        std::cin >> n;
                        Lineform<double> P2(n);
                        std::cout << "Entter Linefom\n";
                        std::cin >> P2;
                        Lineform<double> P3 = P1 - P2;
                        std::cout << "Result factors: " << P3 << "\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break;
                    }
                    case 2: {
                        int n;
                        std::cout << "Enter dimension\n";
                        std::cin >> n;
                        Lineform<std::complex<double>> P1(n);
                        std::cout << "Entter Linefom\n";
                        std::cin >> P1;
                        std::cout << "Enter degree\n";
                        std::cin >> n;
                        Lineform<std::complex<double>> P2(n);
                        std::cout << "Entter Linefom\n";
                        std::cin >> P2;
                        Lineform<std::complex<double>> P3 = P1 - P2;
                        std::cout << "Result factors: " << P3 << "\n";
                        P1.Delete();
                        P2.Delete();
                        P3.Delete();
                        CIN_FLUSH;
                        break; }
                    default: {
                        std::cout << "Incorrect choose";
                        CIN_FLUSH;
                        break; }
                }
                break;
            }
        }
    }
    return 0;
}