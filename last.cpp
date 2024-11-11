#include <iostream>
#include<string>
#include<windows.h>
#include<fstream>
#include<vector>
#include<algorithm>
#include <sstream>
using namespace std;
string Posledznach (const string& l, int n) {
    istringstream iss(l);
    vector<string> vect;
    string str;
 while (iss >> str) 
 {
        vect.push_back(str);
 }
 string result;
 size_t startIndex = (vect.size() > n) ? vect.size() - n : 0;
    for (size_t i = startIndex; i < vect.size(); ++i)
    {
        result += vect[i] + " "; 
    }

    return result; 
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    ofstream fout;
    ifstream fin;
    //fout.open("work.txt");
    //fout.close();

    fin.open("work.txt");
    int COUNT = 1;
    while (!fin.eof())
    {
        char a1;
        fin.get(a1);
        if (a1 == ' ')
        {
            COUNT++;
        }
    }
    fin.close();
    fin.open("work.txt");
    string line;
    int num =4 ; // Количество последних значений, которые нужно извлечь
    string itog;
    while (getline(fin, line)) 
    {
        itog = Posledznach(line, num); // Получаем последние значения
        cout << "Последние " << num << " значения: " << itog<< std::endl;
    }
    fin.close(); // Закрываем файл

    
    stringstream ss(itog);
    vector<int> v;

    copy(istream_iterator<int>(ss), {}, back_inserter(v));
    copy(begin(v), end(v), ostream_iterator<int>(cout, "\n"));
    int sum = 0;
    for (size_t i = 0; i < v.size(); i++)
    {
        
        sum += v[i];
        
    }
cout << sum;
  
}
