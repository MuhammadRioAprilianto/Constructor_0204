#include <iostream>
#include <string>
using namespace std;

class petugas;
class peminjam;
class admin;
class buku
{
    private:
    string judul;
    string penulis;
    bool dipinjam;
    public:
    buku(string j, string p):judul(j), penulis(p), dipinjam(false){}
    friend class petugas;
};

