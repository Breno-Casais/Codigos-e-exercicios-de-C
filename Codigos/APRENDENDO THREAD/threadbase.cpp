#define WIN32_LEAN_AND_MEAN 
#include <iostream>
#include <windows.h>
#include <process.h>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
typedef unsigned (WINAPI *PBEGINTHREADEX_THREADFUNC)(LPVOID lpThreadParameter);
typedef unsigned *PBEGINTHREADEX_THREADID;
using namespace std;
#define equipes 7 
#define maxCarroPista 7 
#define numCarro 10
HANDLE hMutex[equipes];
HANDLE hSemaphore;

class ThreadObject
{
public:
	ThreadObject(); // Construtor
	void StartThread();
	void WaitForExit();
	static DWORD WINAPI ThreadFunc(LPVOID param);
	void SetKillThread(bool kill);
	bool GetKillThread();
protected:
	virtual DWORD ThreadMemberFunc();
	HANDLE m_hThread; // Handle para thread criada // ponteiroo para thread
	DWORD m_ThreadId; // Identificador da thread
	bool KillThread;
};

ThreadObject::ThreadObject() // Inicializa membros privados da classe
{
	this->m_hThread = NULL;
	this->m_ThreadId = 0;
	this->KillThread = false;
}

void ThreadObject::StartThread()
{
	m_hThread = (HANDLE)_beginthreadex(NULL, 0,
(PBEGINTHREADEX_THREADFUNC) ThreadObject::ThreadFunc,
(LPVOID)this, // passa pointer para objeto como parâmetro
0, (PBEGINTHREADEX_THREADID) &m_ThreadId );
	if (m_hThread) {
		std::cout<< "Thread launched\n";
	}
}

void ThreadObject::WaitForExit() // Espera fim da thread
{
	WaitForSingleObject(m_hThread, INFINITE);
	CloseHandle(m_hThread);
}
void ThreadObject::SetKillThread(bool kill) {
	this->KillThread = kill;
}
bool ThreadObject::GetKillThread() {
	return this->KillThread;
}
// This is a static member function. Unlike C static functions, you only
// place the static declaration on the function declaration in the class, not
// on its implementation. Static member functions have no "this" pointer, but
// do have access rights.
DWORD WINAPI ThreadObject::ThreadFunc(LPVOID param) {
// Use the param as the address of the object
	ThreadObject* pto = (ThreadObject*)param;
// Call the member function. Since we have a proper object pointer,
// even virtual functions will be called properly.
	return pto->ThreadMemberFunc();
}
// This above function ThreadObject::ThreadFunc() calls this function after the
// thread starts up.
DWORD ThreadObject::ThreadMemberFunc()
// Função que desempenhará as funções da thread
{
// Do something useful ...
	while(!this->GetKillThread())
	{
		std::cout << ".";
		Sleep(2000);
	}
	_endthread();
	return 0;
}

class formula1 : public ThreadObject {
	protected:
		HANDLE m_hThread[];
		DWORD dwret;
		DWORD dwExitCode;	
		int nEquipes,nCar;
		char BoxName[5];
	public:
		formula1(){	
			m_hThread[numCarro];
			dwExitCode = 0;		
		} 
		
		void CriarMutex(){
			for(nEquipes = 0; nEquipes < equipes;++nEquipes ){
				sprintf(BoxName, "Box%d", nEquipes);
				hMutex[nEquipes] = CreateMutex(NULL, FALSE, BoxName);	
			}
		}
		
		void CriarSemaphoro(){
			CreateSemaphore(NULL,maxCarroPista,maxCarroPista,"MAX_CARRO");
			for(nCar = 0 ; nCar < numCarro;nCar++){
				
			}
		}
	
		
		
	
};

int main(){
	ThreadObject a1;
	a1.StartThread();
	Sleep(10000);
	a1.SetKillThread(true);
	a1.WaitForExit();
	
	return 0;
}
