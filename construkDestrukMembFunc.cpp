#include <iostream>
using namespace std;

class Mahasiswa
{
    private:
        static int jmlmhs;
    public:
        string status;
        string nama;
        int nim;
        Mahasiswa(string pnama, int pnim){
            status = "Mahasiswa Baru ";
            nama = pnama;
            nim = pnim;
            cout << "Mahasiswa dibuat " << nama << endl;
            cout << "Status = " << status << endl;
            ++jmlmhs;
        };
        ~Mahasiswa(){
            cout << "Mahasiswa dengan nama " << nama << " Dihancurkan" << endl;
            --jmlmhs;
        };
        static int gettotalmhs(){
            
            return jmlmhs;
        }
};

int Mahasiswa :: jmlmhs = 0;

int main(){
    cout << "Jumlah Mahasiswa = " << Mahasiswa :: gettotalmhs() << endl;
    Mahasiswa mhs1("Rudi", 28);
    Mahasiswa mhs2("Joko", 73);
    mhs2.status = "Status baru = Mahasiswa uzur";
    cout << mhs2.status << endl;
    Mahasiswa mhs3("Wobo", 69);
    cout << "Jumlah Mahasiswa = " << Mahasiswa :: gettotalmhs() << endl;
        {
            Mahasiswa mhs4("Dewo", 98);
            cout << "Jumlah Mahasiswa dalam bracket = " << Mahasiswa :: gettotalmhs() << endl;
        }
    cout << "Jumlah Mahasiswa = " << Mahasiswa :: gettotalmhs() << endl;
    return 0;
}