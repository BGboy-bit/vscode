/**************/
/*****����*****/
/*************/

//���ߣ�zjz
//��ʼ�������ڣ�2023.4.20
//�����������ڣ�

/*******************************/
/*��ʱ�Ѵ��뱸����game1,game2������*/
/******************************/



//������1.0 ȥ��#include<bits/stdc++.h>��Ϊc��ͷ         (vitual studio������#include<bits/stdc++.h>)    2023.4.20
//������1.1 ��fflush(stdin)��Ϊrewind(stdin)                      (vitual studio������fflush(stdin))    2023.4.40
//������1.2 ��vscode���뷽ʽ��ΪGB2312                               (UTF-8�������������壬�������������)    2024.4.20


//������־��

//task:�����к������ڿ�ͷ������
//task:��������FirstRound()
//task:��ɾ���ϵͳ������
//task:�������������������㷨//task:�ڿ�ʼ������Ӽ������ɣ�����mid�˵��ġ������˼䡰��Ϊ���������˵�����
//task:��д�Լ���ͷ�ļ��������������ϸ�ֳ�ȥ
//task:���SecondRound()��ThirdRound()������
//task:��ɱ���ϵͳ������ϵͳ�����ﱬ��ϵͳ������
//task:��ɼ�����ϵͳ����


#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>

struct Character {   
    int HP,MP;//Ѫ�� ����
    int ATK,DEF;//������ ������
    char Name[100];
    int Class;
    int Level;
    char weapon[100];//����ϵͳ�����ڴ�
};

Character Player,CntPlayer;

const int MAXMAP = 3,MAXBoss = 3;
const char* Master = "zjz";
bool f = 1;//��¼��һ������Ƿ�Ϊֱ���˳�
bool g = 1;//��¼�Ƿ��м�¼���������ֵ
bool h = 1;//��¼�Ƿ��м�¼���������ֵ
bool ris[MAXMAP + 1];//��¼�ؿ��Ƿ��Ѿ�ͨ��
int cnt[MAXMAP + 1];//��¼����صĴ���
char s[MAXMAP + 1][100] = {{},{"�߳���ƿ��"}, {"ĥ������"}, {"���Ȳ���"}};

struct Boss {
    int HP,ATK;
    char Name[100];
    char Talent[100];
    int exp;
};

Boss boss[MAXBoss + 1] = {{},{10,1,"�̽��",""},{20,3,"��ɽԳ",""},{40,7,"����",""}};
Boss Cntboss;

void EnterQuit() {//����س��˳����������Ļ
    char c;
    rewind(stdin);//��ջ���������
    scanf("%c",&c);
    system("cls");//��տ���̨����
}

int Query() {
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    printf("�Ƿ�Ҫ�������飿\n");
    printf("1.��!�ҵ�ʱ��ܱ���Ķ�������!\n");
    printf("2.����,�����д����ô���ұ���úú�Ʒζһ��(������ĺܺÿ���!��д�Ĵ�Ϲ����).\n");
    printf("���������ѡ��");
    rewind(stdin);//��ջ���������
    int x;
    scanf("%d",&x);
    system("cls");//��տ���̨����
    if(x == 2) return 1;
    else return 0;
}

void ShowIntrChar() {//��������
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    printf("����ʿ��\n");
    printf("���¶��������ڴ���,�ŵ��ǻ�����,����ʹ�÷���,�Ҿ���������,ȱ�����᲻�𵶽�,��Ѫ�ܱ�.\n\n");
    printf("���������\n");
    printf("��Ϊ������,��ǧ������,���Ժ���,Ƥ�ܺ�,�������ָ��ѵ�,���޷�ʹ�����������,����ȭͷ˵��,ȭͷӲ�ĵ���Ŵ�.\n\n");
    printf("�����ޡ�\n");
    printf("˧�������츳��Ҫ��ܸ�,û�б����ɽ��ͺ����ڽ�������·����Զ.\n\n");
    printf("���»س��˳�");
    EnterQuit();
}

