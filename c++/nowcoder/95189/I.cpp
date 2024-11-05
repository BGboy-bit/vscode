///存储：点 向量 线段 直线 圆
///点操作：內积，外积，equals与== 相等，+操作 -操作 
///直线与直线的正交判断dot = 0  平行判断 cross = 0
///点到直线的投影，点与直线的映像点
///三个点的逆时针ccw
///判断俩线段是否相交
///求两个点之间距离Distance，点与直线距离DistancePL，点与线段距离DistancePS，两个线段之间距离Distance
///求两个线段的交点CrossPoint，圆与直线的交点CrossPoints，圆与圆的交点CrossPoints
#include <bits/stdc++.h>
#define show(x) std::cerr << #x << "=" << x << std::endl;
#define IOS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;
const int MAX = 300500;
const int INF = 1e9;
const int N=1006;
const long long MOD = 998244353;
const double EPS = (1e-10);
class Point{                 ///Point
public:
    double x,y;
    Point(double x=0,double y=0):x(x),y(y){}
    Point operator + (Point p){
        return Point(x+p.x,y+p.y);
    }
    bool operator<(const Point &other) const {
        if (x != other.x) {
            return x < other.x;
        } else {
            return y < other.y;
        }
    }
    Point operator - (Point p){
        return Point(x-p.x,y-p.y);
    }
    Point operator * (double k){
        return Point(x*k,y*k);
    }
    Point operator / (double k){
        return Point(x/k,y/k);
    }
    bool operator == (const Point &p)const{
        return fabs(x-p.x)<EPS && fabs(y-p.y)<EPS;
    }
    double norm(){
        return sqrt(x*x+y*y);
    }
    friend ostream& operator <<(ostream& os,Point p){
        os << "p.x = " << p.x << " p.y = " << p.y  << endl;
        return os;
    }
};
double dot(Point a,Point b){    ///orthogonal : dot = 0
    return a.x*b.x+a.y*b.y;
}
double cross(Point a,Point b){  ///parallel : cross = 0
    return a.x*b.y-a.y*b.x;
}
bool equals(Point a,Point b){
    return (((a)-(b)).norm()<EPS);
}
typedef Point Vector;           ///Vector
class Segment{
public:
    Point p1,p2;
    Segment(Point p1 = Point(),Point p2 = Point()):p1(p1),p2(p2){}
};
///struct Segment{Point p1,p2;};   ///Segment
typedef Segment Line;           ///Line
Point Project(Point p,Segment s){
    Vector base = s.p2-s.p1;
    double r = dot(p-s.p1,base)/base.norm()/base.norm();
    return (s.p1 + base * r);
}
Point Reflect(Point p,Segment s){
    return p + (Project(p,s)-p)*2.0;
}
static const int COUNTER_CLOCKWISE = 1;
static const int CLOCKWISE = -1;
static const int ONLINE_BACK = 2;
static const int ONLINE_FRONT = -2;
static const int ON_SEGMENT = 0;

int ccw(Point p0,Point p1,Point p2){
    Vector a = p1 - p0;
    Vector b = p2 - p0;
    if(cross(a,b)>EPS)return COUNTER_CLOCKWISE;
    if(cross(a,b)<-EPS)return CLOCKWISE;
    if(dot(a,b)<-EPS)return ONLINE_BACK;
    if(a.norm()<b.norm())return ONLINE_FRONT;
    return ON_SEGMENT;
}
bool intersect(Point p1,Point p2,Point p3,Point p4){
    return (ccw(p1,p2,p3)*ccw(p1,p2,p4)<=0 &&
            ccw(p3,p4,p1)*ccw(p3,p4,p2)<=0);
}
bool intersect(Segment s1,Segment s2){
    return intersect(s1.p1,s1.p2,s2.p1,s2.p2);
}
double Distance(Point a,Point b){
    return (a-b).norm();
}
double DistancePL(Point p,Line l){
    return abs(cross(l.p2 - l.p1,p - l.p1) / (l.p2-l.p1).norm());
}
double DistancePS(Point p,Segment s){
    if(dot(s.p2 - s.p1 ,p - s.p1) < 0.0)return (p-s.p1).norm();
    if(dot(s.p1 - s.p2 ,p - s.p2) < 0.0)return (p-s.p2).norm();
    return DistancePL(p,s);
}



