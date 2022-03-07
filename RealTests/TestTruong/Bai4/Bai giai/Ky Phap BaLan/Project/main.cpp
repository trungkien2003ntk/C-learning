// Các thư viện sử dụng trong chương trình.
#include <iostream>
#include <string>
#include <fstream>
using namespace std;

// Khai báo cấu trúc dữ liệu ngăn xếp stack.
struct Node
{
	string Data; // Dữ liệu chứa bên trong Stack.
	struct Node *pNext; // Con trỏ pNext để tạo mối liên kết giữa các Node.
};
typedef struct Node NODE;

struct Stack
{
	NODE *Top; // Top quản lý đầu Stack.
};
typedef struct Stack STACK;


// Khởi tạo ngăn xếp.
void Init(STACK &s)
{
	s.Top = NULL;
}

// Tạo Node trong ngăn xếp Stack.
NODE *GetNode(string x) // Dữ liệu bên trong Node đang có kiểu string.
{
	NODE *p = new NODE;
	if(p == NULL)
	{
		cout << "\nKhong du bo nho de cap phat !";
		system("pause");
		return NULL;
	}
	p ->Data = x; // Lưu dữ liệu Data vào bên trong Node.
	p ->pNext = NULL; // Cập nhật lại mối liên kết.
	return p; // Trả về Node p.
}

// Kiểm tra Stack rỗng. Trả về true nếu Stack có phần tử, ngược lại trả về false.
bool IsEmpty(STACK s)
{
	if(s.Top == NULL)
	{
		return false;
	}
	return true;
}

// Thêm 1 Node vào Stack. Trả về true nếu thêm thành công, ngược lại trả về false.
bool Push(STACK &s, NODE *p)
{
	if(IsEmpty(s) == false)
	{
		s.Top = p; // Cập nhật đầu Stack chính là Node p.
		return true;
	}
	
	p ->pNext = s.Top;
	s.Top = p;
	return true;
}

// Lấy phần tử trong Stack đem ra ngoài. Trả về true nếu lấy thành công, ngược lại trả về false.
bool Pop(STACK &s, string &x)
{
	if(IsEmpty(s) == false)
	{
		return false;
	}
	NODE *p = s.Top; // Con trỏ p trỏ tới con trỏ Top.
	x = p ->Data;
	s.Top = s.Top ->pNext;
	delete p;
	return true;
}

// Xem phần tử đầu Stack. Trả về true nếu xem thành công, ngược lại trả về false.
bool Top(STACK s, string &x)
{
	if(IsEmpty(s) == false)
	{
		return false;
	}
	x = s.Top ->Data;
	return true;
}

// Hàm xử lý.
void XuLy(STACK &s)
{
	ifstream FileIn; // Khai báo File để đọc dữ liệu.
	FileIn.open("input.txt", ios_base::in); // Mở file để đọc.

	// Kiểm tra file tồn tại.
	if(!FileIn)
	{
		cout << "\nKhong tim thay tap tin input.txt";
		system("pause");
		return; // Kết thúc.
	}

	string str; // Biến lưu giá trị đọc từ File vào.
	getline(FileIn, str); // Đọc dữ liệu từ file lưu vào biến str.

	FileIn.close(); // Đóng file lại.

	Init(s); // Khởi tạo Stack.

	string p1, p2, p3;
	int KetQua;

	for(int i = 0; i < str.length(); i++)
	{
		NODE *p = new NODE;
		if(str[i] == '(')
		{
			continue; // Bỏ lần lặp hiện tại.
		}
		if(str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/' || str[i] == '%')
		{
			char *Temp = new char;
			Temp[0] = str[i];
			Temp[1] = '\0';
			string a = Temp;
		
			p = GetNode(a);
			Push(s, p);
		}

		string Temp;
		int Start;
		int End;

		if(str[i] >= '0' && str[i] <= '9')
		{
			Start = i;

			for(int j = i + 1; j < str.length(); j++)
			{
				if(str[j] < '0' || str[j] > '9')
				{
					End = j;
					i = j;
					break;
				}
			}
			End - 1;
			Temp = str.substr(Start, End - Start);
			
			p = GetNode(Temp);
			Push(s, p);
		}

		if(str[i] == ')')
		{
			Pop(s, p1);
			Pop(s, p2);
			Pop(s, p3);

			int Num3, Num1;
			Num3 = atoi(p3.c_str());
			Num1 = atoi(p1.c_str());

			if(p2 == "+")
			{
				KetQua = Num3 + Num1;
			}
			else if(p2 == "-")
			{
				KetQua = Num3 - Num1;
			}
			else if(p2 == "*")
			{
				KetQua = Num3 * Num1;
			}
			else if(p2 == "/")
			{
				KetQua = Num3 / Num1;
			}
			else if(p2 == "%")
			{
				KetQua = Num3 % Num1;
			}

			// Đưa lại nó vào trong Stack.
			char chr[20];
			itoa(KetQua, chr, 10);
			Node *q = GetNode((string)chr);
			Push(s, q);
		}
	}
	cout << KetQua;
}

// Hàm main.
void main()
{
	STACK s;
	XuLy(s);
	
	system("pause");
}