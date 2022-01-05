#include "algorithms.h"
#include<chrono>

void RandomStringGenerator(string code[], int codeLength)
{
    string box = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefjhijklmnopqrstuvwxyz0123456789";
    int boxLength = box.length();
    for (int i = 0; i < codeLength; i++)
    {
        code[0] = code[0] + box[rand() % boxLength];
    }
}

void SinhURL(string url[])
{
    int k = 1;
    int r = 7;
    int count = 0;
    string a[1];
    a[0] = "https://utex.hcmute.edu.vn";
    string* b = a;
    url[0] = *b;
    for (int m = 0; m < 10; m++)
    {
        a[0] = "https://utex.hcmute.edu.vn/";
        RandomStringGenerator(a, r);
        string* b = a;
        url[k] = *b;
        int temp1 = k;
        for (int h = 0; h < 10; h++)
        {
            k++;
            a[0] = url[temp1] + '/';
            RandomStringGenerator(a, r);
            string* c = a;
            url[k] = *c;
            int temp2 = k;
            for (int l = 0; l < 10; l++)
            {
                k++;
                a[0] = url[temp2] + '/';
                RandomStringGenerator(a, r);
                string* d = a;
                url[k] = *d;
            }
        }
    }
}
int Prime(int k)
{
    int n = 1.2 * k + 1;
    while (1)
    {
        int count = 0;
        for (int i = 1; i <= n; i++)
        {
            if (n % i == 0)
                count++;
        }
        if (count == 2)
            return n;
        n++;
    }
    return 0;
}

void DoThoiGianThucThiHashFunction_Div(string url[])
{
    std::cout << "Do thoi gian thuc thi HashFunction_Div" << endl << endl;
    int prime;

    int x = 1;
    while (x <= 10)
    {
        prime = Prime(100 * x);
        double sum = 0, max = 0, min = 10;
        for (int i = 0; i < 100 * x; i++)
        {
            string a = url[i];
            auto begin = chrono::high_resolution_clock().now();
            HashFunction_Div(a, prime);
            auto end = chrono::high_resolution_clock().now();

            auto result = chrono::duration_cast<std::chrono::microseconds>(end - begin);
            sum += result.count();
            if (result.count() > max)
                max = result.count();
            if (result.count() < min)
                min = result.count();
        }
        double avg = (double)(sum / (100 * x));
        std::cout << "The number of URLs: " << 100 * x << endl;
        cout << "Max execution time: " << max * 1e-6 << " s" << endl;
        cout << "Min execution time: " << min * 1e-6 << " s" << endl;
        std::cout << "Average execution time: " << avg * 1e-6 << " s" << endl << endl;
        x++;
    }
    std::cout << "--------------------------------------------" << endl;
}
void DoThoiGianThucThiHashFunction_Mul(string url[])
{
    std::cout << "Do thoi gian thuc thi HashFunction_Mul" << endl << endl;
    int prime;

    int x = 1;
    while (x <= 10)
    {
        prime = Prime(100 * x);
        double sum = 0, max = 0, min = 10;
        for (int i = 0; i < 100 * x; i++)
        {
            string a = url[i];
            auto begin = chrono::high_resolution_clock().now();
            HashFunction_Mul(a, prime);
            auto end = chrono::high_resolution_clock().now();

            auto result = chrono::duration_cast<std::chrono::microseconds>(end - begin);
            sum += result.count();
            if (result.count() > max)
                max = result.count();
            if (result.count() < min)
                min = result.count();
        }
        double avg = (double)(sum / (100 * x));
        std::cout << "The number of URLs: " << 100 * x << endl;
        cout << "Max execution time: " << max * 1e-6 << " s" << endl;
        cout << "Min execution time: " << min * 1e-6 << " s" << endl;
        std::cout << "Average execution time: " << avg * 1e-6 << " s" << endl << endl;
        x++;
    }
    std::cout << "--------------------------------------------" << endl;
}
void DoSoLanDungDo(string url[])
{
    std::cout << "Do so lan va cham cua tung url:" << endl<<endl;
    int prime;
    int x = 1;
    while (x <= 10)
    {
        HashTable* h[2000];
        for (int i = 0; i < 2000; i++)
            h[i] = new HashTable;
        prime = Prime(100 * x);
        double sum = 0, max = 0, min = 2000;
        int sum_a = 0;
        for (int i = 0; i < 100 * x; i++)
        {
            string a = url[i];
            Insert_VC(h, url[i], prime, max, min, sum, sum_a);

        }
        double avg = (double)(sum / (100 * x));
        std::cout << "The number of URLs: " << 100 * x << endl;
        std::cout << "Max Collision: " << max << " lan" << endl;
        std::cout << "Min Collision: " << min << " lan" << endl;
        std::cout << "Average Collision: " << avg << " lan" << endl << endl;
        x++;
    }
    std::cout << "--------------------------------------------" << endl;
}
void DoSoLanDungDo_HASHTABLESIZE(string url[])
{
    std::cout << "Do so lan va cham cua tung url:" << endl << endl;
    int prime;
    
    int k = 1;
    while (k <= 3)
    {
        int x = 1;
        int n;
        std::cout << "Gia tri HASHTABLESIZE = ";
        if (k == 1)
            std::cout << "xap xi so luong url" << endl;
        else if (k == 2)
            std::cout << "gap 1,2 lan so luong url" << endl;
        else
            std::cout << "gap 3 lan so luong url" << endl;
        while (x <= 10)
        {
            if (k == 1)
                n = (100 * x) / 1.2 + 1;
            else if (k == 2)
                n = 100 * x + 1;
            else
                n = (3 * 100 * x) / 1.2 + 1;
            HashTable* h[4000];
            for (int i = 0; i < 4000; i++)
                h[i] = new HashTable;
            prime = Prime(n);
            double sum = 0, max = 0, min = 2000;
            int sum_a = 0;
            for (int i = 0; i < 100 * x; i++)
            {
                string a = url[i];
                Insert_VC(h, url[i], prime, max, min, sum, sum_a);

            }
            double avg = (double)(sum / (100 * x));
            std::cout << "The number of URLs: " << 100 * x << endl;
            std::wcout << "Prime: " << prime << endl;
            std::cout << "Average Collision: " << avg << " lan" << endl;
            std::cout << "Empty index: " << prime - 100 * x<< endl << endl;
            x++;
        }
        k++;
    }
    std::cout << "--------------------------------------------" << endl;
}
int main()
{
    string url[2000];
    SinhURL(url);

    //danh gia chon HASHTABLESIZE
    DoSoLanDungDo_HASHTABLESIZE(url);
    
    //danh gia 2 phuong phap bam
    DoThoiGianThucThiHashFunction_Div(url);
    DoThoiGianThucThiHashFunction_Mul(url);

    return 0;
}