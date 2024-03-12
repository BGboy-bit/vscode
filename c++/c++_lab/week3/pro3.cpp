#include<bits/stdc++.h>
using namespace std;
typedef __int128 i128;
typedef long long ll;
typedef double db;

const db PI = acos(-1);
const ll inf = 2e18 + 10;
const int mod = 998244353;
const int MAX = 2e5 + 10;
bool multi = 1;//��������

const int MAX_TICKS = 200;

class Time {

    public :
        Time ( int = 0, int = 0, int = 0 ); // default constructor
    
        void setTime( int, int, int );
        
        void setHour( int );
        int getHour();
        
        void setMinute( int );
        int getMinute();
        
        void setSecond( int );
        int getSecond();
        
        void printStandard();
        void tick();

    private :
        int hour;
        int minute;
        int second;

}; // end class Time

Time::Time(int hr, int mi, int sec) : hour(hr), minute(mi), second(sec) {
    cout << "Time���캯�����óɹ�!" << "\n";
}

void Time::setTime(int hr, int mi, int sec) {
    hour = hr; minute = mi; second = sec;
    cout << "Set time succeed!" << "\n";
}

void Time::tick() {
    second ++ ;
    if(second >= 60) {
        second -= 60;
        minute ++ ;
        if(minute >= 60) {
            minute -= 60;
            hour ++ ;
            if(hour >= 24) hour -= 24;
        }
    }
} 

void Time::printStandard() {
    if(hour >= 13) cout << "���ڵ�ʱ����(" << hour << ":" << minute  << ":" << second << ":" << "PM)" << "\n";
    else cout << "���ڵ�ʱ����(" << hour << ":" << minute << ":" << second << ":" << "AM)" << "\n";
}

void Time::setHour(int hr) {
    hour = hr;
    cout << "Set hour succeed!" << "\n";
}

int Time::getHour() {
    cout << "������" << hour << "����" << "\n";
}

void Time::setMinute(int mi) {
    minute = mi;
    cout << "Set minute succeed!" << "\n";
}

int Time::getMinute() {
    cout << "������" << minute << "��" << "\n";
}

void Time::setSecond(int sec) {
    second = sec; 
    cout << "Set second succeed!" << "\n";
}

int Time::getSecond() {
    cout << "������" << second << "��" << "\n";
} 

int main()
{
   Time t;

   t.setTime( 23, 59, 57 );

   for ( int ticks = 1; ticks < MAX_TICKS; ++ticks ) {
      t.printStandard();
      cout << endl;
      t.tick();

   } // end for
    cout << "���������޸ĵ�Сʱ��: ";
    ll hr; cin >> hr;
    t.setHour(hr);
    cout << "���������޸ĵķ���: "; 
    ll mi; cin >> mi; 
    t.setMinute(mi);
    cout << "���������޸ĵ�����: ";
    ll sec; cin >> sec;
    t.setSecond(sec);
    t.getHour(); t.getMinute(); t.getSecond();
   return 0;

} // end main
