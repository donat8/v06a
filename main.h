#include <windows.h>
#include <tchar.h>
#include "nwpwin.h"
#include "nwpdlg.h"

class SizeDialog : public Dialog {
private:
	POINT paramsXY;
public:
	SizeDialog(POINT params)
		:paramsXY(params) {}
	POINT GetParamsXY() const { return paramsXY; }
protected:
	int IDD();
	bool OnInitDialog();
	bool OnOK();
	bool CheckInput(long& ref, int ctrlID);

};

class MainWindow : public Window {
private:
	COLORREF color;
	POINT params;
public:
	MainWindow()
		:params({ 20,20 }), color(RGB(128, 128, 255))
	{}
protected:
	void OnPaint(HDC hdc);
	void OnCommand(int id);
	void OnDestroy();
};
