#include <iostream>
using namespace std;

void line()
{
    cout << "__________" << endl;
}
class HoaDon
{
private:
    int soCu;
    int soMoi;
    float chenhLech;
public:
    float getChenhLech() {
        return chenhLech;
    }
    void set_chenhLech(float cl);
    void input();
    float KLTieuThu();
    double ThanhTien();
};
void HoaDon::set_chenhLech(float cl)
{
    chenhLech = cl;
}
void HoaDon::input()
{
    cout << "nhap so moi: ";
    cin >> soMoi;
    cout << "nhap so cu: ";
    cin >> soCu;
}
float HoaDon::KLTieuThu()
{
    return soMoi - soCu;
}
double HoaDon::ThanhTien()
{
    return (double) 10094.947511 * (KLTieuThu() + chenhLech);
}
class DanhSachHoaDon
{
private:
    HoaDon *arr;
    int top;
public:
    DanhSachHoaDon()
    {
        arr = nullptr;
        top = -1;
    }
    friend void line();
    void input();
    void output();
    void freeSpace();
};
void DanhSachHoaDon::input()
{
    int n;
    float tempTong = 0;
    line();
    cout << "nhap so hoa don can chia: ";
    cin >> n;

    HoaDon hoaDonTong;
    line();
    cout << "nhap hoa don tong: " << endl;
    hoaDonTong.input();

    arr = new HoaDon[n];
    for (int i = 0; i < n; ++i)
    {
        line();
        cout << "nhap hoa don " << i + 1 << ": " << endl;
        arr[i].input();
        tempTong += arr[i].KLTieuThu();
        top++;
    }

    float chenhLech = (float) (hoaDonTong.KLTieuThu() - tempTong) / n;

    for (int i = 0; i < n; ++i)
    {
        arr[i].set_chenhLech(chenhLech);
    }

}
void DanhSachHoaDon::output()
{
    double sum = 0;
    line();
    for (int i = 0; i <= top; i++)
    {
        cout << "thanh tien (hoa don " << i + 1 << "): ";
        cout << arr[i].ThanhTien() << " vnd" << endl;
        sum += arr[i].ThanhTien();
    }
    cout << "tong: ";
    cout << sum << " vnd" << endl;
    cout << "chenh lech: " << arr[0].getChenhLech() + arr[1].getChenhLech() << endl;
}
void DanhSachHoaDon::freeSpace()
{
    delete[] arr;
}
int main()
{
    DanhSachHoaDon hd = DanhSachHoaDon();
    hd.input();
    hd.output();
    hd.freeSpace();
    return 0;
}