void ShowCharacter(int x) {
    if(x == 0)  {
        printf("%s\nѪ��: %d  ����: %d  ������: %d  ������: %d\n\n",Player.Name,Player.HP,Player.MP,Player.ATK,Player.DEF);
        if(g) {
            CntPlayer = Player;
            g = 0;
        }
    }
    else {
        printf("%s\nѪ��: %d  ������: %d\n\n",boss[x].Name,boss[x].HP,boss[x].ATK);
        if(h) {
            Cntboss = boss[x];
            h = 0;
        }
    }
}

void PrintLevel() {//��ӡ����
    if(Player.Class >= 2) {
        switch(Player.Level) {
            case 1: printf("����:��ͭƤ����\n"); break;
            case 2: printf("����:���ݸ�����\n"); break;
            case 3: printf("����:�������\n"); break;
            case 4: printf("����:����������\n"); break;
            case 5: printf("����:����®����\n"); break;
            case 6: printf("����:����������\n"); break;
            case 7: printf("����:���ۺ�����\n"); break;
            case 8: printf("����:�����ž���\n"); break;
            case 9: printf("����:���𵤾���\n"); break;
            case 10: printf("����:��ԪӤ����\n"); break;
            case 11: printf("����: ����豾���\n"); break;
            case 12: printf("����: �����˾���\n"); break;
            case 13: printf("����: ����������\n"); break;
            case 14: printf("����: ���ϵ���ء�\n"); break;
            case 15: printf("����: ��? ? ?��\n"); break;
        }
    }
    else {
        switch(Player.Level) {
            case 1: printf("����:�����߾���\n"); break;
            case 2: printf("����:��ľ̥����\n"); break;
            case 3: printf("����:��ˮ������\n"); break;
            case 4: printf("����:��Ӣ�꾳��\n"); break;
            case 5: printf("����:�����Ǿ���\n"); break;
            case 6: printf("����:���䵨����\n"); break;
            case 7: printf("����:��������\n"); break;
            case 8: printf("����:���𻯾���\n"); break;
            case 9: printf("����:��ɽ�۾���\n"); break;
            case 10: printf("����:��ֹ������ʢ����\n"); break;
            case 11: printf("����:��ֹ�������澳��\n"); break;
            case 12: printf("����:��ֹ�����񵽾���\n"); break;
            case 13: printf("����: �����񾳡�\n"); break;
        }
    }
}

void Warrior() {//�������
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    Player.Class = 1;
    Player.HP = 10;
    Player.MP = 0;
    Player.ATK = 5;
    Player.DEF = 8;
    Player.Level = 1;
    printf("��������������!\n");
    printf("��ɫ: �������  HP:%d  MP:%d  ATK:%d DEF:%d\n",Player.HP,Player.MP,Player.ATK,Player.DEF);
    printf("���»س�����");
    EnterQuit();
}

void Swordsman() {//����
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    Player.Class = 2;
    Player.HP = 1;
    Player.MP = 5;
    Player.ATK = 1;
    Player.DEF = 1;
    Player.Level = 1;
    printf("��������������!\n");
    printf("��ɫ: ����  HP:%d  MP:%d  ATK:%d DEF:%d\n",Player.HP,Player.MP,Player.ATK,Player.DEF);
    printf("���»س�����");
    EnterQuit();
}

void Monk() {//����ʿ
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    Player.Class = 3;
    Player.HP = 3;
    Player.MP = 10;
    Player.ATK = 2;
    Player.DEF = 2;
    Player.Level = 1;
    printf("��������������!\n");
    printf("��ɫ: ����ʿ  HP:%d  MP:%d  ATK:%d DEF:%d\n",Player.HP,Player.MP,Player.ATK,Player.DEF);
    printf("���»س�����");
    EnterQuit();
}

void MAster() {
    for(int i = 1; i <= MAXMAP; i ++) {
        ris[i] = 1;
        cnt[i] = 1;
    }
    Player.ATK = 999;
    Player.DEF = 999;
    Player.HP = 999;
    Player.MP = 999;
    if(Player.Class == 1) Player.Level = 13;
    else Player.Level = 15;
}

