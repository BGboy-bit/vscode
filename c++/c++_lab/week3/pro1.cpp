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
            cout << "�ɹ����ù��캯��!\nCPU_Rank = " << rank << "\tfrequency = " << frequency << "\t volrage = " << voltage << "\n";
        }
        ~CPU();
        void run() {
            cout << "CPU start run!" << "\n";
        }
        void stop() {
            cout << "CPU stop!" << "\n";
        }
};

CPU::~CPU() {
    cout << "�ɹ�������������!" << "\n";
} 

void Solve() {
    ll ra, fr, vo;
    cout << "������CPU�ĵȼ�: "; cin >> ra;
    cout << "������CPU��Ƶ��: "; cin >> fr;
    cout << "������CPU�ĵ�ѹ: "; cin >> vo;
    CPU cpu(ra, fr, vo);
    cpu.run();
    cpu.stop();
}


signed main() {
    // ios::sync_with_stdio(false);
    // cin.tie(0); cout.tie(0);
    ll T = 1;
    if(multi) cin >> T;
    while(T -- ) {
        Solve();
    }
    return 0;
}