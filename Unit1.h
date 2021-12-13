//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Chart.hpp>
#include <ExtCtrls.hpp>
#include <TeEngine.hpp>
#include <TeeProcs.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Dialogs.hpp>
#include <Series.hpp>
#include <CheckLst.hpp>
#include "CandleCh.hpp"
#include "ErrorBar.hpp"
#include "PERFGRAP.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TSpeedButton *SpeedButton3;
        TListBox *ListBox1;
        TLabel *Label1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TGroupBox *GroupBox2;
        TListBox *ListBox2;
        TProgressBar *ProgressBar1;
        TGroupBox *GroupBox4;
        TSpeedButton *SpeedButton4;
        TButton *Button4;
        TCheckBox *CheckBox7;
        TGroupBox *GroupBox6;
        TLabeledEdit *LabeledEdit14;
        TPageControl *PageControl2;
        TTabSheet *TabSheet4;
        TLabel *Label2;
        TLabel *Label4;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label5;
        TChart *Chart1;
        TFastLineSeries *Series1;
        TChart *Chart2;
        TFastLineSeries *Series2;
        TFastLineSeries *Series4;
        TGroupBox *GroupBox7;
        TButton *Button5;
        TLabeledEdit *LabeledEdit11;
        TLabeledEdit *LabeledEdit13;
        TButton *Button6;
        TTrackBar *TrackBar1;
        TUpDown *UpDown2;
        TTabSheet *TabSheet5;
        TChart *Chart3;
        TFastLineSeries *Series5;
        TFastLineSeries *Series6;
        TFastLineSeries *Series7;
        TFastLineSeries *Series8;
        TFastLineSeries *Series9;
        TFastLineSeries *Series10;
        TFastLineSeries *Series11;
        TFastLineSeries *Series12;
        TFastLineSeries *Series13;
        TFastLineSeries *Series14;
        TFastLineSeries *Series15;
        TFastLineSeries *Series16;
        TFastLineSeries *Series17;
        TFastLineSeries *Series18;
        TFastLineSeries *Series19;
        TFastLineSeries *Series20;
        TFastLineSeries *Series21;
        TFastLineSeries *Series22;
        TFastLineSeries *Series23;
        TFastLineSeries *Series24;
        TFastLineSeries *Series25;
        TFastLineSeries *Series26;
        TFastLineSeries *Series27;
        TFastLineSeries *Series28;
        TCheckListBox *CheckListBox1;
        TCheckBox *CheckBox6;
        TLabel *Label9;
        TGroupBox *GroupBox5;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TCheckBox *CheckBox5;
        TRadioButton *RadioButton9;
        TRadioGroup *RadioGroup2;
        TLabel *Label11;
        TLabel *Label12;
        TLabel *Label13;
        TChart *Chart5;
        TFastLineSeries *FastLineSeries1;
        TChart *Chart4;
        TButton *Button7;
        TButton *Button8;
        TTrackBar *TrackBar2;
        TUpDown *UpDown3;
        TButton *Button9;
        TButton *Button10;
        TEdit *Edit1;
        TEdit *Edit2;
        TChart *Chart6;
        TFastLineSeries *Series29;
        TButton *Button2;
        TGroupBox *GroupBox8;
        TButton *Button3;
        TLabeledEdit *LabeledEdit17;
        TLabeledEdit *LabeledEdit18;
        TLabel *Label15;
        TButton *Button11;
        TCheckBox *CheckBox10;
        TLabel *Label16;
        TBarSeries *Series3;
        TTabSheet *TabSheet6;
        TChart *Chart7;
        TFastLineSeries *FastLineSeries2;
        TButton *Button13;
        TButton *Button14;
        TChart *Chart8;
        TFastLineSeries *FastLineSeries3;
        TEdit *Edit3;
        TLabel *Label17;
        TCheckBox *CheckBox11;
        TCheckBox *CheckBox12;
        TRadioGroup *RadioGroup4;
        TGroupBox *GroupBox9;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TTabSheet *TabSheet7;
        TBitBtn *BitBtn1;
        TFastLineSeries *Series30;
        TLabeledEdit *LabeledEdit24;
        TCheckBox *CheckBox14;
        TLabel *Label18;
        TRadioGroup *RadioGroup5;
        TSaveDialog *SaveDialog1;
        TButton *Button15;
        TCheckBox *CheckBox16;
        TChart *Chart9;
        TFastLineSeries *Series31;
        TTabSheet *TabSheet8;
        TGroupBox *GroupBox10;
        TPageControl *PageControl3;
        TTabSheet *TabSheet9;
        TTabSheet *TabSheet10;
        TTabSheet *TabSheet11;
        TLabeledEdit *LabeledEdit2;
        TCheckBox *CheckBox15;
        TLabeledEdit *LabeledEdit10;
        TComboBox *ComboBox1;
        TLabel *Label10;
        TLabeledEdit *LabeledEdit12;
        TLabeledEdit *LabeledEdit15;
        TLabeledEdit *LabeledEdit1;
        TCheckBox *CheckBox4;
        TLabeledEdit *LabeledEdit5;
        TLabeledEdit *LabeledEdit6;
        TCheckBox *CheckBox2;
        TCheckBox *CheckBox3;
        TCheckBox *CheckBox1;
        TLabeledEdit *LabeledEdit16;
        TLabeledEdit *LabeledEdit19;
        TButton *Button12;
        TGroupBox *GroupBox3;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TGroupBox *GroupBox11;
        TLabeledEdit *LabeledEdit7;
        TUpDown *UpDown1;
        TLabeledEdit *LabeledEdit9;
        TLabeledEdit *LabeledEdit8;
        TLabeledEdit *LabeledEdit4;
        TLabel *Label3;
        TLabeledEdit *LabeledEdit22;
        TLabeledEdit *LabeledEdit25;
        TLabeledEdit *LabeledEdit21;
        TLabeledEdit *LabeledEdit27;
        TLabeledEdit *LabeledEdit28;
        TCheckBox *CheckBox13;
        TLabeledEdit *LabeledEdit26;
        TLabeledEdit *LabeledEdit20;
        TLabeledEdit *LabeledEdit23;
        TFastLineSeries *Series32;
        TButton *Button16;
        TButton *Button1;
        TRadioGroup *RadioGroup1;
        TRadioButton *RadioButton8;
        TLabeledEdit *LabeledEdit3;
        TRadioGroup *RadioGroup3;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TFastLineSeries *Series33;
        TButton *Button17;
        TButton *Button18;
        TLabel *Label14;
        TLabel *Label19;
        TButton *Button19;
        TGroupBox *GroupBox13;
        TCheckBox *CheckBox18;
        TLabel *Label20;
        TCheckBox *CheckBox19;
        TVolumeSeries *Series35;
        TVolumeSeries *Series34;
        TGroupBox *GroupBox14;
        TButton *Button20;
        TButton *Button21;
        TButton *Button22;
        TButton *Button23;
        TOpenDialog *OpenDialog1;
        TCheckBox *CheckBox20;
        TGroupBox *GroupBox15;
        TUpDown *UpDown4;
        TUpDown *UpDown5;
        TCheckBox *CheckBox21;
        TGroupBox *GroupBox16;
        TButton *Button24;
        TButton *Button25;
        TButton *Button26;
        TButton *Button27;
        TCheckBox *CheckBox22;
        TLabel *Label21;
        TLabel *Label22;
        TGroupBox *GroupBox12;
        TCheckBox *CheckBox17;
        TEdit *Edit4;
        TEdit *Edit5;
        TCheckBox *CheckBox9;
        TOpenDialog *OpenDialog2;
        TButton *Button28;
        TRadioButton *RadioButton7;
        TCheckBox *CheckBox8;
        TFastLineSeries *Series36;
        TCheckBox *CheckBox23;
        TLabel *Label23;
        TButton *Button29;
        TLabeledEdit *LabeledEdit29;
        TCheckBox *CheckBox24;
        TButton *Button30;
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall SpeedButton2Click(TObject *Sender);
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
        void __fastcall TrackBar1Change(TObject *Sender);
        void __fastcall LabeledEdit9Enter(TObject *Sender);
        void __fastcall Chart1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Chart2MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall SpeedButton4Click(TObject *Sender);
        void __fastcall Button4Click(TObject *Sender);
        void __fastcall CheckListBox1Click(TObject *Sender);
        void __fastcall Button6Click(TObject *Sender);
        void __fastcall Button5Click(TObject *Sender);
        void __fastcall Chart3MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall Chart3MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Chart1Zoom(TObject *Sender);
        void __fastcall Chart1UndoZoom(TObject *Sender);
        void __fastcall Chart2Zoom(TObject *Sender);
        void __fastcall Chart2UndoZoom(TObject *Sender);
        void __fastcall Chart4MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall RadioButton5Click(TObject *Sender);
        void __fastcall RadioButton7Click(TObject *Sender);
        void __fastcall RadioButton8Click(TObject *Sender);
        void __fastcall LabeledEdit1KeyPress(TObject *Sender, char &Key);
        void __fastcall CheckBox6Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall RadioButton6Click(TObject *Sender);
        void __fastcall RadioGroup2Click(TObject *Sender);
        void __fastcall CheckBox9Click(TObject *Sender);
        void __fastcall RadioButton9Click(TObject *Sender);
        void __fastcall Button7Click(TObject *Sender);
        void __fastcall Button8Click(TObject *Sender);
        void __fastcall CheckBox5Click(TObject *Sender);
        void __fastcall UpDown3Click(TObject *Sender, TUDBtnType Button);
        void __fastcall TrackBar2Change(TObject *Sender);
        void __fastcall Button3Click(TObject *Sender);
        void __fastcall Button11Click(TObject *Sender);
        void __fastcall Chart1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall LabeledEdit16KeyPress(TObject *Sender, char &Key);
        void __fastcall Button12Click(TObject *Sender);
        void __fastcall Button14Click(TObject *Sender);
        void __fastcall Button13Click(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall Button15Click(TObject *Sender);
        void __fastcall RadioGroup4Click(TObject *Sender);
        void __fastcall RadioGroup5Click(TObject *Sender);
        void __fastcall Button16Click(TObject *Sender);
        void __fastcall Chart3DblClick(TObject *Sender);
        void __fastcall Chart9MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Button17Click(TObject *Sender);
        void __fastcall Button18Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Button19Click(TObject *Sender);
        void __fastcall LabeledEdit9KeyPress(TObject *Sender, char &Key);
        void __fastcall CheckBox8Click(TObject *Sender);
        void __fastcall CheckBox19Click(TObject *Sender);
        void __fastcall Chart5DblClick(TObject *Sender);
        void __fastcall Chart4DblClick(TObject *Sender);
        void __fastcall Chart1DblClick(TObject *Sender);
        void __fastcall Chart9DblClick(TObject *Sender);
        void __fastcall Chart6DblClick(TObject *Sender);
        void __fastcall Button23Click(TObject *Sender);
        void __fastcall CheckBox20Click(TObject *Sender);
        void __fastcall Button22Click(TObject *Sender);
        void __fastcall Button20Click(TObject *Sender);
        void __fastcall Button21Click(TObject *Sender);
        void __fastcall CheckBox13Click(TObject *Sender);
        void __fastcall Button28Click(TObject *Sender);
        void __fastcall LabeledEdit20KeyPress(TObject *Sender, char &Key);
        void __fastcall ComboBox1Change(TObject *Sender);
        void __fastcall LabeledEdit10KeyPress(TObject *Sender, char &Key);
        void __fastcall LabeledEdit23KeyPress(TObject *Sender, char &Key);
        void __fastcall Button29Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall LabeledEdit29KeyPress(TObject *Sender, char &Key);
        void __fastcall Button30Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <complex.h>
#include <fstream.h>
#include <clipbrd.hpp>
#include <IniFiles.hpp>

int __fastcall ReadF1_Data(int type, int nch, int nd);
void __fastcall ReadF_Data(int posd, int posf, int nd, int type);
void __fastcall Conv_mV(float* inbuf,  float* out, int n, int nch);
void __fastcall norm_data(float* inbuf,  float* out, int n, int nch);
int __fastcall Detector_Ob(float* in, int* out, int sn, int n);
int __fastcall DetErrObor();
void __fastcall DelOborot(int starto, int stopo);
int __fastcall Calc_Param_Ob();
void __fastcall Norm_Data_Ob(int nd);
void __fastcall View_Ob();
void __fastcall View_ObT();
void ViewerrOb();
void __fastcall View_Obor_Data(int nt);
int __fastcall Calc_Ob_Reductor();
void __fastcall Calc_Garm();
int __fastcall Calc_Garm_Usr();
void __fastcall ViewGarm_All();
void __fastcall ViewGarm();
void __fastcall View_Garm_Obor(int nt);
void ViewMetkiOb();
void __fastcall ViewGarmUsr();
void __fastcall Paint_Char();
void __fastcall Calc_Param();
int __fastcall Calc_Len_Data(int type);
void Obor_FFT(int nt);
void __fastcall Fft(int isign, int num_time, complex<float> *data);
int ReadF_Data_Enc(int,int);
void View_Data_Enc(int nd);
void View_tStrob_Enc(int nd);
int Calc_T_EncT();
int Syntez_Signal_Enc();
void ReadEncView(int offs);
int __fastcall GetTEncFromFile();
int __fastcall GetTEncFromFileLenta();
long __fastcall GetEncNumSampleFile();
void __fastcall ViewTEnc();
void __fastcall ViewSigEnc();
int getTObor(int Num);
void __fastcall PorogTEnc();
int getTOborLenta(int Num);
void View_Ob_Enc();
void CalcNoborFix();

#define N_RCV_MAX 8000000
#define LEN_VIEW_DEF 100000
#define MAX_H 30000
#define MAX_H_USR 4000
#define MAX_H_ERR 5000
#define MAX_LEN_OB 50000
#define N_MAX_GARM 25
#define PI      3.14159265
#define NBUF_DET_PEREHOD 9
#define MAX_METOK_LENTA 4000
//---------------------------------------------------------------------------
#endif
