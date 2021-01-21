#define WIN32_LEAN_AND_MEAN
#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <process.h> // _beginthreadex() e _endthreadex()
#include <conio.h> // _getch
// Casting para terceiro e sexto parâmetros da função _beginthreadex
typedef unsigned (WINAPI *CAST_FUNCTION)(LPVOID);
typedef unsigned *CAST_LPDWORD;
#define EQUIPES 7
#define MAX_CARROS_PISTA 5
#define NUM_CARROS 10 // número de carros na simulação
HANDLE hMutex[EQUIPES];
HANDLE hSemaphore;
DWORD WINAPI FuncCar(LPVOID); // declaração da função
int main()
{
HANDLE hThreads[NUM_CARROS];
DWORD dwThreadId;
DWORD dwExitCode = 0;
DWORD dwRet;
int nEquipe, nCar;
char BoxName[5];
// cria Mutexes, um para cada Equipe
for (nEquipe=0; nEquipe<EQUIPES; ++nEquipe) {
sprintf(BoxName, "Box%d", nEquipe);
hMutex[nEquipe] = CreateMutex(NULL, FALSE, BoxName);
} //for
hSemaphore =

CreateSemaphore(NULL,MAX_CARROS_PISTA,MAX_CARROS_PISTA,"MAX_CARROS");

// cria threads, uma para cada carro
for (nCar=0; nCar<NUM_CARROS; ++nCar) {
nEquipe = rand() % EQUIPES;
// cada thread representa um carro de uma equipe
hThreads[nCar] = (HANDLE) _beginthreadex(

NULL, 0, (CAST_FUNCTION)FuncCar,
(LPVOID)((nCar<<8) + nEquipe),
0, (CAST_LPDWORD)&dwThreadId );

if (hThreads[nCar])
printf("Carro %2d Equipe %d Id= %0x \n", nCar, nEquipe, dwThreadId);

} // for
// Espera todas as threads terminarem
dwRet = WaitForMultipleObjects(NUM_CARROS,hThreads,TRUE,INFINITE);
for (nCar=0; nCar<NUM_CARROS; ++nCar) {
dwRet
=GetExitCodeThread(hThreads[nCar], &dwExitCode);
CloseHandle(hThreads[nCar]); // apaga referência ao objeto
} // for
for (nEquipe=0; nEquipe < EQUIPES; ++nEquipe) CloseHandle(hMutex[nEquipe]);
CloseHandle(hSemaphore);
printf("\nAcione uma tecla para terminar\n");

_getch(); // Pare aqui, caso não esteja executando no ambiente MDS
//- Microsoft Developer Studio
return EXIT_SUCCESS;
} // main
DWORD WINAPI FuncCar(LPVOID id)
{
LONG lOldValue;
int nCar, iTeam;
iTeam= (DWORD)id % 256;
nCar = (DWORD)id / 256;
for (int i=0;i<3;++i) { // dá 3 voltas na pista
printf("Carro %d da Equipe %d quer treinar... volta %d \n", nCar,

iTeam, i);

WaitForSingleObject(hMutex[iTeam], INFINITE);
WaitForSingleObject(hSemaphore, INFINITE);
printf("Carro %d da Equipe %d treinando... volta %d \n", nCar,

iTeam, i);

Sleep(100*(rand() % 10)); // corre durante certo tempo
ReleaseSemaphore(hSemaphore, 1, &lOldValue);
ReleaseMutex(hMutex);
printf("Carro %d da Equipe %d acabou de treinar... volta %d \n", nCar,

iTeam, i);

} // for _endthreadex(0);
return(0);
} // FuncCar
