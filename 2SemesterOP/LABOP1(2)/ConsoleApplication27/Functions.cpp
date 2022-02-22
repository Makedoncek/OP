#include <iostream>
#include <fstream>
#include <string>
using namespace std;



string inputText() {
    string initial = "Initial.txt";
    cout << "Input your text (press  Ctrl-Q combinination to stop entering your text):\n";
    ofstream fout(initial); //��������� �� �������� ��'���� ������ ��� ������ ����� � ����� 
    string str; //����� ��� ���������� ���������� �����
    int count = 0;//����� ���������� �����, ���� ��������� ������������
    while (str.find(17) == string::npos) { //�������� �� �������� ���������(Ctrl-Q) � ������ 
        getline(cin, str);
        if (count == 0 && str.find(17) == string::npos)
            fout << str;
        else if (str.find(17) == string::npos)
            fout << endl << str;
        count++;
    }
    fout.close();
    return initial;
}

void chooseFile(string init, string even, string odd) {
    ifstream filein(init); //��������� �� �������� ��'���� ������ ��� ������� ����� � ����� 
    ofstream even1(even); //..��� ������ � ������ ���� (��� ������)
    ofstream odd2(odd); //..��� ������ � ������ ����(��� ��������)
    string str;
    int count = 1; //  ˳������� ������ �������� ������
    while (!filein.eof()) { //�������� �� ����� ���������� �����
        getline(filein, str);
        if (count % 2 == 0) {
            if (count == 2) even1 << str;
            else even1 << endl << str;
        }
        else {
            if (count == 1) odd2 << str;
            else odd2 << endl << str;
        }
        count++;
    }
    filein.close();
    even1.close();
    odd2.close();
}

void addText(string adress) {
    ofstream fileout(adress, ios::app); //app (append) ��������������� ��� �������� ����� � ����� �����
    cout << "You can add some text,to end entering the text press Ctrl-Q:\n";
    string str;
    int count = 0;
    while (str.find(17) == string::npos) {
        getline(cin, str);
        if (count == 0 && str.find(17) == string::npos)
            fileout << str;
        else if (str.find(17) == string::npos)
            fileout << endl << str;
        count++;
    }
    fileout.close();
}

void outputFile(string adress) {
    ifstream filein(adress); //������ ������ ����� ��� ������� ���������� � �����
    string str;
    while (!filein.eof()) {
        getline(filein, str);
        cout << str << endl;
    }
    cout << endl;
}

void alphabetSort(string adress) {
    fstream filein(adress); //��'��� ������������� ����� (i/o)(�� �������, ��� � �����)
    int cntLines = 0;
    string str;
    while (!filein.eof()) { //����������� ������� ����� � ����
        getline(filein, str);
        cntLines++;
    }
    filein.close();
    filein.open(adress, ios::in); //�������� ����� � ����� ���������� ����������
    string* lines = new string[cntLines]; //����� ��� ������ ����� ������ � ����� 
    for (int i = 0; i < cntLines; i++) {
        getline(filein, lines[i]);
    }
    filein.close();
    for (int i = 0; i < cntLines; i++) {
        int cntSpace = 0;
        string nStr = "";
        for (int j = 0; j < lines[i].length(); j++) { //��������� ����������� ������ �� ������� ���������� �����
            if (lines[i][j] == ' ') {
                cntSpace++;
            }
            else {
                if (cntSpace != 0) {
                    cntSpace = 0;
                    nStr += ' ';
                }
                nStr += lines[i][j];
            }
        }
        if (nStr[0] == ' ') nStr.erase(0, 1); //��������� ������ � ������� ������� ������� ����� 
        if (nStr[nStr.length() - 1] != ' ') nStr.push_back(' ');
        int cntWords = 0;
        lines[i] = nStr;   //�������������� ��� ������������� ������ ������ ���������� �������� � ����� ����� 
        while (nStr.length() > 0) { //����������� �-�� ���  � �����
            cntWords++;
            nStr.erase(0, nStr.find(' ') + 1);
        }
        string* words = new string[cntWords]; //��������� ����� � ����� ���
        nStr = lines[i];
        for (int j = 0; j < cntWords; j++) {
            words[j] = nStr.substr(0, nStr.find(' '));
            nStr.erase(0, nStr.find(' ') + 1);
        }
        for (int j = 0; j < cntWords - 1; j++) { //���������� ��� �� ��������
            for (int g = 1; g < cntWords; g++) {
                if (words[g - 1].length() > words[g].length()) {
                    for (int k = 0; k < words[g].length(); k++) {
                        if (words[g - 1][k] > words[g][k]) { //�������� ���� ������ ��� � ���������� ���������
                            string t = words[g];
                            words[g] = words[g - 1];
                            words[g - 1] = t;
                            break;
                        }
                        else if (words[g - 1][k] < words[g][k]) break;
                    }
                }
                else {
                    for (int k = 0; k < words[g - 1].length(); k++) {
                        if (words[g - 1][k] > words[g][k]) {
                            string t = words[g];
                            words[g] = words[g - 1];
                            words[g - 1] = t;
                            break;
                        }
                        else if (words[g - 1][k] < words[g][k]) break;
                    }
                }
            }
        }
        lines[i] = "";
        for (int j = 0; j < cntWords; j++) { //����� ������������ ��� � ��������� �����
            lines[i] += words[j] + ' ';
        }
        lines[i].pop_back();
    }
    filein.open(adress, fstream::in | fstream::out | fstream::trunc); //����� ���������� ����� ������ �� ����� (trunc - ��� ������� �����)
    for (int i = 0; i < cntLines; i++) {
        filein << lines[i] << endl;
    }
    filein.close();
}