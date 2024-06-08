#include <iostream>
#include <string>
#include <atlstr.h>
#include <Windows.h>

bool WriteComPort(CString Port, CString ch);

using namespace std;

int main()
{
	bool ErrorState = WriteComPort("COM3", "A");
	cout << ErrorState << endl;
	return 0;


}

bool WriteComPort(CString Port, CString ch)
{
	DCB dcb;
	DWORD byteswritten;
	HANDLE hPort = CreateFile(Port, GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0,NULL);

	if (!GetCommState(hPort, &dcb))
	{
		cout << "GetCommState" << endl;
		return false;
	}

	dcb.BaudRate = CBR_9600;
	dcb.ByteSize = 8;
	dcb.Parity = NOPARITY;
	dcb.StopBits = ONESTOPBIT;

	if (!SetCommState(hPort, &dcb))
	{
		cout << "SetCommState" << endl;
		return false;

	}

	bool retVal = WriteFile(hPort, ch, 1, &byteswritten, NULL);
	CloseHandle(hPort);
	return retVal;

}