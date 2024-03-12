#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//多组输入


class CPU {
    private : 
        enum CPU_Rank{P1 = 1, P2, P3, P4, P5, P6, P7}; 
        CPU_Rank rank;
        ll frequency;
        db voltage;
    public : 
        CPU(ll rank, ll fre, db vol) : rank((CPU_Rank)rank), frequency(fre), voltage(vol) {
            cout << "成功调用CPU构造函数!\nCPU_Rank = " << rank << "\tfrequency = " << frequency << "\t volrage = " << voltage << "\n";
        }
        ~CPU();
};
CPU::~CPU() {
    cout << "成功调用CPU析构函数!" << "\n";
} 

class RAM {
    private : 
        ll size;
    public : 
        RAM(ll size); 
        ~RAM();
};
RAM::RAM(ll size) : size(size) {
    cout << "成功调用RAM构造函数!\nRAM_size = " << size << "\n";
}
RAM::~RAM() {
	cout << "成功调用RAM析构函数!" << "\n";
}

class CDROM {
    private : 
        ll num;
    public :
        CDROM(ll A);
        ~CDROM();
};
CDROM::CDROM(ll num) : num(num) {
    cout << "成功调用CDROM构造函数!" << "\n";
} 
CDROM::~CDROM() {
    cout << "成功调用CDROM析构函数!" << "\n";
} 


class Computer {
private :
    CPU cpu; 
    RAM ram;
    CDROM cdrom;
public :
    Computer(const CPU &cpu,const RAM &ram,const CDROM &cdrom);
    ~Computer();
    void run(); 
    void stop();
};

Computer::Computer(const CPU &cpu,const RAM &ram,const CDROM &cdrom) : cpu(cpu), ram(ram), cdrom(cdrom) {
    cout << "成功调用Computer构造函数!" << "\n"; 
}

Computer::~Computer() {
    cout << "成功调用Computer析构函数!" << "\n";
}

void Computer::run() {
    cout << "Computer is run!" << "\n";
}

void Computer::stop() {
    cout << "Computer is stop!" << "\n";
}

void Solve() {
    ll ra, fr, vo, si, num;
    cout << "请输入CPU的等级: "; cin >> ra;
    cout << "请输入CPU的频率: "; cin >> fr;
    cout << "请输入CPU的电压: "; cin >> vo;
    CPU cpu(ra, fr, vo);
    cout << "请输入RAM的大小: "; cin >> si;
    RAM ram(si);
    cout << "请输入CDROM的数量: "; cin >> num;
    CDROM cdrom(num);
    Computer computer(cpu, ram, cdrom);
    computer.run();
    computer.stop();
}


signed main() {
//    ios::sync_with_stdio(false);
//    cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}