// 计算叉积
double cross_product(Point A, Point B, Point C) {
    return (B.x - A.x) * (C.y - A.y) - (B.y - A.y) * (C.x - A.x);
}

// 判断点P是否在线段CD上
bool on_segment(Point C, Point D, Point P) {
    return (std::min(C.x, D.x) <= P.x && P.x <= std::max(C.x, D.x) &&
            std::min(C.y, D.y) <= P.y && P.y <= std::max(C.y, D.y));
}

// 求交点并判断是否存在交点
Point line_segment_intersect(Point A, Point B, Point C, Point D, bool &has_intersection) {
    // 初始化返回值和标志位
    Point intersection = {-1, -1};
    has_intersection = false;

    // 计算叉积，用于判断线段CD的端点是否在直线AB两侧
    double P1 = cross_product(A, B, C);
    double P2 = cross_product(A, B, D);

    // 如果两叉积异号，则存在交点
    if (P1 * P2 < 0) {
        // 使用参数方程计算交点坐标
        double t = std::fabs(P1) / (std::fabs(P1) + std::fabs(P2));
        intersection.x = C.x + t * (D.x - C.x);
        intersection.y = C.y + t * (D.y - C.y);
        has_intersection = true;
        return intersection;
    }

    // 检查是否有端点在线段上
    if (P1 == 0 && on_segment(C, D, A)) {
        intersection = A;
        has_intersection = true;
        return intersection;
    }
    if (P2 == 0 && on_segment(C, D, B)) {
        intersection = B;
        has_intersection = true;
        return intersection;
    }

    // 没有交点，返回负值的坐标以表示无交点
    intersection.x = -1;
    intersection.y = -1;
    return intersection;
}

typedef vector<Point>Polygon;   ///Polygon
class Circle{                   ///Circle
public:
    Point c;
    double r;
    Circle(Point c = Point(),double r=0.0):c(c),r(r){}
    friend ostream& operator <<(ostream& os,Circle d){
        os << "c.x = " << d.c.x << " c.y = " << d.c.y  << " c.r = " << d.r << endl;
        return os;
    }
};
pair<Point,Point> CrossPoints(Circle c,Line l){
    ///assert(intersect(c,l));
    Vector pr = Project(c.c,l);
    Vector e = (l.p2 - l.p1)/ (l.p2-l.p1).norm();
    double base = sqrt(c.r * c.r - (pr - c.c).norm() * (pr - c.c).norm());
    return make_pair(pr + e*base , pr - e*base);
}
double arg(Vector p){return atan2(p.y,p.x);}
Vector polar(double a,double r){return Point(cos(r)*a,sin(r)*a);}
pair<Point,Point>CrossPoints(Circle c1, Circle c2){
    ///assert(intersect(c1,c2));
    double d = (c1.c-c2.c).norm();
    double a = acos((c1.r * c1.r + d * d - c2.r * c2.r)/(2 * c1.r * d));
    double t = arg(c2.c - c1.c);
    return make_pair(c1.c + polar(c1.r,t+a),c1.c + polar(c1.r,t-a));
}
bool cmp(auto x,auto y)
{

    return x.first<y.first;
}

Point p[N];

void solve()
{
    int n,m;
    cin>>n>>m;
    double ax,ay,bx,by;
    cin>>ax>>ay>>bx>>by;
    double x,y;
    Point st(ax,ay),sd(bx,by);
    Line lx(st,sd);
    for(int i=1;i<=n;i++){
        cin>>x>>y;
        p[i]=Point(x,y);
    }
    int h,k;
    while(m--){
        cin>>h>>k;
        vector<pair<double,Point>>d;
        
        double dis;
        for(int i=1;i<=n;i++){
            if(i==h)continue;
            Line l(p[i],p[h]);
            bool f=0;
            Point xx=line_segment_intersect(p[i],p[h], st, sd,f);
            if(!f)continue;
            dis=Distance(xx,st);
            d.push_back({dis,xx});
        }
        if(d.size()<k){
            cout<<"-1\n";
            continue;
        }
        sort(d.begin(),d.end());
        cout<<d[k-1].second.x<<' '<<d[k-1].second.y<<'\n';
    }

}
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr),cout.tie(nullptr);
    cout<<fixed<<setprecision(15);
    int T=1;
    // cin>>T;
    while(T--){
        solve();
    }
}


