#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
typedef int** matrix;

void pamiecNew(matrix& b, const int& m_, const int& n_)
{
    b = new int* [m_];
    for (int i = 0; i < m_; ++i)
        b[i] = new int[n_];
}

void pamiecDel(matrix& b, const int& m_, const int& n_)
{
    for (int i = 0; i < m_; ++i)
        delete []b[i];

    delete []b;
}
int wypelnij(matrix& b, const int& m_, const int& n_, const int& w)
{
    for (int i = 0; i < m_; ++i)
        for (int j = 0; j < n_; ++j)
            b[i][j] = w;
    return 0;
}
void wyswietl(const matrix& c, const int& m_, const int& n_)
{
    for (int i = 0; i < m_; ++i)
    {
        for (int j = 0; j < n_; ++j)
            cout<<"\t"<<c[i][j];
        cout << endl;
    }

}
void wypelnij_los(matrix& b, const int& m_, const int& n_, const int& minZ, const int& maxZ)
{
    int zakres = maxZ - minZ + 1;
    srand(time(NULL));
    for (int i = 0; i < m_; ++i)
        for (int j = 0; j < n_; ++j)
            b[i][j] = rand() % zakres + minZ;
}
void zapiszDoPliku(string nazwaPliku, const matrix& c, const int& m_, const int& n_)
{
    ofstream plik;
    plik.open(nazwaPliku.c_str());
    for (int i = 0; i < m_; ++i)
    {
        for (int j = 0; j < n_; ++j)
            plik << "\t" << c[i][j];
        plik << endl;
    }
    plik.close();
}
void wypelnij_los_sym(matrix& b, const int& m_, const int& n_, const int& startZ, const int& endZ)
{
    int zakres = endZ - startZ + 1;
    srand(time(NULL));
    for (int i = 0; i < m_; ++i)
        for (int j = i; j < n_; ++j)
            b[i][j] = b[j][i] = rand() % zakres + startZ;
}
bool czySymetryczna(const matrix& c, const int& m_, const int& n_)
{
    for (int i = 0; i < m_; ++i)
    {
        for (int j = i+1; j < n_; ++j)
            if(c[i][j]!=c[j][i])
                    return false;
    }
    return true;
 
}

void czytajZpliku(string nazwaPliku, matrix& b, const int& m_, const int& n_)
{
    ifstream plikA;
    plikA.open(nazwaPliku.c_str());
    for (int i = 0; i < m_; ++i)
        for (int j = 0; j < n_; ++j)
            plikA >> b[i][j];
    plikA.close();
}


void dodawanie_macierzy(const matrix& a, const matrix &b, const int & m_, const int &n_, matrix& wynik)
	{
		
		for (int i=0; i<m_; i++)
		{
			for(int j=0; j<n_; j++)
				wynik[i][j] = a[i][j] + b[i][j];
				
		}
	}

void odejmowanie_macierzy(const matrix& a, const matrix &b, const int & m_, const int &n_, matrix& wynik)
	{
		
		for (int i=0; i<m_; i++)
		{
			for(int j=0; j<n_; j++)
				wynik[i][j] = a[i][j] - b[i][j];
				
		}
	}


void mnozenie_macierzy(const matrix& a, const matrix &b, const int & mA, const int &nA, const int &nB, matrix& wynik)
	{
		
		for (int i=0; i<mA; i++)
		{
			for(int j=0; j<nB; j++)
				{
					wynik[i][j]=0;
						for(int k=0; k<nA; k++)
							wynik[i][j]+= a[i][k] * b[k][j];
				}
		}
		
	}

void transponowanie(const matrix&a, const int m_, const int n_, matrix& wynik)
{
	for(int i=0; i<m_; i++)
	for(int j=0; j<n_; j++)
	{
		wynik[j][i]=a[i][j];
	}
}


