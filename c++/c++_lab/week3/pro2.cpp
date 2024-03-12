#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 0;//��������


class CPU {
    private : 
        enum CPU_Rank{P1 = 1, P2, P3, P4, P5, P6, P7}; 
        CPU_Rank rank;
        ll frequency;
        db voltage;
    public : 
        CPU(ll rank, ll fre, db vol) : rank((CPU_Rank)rank), frequency(fre), voltage(vol) {
            cout << "�ɹ�����CPU���캯��!\nCPU_Rank = " << rank << "\tfrequency = " << frequency << "\t volrage = " << voltage << "\n";
        }
        ~CPU();
};
CPU::~CPU() {
    cout << "�ɹ�����CPU��������!" << "\n";
} 

class RAM {
    private : 
        ll size;
    public : 
        RAM(ll size); 
        ~RAM();
};
RAM::RAM(ll size) : size(size) {
    cout << "�ɹ�����RAM���캯��!\nRAM_size = " << size << "\n";
}
RAM::~RAM() {
	cout << "�ɹ�����RAM��������!" << "\n";
}

class CDROM {
    private : 
        ll num;
    public :
        CDROM(ll A);
        ~CDROM();
};
CDROM::CDROM(ll num) : num(num) {
    cout << "�ɹ�����CDROM���캯��!" << "\n";
} 
CDROM::~CDROM() {
    cout << "�ɹ�����CDROM��������!" << "\n";
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
    cout << "�ɹ�����Computer���캯��!" << "\n"; 
}

Computer::~Computer() {
    cout << "�ɹ�����Computer��������!" << "\n";
}

void Computer::run() {
    cout << "Computer is run!" << "\n";
}

void Computer::stop() {
    cout << "Computer is stop!" << "\n";
}

void Solve() {
    ll ra, fr, vo, si, num;
    cout << "������CPU�ĵȼ�: "; cin >> ra;
    cout << "������CPU��Ƶ��: "; cin >> fr;
    cout << "������CPU�ĵ�ѹ: "; cin >> vo;
    CPU cpu(ra, fr, vo);
    cout << "������RAM�Ĵ�С: "; cin >> si;
    RAM ram(si);
    cout << "������CDROM������: "; cin >> num;
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