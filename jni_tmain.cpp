#include "jni_tmain.h"
#include <Windows.h>
#include "data.h"

JNIEXPORT void JNICALL Java_jni_tmain_no_1args_1return
(JNIEnv*, jobject)
{
	OutputDebugString(L"Java_jni_tmain_no_1args_1return beg");

	HWND hwnd = FindWindow(NULL, L"daemon");
	if (hwnd) {
		int len = 32;
		PARAM* param = (PARAM *)malloc(sizeof(PARAM) + sizeof(int) * len);
		param->len = len;
		for (int i = 0; i < len; ++i)
			param->data[i] = 4;
		COPYDATASTRUCT cpd;
		cpd.dwData = 0;
		cpd.lpData = param;
		cpd.cbData = sizeof(PARAM) + sizeof(int) * len;
		SendMessage(hwnd, WM_COPYDATA, 0, (LPARAM)&cpd);
	}

	int i = Data::get_instance()->d.back();
	char str[32] = { 0 };
	sprintf_s(str, "deque %d", i);
	OutputDebugStringA(str);

	OutputDebugString(L"Java_jni_tmain_no_1args_1return end");
}
