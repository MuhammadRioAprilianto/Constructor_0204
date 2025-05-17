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
    friend class admin;
};

class peminjam
{
    private:
    string nama;
    string ID;
    int totalPinjam;
    public:
    peminjam(string n, string i):nama(n), ID(i), totalPinjam(0){}
    friend class petugas;
    friend class admin;
};

class petugas
{
    private:
    string nama;
    string idPetugas;
    string levelAkses;
    public:
    petugas(string n, string i, string la):nama(n), idPetugas(i), levelAkses(la){}

    void peminjaman(buku& b, peminjam& p)
    {
        if(!b.dipinjam) //menandakan buku sedang tidak dipinjam
        {
            b.dipinjam = true;
            p.totalPinjam++;
            cout << "Buku dapat dipinjam oleh : " << p.nama << endl;
        }
        else
        {
            b.dipinjam = false;
            cout << "Buku sedang dipinjam" << endl;
        }
    }

    void pengembalian(buku& b, peminjam& p)
    {
        if(b.dipinjam)
        {
            b.dipinjam = false;
            p.totalPinjam--;
            cout << "buku sudah dikembalikan" << endl;
        }
        else
        {
            cout << "buku sedang tidak dipinjam" << endl;
        }
    }

    friend class admin;
};

class admin
{
    public:
    void lihatStatistikPeminjam(const peminjam& p)
    {
        cout << "Statistik Data Peminjam : " << endl;
        cout << "-Nama Peminjam : " << p.nama << endl;
        cout << "-ID Peminjam : " << p.ID << endl;
        cout << "-Jumlah buku yang dipinjam : " << p.totalPinjam << endl;
    }
    void lihatStatistikBuku(const buku& b)
    {
        cout << "Statistik Data Buku : " << endl;
        cout << "-Judul Buku : " << b.judul << endl;
        cout << "-Penulis Buku : " << b.penulis << endl;
        cout << "-Status Buku : " << (b.dipinjam ? "Dipinjam" : "Tersedia") << endl; 
    }
    void ubahLevelPetugas(petugas& p, string levelBaru)
    {
        p.levelAkses = levelBaru;
        cout << "Nama Petugas : " << p.nama << endl;
        cout << "ID Petugas : " << p.idPetugas << endl;
        cout << "Akses Level : " << p.nama << " diubah menjadi : " << levelBaru << endl;
    }
};

int main() {
    buku buku("Cara Berbisnis Agama", "Rifal Ardi Al-Tegalli");
    peminjam peminjam("Gibran Saputra", "BT001");
    petugas petugas("Joni", "PT001", "Biasa");
    admin admin;

    petugas.peminjaman(buku, peminjam);
    admin.lihatStatistikPeminjam(peminjam);
    petugas.pengembalian(buku, peminjam);
    admin.ubahLevelPetugas(petugas, "Senior");
    admin.lihatStatistikPeminjam(peminjam);
    admin.lihatStatistikBuku(buku);

    return 0;
}