#include <iostream>
#include <ctime>
#include <cstddef>
#include <ctime>
#include <fstream>

//typedef std::size_t mType;
typedef int mType;

void InputData(mType& n, mType& s, mType& e)
{
	std::cout << "Enter the count of matrices." << std::endl;
	std::cin >> n;
	std::cout << "Enter the start range of matrix elements." << std::endl;
	std::cin >> s;
	std::cout << "Enter the end range of matrix elements." << std::endl;
	std::cin >> e;
}

void genSizes(mType* M, mType* N, mType* K, mType& n, mType& s, mType& e)
{
	srand(time(0));

	for (int i = 0; i < n; ++i) {
		M[i] = rand() % e + s;
		N[i] = rand() % e + s;
		K[i] = rand() % e + s;
	}
}


void genMatrix(const char* fName, mType* a, mType* b, mType& n, mType& s, mType& e)
{
	std::ofstream fr(fName, std::ios::out);
	if(!fr.is_open()) {
		std::cerr << "The file unable to open!";
		std::exit(1);
	} else {
		for (int i = 0; i < n; ++i) {
			fr << "#" << i + 1 << " " << a[i] << "x" << b[i] << std::endl;
			for (int j = 0; j < a[i]; ++j) {
				for(int k = 0; k < b[i]; ++k) {
					fr << rand() % e + s << " ";
				}
				fr << std::endl;
			}
		}
	}
}

void Delete(mType* m)
{
	delete[] m; 
}



int main()
{
	mType n, s, e;
	mType *M = new mType[n];
	mType *N = new mType[n];
	mType *K = new mType[n];
	
	InputData(n, s, e);
	genSizes(M, N, K, n, s, e);
	
	genMatrix("A.txt", M, N, n, s, e);
	genMatrix("B.txt", M, N, n, s, e);
	genMatrix("C.txt", N, K, n, s, e);
	genMatrix("D.txt", N, K, n, s, e);

	delete[] M;
	delete[] N;
	delete[] K;

//	Delete(M);
//	Delete(N);
//	Delete(K);
	
	return 0;
}

