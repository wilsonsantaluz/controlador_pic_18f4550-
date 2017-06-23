//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "pic_smain.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "JvHidControllerClass"
#pragma resource "*.dfm"
TForm1 *Form1;
TJvHidDevice *CurrentDevice;
Integer Controle;
TJvHidDevice *Dev;
//---------------------------------------------------------------------------
void __fastcall TForm1::Recebe_Dados(TJvHidDevice *HidDev,
	  BYTE ReportID,const void *Data, WORD Size)
{
Integer I;

Byte Aux;
String str;
Edit9->Clear();
for (I = 0; I < Size ; I++)
{
Aux =(PChar(Data)[I]);
str = str + IntToHex(Aux,2);

Edit9->Text = UpperCase(str);
}
Memo1->Lines->Add(UpperCase(str));

}
//
void __fastcall TForm1::Enviar_Comando()
{
Cardinal ToWrite,Written;
Byte Buf[64];
if (CurrentDevice)
{
ToWrite = CurrentDevice->Caps.OutputReportByteLength;
Buf[0]= StrToInt(Edit1->Text);
Buf[1]= StrToInt(Edit2->Text);
Buf[2]= StrToInt(Edit3->Text);
Buf[3]= StrToInt(Edit4->Text);
Buf[4]= StrToInt(Edit5->Text);
Buf[5]= StrToInt(Edit6->Text);
Buf[6]= StrToInt(Edit7->Text);
Buf[7]= StrToInt(Edit8->Text);
Buf[8]= StrToInt(Edit10->Text);
//
Written = 0;
CurrentDevice->WriteFile(Buf, ToWrite, Written);
}

}


void __fastcall TForm1::Controla_Led()
{
Integer I;
Cardinal ToWrite,Written;
Byte Buf[8];
if (CurrentDevice)
{
ToWrite = CurrentDevice->Caps.OutputReportByteLength;
Buf[0]= 0;
Buf[1]= Controle;
Buf[2]= 0;
Buf[3]= 0;
Buf[4]= 0;
Buf[5]= 0;
Buf[6]= 0;
Buf[7]= 0;
Buf[8]= 0;
////////////////
Written = 0;
CurrentDevice->WriteFile(Buf, ToWrite, Written);
}
}
////
void __fastcall TForm1::Zera_24cxx()
{
Integer I;
Cardinal ToWrite,Written;
Byte Buf[8];
if (CurrentDevice)
{
ToWrite = CurrentDevice->Caps.OutputReportByteLength;
Buf[0]= 0;
Buf[1]= 15;
Buf[2]= StrToInt(Edit1->Text);
Buf[3]= 0;
Buf[4]= 0;
Buf[5]= 0;
Buf[6]= 0;
Buf[7]= 0;
Buf[8]= 0;
////////////////
Written = 0;
CurrentDevice->WriteFile(Buf, ToWrite, Written);
}
}
////
String DeviceName(TJvHidDevice *HidDev)
{
AnsiString str;
if (HidDev->ProductName != "")
{
return HidDev->ProductName;
}
else
{
return str.sprintf("VID=%04X PID=%04X",HidDev->Attributes.VendorID,HidDev->Attributes.ProductID);
}
if (HidDev->SerialNumber != "")
{
return  str.sprintf(" (Serial=%s)",HidDev->SerialNumber);
}
return(0);
}
//

//
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::JvHidDeviceController1Arrival(TJvHidDevice *HidDev)
{
//TJvHidDevice *Dev;
//AnsiString str;
//ListBox1->Items->Add(str.sprintf("VID=%04X PID=%04X",HidDev->Attributes.VendorID,HidDev->Attributes.ProductID));
}
//---------------------------------------------------------------------------


