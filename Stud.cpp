#include "Stud.h"
#include "Mylib.h"

void input(Stud &Local, int n){
    cout<<"Input Name: ";
    cin >> Local.name;
    cout <<"Surname: ";
    cin >> Local.surname;
    cout << n << " homework results: ";
    int temp;
    for (int i = 0; i < n; i++)
    {
        cin >> temp;
        Local.nd.push_back(temp);
    }
    cout << "Exam: ";
    cin >> Local.egz;
}

void inputRandom(Stud &Local, int n){
    cout<<"Input Name: ";
    cin >> Local.name;
    cout <<"Surname: ";
    cin >> Local.surname;

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist10(1,10);

    for (int i = 0; i < n; i++)
        Local.nd.push_back(dist10(rng));
    Local.egz = dist10(rng);
}

void empty(Stud &Local){
    Local.name.clear();
    Local.surname.clear();
    Local.nd.clear();
}

double averageResult(vector<int> nd, int egz){
    int sum=0;
    for (auto &i : nd)
        sum+=i;
    return sum/nd.size()*0.4+egz*0.6;
}

double medianResult(vector<int> nd, int egz){
    std::sort(nd.begin(), nd.end());
    int n = nd.size();
    if (n % 2 == 0) 
        return ((nd[n / 2 - 1] + nd[n / 2]) / 2)*0.4+egz*0.6;
    else return nd[n / 2]*0.4+egz*0.6;
}

void output(vector<Stud> vec, string method){
    cout << std::left << "Vardas" << setw(15) << "Pavarde" << setw(15) << "Galutinis ("<< method <<")\n";
    cout << "------------------------------------------------------------\n";    
    if(method == "Vid."){
        for (auto &&Stud : vec)
            cout << std::left << Stud.name << setw(15) << Stud.surname << setw(15) << std::fixed 
            << std::setprecision(2) << averageResult(Stud.nd, Stud.egz) <<"\n";
    }
    else{
        for (auto &&Stud : vec)
            cout << std::left << Stud.name << setw(15) << Stud.surname << setw(15) << std::fixed 
            << std::setprecision(2) << medianResult(Stud.nd, Stud.egz) << "\n";
    }
}