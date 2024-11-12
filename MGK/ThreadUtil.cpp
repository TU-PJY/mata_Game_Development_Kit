#include "ThreadUtil.h"


void ThreadUtil::New(HANDLE& HandleValue, LPTHREAD_START_ROUTINE ThreadFunction, LPVOID Param) {
	HandleValue = CreateThread(NULL, 0, ThreadFunction, Param, 0, NULL);
}

bool ThreadUtil::IsRunning(HANDLE& HandleValue) {
	DWORD Result;
	GetExitCodeThread(HandleValue, &Result);

	if (Result == STILL_ACTIVE)
		return true;
	return false;
}

void ThreadUtil::Delete(HANDLE& HandleValue) {
	CloseHandle(HandleValue);
}

void ThreadUtil::InitSection(CRITICAL_SECTION& Section) {
	InitializeCriticalSection(&Section);
}

void ThreadUtil::DeleteSection(CRITICAL_SECTION& Section) {
	DeleteCriticalSection(&Section);
}

void ThreadUtil::Lock(CRITICAL_SECTION& Section) {
	EnterCriticalSection(&Section);
}

void ThreadUtil::Unlock(CRITICAL_SECTION& Section) {
	LeaveCriticalSection(&Section);
}