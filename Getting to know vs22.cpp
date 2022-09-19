#include <iostream>
#include <fstream>

using namespace std;

int main() {

	setlocale(LC_ALL, "Russian");

	ifstream in("in.txt");

	int size1 = 0;
	int size2 = 0;
	int value = 0;

	in >> size1;

	int* arr = 0;

	if (size1 > 0) 
	{
		arr = new int[size1]();
		int count = 0;

		for (int i = 0; i < size1; ++i) 
		{
			in >> arr[i];
			++count;
		}
	}
	else 
	{
		cout << "Размер массива не должен быть равен нулю: " << endl;
	}

	in >> size2;
	int* arr2 = 0;
	if (size2 > 0) 
	{
		arr2 = new int[size2]();
		int count = 0;

		for (int i = 0; i < size2; ++i) 
		{
			++count;
			in >> arr2[i];
		}
	}
	else 
	{
		cout << "Размер массива не должен быть равен нулю: " << endl;
	}


	in.close();

	ofstream fout("out.txt");
	fout << size2 << endl;

	value = arr2[size2 - 1];
	fout << value << " ";

	for (int i = 0; i < size2 - 1; ++i) 
	{
		value = arr2[i];
		fout << value << " ";
	}

	fout << endl;

	fout << size1 << endl;

	for (int i = 1; i < size1; ++i) 
	{
		value = arr[i];
		fout << value << " ";
	}

	value = arr[0];
	fout << value << endl;

	fout.close();

	cout << "Запись файла прошла успешно." << endl;

	delete[] arr;
	delete[] arr2;
}