void Start() {//��ʼ����
    printf("*------------------>����<----------------------*\n");
    printf("*    ��ӭ����zjz����������,Ԥף��λ��Ŀ���    *\n");
    printf("*                                              *\n");
    printf("*         ��ǧ���� ���治�� �������           *\n"); 
    printf("*             �ҳ�ƽ�� Ψ��һ��                *\n");
    printf("*�ɰ�ɽ �Ͻ� ���� ���� ��ħ ��� ժ�� �ݳ� ����*\n");
    printf("*    �ҽг�ƽ�� ƽƽ������ƽ�� ����һ������    *\n");
    printf("*                                              *\n");
    printf("*            �������ּ���ʼ����֮�ã�          *\n");
    printf("*                1.��ʼ���ɣ�                  *\n");
    printf("*                2.�鿴��������                *\n");
    printf("*                3.�鿴boss����                *\n");
    printf("*                4.���ط��䡣                  *\n");    
    printf("*                                              *\n");    
    printf("*      ԭ������������    ���ߣ����Ϸ���      *\n");
    printf("*           ��Ϸ����: zjz(��֤���)            *\n");
    printf("************************************************\n"); 
}

void HandleName() {//ȡ��
    printf("*------------------>����<----------------------*\n\n");
    char name[100];
    printf("������������䣺");
    rewind(stdin);//��ջ���������
    scanf("%s",name);
    strcpy(Player.Name,name);
    if(strcmp(Player.Name,Master) == 0) {
        MAster();
    }
}

void ShowPanel() {//չʾ���԰�
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    printf("===========================\n");
    switch(Player.Class) {
        case 1: printf("*         �������        *\n"); break;
        case 2: printf("*          ����           *\n"); break;
        case 3: printf("*          ����ʿ         *\n"); break;
    }
    printf("���:%s\n",Player.Name);
    printf("Ѫ��:%d\n",Player.HP);
    printf("����:%d\n",Player.MP);
    printf("������:%d\n",Player.ATK);
    printf("������:%d\n",Player.DEF);
    //printf("Level:%d\n",Player.Level);
    PrintLevel();
    printf("===========================\n");
    printf("���»س�����");
    EnterQuit();
}

void ChooseCharacter() {//ѡȡ��ɫ
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    printf("1.������� 2.���� 3.����ʿ 4.��ɫ����\n");
    char c;
    printf("��ѡ���ɫ��");
    rewind(stdin);//��ջ���������
    scanf("%c",&c);
    switch(c) {
        case'1': Warrior(); break;
        case'2': Swordsman(); break;
        case'3': Monk(); break;
        case'4': ShowIntrChar(); ChooseCharacter();break;
    }
    HandleName();
    ShowPanel();
    printf("*------------------>����<----------------------*\n\n");
    if(strcmp(Player.Name,Master) == 0) {
        printf("��ӭ����,����\n");
    }
    else {
        printf("��ӭ���� %s ����zjz����������,׼���ÿ������������������?\n\n",Player.Name);
        printf("1.�Ȳ����˸���!  2.��Ҫ��¯����,TMD���������������!\n");
        printf("��ѡ��");
        int x;
        scanf("%d",&x);
        if(x == 2) ChooseCharacter();
    }
}

void PrintTable() {
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    printf("*------------------------------*\n");
    printf("|         ===||======>         |\n");
    printf("*------------------------------*\n");
    printf("|                              |\n");
    printf("|         1.��ͼ               |\n");
    printf("|         2.�鿴�������       |\n");
    printf("|         3.����               |\n");
    printf("|         4.������             |\n");
    printf("|         5.�����˽�           |\n");
    printf("|                              |\n");
    printf("*------------------------------*\n");
}

void ShowMap() {
    printf("Ŀ¼\n");
     printf("======================\n");
    for(int i = 1; i <= MAXMAP; i ++) {
        printf("��%d��: ",i);
        if(ris[i - 1]) printf("%s\n",s[i]);
        else printf("? ? ?\n");
    }
    printf("\n");
    printf("%d.���ز˵�\n",MAXMAP + 1);
    printf("======================\n\n");
}

