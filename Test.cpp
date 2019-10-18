#include <iostream>
#include <fstream> 
#include <ctime>
#include <cstddef>

typedef std::size_t mType;

void InputData(mType& n, mType& s, mType& e) 
{
	std::cout << "Enter the count of matrices." << std::endl;
	std::cin >> n;
	std::cout << "Enter the start point of marix elements." << std::endl;
	std::cin >> s;
	std::cout << "Enter the end point of matrix elements." << std::endl;
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

void Print(mType* M, mType& n)
{
	for (int i = 0; i < n; ++i) {
		std::cout << M[i] << " ";
	}
}

void genMatrixFile(const char* fName, mType* M, mType* N, mType& n, mType& s, mType& e)
{
	std::ofstream fr(fName, std::ios::out);
	if (fr.is_open()) {
		for (int i = 0; i < n; ++i) {
			fr << "#" << i + 1 << " " << M[i] << "x" << N[i] << std::endl;
			for (int j = 0; j < M[i]; ++j) {
				for (int k = 0; k < N[i]; ++k) {
					fr << rand() % e + s << " ";
				}
				fr << std::endl;
			}
		}
	}
	else {
		std::cerr << "Unable to open file!";
		exit(1);
	}
}

int main()
{
	mType n, s, e;
	InputData(n, s, e);
	mType *M = new mType[n];
	mType *N = new mType[n];
	mType *K = new mType[n];

	genSizes(M, N, K, n, s, e);
	genMatrixFile("A.txt", M, N, n, s, e);
	genMatrixFile("B.txt", M, N, n, s, e);
	genMatrixFile("C.txt", N, K, n, s, e);
	genMatrixFile("D.txt", N, K, n, s, e);

	//Print(M, n);
	
	std::cin.get();

	delete[] M;
	delete[] N;
	delete[] K;

	return 0;
}




