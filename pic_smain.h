//---------------------------------------------------------------------------

#ifndef pic_smainH
#define pic_smainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "JvHidControllerClass.hpp"
#include <XPMan.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TJvHidDeviceController *JvHidDeviceController1;
	TGroupBox *GroupBox1;
	TListBox *ListBox2;
	TListBox *ListBox1;
	TMemo *Memo1;
	TButton *Button2;
	TButton *Button3;
	TEdit *Edit1;
	TXPManifest *XPManifest1;
	TLabel *Label1;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TLabel *Label2;
	TLabel *Label3;
	TButton *Button1;
	TEdit *Edit9;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label6;
	TLabel *Label7;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TButton *Button4;
	TButton *Button5;
	TEdit *Edit10;
	TLabel *Label12;
	void __fastcall Recebe_Dados(TJvHidDevice *HidDev,
	  BYTE ReportID,const void *Data, WORD Size);
	void __fastcall	Zera_24cxx();
	void __fastcall	Enviar_Comando();
	void __fastcall	Controla_Led();
	void __fastcall JvHidDeviceController1Arrival(TJvHidDevice *HidDev);
	void __fastcall JvHidDeviceController1DeviceChange(TObject *Sender);
	void __fastcall JvHidDeviceController1DeviceData(TJvHidDevice *HidDev,
		  BYTE ReportID, const Pointer Data, WORD Size);
	bool __fastcall JvHidDeviceController1Enumerate(TJvHidDevice *HidDev,
          const int Idx);
	void __fastcall ListBox2Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall JvHidDeviceController1Removal(TJvHidDevice *HidDev);
	void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit2KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit3KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit6KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit7KeyPress(TObject *Sender, char &Key);
	void __fastcall Edit8KeyPress(TObject *Sender, char &Key);
	void __fastcall Button5Click(TObject *Sender);
	void __fastcall Button4Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
