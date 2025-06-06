#include <iostream>
using  namespace std;

class angka{
    private:
    int *arr;
    int panjang;
public:
    angka(int); //constructor
    ~angka(); //destrctor
    void cetakData();
    void isiData();
};
//definisi member function
angka::angka(int i){
    panjang = i;
    arr = new int[i];
    isiData();
}

angka::~angka(){
    cout << endl;
    cetakData();
    delete[]arr;
    cout << "Alamat Array Sudah Dilepaskan" << endl;
}

void angka::cetakData(){
    for(int i=1; i <= panjang; i++){
        cout << i << " = " << arr[i] << endl;
    }
}

void angka::isiData(){
    for(int i=1; i<=panjang; i++){
        cout << i << " = ";cin >> arr[i];
    }
    cout << endl;
}

int main() {
angka belajarCPP(3); // Constructor Dipanggil
angka *ptrBelajarCPP = new angka(5); // Constructor Dipanggil
delete ptrBelajarCPP; // Destructor Dipanggil

return 0;
} // Destructor Dipanggil