#include <bits/stdc++.h>
using namespace std;

struct GiaoVien
{
    int magv, namsinh, snct;
    char tengv[250], gioitinh[250], sdt[250];
    double luong;
};

struct DNodeGV
{
    GiaoVien info;
    DNodeGV *next;
};

typedef struct ListGV
{
    DNodeGV *head;
    DNodeGV *tail;
} ListGV;

struct CTGD
{
    int magv, sotday;
    char tengv[250], monhoc[250], lopday[250], phonghoc[250];
};

struct DNodeCTGD
{
    CTGD info;
    DNodeCTGD *next;
};

typedef struct ListCTGD
{
    DNodeCTGD *head;
    DNodeCTGD *tail;
} ListCTGD;

void InitializeListGV(ListGV &list)
{
    list.head = list.tail = NULL;
}

void InitializeListCTGD(ListCTGD &list)
{
    list.head = list.tail = NULL;
}

// Thêm giảng viên vào danh sách
void InsertGV(ListGV &list, GiaoVien data)
{
    DNodeGV *newNode = new DNodeGV;
    newNode->info = data;
    newNode->next = nullptr;
    if (list.head == nullptr)
    {
        list.head = list.tail = newNode;
    }
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

// Thêm quản lý giảng dạy vào danh sách
void InsertCTGD(ListCTGD &list, CTGD data)
{
    DNodeCTGD *newNode = new DNodeCTGD;
    newNode->info = data;
    newNode->next = nullptr;
    if (list.head == nullptr)
    {
        list.head = list.tail = newNode;
    }
    else
    {
        list.tail->next = newNode;
        list.tail = newNode;
    }
}

// Hiển thị thông tin giảng viên
void PrintGV(GiaoVien gv)
{
    cout << left << setw(10) << gv.magv << "\t" << setw(20) << gv.tengv << "\t"
         << setw(10) << gv.namsinh << "\t" << setw(10) << gv.gioitinh << "\t"
         << setw(15) << gv.sdt << setw(10) << "\t" << gv.luong << endl;
}

// Hiển thị danh sách giảng viên
void PrintListGV(ListGV list)
{
    cout << left << setw(10) << "Mã GV" << "\t" << setw(20) << "Tên GV" << "\t"
         << setw(10) << "Năm sinh" << "\t" << setw(10) << "Giới tính" << "\t"
         << setw(15) << "SĐT" << "\t" << setw(10) << "Lương" << endl;
    DNodeGV *tmp = list.head;
    while (tmp != nullptr)
    {
        PrintGV(tmp->info);
        tmp = tmp->next;
    }
}

// Hiển thị thông tin giảng dạy
void PrintCTGD(CTGD ctgd)
{
    cout << left << setw(10) << ctgd.magv << "\t" << setw(20) << ctgd.tengv << "\t"
         << setw(20) << ctgd.monhoc << "\t" << setw(20) << ctgd.lopday << "\t"
         << setw(10) << ctgd.sotday << "\t" << setw(20) << ctgd.phonghoc << endl;
}

// Hiển thị danh sách giảng dạy
void PrintListCTGD(ListCTGD list)
{
    cout << left << setw(10) << "Mã GV" << "\t" << setw(20) << "Tên GV" << "\t"
         << setw(20) << "Môn học" << "\t" << setw(20) << "Lớp dạy" << "\t"
         << setw(10) << "Số tờ dạy" << "\t" << setw(20) << "Phòng học" << endl;
    DNodeCTGD *tmp = list.head;
    while (tmp != nullptr)
    {
        PrintCTGD(tmp->info);
        tmp = tmp->next;
    }
}

// Hàm đọc file giảng viên
void ReadFileGV(ListGV &list, const string &filename)
{
    ifstream file(filename, ios::binary);
    if (file.is_open())
    {
        int n;
        file.read((char *)&n, sizeof(int));
        for (int i = 0; i < n; i++)
        {
            GiaoVien gv;
            file.read((char *)&gv, sizeof(GiaoVien));
            InsertGV(list, gv);
        }
        file.close();
        cout << "Đọc file giảng viên thành công.\n";
    }
}

// Hàm ghi file giảng
void WriteFileGV(ListGV list, const string &filename)
{
    ofstream file(filename, ios::binary);
    if (file.is_open())
    {
        int n = 0;
        DNodeGV *tmp = list.head;
        while (tmp != nullptr)
        {
            n++;
            tmp = tmp->next;
        }
        file.write((char *)&n, sizeof(int));
        tmp = list.head;
        while (tmp != nullptr)
        {
            file.write((char *)&tmp->info, sizeof(GiaoVien));
            tmp = tmp->next;
        }
        file.close();
        cout << "Ghi file giảng viên thành công.\n";
    }
}

// Xóa giảng viên theo mã
void DeleteGV(ListGV &list, int magv)
{
    DNodeGV *tmp = list.head;
    DNodeGV *prev = nullptr;
    while (tmp != nullptr && tmp->info.magv != magv)
    {
        prev = tmp;
        tmp = tmp->next;
    }
    if (tmp == nullptr)
    {
        cout << "Không tìm thấy giảng viên.\n";
        return;
    }
    if (prev == nullptr)
    {
        list.head = tmp->next;
    }
    else
    {
        prev->next = tmp->next;
    }
    if (tmp == list.tail)
    {
        list.tail = prev;
    }
    delete tmp;
    cout << "Giảng viên đã được xóa.\n";
}

// Tìm kiếm giảng viên theo tên
DNodeGV *FindGVByName(ListGV &list, const string &name)
{
    DNodeGV *tmp = list.head;
    while (tmp != nullptr)
    {
        if (tmp->info.tengv == name)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return nullptr;
}

DNodeGV *FindGVByMaGV(ListGV &list, int magv)
{
    DNodeGV *tmp = list.head;
    while (tmp != nullptr)
    {
        if (tmp->info.magv == magv)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return nullptr;
}

// Sắp xếp giảng viên theo năm sinh
void SortGVByYear(ListGV &list)
{
    if (list.head == nullptr)
        return;

    bool check;
    do
    {
        check = false;
        DNodeGV *tmp = list.head;
        while (tmp->next != nullptr)
        {
            if (tmp->info.namsinh > tmp->next->info.namsinh)
            {
                swap(tmp->info, tmp->next->info);
                check = true;
            }
            tmp = tmp->next;
        }
    } while (check);
}

// Cập nhật thông tin giảng viên
void UpdateGV(ListGV &list, int magv, GiaoVien newGV)
{
    DNodeGV *tmp = list.head;
    while (tmp != nullptr)
    {
        if (tmp->info.magv == magv)
        {
            tmp->info = newGV;
            cout << "Thông tin giảng viên đã được cập nhật.\n";
            return;
        }
        tmp = tmp->next;
    }
    cout << "Giảng viên không tồn tại.\n";
}

// Hiển thị số lượng giảng viên
int CountGV(ListGV &list)
{
    int count = 0;
    DNodeGV *tmp = list.head;
    while (tmp != nullptr)
    {
        count++;
        tmp = tmp->next;
    }
    return count;
}

// Xóa ct giảng dạy theo mã
void DeleteCTGD(ListCTGD &list, int magv)
{
    DNodeCTGD *current = list.head;
    DNodeCTGD *prev = nullptr;
    while (current != nullptr && current->info.magv != magv)
    {
        prev = current;
        current = current->next;
    }
    if (current == nullptr)
    {
        cout << "Không tìm thấy giảng viên.\n";
        return;
    }
    if (prev == nullptr)
    {
        list.head = current->next;
    }
    else
    {
        prev->next = current->next;
    }
    if (current == list.tail)
    {
        list.tail = prev;
    }
    delete current;
    cout << "Giảng viên đã được xóa.\n";
}

// Tìm kiếm giảng dạy theo tên
DNodeCTGD *FindCTGDByName(ListCTGD &list, const string &name)
{
    DNodeCTGD *current = list.head;
    while (current != nullptr)
    {
        if (current->info.tengv == name)
        {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// Sắp xếp giảng dạy theo số tờ dạy
void SortCTGDByTods(ListCTGD &list)
{
    if (list.head == nullptr)
        return;

    bool swapped;
    do
    {
        swapped = false;
        DNodeCTGD *current = list.head;
        while (current->next != nullptr)
        {
            if (current->info.sotday > current->next->info.sotday)
            {
                swap(current->info, current->next->info);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

// Cập nhật thông tin giảng dạy
void UpdateCTGD(ListCTGD &list, int magv, CTGD newCTGD)
{
    DNodeCTGD *current = list.head;
    while (current != nullptr)
    {
        if (current->info.magv == magv)
        {
            current->info = newCTGD;
            cout << "Thông tin giảng viên đã được cập nhật.\n";
            return;
        }
        current = current->next;
    }
    cout << "Giảng viên không tồn tại.\n";
}

// Hienn thị số lượng giảng day
int CountCTGD(ListCTGD &list)
{
    int count = 0;
    DNodeCTGD *current = list.head;
    while (current != nullptr)
    {
        count++;
        current = current->next;
    }
    return count;
}

// đọc file giảng dạy
void ReadFileCTGD(ListCTGD &list, const string &filename)
{
    ifstream file(filename, ios::binary);
    if (file.is_open())
    {
        int n;
        file.read((char *)&n, sizeof(int));
        for (int i = 0; i < n; i++)
        {
            CTGD ctgd;
            file.read((char *)&ctgd, sizeof(CTGD));
            InsertCTGD(list, ctgd);
        }
        file.close();
        cout << "Đọc file giảng dạy thành công.\n";
    }
    else
    {
        cout << "Không thể mở file.\n";
    }
}

// Ghi file giảng dạy
void WriteFileCTGD(ListCTGD list, const string &filename)
{
    ofstream file(filename, ios::binary);
    if (file.is_open())
    {
        int n = 0;
        DNodeCTGD *tmp = list.head;
        while (tmp != nullptr)
        {
            n++;
            tmp = tmp->next;
        }
        file.write((char *)&n, sizeof(int));
        tmp = list.head;
        while (tmp != nullptr)
        {
            file.write((char *)&tmp->info, sizeof(CTGD));
            tmp = tmp->next;
        }
        file.close();
        cout << "Ghi file giảng dạy thành công.\n";
    }
    else
    {
        cout << "Không thể mở file.\n";
    }
}

//thêm chi tiết giảng dạy vào danh sách
CTGD NhapCTGD(ListCTGD &listCTGD, ListGV &listGV)
{
    CTGD ctgd;
    cout << "Nhập mã giảng viên: ";
    cin >> ctgd.magv;
    DNodeGV *gv = FindGVByMaGV(listGV, ctgd.magv);
    if(gv == nullptr){
        cout << "Không tìm thấy giảng viên.\n";
        return ctgd;
    }else{
        strcpy(ctgd.tengv, gv->info.tengv);
    }
    cout << "Nhập môn học: "; cin.ignore(); cin.getline(ctgd.monhoc, 250);
    cout << "Nhập lớp dạy: "; cin.getline(ctgd.lopday, 250);
    cout << "Nhập số tờ dạy: "; cin >> ctgd.sotday;
    cout << "Nhập phòng học: "; cin.ignore(); cin.getline(ctgd.phonghoc, 250);
    return ctgd;
}


// Menu quản lý chi tiết giảng dạy
void MenuCTGD(ListCTGD &listCTGD, ListGV &listGV)
{
    int choice;
    do
    {
        cout << "\nQuản lý chi tiết giảng dạy\n";
        cout << "1. Thêm chi tiết giảng dạy\n";
        cout << "2. Hiển thị danh sách giảng dạy\n";
        cout << "3. Đọc file giảng dạy\n";
        cout << "4. Ghi file giảng dạy\n";
        cout << "5. Xóa giảng viên theo mã\n";
        cout << "6. Tìm kiếm giảng viên theo tên\n";
        cout << "7. Sắp xếp giảng viên theo số tờ dạy\n";
        cout << "8. Cập nhật thông tin giảng dạy\n";
        cout << "9. Hiển thị số lượng giảng dạy\n";
        cout << "0. Quay lại menu chính\n";
        cout << "Lựa chọn: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            CTGD ctgd = NhapCTGD(listCTGD, listGV);
            InsertCTGD(listCTGD, ctgd);
            break;
        }
        case 2:
        {
            PrintListCTGD(listCTGD);
            break;
        }
        case 3:
        {
            ReadFileCTGD(listCTGD, "chitietgiangday.dat");
            break;
        }
        case 4:
        {
            WriteFileCTGD(listCTGD, "chitietgiangday.dat");
            break;
        }
        case 5:
        {
            int magv;
            cout << "Nhập mã giảng viên cần xóa: ";
            cin >> magv;
            DeleteCTGD(listCTGD, magv);
            break;
        }
        case 6:
        {
            string name;
            cout << "Nhập tên giảng viên cần tìm: ";
            cin.ignore();
            getline(cin, name);
            DNodeCTGD *result = FindCTGDByName(listCTGD, name);
            if (result)
            {
                PrintCTGD(result->info);
            }
            else
            {
                cout << "Không tìm thấy giảng viên.\n";
            }
            break;
        }
        case 7:
        {
            SortCTGDByTods(listCTGD);
            cout << "Danh sách giảng viên đã được sắp xếp theo số tờ dạy.\n";
            break;
        }
        case 8:
        {
            int magv;
            cout << "Nhập mã giảng viên cần cập nhật: ";
            cin >> magv;
            CTGD newCTGD;
            cout << "Nhập môn học mới: ";
            cin.ignore();
            cin.getline(newCTGD.monhoc, 250);
            cout << "Nhập lớp dạy mới: ";
            cin.getline(newCTGD.lopday, 250);
            cout << "Nhập số tờ dạy mới: ";
            cin >> newCTGD.sotday;
            UpdateCTGD(listCTGD, magv, newCTGD);
            break;
        }
        case 9:
        {
            int count = CountCTGD(listCTGD);
            cout << "Số lượng giảng viên: " << count << endl;
            break;
        }
        case 0:
        {
            cout << "Quay lại menu chính.\n";
            break;
        }
        default:
        {
            cout << "Lựa chọn không hợp lệ, vui lòng thử lại.\n";
            break;
        }
        }
    } while (choice != 0);
}

void MenuGiangVien(ListGV &listGV)
{
    int choice;
    do
    {
        cout << "\nQuản lý giảng viên\n";
        cout << "1. Thêm giảng viên\n";
        cout << "2. Hiển thị danh sách giảng viên\n";
        cout << "3. Đọc file giảng viên\n";
        cout << "4. Ghi file giảng viên\n";
        cout << "5. Xóa giảng viên theo mã\n";
        cout << "6. Tìm kiếm giảng viên theo tên\n";
        cout << "7. Sắp xếp giảng viên theo năm sinh\n";
        cout << "8. Cập nhật thông tin giảng viên\n";
        cout << "9. Hiển thị số lượng giảng viên\n";
        cout << "0. Quay lại menu chính\n";
        cout << "Lựa chọn: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            GiaoVien gv;
            cout << "Nhập mã giảng viên: ";
            cin >> gv.magv;
            cin.ignore();
            cout << "Nhập tên giảng viên: ";
            cin.getline(gv.tengv, 250);
            cout << "Nhập năm sinh: ";
            cin >> gv.namsinh;
            cin.ignore();
            cout << "Nhập giới tính: ";
            cin.getline(gv.gioitinh, 250);
            cout << "Nhập số điện thoại: ";
            cin.getline(gv.sdt, 250);
            cout << "Nhập lương: ";
            cin >> gv.luong;
            InsertGV(listGV, gv);
            break;
        }
        case 2:
        {
            PrintListGV(listGV);
            break;
        }
        case 3:
        {
            ReadFileGV(listGV, "giangvien.dat");
            break;
        }
        case 4:
        {
            WriteFileGV(listGV, "giangvien.dat");
            break;
        }
        case 5:
        {
            int magv;
            cout << "Nhập mã giảng viên cần xóa: ";
            cin >> magv;
            DeleteGV(listGV, magv);
            break;
        }
        case 6:
        {
            string tengv;
            cout << "Nhập tên giảng viên cần tìm: ";
            cin.ignore();
            getline(cin, tengv);
            DNodeGV *gv = FindGVByName(listGV, tengv);
            if (gv != nullptr)
            {
                PrintGV(gv->info);
            }
            else
            {
                cout << "Không tìm thấy giảng viên.\n";
            }
            break;
        }
        case 7:
        {
            SortGVByYear(listGV);
            cout << "Danh sách giảng viên đã được sắp xếp theo năm sinh.\n";
            break;
        }
        case 8:
        {
            int magv;
            cout << "Nhập mã giảng viên cần cập nhật: ";
            cin >> magv;
            GiaoVien newGV;
            cout << "Nhập tên giảng viên: ";
            cin.ignore();
            cin.getline(newGV.tengv, 250);
            cout << "Nhập năm sinh: ";
            cin >> newGV.namsinh;
            cin.ignore();
            cout << "Nhập giới tính: ";
            cin.getline(newGV.gioitinh, 250);
            cout << "Nhập số điện thoại: ";
            cin.getline(newGV.sdt, 250);
            cout << "Nhập lương: ";
            cin >> newGV.luong;
            UpdateGV(listGV, magv, newGV);
            break;
        }
        case 9:
        {
            int count = CountGV(listGV);
            cout << "Số lượng giảng viên: " << count << endl;
            break;
        }
        case 0:
        {
            cout << "Thoát chương trình.\n";
            break;
        }
        default:
            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại.\n";
        }
    } while (choice != 0);
}

int main()
{
    ListGV listGV;
    ListCTGD listCTGD;
    InitializeListGV(listGV);
    InitializeListCTGD(listCTGD);
    int chon;
    do
    {
        cout << "-------MENU CHINH------------\n";
        cout << "1. Quản lý giảng viên.\n";
        cout << "2. Quản lý chi tiết giảng dạy.\n";
        cout << "0. Thoát.\n";
        cout << "mời bạn chọn: ";
        cin >> chon;
        switch (chon)
        {
        case 1:
        {
            MenuGiangVien(listGV);
            break;
        }
        case 2:
        {
            MenuCTGD(listCTGD, listGV);
            break;
        }
        case 0:
        {
            break;
        }
        default:
        {
            cout << "vui lòng chọn theo menu\n.";
            break;
        }
        }

    } while (chon != 0);

    return 0;
}