void __fastcall TForm1::JvHidDeviceController1DeviceChange(TObject *Sender)
{
  TJvHidDevice *Dev;
   int I;
   // HidCtlDeviceChange happens before TUsagesForm.Create completed
   // DevListBox may have not been created yet
   if(ListBox2 != NULL)
   {
 	// hand back all the devices assigned to the list entries
	for(I = 0; I < ListBox2->Count; I++)
	{
	  Dev = (TJvHidDevice *) ListBox2->Items->Objects[I];
	  JvHidDeviceController1->CheckIn(Dev);
	  ListBox2->Items->Objects[I] = NULL;
 	}
	ListBox2->Items->Clear();
   //	ListBox2->Color = clScrollBar;
   //	ListBox2->Enabled = false;
	JvHidDeviceController1->Enumerate();
   }

//TJvHidDevice *Dev = (TJvHidDevice *)DevList->Items[DevListBox->ItemIndex];
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvHidDeviceController1DeviceData(TJvHidDevice *HidDev,
	  BYTE ReportID, const Pointer Data, WORD Size)
{
Integer I;
AnsiString str;

if (CurrentDevice)
{
 CurrentDevice->OnData = Recebe_Dados;
}

}
//---------------------------------------------------------------------------

bool __fastcall TForm1::JvHidDeviceController1Enumerate(TJvHidDevice *HidDev,
      const int Idx)
{
Integer N;
TJvHidDevice *Dev;

  N = ListBox2->Items->Add(DeviceName(HidDev));
  JvHidDeviceController1->CheckOutByIndex(Dev,Idx);
  HidDev->NumInputBuffers = 128;
  HidDev->NumOverlappedBuffers = 128;
  ListBox2->Items->Objects[N] = Dev;
  return true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::ListBox2Click(TObject *Sender)
{

Integer I;


ListBox1->Clear();
  CurrentDevice = 0;
  if (ListBox2->ItemIndex != -1)
  {
  Dev = (TJvHidDevice *)ListBox2->Items->Objects[ListBox2->ItemIndex];
  CurrentDevice = Dev;
  }
  if (ListBox2->ItemIndex != -1)
  {
 ListBox1->Items->Append("Conectado -> " + ListBox2->Items->Strings[ListBox2->ItemIndex]) ;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
//TJvHidDevice *Dev;
  if (ListBox2->ItemIndex != -1)
  {
  ListBox1->Clear();
  Dev = (TJvHidDevice *)ListBox2->Items->Objects[0];
  CurrentDevice = Dev;
  ListBox1->Items->Append("Vendor : " + CurrentDevice->VendorName);
  ListBox1->Items->Append("Product Name : " + CurrentDevice->ProductName);
  ListBox1->Items->Append("Serial : " + CurrentDevice->SerialNumber);
  ListBox1->Items->Append("Vendor ID : " + IntToHex(CurrentDevice->Attributes.VendorID,4));
  ListBox1->Items->Append("Product ID : " + IntToHex(CurrentDevice->Attributes.ProductID,4));
  ListBox1->Items->Append("Version Number : " + IntToHex(CurrentDevice->Attributes.VersionNumber,4));
  ListBox1->Items->Append("Input Report Byte : " + IntToStr(CurrentDevice->Caps.InputReportByteLength - 1)+ " Bytes");
  ListBox1->Items->Append("Output Report Byte : " + IntToStr(CurrentDevice->Caps.OutputReportByteLength - 1)+ " Bytes");
  ListBox1->Items->Append("FeatureReport : " + IntToStr(CurrentDevice->Caps.FeatureReportByteLength )+ " Bytes");
  //Memo1->Lines->Add(CurrentDevice->LanguageStrings);


  }

}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button3Click(TObject *Sender)
{
if (CurrentDevice)
 {
   Enviar_Comando();
   Application->ProcessMessages();
 }

}
//---------------------------------------------------------------------------



void __fastcall TForm1::Button1Click(TObject *Sender)
{
Memo1->Clear();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::JvHidDeviceController1Removal(TJvHidDevice *HidDev)
{
ListBox1->Clear();
Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
if (!(Key >= '0' && Key <= '9')&&(Key != VK_BACK)&&(!(Key >= 'a' && Key <= 'f')&&(!(Key >= 'A' && Key <= 'F'))))
{
 Key = 0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit2KeyPress(TObject *Sender, char &Key)
{
if (!(Key >= '0' && Key <= '9')&&(Key != VK_BACK)&&(!(Key >= 'a' && Key <= 'f')&&(!(Key >= 'A' && Key <= 'F'))))
{
 Key = 0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit3KeyPress(TObject *Sender, char &Key)
{
if (!(Key >= '0' && Key <= '9')&&(Key != VK_BACK)&&(!(Key >= 'a' && Key <= 'f')&&(!(Key >= 'A' && Key <= 'F'))))
{
 Key = 0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit4KeyPress(TObject *Sender, char &Key)
{
if (!(Key >= '0' && Key <= '9')&&(Key != VK_BACK)&&(!(Key >= 'a' && Key <= 'f')&&(!(Key >= 'A' && Key <= 'F'))))
{
 Key = 0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit5KeyPress(TObject *Sender, char &Key)
{
if (!(Key >= '0' && Key <= '9')&&(Key != VK_BACK)&&(!(Key >= 'a' && Key <= 'f')&&(!(Key >= 'A' && Key <= 'F'))))
{
 Key = 0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit6KeyPress(TObject *Sender, char &Key)
{
if (!(Key >= '0' && Key <= '9')&&(Key != VK_BACK)&&(!(Key >= 'a' && Key <= 'f')&&(!(Key >= 'A' && Key <= 'F'))))
{
 Key = 0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit7KeyPress(TObject *Sender, char &Key)
{
if (!(Key >= '0' && Key <= '9')&&(Key != VK_BACK)&&(!(Key >= 'a' && Key <= 'f')&&(!(Key >= 'A' && Key <= 'F'))))
{
 Key = 0;
}
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit8KeyPress(TObject *Sender, char &Key)
{
if (!(Key >= '0' && Key <= '9')&&(Key != VK_BACK)&&(!(Key >= 'a' && Key <= 'f')&&(!(Key >= 'A' && Key <= 'F'))))
{
 Key = 0;
}	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button5Click(TObject *Sender)
{
   Controle ='1';
   Controla_Led();
   Application->ProcessMessages();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button4Click(TObject *Sender)
{
   Controle = '2';
   Controla_Led();
   Application->ProcessMessages();
}
//---------------------------------------------------------------------------

