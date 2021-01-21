#define WIN32_LEAN_AND_MEAN 
#include <iostream>
#include <windows.h>
#include <process.h>
typedef unsigned (WINAPI *PBEGINTHREADEX_THREADFUNC)(LPVOID lpThreadParameter);
typedef unsigned *PBEGINTHREADEX_THREADID;
using namespace std;
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


class teste: public ThreadObject{
	private:
	public:
		teste(){
			
		}
	DWORD ThreadMemberFunc() {
	while(!this->GetKillThread())
	{
		std::cout << "Estou na thread teste\n";
		Sleep(1000);
	}
	_endthread();
	return 0;
	}
};

class vem: public ThreadObject{
	private:

	public:
		vem(){
			
		}
	DWORD ThreadMemberFunc() {
	while(!this->GetKillThread())
	{
		std::cout << "Estou na thread VEMMMMMMMM" << std::endl;
		Sleep(1000);
	}
	_endthread();
	return 0;
	}
	
	DWORD GetCurrentThreadId(void);
};

class breno: public ThreadObject{
	private:

	public:
		breno(){
			
		}
	DWORD ThreadMemberFunc() {
	while(!this->GetKillThread())
	{
		std::cout << "Estou na thread BRENO" << std::endl;
		Sleep(1000);
	}
	_endthread();
	return 0;
	}
	
	void borapara(){
		SuspendThread(m_hThread);
	}
	
	void boravoltar(){
		ResumeThread(m_hThread);
	}
};

int main()
{
	std::cout<<"entrei meu querido/n ";
	teste tes;
	breno bre;
	vem vem;
	bre.StartThread();
	Sleep(5000);
	
	tes.StartThread(); // Cria thread
	Sleep(3000);
	bre.borapara();
	Sleep(5000);
	
	vem.StartThread();
	Sleep(5000);
	tes.SetKillThread(true);
	tes.WaitForExit(); // Espera fim da thread
	vem.SetKillThread(true);
	vem.WaitForExit(); // Espera fim da thread
	cout<<"Acabei de fazer aui bobap";
	bre.boravoltar();
	Sleep(3000);
	bre.SetKillThread(true);
	bre.WaitForExit();
	std::cout<<"acabou meu querido ";
	
}