int main()
{


    //int m = 5;
    //int n = 5;
    //matrix A;
    //pamiecNew(A, m, n);
    //wypelnij(A, m, n, 7);
    //wypelnij_los(A, m, n,50,100);
    //wypelnij_los_sym(A, m, n,50,100);
    //wyswietl(A, m,n);
    
	
	cout<< "---------------macierz A-------------" <<endl;
	int mA=4;
	int nA=3;
	matrix A;
	pamiecNew(A, mA, nA);
	czytajZpliku("/home/piotr/Documents/VS_Code/C++/Metody_numeryczne/Macierze/macierzA.txt", A, mA, nA);
	wyswietl(A,mA,nA);



	cout<< "---------------macierz B-------------" <<endl;
	int mB=4;
	int nB=3;
	matrix B;
	pamiecNew(B, mB, nB);
	czytajZpliku("/home/piotr/Documents/VS_Code/C++/Metody_numeryczne/Macierze/macierzB.txt", B, mB, nB);
	wyswietl(B,mB,nB);



	cout<< "---------------macierz C-------------" <<endl;
	int mC=4;
	int nC=3;
	matrix C;
	pamiecNew(C, mC, nC);
	czytajZpliku("/home/piotr/Documents/VS_Code/C++/Metody_numeryczne/Macierze/macierzC.txt", C, mC, nC);
	wyswietl(C,mC,nC);



	cout<< "---------------macierz D-------------" <<endl;
	int mD=4;
	int nD=4;
	matrix D;
	pamiecNew(D, mD, nD);
	czytajZpliku("/home/piotr/Documents/VS_Code/C++/Metody_numeryczne/Macierze/macierzD.txt", D, mD, nD);
	wyswietl(D,mD,nD);



	cout<< "---------------macierz E-------------" <<endl;
	int mE=4;
	int nE=4;
	matrix E;
	pamiecNew(E, mE, nE);
	czytajZpliku("/home/piotr/Documents/VS_Code/C++/Metody_numeryczne/Macierze/macierzE.txt", E, mE, nE);
	wyswietl(E,mE,nE);

	
	
	cout<< "---------------macierz F-------------" <<endl;
	int mF=4;
	int nF=1;
	matrix F;
	pamiecNew(F, mF, nF);
	czytajZpliku("/home/piotr/Documents/VS_Code/C++/Metody_numeryczne/Macierze/macierzF.txt", F, mF, nF);
	wyswietl(F,mF,nF);

	
//		cout<< "---------------macierz W1_1-------------" <<endl;
	int mW1_1=4;
	int nW1_1=3;
	matrix W1_1;
	pamiecNew(W1_1, mW1_1, nW1_1);
//	
		cout<< "---------------macierz W1-------------" <<endl;
	int mW1=4;
	int nW1=3;
	matrix W1;
	pamiecNew(W1, mW1, nW1);
	//wyswietl(W1,mW1,nW1);
	dodawanie_macierzy(A, B, 4, 3, W1_1);
	odejmowanie_macierzy(W1_1, C, 4, 3 ,W1);
	wyswietl(W1, mW1, nW1);
	
	
	
zapiszDoPliku("L1a.txt", W1, mW1, nW1);


	//cout<< "[sprawdzenie macierzy pomocniczej]---------------macierz B(transponowana)-------------" <<endl;
	int nBT=4;
	int mBT=3;
	matrix BT;
	pamiecNew(BT, mBT, nBT);
	transponowanie(B,nBT, mBT, BT);
	wyswietl(BT, mBT, nBT);


		cout<< "---------------macierz W2-------------" <<endl;
	int mW2=4;
	int nW2=4;
	matrix W2;
	pamiecNew(W2, mW2, nW2);
	mnozenie_macierzy(A,BT, 4, 3, 4, W2);
	wyswietl(W2,mW2,nW2);
	zapiszDoPliku("L1b.txt", W2, mW2, nW2);

		cout<< "---------------macierz W3-------------" <<endl;
	int mW3=4;
	int nW3=4;
	matrix W3;
	pamiecNew(W3, mW3, nW3);
	mnozenie_macierzy(E,D, 4, 4, 4, W3);
	wyswietl(W3,mW3,nW3);
	zapiszDoPliku("L1c.txt", W3, mW3, nW3);

			cout<< "---------------macierz W6-------------" <<endl;
	int mW6=4;
	int nW6=1;
	matrix W6;
	pamiecNew(W6, mW6, nW6);
	mnozenie_macierzy(E,F, 4, 4, 4, W6);
	wyswietl(W6,mW6,nW6);
	zapiszDoPliku("L1f.txt", W6, mW6, nW6);



	




	
	pamiecDel(W1, mW1, nW1);
	pamiecDel(W1_1, mW1_1, nW1_1);
	pamiecDel(W2, mW2, nW2);
	pamiecDel(W3, mW3, nW3);
	pamiecDel(W6, mW6, nW6);
	pamiecDel(BT,mBT,nBT);
	pamiecDel(A, mA, nA);
	pamiecDel(B, mB, nB);
	pamiecDel(C, mC, nC);
	pamiecDel(D, mD, nD);
	pamiecDel(E, mE, nE);
	pamiecDel(F, mF, nF);
		return 0;
}











    //if (czySymetryczna(A, m, n))
    //    cout << "macierz symetryczna";
    //else
    //    cout << "macierz niesymetryczna";
    //cout << "wypelniono" << endl;
    //czytajZpliku()
	//zapiszDoPliku("test2.txt", A, m, n);
