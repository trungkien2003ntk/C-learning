#include <iostream>
using namespace std;

int n;
int d;
int arr[100000];
int arr_check[100000];// check xem so do da co xuat hien trong day~ nao chua
int carr_check=0;
int arr_ss[100000];// arr dung de so sanh cac count
int carr_ss=0;
int c=0;
int dem;

void input()
{
    for(int x=0;x<n;x++)
        cin>>arr[x];
}

bool kotrung(int n)
{
    int counttrung=0;
    for(int x=0;x<carr_check;x++)
        if(n==arr_check[x])
            counttrung++;
    if(counttrung==0)
        return 1;
    else
        return 0;
}

void xuly()
{
    
    for(int x=0;x<n;x++) //chay tu so dau den so cuoi
    {   
        if(kotrung(arr[x])) //số đó đã có trong arr check hay chưa truong hop 1 3 7 thì xet 1 r khong xet 3 nữa vì 1 đã có 1 3 7 thì kiểu gì thằng 3 cũng bé hơn dãy 1
        {   
            c=arr[x]; // c se bang so do
            dem=1;// tinh luon so do la 1
            arr_check[carr_check]=arr[x]; // dua con so dau tiên vào arr check
            carr_check++; // cộng cound của arr lên để lưu cho arr tiếp theo
            for(int i=0;i<n;i++) // chay tu so dau den so cuoi
            {
                if(arr[i]==c+d && kotrung(arr[i])) // neu co so nao = số đó + d  và kiem tra xem số đó đã có trong arr check hay chưa 
                {
                    arr_check[carr_check]=arr[i]; // đưa số đó vào arr check
                    carr_check++; // côngj count arr
                    dem++; //cong đếm
                    c=c+d; // c lúc này sẽ là c + d
                    i=0; // reset i=0 để xét từ đầu dãy trường hợp 1 7 3 thì số 7 nằm trước số 3 nếu ko reset sẽ ko tìm được
                }
            }
            arr_ss[carr_ss]=dem; // sau khi xet xong sẽ có 1 thằng đếm là số lần mà nó thỏa cái if , bê đếm thứ nhất vào 1 arr so sánh
            carr_ss++; // cộng lên để cho lần lưu tiep theo
        }     // rồi quay lại xét số thứ 2 
    }
    for(int x=0;x<carr_ss;x++)
        cout<<arr_ss[x]<<" ";
    cout<<endl;
    for(int x=0;x<carr_check;x++)
        cout<<arr_check[x]<<" ";
}

int max() // tìm max trong dãy đếm
{
    int max=arr_ss[0];
    for(int x=1;x<carr_ss;x++)
        if(arr_ss[x]>max)
            max=arr_ss[x];
    return max;
}

int main()
{
    cin>>n;
    cin>>d;
    input();
    xuly();
    cout<<endl;
    cout<<max();
    return 0;
}