void FirstActor() {
    printf("��һ�¡��������߳�������\n");
    printf("���»س�����"); EnterQuit();
    printf("*------------------>����<----------------------*\n\n");
    printf("��ԭ������������ͨ��һ�����,������5��ʱ,��������ĸ���֪����С�������,�ʹ�������ı�����,��ĸ���ܷ���˫˫����,��ĸ����Ǳ��ˣ������ŵĶ���,������ĸ��ף�����,���ĸ�ײ��ض���...\n");
    printf("�㱾���ɱ������,��ڰ��е�ө��,С��Ļ�Ե�׷�����ӿ��,��ȴ����ס...\n");
    printf("���»س�����"); EnterQuit();
    printf("*------------------>����<----------------------*\n\n");
    printf("ʮ��������,С�������³��׵߸�������������Ŀ���...\n");
    printf("���»س�����"); EnterQuit();
    printf("*------------------>����<----------------------*\n\n");
    printf("���鶴��(��������)�������������˳����˻���,��Ȼ���д����ѹ��,���۸�������������ͨ�˻�����������,��ĳ����žͱ����̽�����,�ñ�������������Ӳ���...\n");
    printf("���»س�����"); EnterQuit();
    printf("*------------------>����<----------------------*\n\n");
}

void FirstRound() {
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    g = 1; h = 1;
    // cnt[1] ++;//����ר��
    if(cnt[1] ++ == 0) FirstActor();
    else {
        if(Query()) {
            printf("*------------------>����<----------------------*\n\n");
            FirstActor(); 
        }
    }
    printf("��սboss��������%s\n\n",boss[1].Name);
    ShowCharacter(0); ShowCharacter(1);

}

void SecondRound() {
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    g = 1; h = 1;
    if(ris[1]) {
        printf("�����ڴ�\n");
    }
    else {
        printf("�������������ǰ��Ĺؿ�\n");
    }
}

void ThirdRound() {
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    g = 1; h = 1;
    if(ris[2]) {
        printf("�����ڴ�\n");
    }
    else {
        printf("�������������ǰ��Ĺؿ�\n");
    }
}


void Map() {
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    ShowMap();
    printf("���������ѡ��: ");
    rewind(stdin);//��ջ���������
    int x;
    scanf("%d",&x);
    switch(x) {
        case 1: FirstRound(); break;
        case 2: SecondRound(); break;
        case 3: ThirdRound(); break;
        default: break;
    }
    printf("���»س�����");
    EnterQuit();
}

void ShowBackpack() {

}

void Backpack() {
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    ShowBackpack();
    printf("�����ڴ�\n");
    printf("���»س�����");
    EnterQuit();
}

void ShowTalentTree() {
    
}

void TalentTree() {
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    ShowTalentTree();
    printf("�����ڴ�\n");
    printf("���»س�����");
    EnterQuit();
}

void MidHandle() {
    char handle;
    ris[0] = 1;//�õ�һ�ؿɼ�
    while(1) {
        PrintTable();
        printf("�����룺");
        scanf("%c",&handle);
        switch(handle) {
            case'1': Map(); break;
            case'2': ShowPanel(); break;
            case'3': Backpack(); break;
            case'4': TalentTree(); break; 
            default: return; break;          
        }
    }
}

void ShowProbability() {//�鿴boss����
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    printf("�����ڴ�\n");
    printf("���»س����ؿ�ʼ����");
    EnterQuit();
}

void ShowWeapon() {//�鿴��������
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    printf("�����ڴ�\n");
    printf("���»س����ؿ�ʼ����");
    EnterQuit();
}

void SayGoodbye() {
    system("cls");//��տ���̨����
    printf("*------------------>����<----------------------*\n\n");
    printf("����֮�õ��˾ͽ�����,���������ó̻��ڼ���.��������ϧÿһ��,���ڵ���,���������Լ��ľ�������^_^.\n");
}


void FirstHandle() {
    char handle;
    while(1) {
        Start();
        printf("�����룺");
        scanf("%c",&handle);
        switch(handle) {
            case'1': ChooseCharacter(); printf("���»س�����"); EnterQuit(); return; break;
            case'2': ShowProbability(); break;
            case'3': ShowWeapon(); break;
            default: f = 0; return; break;          
        }
    }
}

int main() {
    FirstHandle();
    if(f) MidHandle();
    SayGoodbye(); 
    system("pause");
    return 0;
}